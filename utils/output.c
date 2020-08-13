#include "../includes/basics.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	int		digits;
	int		sign;

	sign = 1;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
		sign = -1;
	}
	digits = get_digits(n) - (sign == -1 ? 1 : 0);
	while (n)
	{
		ft_putchar((n / ten_to(digits - 1)) + 48);
		n = n % ten_to(digits - 1);
		digits--;
	}
}