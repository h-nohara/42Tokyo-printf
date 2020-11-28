#include <stdio.h>

/* gcc test_split.c ft_split.c ft_substr.c ft_strdup.c */
char	**ft_split(char *s, char c);

void test(char *s, char c)
{
	char **box;

	printf("[%s] [%c]\n", s, c);
	box = ft_split(s, c);
	printf("done ft_split\n");
	while (*box != NULL)
		printf("[%s] ", *box++);
	printf("\n\n");
}

int main(void)
{
	char a1[] = "xxabcdxxxabcxxabcde";
	char a2[] = "abcdxxxabcxxabcdexx";
	char a3[] = "xabcdxxxabcxxabcdex";
	char a4[] = "abcdabcabc";
	char x = 'x';

	char b1[] = "    ";
	char nul = '\0';

	char nulstart[] = "\0aaaa";

	test(a1,x);
	test(a2,x);
	test(a3,x);
	test(a4,x);

	printf("=================\n");
	test(b1, ' ');
	test(b1, nul);

	printf("=================\n");
	test(&nul, '\0');
	test(nulstart, '\0');
}
