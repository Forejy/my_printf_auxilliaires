#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <stdint.h>
#include "../Includes/Functions.h"
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include "../Includes/Convert_base.h"




void	test_fonction_appel_va_list(int nb, va_list ap)
{
	int n = 0;
	n = va_arg(ap, int);
	printf("%d\n", n);
}

void suite_nombre(int nb, ...)
{
	va_list ap;

	va_start(ap, nb);
	va_arg(ap, int);
	test_fonction_appel_va_list(nb, ap);
	test_fonction_appel_va_list(nb, ap);
	va_end(ap);
}

int main()
{
	setlocale(LC_ALL, "");

	int i                = 1;
	unsigned char	x   = 255;
	long				lg = LONG_MAX;
	long long			llg = LLONG_MAX;
	ssize_t ss_t         = SSIZE_MAX;
	size_t s_t			 = SIZE_MAX;
	//suite_nombre(4, 1, 2, 3, 4);
	//printf("%zhd\n", -50);
//	printf("%lli \n", -9223372036854775807);
	printf("INT_MAX : %d\n", INT_MAX);
	printf("UINT_MAX : %u\n", UINT_MAX);
	printf("SHRT_MAX : %hd\n", SHRT_MAX);
	printf("USHRT_MAX :%hu\n", USHRT_MAX);
	printf("LONG_MAX : %ld\n", lg); // Si hld ou lhd le l surcharge le h
	printf("LLONG_MAX : %lld\n", llg);
	printf("LLONG_MIN : %lld\n", LLONG_MIN);
	printf("ULONG_MAX : %lu\n", ULONG_MAX);
	printf("ULLONG MAX : %llu\n", ULLONG_MAX);
	printf("SIZE_T MAX : %llu\n", s_t);
	printf("SSIZE_T_MAX : %llu\n", ss_t);
	printf("UNSIGNED CHAR MAX : %d\n", x);
	printf("HEXA : %x\n", 155);
	printf("INTMAX_T MAX : %jd\n", INTMAX_MAX);
	printf("INTMAX_T MIN : %jd\n", INTMAX_MIN);
	printf("UINTMAX_T MAX : %ju\n", UINTMAX_MAX);
	printf("Short : %zu\nLong : %zu\nLong Long : %zu\nUnsigned Long : %zu\nUnsigned Long Long : %zu\n",
		   sizeof(short), sizeof(long), 8, sizeof(unsigned long), sizeof(unsigned long long));
	printf("Unsigned char : %zu\n", sizeof(unsigned char));
	printf("Size_t : %zu\n", sizeof(size_t));
	printf("Ssize_t : %zd");

	long		neglg = -648;
	printf("%li\n", neglg);
	//printf("\nli\n", -5);
	//printf("|%-010.5d|\n", -12);
	//printf("%0100llu\n", 555555555555);
	//printf("%+010.4d\n", +12);
	//wint_t C = '®'; //Ne marche pas car on dit a l'ordinateur de loger un caractere de plusieurs octets sur un octet
//	wint_t C = L'ᴟ';
//	wint_t K = L'\xE1\xB4\x9F';
//	wchar_t *wchar = L"\xE1\xB4\x9F";
//	write(1, L"ᴟ", 15);
//	int D = 0b010101001;
//	printf("%d\n", C);
//	printf("%C\n", K);
//	printf("%s", "\xE2\x98\xA0");
	unsigned char a = 0xE1;
	printf("%d\n", a);

	unsigned char b = 0xB4;
	printf("%d\n", b);

	unsigned char l = 0x9F;
	printf("%d\n", l);

	unsigned char d = 0x0a;
	printf("%d\n", d);

	printf("Utilisation de write : \n");
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &l, 1);
	write(1, &d, 1);
	unsigned char c;
	c = 225;
	write(1, &c, 1);
	c = 180;
	write(1, &c, 1);
	c = 159;
	write(1, &c, 1);
	c = 10;
	write(1, &c, 1);

	printf("%d\n",  L'ᴟ');
	t_binary	*binary;
	binary = dec_to_binary(L'ᴟ');
	printf("%d\n", '10');

	/*int titi = 12592;
	while (titi > 0)
	{
		printf("%d\n", (titi % 16));
		titi = titi / 16;
	}*/
	//Resultat attendu :
	// 11110000
	// 10000000
	// 10000000
	// 10111001
//10000110 10111010
	printf("%s\n", binary->a);
	printf("%s\n", binary->b);
	printf("%s\n", binary->c);
	printf("%s\n", binary->d);

	printf("test affichage hexa avec un 0\n");
//	printf("%d\n", c);
	/*c = 0xe1;
	printf("%d\n", c);
	write(1, &c, 1);*/
	c = 0xe1;
	write(1, &c, 1);
	c = 0x88;
	write(1, &c, 1);
	c = 0xb4;
	write(1, &c, 1);
	c = 0x0a;
	write(1, &c, 1);

	//3 BITS SUR 3 BITS OK
	c = 0xe1;
	write(1, &c, 1);
	c = 0xb4	;
	write(1, &c, 1);
	c = 0x9f;
	write(1, &c, 1);
	c = 0x0a;
	write(1, &c, 1);

	//3 BITS SUR 4 BITS PAS OK
	c = 0xf0;
	write(1, &c, 1);
	c = 0x81;
	write(1, &c, 1);
	c = 0xb4	;
	write(1, &c, 1);
	c = 0x9f;
	write(1, &c, 1);
	c = 0x0a;
	write(1, &c, 1);

	printf("test putchar avec unicode : ");
	my_putchar(48);
	/*unsigned char lk = 255;
	write(1, &c, 1);

	printf("%d\n", L'ᴟ');

	//printf("Sizeof wint_t : %d, Caractere Unicode affiche : %C%S\n", sizeof(wint_t), C, wchar);*/
	return (0);



	/*
	 * Long et Long Long sur Unix ont la meme taille, et du coup le meme intervalle	 *
	 */
}