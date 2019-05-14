/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rotate.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jemagnie <jemagnie@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/21 15:34:48 by jemagnie     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/21 16:28:56 by jemagnie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_room		*avl_rotate_leftleft(t_room *node)
{
	t_room	*a;
	t_room	*b;

	a = node;
	b = a->LEFT;
	a->LEFT = b->RIGHT;
	b->RIGHT = a;
	a->depth = avl_height(a);
	b->depth = avl_height(b);
	return (b);
}

t_room		*avl_rotate_leftright(t_room *node)
{
	t_room	*a;
	t_room	*b;
	t_room	*c;

	a = node;
	b = a->LEFT;
	c = b->RIGHT;
	a->LEFT = c->RIGHT;
	b->RIGHT = c->LEFT;
	c->LEFT = b;
	c->RIGHT = a;
	a->depth = avl_height(a);
	b->depth = avl_height(b);
	c->depth = avl_height(c);
	return (c);
}

t_room		*avl_rotate_rightleft(t_room *node)
{
	t_room	*a;
	t_room	*b;
	t_room	*c;

	a = node;
	b = a->RIGHT;
	c = b->LEFT;
	a->RIGHT = c->LEFT;
	b->LEFT = c->RIGHT;
	c->RIGHT = b;
	c->LEFT = a;
	a->depth = avl_height(a);
	b->depth = avl_height(b);
	c->depth = avl_height(c);
	return (c);
}

t_room		*avl_rotate_rightright(t_room *node)
{
	t_room	*a;
	t_room	*b;

	a = node;
	b = a->RIGHT;
	a->RIGHT = b->LEFT;
	b->LEFT = a;
	a->depth = avl_height(a);
	b->depth = avl_height(b);
	return (b);
}
