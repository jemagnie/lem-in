/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoinchar.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jemagnie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 15:59:11 by jemagnie     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 16:04:07 by jemagnie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinchar(char const *s, char c)
{
	char	*s2;

	s2 = ft_strnew(1);
	s2[0] = c;
	return (ft_strjoin(s, s2));
}
