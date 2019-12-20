#include "libftprintf.h"

int main()
 {
    printf("%d\n", ft_printf("%0.*u", -25, 0));
    printf("%d\n", printf("%0.*u", -25, 0));

    printf("|%u|\n", ft_printf("%0*.*u", -10, 5, 42));
    printf("|%u|\n\n", printf("%0*.*u", -10, 5, 42));

    printf("|%u|\n", ft_printf("%0*.*u", 10, -5, -42));
    printf("|%u|\n\n", printf("%0*.*u", 10, -5, -42));

    printf("|%u|\n", ft_printf("%0*.*u", 10, 5, -42));
    printf("|%u|\n\n", printf("%0*.*u", 10, 5, -42));

    printf("|%u|\n", ft_printf("%0*.*u", -10, -5, -55));
    printf("|%u|\n\n", printf("%0*.*u", -10, -5, -55));

    printf("|%u|\n", ft_printf("%0*.*u", -10, -5, 42));
    printf("|%u|\n\n", printf("%0*.*u", -10, -5, 42));

    printf("|%u|\n", ft_printf("%0*.*u", 10, -5, -42));
    printf("|%u|\n\n", printf("%0*.*u", 10, -5, -42));

printf("\n");

    printf("|%u|\n", ft_printf("%0*.*u", 10, 15, 42));
    printf("|%u|\n\n", printf("%0*.*u", 10, 15, 42));

    printf("|%u|\n", ft_printf("%0*.*u", -10, 15, 42));
    printf("|%u|\n\n", printf("%0*.*u", -10, 15, 42));

    printf("|%u|\n", ft_printf("%0*.*u", 10, -15, 42));
    printf("|%u|\n\n", printf("%0*.*u", 10, -15, 42));

    printf("|%u|\n", ft_printf("%0*.*u", 10, 15, -42));
    printf("|%u|\n\n", printf("%0*.*u", 10, 15, -42));

    printf("|%u|\n", ft_printf("%0*.*u", -10, -15, -42));
    printf("|%u|\n\n", printf("%0*.*u", -10, -15, -42));

    printf("|%u|\n", ft_printf("%0*.*u", -10, -15, 42));
    printf("|%u|\n\n", printf("%0*.*u", -10, -15, 42));

    printf("|%u|\n", ft_printf("%0*.*u", 10, -15, -42));
    printf("|%u|\n\n", printf("%0*.*u", 10, -15, -42));

printf("\n");
printf("\n");

    printf("|%u|\n", ft_printf("%*.*u", 10, 5, 42));
    printf("|%u|\n\n", printf("%*.*u", 10, 5, 42));

    printf("|%u|\n", ft_printf("%*.*u", -10, 5, 42));
    printf("|%u|\n\n", printf("%*.*u", -10, 5, 42));

    printf("|%u|\n", ft_printf("%*.*u", 10, -5, 42));
    printf("|%u|\n\n", printf("%*.*u", 10, -5, 42));





    printf("|%u|\n", ft_printf("%*.*u", 10, 5, -55));
    printf("|%u|\n\n", printf("%*.*u", 10, 5, -55));

    printf("|%u|\n", ft_printf("%10.5u", -55));
    printf("|%u|\n\n", printf("%10.5u", -55));





    printf("|%u|\n", ft_printf("%*.*u", -10, -5, -42));
    printf("|%u|\n\n", printf("%*.*u", -10, -5, -42));

    printf("|%u|\n", ft_printf("%*.*u", -10, -5, 42));
    printf("|%u|\n\n", printf("%*.*u", -10, -5, 42));

    printf("|%u|\n", ft_printf("%*.*u", 10, -5, -42));
    printf("|%u|\n\n", printf("%*.*u", 10, -5, -42));

printf("\n");
printf("\n");

    printf("|%u|\n", ft_printf("%*.*u", 10, 15, 42));
    printf("|%u|\n\n", printf("%*.*u", 10, 15, 42));

    printf("|%u|\n", ft_printf("%*.*u", -10, 15, 42));
    printf("|%u|\n\n", printf("%*.*u", -10, 15, 42));

    printf("|%u|\n", ft_printf("%*.*u", 10, -15, 42));
    printf("|%u|\n\n", printf("%*.*u", 10, -15, 42));





    printf("|%u|\n", ft_printf("%*.*u", 10, 15, -55));
    printf("|%u|\n\n", printf("%*.*u", 10, 15, -55));

  	printf("|%u|\n", ft_printf("%10.15u", -55));
    printf("|%u|\n\n", printf("%10.15u", -55));





    printf("|%u|\n", ft_printf("%*.*u", -10, -15, -42));
    printf("|%u|\n\n", printf("%*.*u", -10, -15, -42));

    printf("|%u|\n", ft_printf("%*.*u", -10, -15, 42));
    printf("|%u|\n\n", printf("%*.*u", -10, -15, 42));

    printf("|%u|\n", ft_printf("%*.*u", 10, -15, -42));
    printf("|%u|\n\n", printf("%*.*u", 10, -15, -42));


    return (0);
}
