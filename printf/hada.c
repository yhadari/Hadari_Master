#include "libftprintf.h"

int ft_printf(const char *ptr, ...);

int main()
{
	int i;
	int j;
	unsigned int a;

	a = 4294967295;
/*
	i = ft_printf("s1 %.5u", 10);
	printf("%s", "XX\n");
	printf("i is %d\n", i);
	j = printf("s1 %.5u", 10);
	printf("%s", "XX\n");
	printf("j is %d\n", j);
	*/printf("-------------------------------------------------\n");
	i = ft_printf("s2 %*.10d", 15, -50);
	printf("%s", "XX\n");
	printf("i is %d\n", i);
	j = printf("s2 %*.10d", 15, -50);
	printf("%s", "XX\n");
	printf("j is %d\n", j);
	return (0);
}
