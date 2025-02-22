/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:29:01 by mhurtamo          #+#    #+#             */
/*   Updated: 2024/11/06 16:31:18 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>


typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	ft_putchar_fd(char c, int fd);

int		ft_toupper(int n);

int		ft_tolower(int n);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_strrchr(char const *str, int c);

char	*ft_strnstr(char *str, char *substr, size_t n);

int		ft_strncmp(const char *s1, char const *s2, size_t n);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

size_t	ft_strlen(char const *str);

size_t	ft_strlcpy(char *dst, char const *src, size_t size);

size_t	ft_strlcat(char *dest, char const *src, size_t size);

char	*ft_strjoin(char const *s1, char const *s2);

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

char	*ft_strdup(char const *str);

char	*ft_strchr(char const *str, int c);

char	**ft_split(char const *str, char c);

void	ft_putstr_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

void	ft_putstr_fd(char *s, int fd);

void	ft_putchar_fd(char c, int fd);

void	*ft_memset(void *str, int c, size_t size);

int		ft_memcmp(const void *str1, const void *str2, size_t n);

void	*ft_memchr(const void *str, int c, size_t n);

char	*ft_itoa(int n);

int		ft_isprint(int n);

int		ft_isdigit(int n);

int		ft_isascii(int n);

int		ft_isalpha(int c);

int		ft_isalnum(int c);

void	*ft_calloc(size_t nitems, size_t size);

void	ft_bzero(void *buffer, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n);

int		ft_atoi(char const *str);

void	ft_putendl_fd(char *s, int fd);

t_list	*ft_lstnew(void *content);

void	ft_lstadd_front(t_list **lst, t_list *n);

int		ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *n);

void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *));

void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
