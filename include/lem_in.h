/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem_in.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jemagnie <jemagnie@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/21 16:11:24 by jemagnie     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/15 00:25:01 by jemagnie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

# define RIGHT		queue
# define LEFT		prev
# define IN_WAY		depth
# define USAGE		"Usage : ./lem-in < [map] or ./lem-in\n(Read in stdin)\n"

typedef struct		s_line
{
	char			*line;
	size_t			len;
	struct s_line	*next;
}					t_line;

typedef struct		s_room
{
	char			*name;
	int				index;
	t_pos			pos;
	int				n_link;
	int				depth;
	struct s_room	*queue;
	struct s_room	*prev;
	struct s_room	**link;
}					t_room;

typedef struct		s_way
{
	t_room			*room;
	int				ant;
	int				len;
}					t_way;

typedef struct		s_lem
{
	t_line			*line;
	char			*buff;
	int				n_buff;
	t_room			*avl;
	t_room			*room;
	t_room			*start;
	t_room			*end;
	t_way			**way;
	t_way			**tmp;
	int				**tab;
	long			*is_way;
	int				bin_way;
	int				n_room;
	int				n_ant;
	int				n_way;
	int				score;
	int				max;
	int				total;
	int				b_start;
	int				b_end;
}					t_lem;

int					parse_ant(t_lem *lem);
int					parse_room(t_lem *lem);
int					parse_link(t_lem *lem);
int					valid_room(const char *line);
int					valid_link(t_lem *lem, const char *line, int a, int b);

int					get_start(t_lem *lem);
int					get_end(t_lem *lem);
int					get_line(t_lem *lem, t_line **line, char *s);
int					get_link(t_lem *lem, int a, int b);
int					get_room(t_room **room, char *line, int index);

void				fill_tab(char **tab, t_room *room);
int					fill_link(t_lem *lem, t_room *room);
void				delete_avl(t_room **node);
int					create_mem(t_lem *lem, const char *line);

int					avl_height(t_room *node);
int					avl_diff(t_room *node);
int					avl_balance(t_room **node);
int					avl_index(t_room *node, char *name);
int					avl_insert(t_room **room, t_room *new_room);

t_room				*avl_rotate_leftleft(t_room *node);
t_room				*avl_rotate_leftright(t_room *node);
t_room				*avl_rotate_rightleft(t_room *node);
t_room				*avl_rotate_rightright(t_room *node);

int					solve(t_lem *lem);

void				reinitialize(t_lem *lem, t_room *room);
int					delete_parse(t_lem *lem);
void				delete_room(t_room **node);
void				delete_line(t_line *line);
int					delete_lem(t_lem *lem);

#endif
