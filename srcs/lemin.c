/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lemin.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jemagnie <jemagnie@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/21 16:30:40 by jemagnie     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/15 00:15:43 by jemagnie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		print_line(t_lem *lem, t_line *line, int len)
{
	t_line	*tmp;
	char	*buff;

	if (!(lem->buff = malloc(sizeof(char) * len + 1)))
		return (0);
	buff = lem->buff;
	tmp = lem->line;
	while (line)
	{
		tmp = line->next;
		buff[--len] = '\n';
		ft_memcpy(&buff[len - line->len], line->line, line->len);
		len -= line->len;
		free(line->line);
		free(line);
		line = tmp;
	}
	lem->buff[lem->n_buff] = '\n';
	write(1, lem->buff, lem->n_buff + 1);
	lem->line = NULL;
	return (1);
}

void	print_ant(t_lem *lem, t_way **way, char b)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (++i <= lem->n_ant)
	{
		j = -1;
		while (++j < lem->n_way)
		{
			k = -1;
			while (++k < way[j][0].len)
				if (way[j][k].ant == i)
				{
					(b) ? write(1, " ", 1) : 0;
					b = 1;
					write(1, "L", 1);
					ft_putnbr(i);
					write(1, "-", 1);
					write(1, way[j][k].room->name,
						ft_strlen(way[j][k].room->name));
				}
		}
	}
	write(1, "\n", 1);
}

void	send_ant(t_lem *lem, t_way **way, int score)
{
	int		i;
	int		j;
	int		ant;

	ant = 0;
	if (lem->tab[lem->start->index][lem->end->index])
	{
		while (++ant <= lem->n_ant)
			ft_printf("L%d-%s%c", ant, lem->end->name,
				ant != lem->n_ant ? ' ' : '\n');
		return ;
	}
	while (++score != lem->score)
	{
		i = -1;
		while (++i < lem->n_way)
		{
			j = way[i][0].len - 1;
			while (--j >= 0)
				way[i][j + 1].ant = way[i][j].ant;
			way[i][0].ant = score + way[i][0].len <= lem->score ?
				++ant : 0;
		}
		print_ant(lem, way, 0);
	}
}

int		delete_lem(t_lem *lem)
{
	int		i;
	t_line	*line;

	i = -1;
	while (++i < lem->n_room)
	{
		if (lem->room[i].link)
			free(lem->room[i].link);
		if (lem->room[i].name)
			free(lem->room[i].name);
	}
	if (lem->line)
		delete_line(lem->line);
	if (lem->buff)
		free(lem->buff);
	if (lem->way)
		free(lem->way);
	if (lem->room)
		free(lem->room);
	ft_bzero(lem, sizeof(t_lem));
	return (0);
}

int		main(int ac, char **av)
{
	t_lem	*lem;

	if (ac > 1 || av[1])
	{
		ft_putstr_fd(USAGE, 2);
		return (0);
	}
	if (!(lem = ft_memalloc(sizeof(t_lem))))
		return (0);
	if (!parse_ant(lem) || !parse_room(lem))
	{
		delete_parse(lem);
		return (ft_free_zero(lem));
	}
	if (parse_link(lem))
		if (print_line(lem, lem->line, lem->n_buff))
		{
			lem->score = lem->n_room + lem->n_ant;
			lem->start = &lem->room[(int)lem->start];
			lem->end = &lem->room[(int)lem->end];
			if (solve(lem))
				send_ant(lem, lem->tmp, -1);
		}
	delete_lem(lem);
	return (ft_free_zero(lem));
}
