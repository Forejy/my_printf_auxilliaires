#include <unistd.h>
#include <wchar.h>

size_t		my_strlen(char *str)
{
	size_t		i;

	i = 3;
	while (1)
	{
		if (str[i - 3] == '\0')
			return (i - 3);
		else if (str[i - 2] == '\0')
			return (i - 2);
		else if (str[i - 1] == '\0')
			return (i - 1);
		else if (str[i] == '\0')
			return (i);
		i += 4;
	}
}

void		my_putchar(int c)
{
	write(1, &c, 1);
}

void		my_putstr(char *str)
{
	write(1, str, my_strlen(str));
}

size_t		myslow_strlen(char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
