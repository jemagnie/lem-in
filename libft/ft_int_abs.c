/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_int_abs.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jemagnie <jemagnie@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/21 15:09:48 by jmagnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 18:18:53 by jemagnie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_int_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}