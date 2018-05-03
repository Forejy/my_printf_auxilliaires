#ifndef TEST_CONVERT_BASE_C_H
#define TEST_CONVERT_BASE_C_H

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

t_binary		*dec_to_binary(int n);
t_hexa		*dec_to_hexa(int n);


#endif //TEST_CONVERT_BASE_C_H
