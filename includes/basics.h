#ifndef BASICS_H
# define BASICS_H
# include <unistd.h>
# include <stdlib.h>

void	ft_bzero(char **buf, int n);
int		ft_strlen(char *str);
int		ft_strclen(char *str, char c);
char	*ft_strccpy(char *str, char c);
int		ft_atoi(char *str);
int		get_digits(int n);
void	ft_putchar(char c);
void	ft_putnbr(int n);
int		ten_to(int n);

#endif