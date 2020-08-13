#include "../includes/basics.h"

void	ft_bzero(char **buf, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		(*buf)[i] = '\0';
		i++;
	}
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_strclen(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*ft_strccpy(char *str, char c)
{
	int		i;
	int		len;
	char	*new;

	i = 0;
	len = ft_strclen(str, c);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (str[i] && str[i] != c)
	{
		new[i] = str[i];
		i++;
	}
	return (new);
}

int		ten_to(int n)
{
	int		ret;
	int		i;

	ret = 1;
	i = 0;
	while (i < n)
	{
		ret *= 10;
		i++;
	}
	return (ret);
}

int		ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		total;
	int		digits;

	i = 0;
	total = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	digits = ft_strlen(str) - (sign == -1 ? 1 : 0);
	while (str[i] <= '9' && str[i] >= '0')
	{
		total += (str[i] - 48) * ten_to(digits - 1);
		digits--;
		i++;
	}
	return (total * sign);
}

int		get_digits(int n)
{
	int		ret;

	ret = 0;
	while (n)
	{
		ret++;
		n = n / 10;
	}
	return (ret);
}