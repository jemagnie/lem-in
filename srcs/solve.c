/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jemagnie <jemagnie@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/21 15:37:29 by jemagnie     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/15 00:24:48 by jemagnie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_room	*go_back(t_room *room, t_room *start, int **tab)
{
	t_room	*tmp;

	while (1)
	{
		--(tab[room->prev->index][room->index]);
		++(tab[room->index][room->prev->index]);
		if (room->prev == start)
			return (room);
		room = room->prev;
	}
}

void	fill_way(t_lem *lem, t_way **way, int **tab, int n)
{
	int		i;
	int		j;
	int		len;
	t_room	*room;

	i = -1;
	lem->total = 0;
	while (++i < n)
	{
		room = way[i][0].room;
		len = 1;
		while (room != lem->end)
		{
			j = -1;
			lem->is_way[room->index >> 6] |= 1L << (room->index & 63);
			while (tab[room->index][room->link[++j]->index] > 0)
				;
			room = room->link[j];
			way[i][len++].room = room;
		}
		way[i][len].room = room;
		way[i][0].len = len;
		lem->total += len;
		lem->max = len > lem->max ? len : lem->max;
	}
}

int		bfs(t_lem *lem, t_room *room, t_room *last, int **mat)
{
	int		i;
	t_room	*next;

	while (1)
	{
		i = -1;
		while (room->link[++i])
		{
			next = room->link[i];
			if (!next->prev && mat[room->index][next->index] > 0 &&
				(!room->IN_WAY || !(mat[next->index][room->index])))
			{
				next->prev = room;
				if ((lem->is_way[next->index >> 6] & 1L << (next->index & 63))
					&& mat[next->index][room->index])
					next->IN_WAY = 1;
				last->queue = next;
				last = next;
				if (next == lem->end)
					return (1);
			}
		}
		if (!(room = room->queue))
			return (0);
	}
}

void	algo(t_lem *lem, t_room *start, int rest, int i)
{
	int		j;
	int		score;

	while (1)
	{
		reinitialize(lem, start);
		if (!bfs(lem, start, start, lem->tab))
			break ;
		ft_bzero(lem->is_way, sizeof(long) * lem->bin_way);
		lem->way[i][0].room = go_back(lem->end, lem->start, lem->tab);
		fill_way(lem, lem->way, lem->tab, ++i);
		if ((rest = lem->n_ant - (lem->max * i - lem->total)) < 0)
			break ;
		score = lem->max - 1 + rest / i + (rest % i != 0);
		if (score < lem->score)
		{
			lem->score = score;
			lem->n_way = i;
			j = -1;
			while (++j < i)
				ft_memcpy(lem->tmp[j], lem->way[j],
					sizeof(t_way) * lem->way[j][0].len);
		}
	}
}

int		solve(t_lem *lem)
{
	int		i;

	if (!lem->start->n_link || !lem->end->n_link)
		return (ft_error("Can't be solved", 0));
	if (!(lem->way = ft_memalloc(2 * (sizeof(t_way *) * lem->start->n_link +
		sizeof(t_way) * lem->n_room * lem->start->n_link))))
		return (ft_error("Error malloc", 0));
	lem->way[0] = (t_way *)(lem->way + lem->start->n_link);
	i = -1;
	while (++i < lem->start->n_link)
		lem->way[i] = lem->way[0] + i * lem->n_room;
	lem->tmp = (t_way **)(lem->way[0] + i * lem->n_room);
	i = -1;
	lem->tmp[0] = (t_way *)(lem->tmp + lem->start->n_link);
	while (++i < lem->start->n_link)
		lem->tmp[i] = lem->tmp[0] + i * lem->n_room;
	if (lem->tab[lem->start->index][lem->end->index])
		return (1);
	else
		algo(lem, lem->start, 0, 0);
	return (lem->n_way ? lem->n_way : ft_error("Can't be solved", 0));
}
