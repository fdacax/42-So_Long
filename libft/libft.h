/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:59:39 by fdacax-m          #+#    #+#             */
/*   Updated: 2023/10/26 22:23:09 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/* ************************************************************************** */
/*                               Libft                                        */
/* ************************************************************************** */

int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(const char *nptr);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_itoa(int n);
char				*ft_strdup(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_split(char const *s, char c);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strtrim(char const *s1, char const *set);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strstr(const char *str, const char *to_find);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/* ************************************************************************** */
/*                               Prinft                                       */
/* ************************************************************************** */

int					ft_printf(const char *format, ...);
void				ft_putstr(char *str, int *i);
void				ft_putnbr(int nb, int *i);
void				ft_putchar(char c, int *i);
void				ft_formu(unsigned int nb, int *i);
void				ft_choose(char format, int nb, int *i);
void				ft_check_format(char format, va_list arg, int *i);
void				ft_put_hex(char format, unsigned int nb, int *i);
void				ft_put_pointer(unsigned long nb, int *i);

/* ************************************************************************** */
/*                               GNL                                          */
/* ************************************************************************** */

char				*get_next_line(int fd);
char				*ft_get_file(char *ptr, int fd);
char				*ft_extracted_line(char *ptr);
char				*ft_remaining(char *ptr);
char				*ft_strcpy(char *src, char *dest, int flag);
char				*ft_strjoin_gnl(char *str1, char *str2);
int					ft_check_character(char *str, int c);
char				*ft_strcpy_nl(char *src, char *dest, int nl_stop);
size_t				ft_strlen_gnl(const char *str);

int					ft_charcmp(char *str, int c);
int					ft_strcmp(char *s1, char *s2);

#endif