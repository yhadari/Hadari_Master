#include "libftprintf.h"

int ft_printf(const char *ptr, ...);

int main()
{
	int i;
	int j;

	i = 0;
	j = 0;
	i = printf("number is |%5%|\n");
	printf("%d\n", i);
	j = ft_printf("number is |%5%|\n");
	printf("%d\n", j);
	printf("------------------------------------------\n");
	return (0);
}
