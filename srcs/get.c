/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jemagnie <jemagnie@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/21 15:31:56 by jemagnie     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 16:43:47 by jemagnie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		get_line(t_lem *lem, t_line **line, char *s)
{
	t_line	*new;

	if ((new = ft_memalloc(sizeof(t_line))))
	{
		if (line)
		{
			new->line = s;
			new->next = *line;
			new->len = ft_strlen(s);
			lem->n_buff += new->len + 1;
			*line = new;
			return (1);
		}
	}
	return (ft_error("Error malloc", 0));
}

int		get_room(t_room **room, char *line, int index)
{
	t_room	*new;
	int		i;

	if (!(new = ft_memalloc(sizeof(t_room))))
		return (ft_error("Error malloc", 0));
	i = 0;
	while (line[i] && line[i] != ' ')
		++i;
	if (!(new->name = ft_strndup(line, i)))
		return (ft_error("Error malloc", 0));
	line += i;
	new->index = index;
	new->pos.x = ft_atoi_ptr(&line);
	new->pos.y = ft_atoi_ptr(&line);
	if (avl_insert(room, new))
		return (1);
	free(new->name);
	free(new);
	return (ft_error("Room already exist", 0));
}

int		get_start(t_lem *lem)
{
	char	*line;
	long	tmp;

	if (!(get_next_line(0, &line)))
	{
		free(line);
		return (0);
	}
	if (!get_line(lem, &(lem->line), line))
		return (0);
	if (valid_room(line))
	{
		tmp = (long)lem->n_room;
		lem->start = (t_room *)tmp;
		lem->b_start = 1;
		if (!get_room(&(lem->room), line, lem->n_room))
			return (0);
		++(lem->n_room);
		return (1);
	}
	return (ft_error("Invalid start", 0));
}

int		get_end(t_lem *lem)
{
	char	*line;
	long	tmp;

	if (!(get_next_line(0, &line)))
	{
		free(line);
		return (0);
	}
	if (!get_line(lem, &(lem->line), line))
		return (0);
	if (valid_room(line))
	{
		tmp = (long)lem->n_room;
		lem->end = (t_room *)tmp;
		lem->b_end = 1;
		if (!(get_room(&(lem->room), line, lem->n_room)))
			return (0);
		++(lem->n_room);
		return (1);
	}
	return (ft_error("Invalid end", 0));
}

int		get_link(t_lem *lem, int a, int b)
{
	int		**tab;

	tab = lem->tab;
	if (a == -1 || b == -1)
		return (0);
	if (!(tab[a][b]))
	{
		tab[a][b] = 1;
		++(lem->room[a].n_link);
	}
	if (!(tab[b][a]))
	{
		tab[b][a] = 1;
		++(lem->room[b].n_link);
	}
	return (1);
}
