#include <stdio.h>

void test_one(char *s)
{
	printf("\"%s\"\n", s);
	printf("ft_atoi: %d\n", ft_atoi(s));
	printf("atoi   : %d\n\n", atoi(s));
}

int main (void)
{
	test_one("123456");
	test_one("12Three45678");
	test_one("Hello World!");
	test_one("+42 BLAH!");
	test_one("-42");
	test_one("-+42");
	test_one("+-42");
	test_one("++--42 ");
	test_one("     +42");
	test_one("\t\n\v\f\r 42");
}
