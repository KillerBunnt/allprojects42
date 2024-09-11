/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:01:40 by tdexmund          #+#    #+#             */
/*   Updated: 2024/06/26 18:11:27 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int				ft_atoi(const char *str);
void			ft_bzero(void *addr, unsigned int byte);
void			*ft_calloc(size_t count, size_t size);
int				ft_isalnum(char x);
int				ft_isalpha(int alph);
int				ft_isascii(int x);
int				ft_isdigit(int dig);
int				ft_isprint(int x);
char			*ft_itoa(int n);
void			*ft_memchr(void *addr, unsigned int find, unsigned int byte);
int				ft_memcmp(const void *str1, const void *str2, size_t byte);
void			*ft_memcpy(void *to, const void *from, unsigned int byte);
void			*ft_memmove(void *to, const void *from, size_t byte);
void			*ft_memset(void *addr, int fill, unsigned int byte);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strchr(char *str, unsigned int chr);
char			*ft_strdup(char *src);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strjoin(char const *s1, char const *s2);
unsigned int	ft_strlcat(char *dest, const char *src, size_t size);
int				ft_strlcpy(char *dest, const char *from, size_t size);
size_t			ft_strlen(const char *str);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *str1, const char *str2, size_t n);
char			*ft_strnstr(const char *str, const char *find, size_t max);
char			*ft_strrchr(const char *str, unsigned int chr);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_tolower(int x);
int				ft_toupper(int x);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

#endif
