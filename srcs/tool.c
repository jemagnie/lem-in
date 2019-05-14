/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tool.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jemagnie <jemagnie@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/21 15:36:41 by jemagnie     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/15 00:24:35 by jemagnie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	reinitialize(t_lem *lem, t_room *room)
{
	t_room	*tmp;

	while (room)
	{
		room->depth = 0;
		room->prev = NULL;
		tmp = room;
		room = room->queue;
		tmp->queue = NULL;
	}
	lem->start->prev = (void *)1;
}

void	delete_line(t_line *line)
{
	t_line	*tmp;

	while (line)
	{
		tmp = line->next;
		if (line->line)
			free(line->line);
		if (line)
			free(line);
		line = tmp;
	}
}

void	delete_room(t_room **node)
{
	if (node && *node)
	{
		if ((*node)->LEFT)
			delete_room(&(*node)->LEFT);
		if ((*node)->RIGHT)
			delete_room(&(*node)->RIGHT);
		free((*node)->name);
		free(*node);
		*node = NULL;
	}
}

int		delete_parse(t_lem *lem)
{
	t_line	*line;
	t_line	*tmp;

	if (!lem->room && !lem->line)
	{
		return (0);
	}
	if (lem->line)
	{
		delete_line(lem->line);
		lem->line = NULL;
	}
	if (lem->room)
	{
		delete_room(&lem->room);
		lem->room = NULL;
	}
	return (0);
}
