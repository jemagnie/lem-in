/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jemagnie <jemagnie@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 15:59:07 by jemagnie     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 17:59:25 by jemagnie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	long			l;
	unsigned char	*str;
	unsigned long	*lg;

	l = ft_mask_char_to_long(c);
	str = (unsigned char *)b;
	while ((len % 8) && len--)
		*str++ = (unsigned char)c;
	len /= 8;
	lg = (unsigned long *)str;
	while (len--)
		*lg++ = l;
	return (b);
}

void	*ft_memset_int(void *b, int c, size_t len)
{
	long			l;
	unsigned int	*tab;
	unsigned long	*lg;

	l = ft_mask_int_to_long(c);
	tab = (unsigned int *)b;
	while ((len % 4) && len--)
		*tab++ = (unsigned int)c;
	len /= 8;
	lg = (unsigned long *)tab;
	while (len--)
		*lg++ = l;
	return (b);
}
