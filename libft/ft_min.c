/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_min.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jemagnie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/30 19:30:19 by jemagnie     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/30 19:33:13 by jemagnie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_min(int a, int b)
{
	return (b ^ ((a ^ b) & -(a < b)));
}
