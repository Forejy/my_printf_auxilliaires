#include <unistd.h>
#include <stdlib.h>

typedef struct	s_hexa
{
	char	a[5];
	char	b[5];
	char	c[5];
	char	d[5];
	int		k;
}				t_hexa;

typedef struct	s_binary
{
	char	a[9];
	char	b[9];
	char	c[9];
	char	d[9];
	int		k;
}				t_binary;

int		numofpow2(int n)
{
	int		i;
	i = 0;
	while (n > 0)
	{
		i++;
		n = n/2;
	}
	return (i);
}

/*4/2 = 2 0
2/2 = 1 0
1/2 = 0 1

3/2 = 1 1
1/2 = 0 1*/

int		compute_minimum_number_of_bits(unsigned int n)
{
	int		pow2;
	int		k;

	pow2 = 1;
	k = 0;
	while (n >  pow2)
	{
		pow2 = 2 * pow2;
		k++;
	}
	return (k);
}

int	compute_minimum_number_of_bytes(int numb_of_bits)
{
	if (numb_of_bits <= 8)
		return (1);
	if (numb_of_bits <= 11)
		return (2);
	if (numb_of_bits <= 16)
		return (3);
	if (numb_of_bits <= 21)
		return (4);
	if (numb_of_bits <= 26)
		return (5);
	else// (numb_of_bits <= 31)
		return (6);

}


int		reverse(int hexa, int pow2)
{
	int		reverse;

	while (pow2 > 0)
	{
		reverse = reverse * 10 + (hexa % 10);
		hexa = hexa / 10;
		pow2--;
	}
}

/*00000001
10000000 ->rev 00000001

00000000*/


void	initialize_t_binary(t_binary *binary)
{
	binary->a[0] = '1';
	binary->a[1] = '1';
	binary->a[2] = '1';
	binary->a[3] = '1';
	binary->a[4] = '0';
	binary->a[5] = '0';
	binary->a[6] = '0';
	binary->a[7] = '0';
	binary->a[8] = '\0';

	binary->b[0] = '1';
	binary->b[1] = '0';
	binary->b[2] = '0';
	binary->b[3] = '0';
	binary->b[4] = '0';
	binary->b[5] = '0';
	binary->b[6] = '0';
	binary->b[7] = '0';
	binary->b[8] = '\0';

	binary->c[0] = '1';
	binary->c[1] = '0';
	binary->c[2] = '0';
	binary->c[3] = '0';
	binary->c[4] = '0';
	binary->c[5] = '0';
	binary->c[6] = '0';
	binary->c[7] = '0';
	binary->c[8] = '\0';

	binary->d[0] = '1';
	binary->d[1] = '0';
	binary->d[2] = '0';
	binary->d[3] = '0';
	binary->d[4] = '0';
	binary->d[5] = '0';
	binary->d[6] = '0';
	binary->d[7] = '0';
	binary->d[8] = '\0';
}

t_binary		*dec_to_binary(int n)
{
	int			pow2;
	int			number_of_bytes;
	t_binary	*binary;
	int			i;
	binary = malloc(sizeof(t_binary));

	initialize_t_binary(binary);
	pow2 = compute_minimum_number_of_bits(n);
	number_of_bytes = compute_minimum_number_of_bytes(pow2);

	i = 7;
	while (i >= 2)
	{
		binary->d[i] = (n % 2) + 48;
		n = n / 2;
		i--;
	}
	i = 7;
	while (i >= 2)
	{
		binary->c[i] = (n % 2) + 48;
		n = n / 2;
		i--;
	}
	i = 7;
	while (i >= 2)
	{
		binary->b[i] = (n % 2) + 48;
		n = n / 2;
		i--;
	}
	binary->c[8] = '\0';
	i = 7;
	while (i >= 5)
	{
		binary->a[i] = (n % 2) + 48;
		n = n / 2;
		i--;
	}
	return(binary);
}

t_hexa		*dec_to_hexa(int n)
{
	int			pow2;
	t_hexa	*t_hexa;
	int			i;
	t_hexa = malloc(sizeof(t_hexa));
	char		*hexa = "0123456789abcdef";

	t_hexa->a[0] = '0';
	t_hexa->a[1] = 'x';
	t_hexa->a[2] = '0';
	t_hexa->a[3] = '0';
	t_hexa->a[4] = '\0';

	t_hexa->b[0] = '0';
	t_hexa->b[1] = 'x';
	t_hexa->b[2] = '0';
	t_hexa->b[3] = '0';
	t_hexa->b[4] = '\0';

	t_hexa->c[0] = '0';
	t_hexa->c[1] = 'x';
	t_hexa->c[2] = '0';
	t_hexa->c[3] = '0';
	t_hexa->c[4] = '\0';

	t_hexa->d[0] = '0';
	t_hexa->d[1] = 'x';
	t_hexa->d[2] = '0';
	t_hexa->d[3] = '0';
	t_hexa->d[4] = '\0';

	i = 3;
	while (i >= 2)
	{
		t_hexa->a[i] = hexa[(n % 16)];
		n = n / 16;
		i--;
	}
	i = 3;
	while (i >= 2)
	{
		t_hexa->b[i] = hexa[(n % 16)];
		n = n / 16;
		i--;
	}
	i = 3;
	while (i >= 2)
	{
		t_hexa->c[i] = hexa[(n % 16)];
		n = n / 16;
		i--;
	}
	i = 3;
	while (i >= 2)
	{
		t_hexa->d[i] = hexa[(n % 16)];
		n = n / 16;
		i--;
	}
	return(hexa);
}


//Convertir la nombre en binaire format UTF8
//Reconvertir en int
//WRITE CETTE DAUBE D'UNICODE SUR 4 OCTETS


