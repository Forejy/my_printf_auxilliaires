#include "../../Includes/Functions.h"

void	my_put_octal_uint(unsigned int nbr)
{
	if (nbr >= 8)
	{
		my_put_octal_uint(nbr / 8);
		my_putchar((char) ((nbr % 8) + '0'));
	}
	if (nbr <= 7)
	{
		my_putchar((char) ((nbr % 8) + '0'));
	}
}

void	my_put_octal_ulong(unsigned long nbr)
{
	if (nbr >= 8)
	{
		my_put_octal_ulong(nbr / 8);
		my_putchar((char) ((nbr % 8) + '0'));
	}
	if (nbr <= 7)
	{
		my_putchar((char) ((nbr % 8) + '0'));
	}
}