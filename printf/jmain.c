#include "libftprintf.h"

int ft_printf(const char *ptr, ...);

int main()
{
	printf("1 %02u\n", 100);
	printf("2 %03u\n", 100);
	printf("3 a%03u\na", 100);
	printf("4 %04u\n", 100);
	printf("5 %02u\n", -100);
	printf("6 %03u\n", -100);
	printf("7 %05u\n", -100);
	printf("8 %04u\n", 0);
	printf("9 %01u\n", 0);
	printf("10 a%01ua\n", 0);
	printf("11 %2.3u\n", 100);
	printf("12 %3.3u\n", 100);
	printf("13 a%3.3ua\n", 100);
	printf("14 %4.3u\n", 100);
	printf("15 %2.3u\n", -100);
	printf("16 %3.3u\n", -100);
	printf("17 %4.3u\n", -100);
	printf("18 %4.3u\n", 0);
	printf("19.1 %1.3u\n", 0);
	printf("19 a%1.3ua\n", 0);
	printf("20 %2.0u\n", 100);
	printf("21 %3.0u\n", 100);
	printf("22 a%3.0ua\n", 100);
	printf("23 %4.0u\n", 100);
	printf("24 %2.0u\n", -100);
	printf("25 %3.0u\n", -100);
	printf("26 %4.0u\n", -100);
	printf("27 %4.0u\n", 0);
	printf("28 %1.0u\n", 0);
	printf("29 %4.u\n", 100);
	printf("30 %2.u\n", -100);
	printf("31 %3.u\n", -100);
	printf("32 %4.u\n", -100);
	printf("33 %4.u\n", 0);
	printf("34 %1.u\n", 0);
	printf("35 a%1.0ua\n", 0);
	printf("36 %2.7u\n", 100);
	printf("37 %15.7u\n", 100);
	printf("38 a%3.7ua\n", 100);
	printf("39 %4.7u\n", 100);
	printf("40 %2.7u\n", -100);
	printf("41 %3.7u\n", -100);
	printf("42 %15.7u\n", -100);
	printf("43 %4.7u\n", 0);
	printf("44 %1.7u\n", 0);
	printf("45 a%1.7ua\n", 0);
	printf("46 %3u\n", 100);
	printf("47 a%3ua\n", 100);
	printf("48 %4u\n", 100);
	printf("49 %2u\n", -100);
	printf("50 %3u\n", -100);
	printf("51 %4u\n", -100);
	printf("52 %4u\n", 0);
	printf("53 %1u\n", 0);
	printf("54 a%1ua\n", 0);
	printf("55 %-2u\n", 100);
	printf("56 %-3u\n", 100);
	printf("57 a%-3ua\n", 100);
	printf("58%-4u\n", 100);
	printf("59 %-2u\n", -100);
	printf("60 %-3u\n", -100);
	printf("61 %-4u\n", -100);
	printf("62 %-4u\n", 0);
	printf("63 %-1u\n", 0);
	printf("64 a%-1ua\n", 0);
	printf("65 %.3u\n", 100);
	printf("66 %.3u\n", 100);
	printf("67 a%.3ua\n", 100);
	printf("68 %.3u\n", 100);
	printf("69 %.3u\n", -100);
	printf("70 %.3u\n", -100);
	printf("71 %.3u\n", -100);
	printf("72 %.3u\n", 0);
	printf("73 %.3u\n", 0);
	printf("74 a%.3ua\n", 0);
	printf("75 %.0u\n", 100);
	printf("75 %.0u\n", 100);
	printf("76 a%.0ua\n", 100);
	printf("77 %.0u\n", 100);
	printf("78 %.0u\n", -100);
	printf("79 %.0u\n", -100);
	printf("80%.0u\n", -100);
	printf("81 %.0u\n", 0);
	printf("82 %.0u\n", 0);
	printf("83 %.u\n", 100);
	printf("84 %.u\n", -100);
	printf("85 %.u\n", -100);
	printf("86 %.u\n", -100);
	printf("87 %.u\n", 0);
	printf("88 %.u\n", 0);
	printf("89 a%.0ua\n", 0);
	printf("90 %.7u\n", 100);
	printf("91 %5.7u\n", 100);
	printf("92 a%.7ua\n", 100);
	printf("93 %.7u\n", 100);
	printf("94 %.7u\n", -100);
	printf("95 %.7u\n", -100);
	printf("96 %5.7u\n", -100);
	printf("97 %.7u\n", 0);
	printf("98 %.7u\n", 0);
	printf("99a%.7ua\n\n", 0);
	printf("------------------------------------------\n");
	ft_printf("1 %02u\n", 100);
	ft_printf("2 %03u\n", 100);
	ft_printf("3 a%03u\na", 100);
	ft_printf("4 %04u\n", 100);
	ft_printf("5 %02u\n", -100);
	ft_printf("6 %03u\n", -100);
	ft_printf("7 %05u\n", -100);
	ft_printf("8 %04u\n", 0);
	ft_printf("9 %01u\n", 0);
	ft_printf("10 a%01ua\n", 0);
	ft_printf("11 %2.3u\n", 100);
	ft_printf("12 %3.3u\n", 100);
	ft_printf("13 a%3.3ua\n", 100);
	ft_printf("14 %4.3u\n", 100);
	ft_printf("15 %2.3u\n", -100);
	ft_printf("16 %3.3u\n", -100);
	ft_printf("17 %4.3u\n", -100);
	ft_printf("18 %4.3u\n", 0);
	ft_printf("19.1 %1.3u\n", 0);
	ft_printf("19 a%1.3ua\n", 0);
	ft_printf("20 %2.0u\n", 100);
	ft_printf("21 %3.0u\n", 100);
	ft_printf("22 a%3.0ua\n", 100);
	ft_printf("23 %4.0u\n", 100);
	ft_printf("24 %2.0u\n", -100);
	ft_printf("25 %3.0u\n", -100);
	ft_printf("26 %4.0u\n", -100);
	ft_printf("27 %4.0u\n", 0);
	ft_printf("28 %1.0u\n", 0);
	ft_printf("29 %4.u\n", 100);
	ft_printf("30 %2.u\n", -100);
	ft_printf("31 %3.u\n", -100);
	ft_printf("32 %4.u\n", -100);
	ft_printf("33 %4.u\n", 0);
	ft_printf("34 %1.u\n", 0);
	ft_printf("35 a%1.0ua\n", 0);
	ft_printf("36 %2.7u\n", 100);
	ft_printf("37 %15.7u\n", 100);
	ft_printf("38 a%3.7ua\n", 100);
	ft_printf("39 %4.7u\n", 100);
	ft_printf("40 %2.7u\n", -100);
	ft_printf("41 %3.7u\n", -100);
	ft_printf("42 %15.7u\n", -100);
	ft_printf("43 %4.7u\n", 0);
	ft_printf("44 %1.7u\n", 0);
	ft_printf("45 a%1.7ua\n", 0);
	ft_printf("46 %3u\n", 100);
	ft_printf("47 a%3ua\n", 100);
	ft_printf("48 %4u\n", 100);
	ft_printf("49 %2u\n", -100);
	ft_printf("50 %3u\n", -100);
	ft_printf("51 %4u\n", -100);
	ft_printf("52 %4u\n", 0);
	ft_printf("53 %1u\n", 0);
	ft_printf("54 a%1ua\n", 0);
	ft_printf("55 %-2u\n", 100);
	ft_printf("56 %-3u\n", 100);
	ft_printf("57 a%-3ua\n", 100);
	ft_printf("58%-4u\n", 100);
	ft_printf("59 %-2u\n", -100);
	ft_printf("60 %-3u\n", -100);
	ft_printf("61 %-4u\n", -100);
	ft_printf("62 %-4u\n", 0);
	ft_printf("63 %-1u\n", 0);
	ft_printf("64 a%-1ua\n", 0);
	ft_printf("65 %.3u\n", 100);
	ft_printf("66 %.3u\n", 100);
	ft_printf("67 a%.3ua\n", 100);
	ft_printf("68 %.3u\n", 100);
	ft_printf("69 %.3u\n", -100);
	ft_printf("70 %.3u\n", -100);
	ft_printf("71 %.3u\n", -100);
	ft_printf("72 %.3u\n", 0);
	ft_printf("73 %.3u\n", 0);
	ft_printf("74 a%.3ua\n", 0);
	ft_printf("75 %.0u\n", 100);
	ft_printf("75 %.0u\n", 100);
	ft_printf("76 a%.0ua\n", 100);
	ft_printf("77 %.0u\n", 100);
	ft_printf("78 %.0u\n", -100);
	ft_printf("79 %.0u\n", -100);
	ft_printf("80%.0u\n", -100);
	ft_printf("81 %.0u\n", 0);
	ft_printf("82 %.0u\n", 0);
	ft_printf("83 %.u\n", 100);
	ft_printf("84 %.u\n", -100);
	ft_printf("85 %.u\n", -100);
	ft_printf("86 %.u\n", -100);
	ft_printf("87 %.u\n", 0);
	ft_printf("88 %.u\n", 0);
	ft_printf("89 a%.0ua\n", 0);
	ft_printf("90 %.7u\n", 100);
	ft_printf("91 %5.7u\n", 100);
	ft_printf("92 a%.7ua\n", 100);
	ft_printf("93 %.7u\n", 100);
	ft_printf("94 %.7u\n", -100);
	ft_printf("95 %.7u\n", -100);
	ft_printf("96 %5.7u\n", -100);
	ft_printf("97 %.7u\n", 0);
	ft_printf("98 %.7u\n", 0);
	ft_printf("99a%.7ua\n", 0);
	return (0);
}
