/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mask.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jemagnie <jemagnie@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/19 14:27:24 by jemagnie     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 17:13:32 by jemagnie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

long	ft_mask_char_to_long(int c)
{
	long	l;

	l = c & 0xff;
	l |= (l << 8);
	l |= (l << 16);
	l |= (l << 16) << 16;
	return (l);
}

long	ft_mask_int_to_long(int c)
{
	long	l;

	l = c & 0xffffffff;
	l |= (l << 32);
	return (l);
}
