/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jemagnie <jemagnie@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/28 14:18:08 by jemagnie     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 01:57:05 by jemagnie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include <wchar.h>
# include <math.h>
# include <limits.h>
# include <time.h>
# include "keycode.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define ABS(value)	(value < 0 ? -value : value)
# define BASE(value) (value < 10 ? 48 : 55)
# define MASK_0X80L	0x8080808080808080L
# define MASK_0X01L 0x0101010101010101L
# define MASK_0X01	0x01010101L
# define MASK_0X80	0x80808080L

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset_int(void *b, int c, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
size_t				ft_strlen(const char *s);
void				*ft_memchr(const void *s, const unsigned char c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);

int					ft_atoi(const char *str);
int					ft_atoi_more(const char *str);
int					ft_atoi_ptr(char **str);
int					ft_atoi_more_ptr(char **str);

int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isspace(int c);
int					ft_isblank(int c);
int					ft_ishexa(int c);
int					ft_isbin(int c);
int					ft_isocta(int c);

int					ft_max(int a, int b);
int					ft_min(int a, int b);
void				ft_swap(int *a, int *b);
long				ft_mask_char_to_long(int c);
long				ft_mask_int_to_long(int c);
int					ft_int_abs(int n);

char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t n);

int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
		size_t len);

void				*ft_memalloc_char(size_t size, int c);
void				*ft_memalloc_int(size_t size, int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

char				*ft_strnew(size_t size);
char				*ft_strupper(char *s);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinint(char const *s, int n);
char				*ft_strjoinchar(char const *s, char c);
char				*ft_strtrim(char const *s);
char				*ft_strepur(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strwhile(const char *s, int (*f)(int));
size_t				ft_nbword(char const *s, char c);
size_t				ft_wordlen(char const *s, char c);

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putstr(const char *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_puthex(long n);
void				ft_putbits(long n, size_t type);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putendl(const char *s);
int					ft_error(const char *s, int n);

char				*ft_itoa(int n);
char				*ft_itoa_base(int n, int base);
int					ft_sqrt(int n);
int					ft_power(int nb, int power);
size_t				ft_intlen_base(int n, const int base);
int					ft_long_len(const long n);
int					ft_ulong_base_len(unsigned long n, const int base);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstadd_end(t_list **alst, t_list *new);
void				ft_lstprint(t_list *begin);
void				ft_del(void *mem, size_t n);
void				ft_doubletab_del(void **map, size_t n);
void				ft_memdelzero(void **mem, size_t n);

size_t				ft_wstrlen(wchar_t *s);
size_t				ft_nwstrlen(wchar_t *s, int n);
int					ft_putwstr(wchar_t *s);
int					ft_putnwstr(wchar_t *s, int n);
int					ft_putwchar(wchar_t c);
int					ft_wclen(wchar_t wc);

int					get_next_line(const int fd, char **line);
int					get_next_len(const int fd, char **line);
void				get_next_free(const int fd);
int					ft_free_zero(void *mem);

int					ft_printf(const char *restrict format, ...);

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

#endif
