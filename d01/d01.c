#include "../includes/input.h"
#include "../includes/basics.h"
#include <stdio.h>

int		calc_fuel(int n)
{
	return (n / 3 - 2);
}

int		main(void)
{
	char	**input;
	int		i;
	int		total;

	i = 0;
	total = 0; 
	input = get_input("d01/input");
	while (input[i])
	{
		total += calc_fuel(ft_atoi(input[i]));
		i++;
	}
	ft_putnbr(total);
	ft_putchar('\n');
	return (0);
}