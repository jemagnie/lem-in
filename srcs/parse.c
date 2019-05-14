/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jemagnie <jemagnie@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/21 15:30:55 by jemagnie     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 16:03:12 by jemagnie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		valid_link(t_lem *lem, const char *line, int a, int b)
{
	char	*one;
	char	*two;
	int		i;

	i = 0;
	while (line[i] && line[i] != '-')
		++i;
	if (!line[i])
		return (0);
	one = ft_strndup(line, i);
	two = ft_strdup(line + i + 1);
	if (!(ft_strcmp(one, two)))
		return (0);
	a = avl_index(lem->avl, one);
	b = avl_index(lem->avl, two);
	free(one);
	free(two);
	return (get_link(lem, a, b));
}

int		valid_room(const char *line)
{
	int		i;

	if (!*line || *line == 'L' || *line == ' ' || *line == '#')
		return (0);
	i = -1;
	while (line[++i] && line[i] != ' ')
		if (line[i] < 33 || line[i] > 126 || line[i] == 45)
			return (0);
	if (!(ft_isdigit(line[i + 1])))
		return (0);
	while (line[++i] && line[i] != ' ')
		if (!(ft_isdigit(line[i])))
			return (0);
	if (!(ft_isdigit(line[i + 1])))
		return (0);
	while (line[++i])
		if (!(ft_isdigit(line[i])))
			return (0);
	return (1);
}

int		parse_link(t_lem *lem)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (ft_strcmp("", line) == 0)
			break ;
		if (!get_line(lem, &(lem->line), line))
		{
			free(line);
			return (0);
		}
		if (*line == '#')
			;
		else if (!(valid_link(lem, line, -1, -1)))
			return (ft_error("Invalid link", 0));
	}
	free(line);
	if (fill_link(lem, lem->room - lem->room->index))
		return (1);
	return (0);
}

int		parse_room(t_lem *lem)
{
	char	*line;

	while (get_next_line(0, &line) && get_line(lem, &(lem->line), line))
	{
		if (!ft_strcmp(line, "##start"))
		{
			if (!get_start(lem))
				return (0);
		}
		else if (!ft_strcmp(line, "##end"))
		{
			if (!get_end(lem))
				return (0);
		}
		else if (valid_room(line))
		{
			if (!get_room(&(lem->room), line, lem->n_room))
				return (ft_error("Invalid room", 0));
			++(lem->n_room);
		}
		else if (*line != '#')
			return (create_mem(lem, line) || ft_error("Invalid room", 0));
	}
	ft_error("Where are the links ? Stupid !", 0);
	return (ft_free_zero(line));
}

int		parse_ant(t_lem *lem)
{
	char	*line;
	int		i;

	if (get_next_line(0, &line))
	{
		i = -1;
		while (line[++i])
			if (!ft_isdigit(line[i]))
			{
				free(line);
				return (ft_error("Invalid number of ants", 0));
			}
		lem->n_ant = ft_atoi(line);
		if (!lem->n_ant || lem->n_ant > 100000)
		{
			free(line);
			return (ft_error("Invalid number of ants", 0));
		}
		if (!get_line(lem, &(lem->line), line))
			return (ft_free_zero(line));
		return (1);
	}
	free(line);
	return (ft_error("Nothing to read", 0));
}
