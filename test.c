#include "ft_printf.h"

int main(){
    char *s = "123";
    char *s2 = "123456789";
    int i2 = 123456789;
    int i3 = 12345;
    int i4 = -123;
    int ui1 = 12345;
    char c1 = 'h';

    ft_printf(" start [%s] : [%10s] : [%.20d] [%c];\n", s, s, 10, 'h');
    printf(" start [%s] : [%10s] : [%.20d] [%c];\n", s, s, 10, 'h');

    ft_printf(" start [%3.5d] : [%10.3d] : [%.20%] [%4.5%];\n", 11, 12);
    printf(" start [%3.5d] : [%10.3d] : [%.20%] [%4.5%];\n", 11, 12);

    ft_printf(" start [%3.5c] : [%10.3c] : [%.20c] [%4.5c];\n", c1, c1, c1, c1);
    printf(" start [%3.5c] : [%10.3c] : [%.20c] [%4.5c];\n", c1, c1, c1, c1);

    ft_printf(" start [%d] : [%10.3d] : [%.20d] [%3.4s];\n", 1234567, 1234567, 1234567, "iamastring");
    printf(" start [%d] : [%10.3d] : [%.20d] [%3.4s];\n", 1234567, 1234567, 1234567, "iamastring");

    char *f = " start [%3.4s] [%4.3s] [%12.3s] [%12.12s] [%12.10s] [%12.14s] [%4.12s]\n";
    ft_printf(f, s2, s2, s2, s2, s2, s2,s2);
    printf(f, s2, s2, s2, s2, s2, s2,s2);

    char *f2 = " start [%3.4d] [%4.3d] [%12.3d] [%12.12d] [%12.10d] [%12.14d] [%4.12d]\n";
    ft_printf(f2, i2, i2, i2, i2, i2, i2,i2);
    printf(f2, i2, i2, i2, i2, i2, i2,i2);

    char *f3 = " start [%03.4s] [%04.3s] [%012.3s] [%012.12s] [%012.10s] [%012.14s] [%04.12s]\n";
    ft_printf(f3, s2, s2, s2, s2, s2, s2,s2);
    printf(f3, s2, s2, s2, s2, s2, s2,s2);

    char *f4 = " start [%03.4d] [%04.3d] [%012.3d] [%012.12d] [%012.10d] [%012.14d] [%04.12d]\n";
    ft_printf(f4, i2, i2, i2, i2, i2, i2,i2);
    printf(f4, i2, i2, i2, i2, i2, i2,i2);

    char *f5 = " start [%03.4%] [%04.3%] [%012.3%] [%012.12%] [%012.10%] [%012.14%] [%04.12%]\n";
    ft_printf(f5, i2, i2, i2, i2, i2, i2,i2);
    printf(f5, i2, i2, i2, i2, i2, i2,i2);

    char *f6 = " start [%3d] [%.3d] [%0.3d] [%12.d] [%0.12d] [%.14d] [%04.d]\n";
    ft_printf(f6, i2, i2, i2, i2, i2, i2,i2);
    printf(f6, i2, i2, i2, i2, i2, i2,i2);

    char *f7 = " start [%3.4u] [%4.3u] [%12.3u] [%12.12u] [%12.10u] [%12.14u] [%4.12u]\n";
    ft_printf(f7, ui1, ui1, ui1, ui1, ui1, ui1, ui1);
    printf(f7, ui1, ui1, ui1, ui1, ui1, ui1, ui1);

    char *f8 = " start [%x] [%3.4x] [%4.3x] [%12.3x] [%12.12x] [%12.10x] [%12.14x]\n";
    ft_printf(f8, i2, i2, i2, i2, i2, i2,i2);
    printf(f8, i2, i2, i2, i2, i2, i2,i2);

    char *f9 = " start [%X] [%3.4X] [%4.3X] [%12.3X] [%12.12X] [%12.10X] [%12.14X]\n";
    ft_printf(f9, i2, i2, i2, i2, i2, i2,i2);
    printf(f9, i2, i2, i2, i2, i2, i2,i2);

    char *f10 = " start [%p] [%3.4p] [%4.3p] [%12.3p] [%12.12p] [%12.10p] [%12.14p]\n";
    ft_printf(f10, s2, s2, s2, s2, s2, s2,s2);
    printf(f10, s2, s2, s2, s2, s2, s2,s2);

    ft_printf("[%-10.4s] [%-010.4s] [%0-10.4s] [%----10.4s]\n", s2, s2, s2, s2);
    printf("[%-10.4s] [%-010.4s] [%0-10.4s] [%----10.4s]\n", s2, s2, s2, s2);

    ft_printf("[%10.4s] [%010.4s] [%010.4s] [%10.4s]\n", s2, s2, s2, s2);
    printf("[%10.4s] [%010.4s] [%010.4s] [%10.4s]\n", s2, s2, s2, s2);

    ft_printf("[%-10.7d] [%-010.7d] [%0-10.7d] [%----10.7d] zero,minus\n", i3, i3, i3, i3);
    printf("[%-10.7d] [%-010.7d] [%0-10.7d] [%----10.7d] zero,minus\n", i3, i3, i3, i3);

    char *f11 = " start [%*s] [%*.s] [%*s] [%*s]\n";
    ft_printf(f11, 3, s2, 4, s2, 12, s2, 4, s2);
    printf(f11, 3, s2, 4, s2, 12, s2, 4, s2);

    char *f12 = " start [%3s] [%4.s] [%12s] [%4s]\n";
    ft_printf(f12, s2, s2, s2, s2);
    printf(f12, s2, s2, s2, s2);

    char *f13 = " start [%3s] [%3.s] [%3.0s] [%12s] [%12.s] [%12.0s]\n";
    ft_printf(f13, s2, s2, s2, s2, s2, s2);
    printf(f13, s2, s2, s2, s2, s2, s2);

    char *f14 = " start [%-01%] [%-01.%] [%-012%] [%-012.%] [%-1%] [%-1.%] [%-12%] [%-12.%]\n";
    ft_printf(f14);
    printf(f14);

    char *f15 = " start [%-1c] [%-1.c] [%-12c] [%-12.c] [%-1c] [%-1.c] [%-12c] [%-12.c]\n";
    ft_printf(f15, c1, c1, c1, c1, c1, c1, c1, c1);
    printf(f15, c1, c1, c1, c1, c1, c1, c1, c1);

    char *f16 = " start [%01%] [%01.%] [%012%] [%012.%] [%1%] [%1.%] [%12%] [%12.%]\n";
    ft_printf(f16);
    printf(f16);

    char *f17 = " start [%01c] [%01.c] [%012c] [%012.c] [%1c] [%1.c] [%12c] [%12.c]\n";
    ft_printf(f17, c1, c1, c1, c1, c1, c1, c1, c1);
    printf(f17, c1, c1, c1, c1, c1, c1, c1, c1);

    char *f18 = " start [%*s] [%*.s] [%*s] [%*s]\n";
    ft_printf(f18, 4, s2, 4, s2, 12, s2, 0, s2);
    printf(f18, 4, s2, 4, s2, 12, s2, 0, s2);

    char *f19 = " start [%4s] [%4.s] [%12s] [%0s]\n";
    ft_printf(f19, s2, s2, s2, s2);
    printf(f19, s2, s2, s2, s2);

    char *f20 = " start [%3.*s] [%4.*s] [%12.*s] [%12.*s] [%12.*s] [%12.*s] [%4.*s]\n";
    ft_printf(f20, 4,s2, 3,s2, 3,s2, 12,s2, 10,s2, 14,s2, 12,s2);
    printf(f20, 4,s2, 3,s2, 3,s2, 12,s2, 10,s2, 14,s2, 12,s2);

    char *f21 = " start [%3.*d] [%4.*d] [%12.*d] [%12.*d] [%12.*d] [%12.*d] [%4.*d]\n";
    ft_printf(f21, 4,i2, 3,i2, 3,i2, 12,i2, 10,i2, 14,i2, 12,i2);
    printf(f21, 4,i2, 3,i2, 3,i2, 12,i2, 10,i2, 14,i2, 12,i2);

    char *f22 = " start [%.s] [%.3s] [%3.s] [%3s] [%1.3s] [%0.3s]\n";
    ft_printf(f22, s2, s2, s2, s2, s2, s2);
    printf(f22, s2, s2, s2, s2, s2, s2);

    printf("f23\n");
    char *f23 = " start [%03i] [%03d] [%012i] [%012d] [%-03i] [%-03d] [%-012i] [%-012d]\n";
    ft_printf(f23, i2, i2, i2, i2, i2, i2, i2, i2, i2, i2);
    printf(f23, i2, i2, i2, i2, i2, i2, i2, i2, i2, i2);

    char *f24 = " start [%03i] [%03d] [%04.4i] [%04.4d] [%04.4d] [%-03i] [%-03d] [%-012i] [%-012d]\n";
    ft_printf(f24, i4, i4, i4, i4, i4, i4, i4, i4, i4, i4, i4);
    printf(f24, i4, i4, i4, i4, i4, i4, i4, i4, i4, i4, i4);

    char *f25 = " start [%0.3i] [%0.3d] [%0.12i] [%0.12d] [%-0.3i] [%-0.3d] [%-0.12i] [%-0.12d]\n";
    ft_printf(f25, i4, i4, i4, i4, i4, i4, i4, i4, i4, i4);
    printf(f25, i4, i4, i4, i4, i4, i4, i4, i4, i4, i4);

    char *f26 = " start [%04.4d] [%04d] [%04.d] [%0.4d]\n";
    ft_printf(f26, i4, i4, i4, i4);
    printf(f26, i4, i4, i4, i4);

    char *f27 = " start [%p] [%3.4p] [%4.3p] [%12.3p] [%12.12p] [%12.10p] [%12.14p]\n";
    ft_printf(f27, s2, s2, s2, s2, s2, s2,s2);
    printf(f27, s2, s2, s2, s2, s2, s2,s2);

    ft_printf(f27, s, s, s, s, s, s,s);
    printf(f27, s, s, s, s, s, s,s);

    ft_printf(" start [%c] aaaa\n", 0);
    printf(" start [%c] aaaa\n", 0);

    return (0);
}
