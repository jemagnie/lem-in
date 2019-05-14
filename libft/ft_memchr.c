/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jemagnie <jemagnie@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 15:59:07 by jemagnie     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 17:13:47 by jemagnie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *mem, const unsigned char c, size_t n)
{
	unsigned long	mask;
	unsigned long	*magic;
	unsigned char	*cp;
	int				i;

	cp = (unsigned char *)mem;
	while ((n % 8) && n--)
		if (*cp++ == c)
			return ((void *)--cp);
	mask = ft_mask_char_to_long((int)c);
	magic = (unsigned long *)cp;
	n /= 8;
	while (n--)
	{
		if ((((*magic ^ mask) - 0x0101010101010101) & 0x8080808080808080))
		{
			i = 8;
			cp = (unsigned char *)magic;
			while (i--)
				if (*cp++ == c)
					return ((void *)--cp);
		}
		++magic;
	}
	return (NULL);
}
