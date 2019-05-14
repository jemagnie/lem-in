/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   avl.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jemagnie <jemagnie@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/21 15:35:41 by jemagnie     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/21 16:29:06 by jemagnie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		avl_index(t_room *node, char *name)
{
	int	cmp;

	cmp = ft_strcmp(name, node->name);
	if (cmp < 0)
	{
		if (node->LEFT)
			return (avl_index(node->LEFT, name));
		return (-1);
	}
	if (cmp > 0)
	{
		if (node->RIGHT)
			return (avl_index(node->RIGHT, name));
		return (-1);
	}
	return (node->index);
}

int		avl_height(t_room *node)
{
	int	left;
	int	right;

	left = 0;
	right = 0;
	if (node->LEFT)
		left = 1 + node->LEFT->depth;
	if (node->RIGHT)
		right = 1 + node->RIGHT->depth;
	return (right > left ? right : left);
}

int		avl_diff(t_room *node)
{
	int	diff;

	diff = 0;
	if (node->LEFT)
		diff += 1 + node->LEFT->depth;
	if (node->RIGHT)
		diff -= 1 + node->RIGHT->depth;
	return (diff);
}

int		avl_balance(t_room **node)
{
	int diff;

	diff = avl_diff(*node);
	if (diff >= 2)
	{
		if (avl_diff((*node)->LEFT) <= -1)
			*node = avl_rotate_leftright(*node);
		else
			*node = avl_rotate_leftleft(*node);
	}
	else if (diff <= -2)
	{
		if (avl_diff((*node)->RIGHT) >= 1)
			*node = avl_rotate_rightleft(*node);
		else
			*node = avl_rotate_rightright(*node);
	}
	return (1);
}

int		avl_insert(t_room **room, t_room *new)
{
	int	cmp;

	if (!(*room))
	{
		*room = new;
		return (1);
	}
	cmp = ft_strcmp(new->name, (*room)->name);
	if (cmp < 0)
	{
		if (!avl_insert(&(*room)->LEFT, new))
			return (0);
		(*room)->LEFT->depth = avl_height((*room)->LEFT);
		return (avl_balance(room));
	}
	if (cmp > 0)
	{
		if (!avl_insert(&(*room)->RIGHT, new))
			return (0);
		(*room)->RIGHT->depth = avl_height((*room)->RIGHT);
		return (avl_balance(room));
	}
	return (0);
}
