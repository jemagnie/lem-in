/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mem.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jemagnie <jemagnie@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/21 15:33:13 by jemagnie     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 16:50:22 by jemagnie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	delete_avl(t_room **node)
{
	if (node && *node)
	{
		if ((*node)->LEFT)
			delete_avl(&(*node)->LEFT);
		if ((*node)->RIGHT)
			delete_avl(&(*node)->RIGHT);
		free(*node);
		*node = NULL;
	}
}

int		fill_link(t_lem *lem, t_room *room)
{
	int		*tab;
	int		i;
	int		j;
	int		l;

	i = -1;
	room = lem->room;
	while (++i < lem->n_room)
	{
		if (!(room[i].link = ft_memalloc(sizeof(t_room *) *
			(room[i].n_link + 1))))
			return (ft_error("Error malloc", 0));
		j = -1;
		l = -1;
		tab = lem->tab[i];
		while (++j < lem->n_room)
			if (tab[j])
				room[i].link[++l] = room + j;
		room[i].link[++l] = NULL;
		room[i].depth = 0;
		room[i].queue = NULL;
		room[i].prev = NULL;
	}
	return (1);
}

void	fill_room(t_room *old, t_room *new)
{
	new[old->index].name = old->name;
	new[old->index].index = old->index;
	if (old->LEFT)
	{
		fill_room(old->LEFT, new);
		new[old->index].LEFT = new + old->LEFT->index;
	}
	else
		new[old->index].LEFT = NULL;
	if (old->RIGHT)
	{
		fill_room(old->RIGHT, new);
		new[old->index].RIGHT = new + old->RIGHT->index;
	}
	else
		new[old->index].RIGHT = NULL;
}

int		create_mem(t_lem *lem, const char *line)
{
	int		i;
	t_room	*new;

	if (!lem->n_room || !lem->b_start || !lem->b_end)
		return (0);
	lem->bin_way = (lem->n_room >> 6) + (lem->n_room & 63 ? 1 : 0);
	if (!(new = ft_memalloc(sizeof(long) * lem->bin_way +
		sizeof(t_room) * lem->n_room +
		(sizeof(int *) + sizeof(int) * lem->n_room) * lem->n_room)))
		return (0);
	i = lem->room->index;
	fill_room(lem->room, new);
	delete_avl(&(lem->room));
	lem->avl = new + i;
	lem->room = new;
	lem->tab = (int **)(lem->room + lem->n_room);
	i = -1;
	lem->tab[0] = (int *)(lem->tab + lem->n_room);
	while (++i < lem->n_room)
		lem->tab[i] = lem->tab[0] + i * lem->n_room;
	lem->is_way = (long *)(lem->tab[0] + i * lem->n_room);
	return (!valid_link(lem, line, -1, -1) ? delete_lem(lem) : 1);
}
