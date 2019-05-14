/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jemagnie <jemagnie@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 15:59:07 by jemagnie     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 18:17:55 by jemagnie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new;

	if (!(new = malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(new, size);
	return (new);
}

void	*ft_memalloc_int(size_t size, int c)
{
	void	*new;

	if (!(new = malloc(sizeof(void) * size)))
		return (NULL);
	ft_memset_int(new, c, size);
	return (new);
}

void	*ft_memalloc_char(size_t size, int c)
{
	void	*new;

	if (!(new = malloc(sizeof(void) * size)))
		return (NULL);
	ft_memset(new, c, size);
	return (new);
}
