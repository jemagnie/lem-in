/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jemagnie <jemagnie@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/28 14:17:14 by jemagnie     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 17:24:09 by jemagnie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char	*long_chr(unsigned long *l, unsigned long mask, int c)
{
	unsigned long	lg;
	unsigned char	*s;

	while (1)
	{
		lg = *l;
		if (((lg - MASK_0X01L) & ~lg & MASK_0X80L) ||
				(((lg ^ mask) - MASK_0X01L) & MASK_0X80L))
		{
			s = (unsigned char *)l;
			while (*s != c)
				if (*s++ == '\0')
					return (NULL);
			return ((char *)s);
		}
		l++;
	}
}

char		*ft_strchr(const char *str, int c)
{
	unsigned long	mask;
	unsigned long	*l;
	unsigned char	*s;

	s = (unsigned char *)str;
	while ((unsigned long)s & 7)
	{
		if (*s == c)
			return ((char *)s);
		if (*s == '\0')
			return (NULL);
		s++;
	}
	l = (unsigned long *)s;
	mask = ft_mask_char_to_long(c);
	return (long_chr(l, mask, c));
}
