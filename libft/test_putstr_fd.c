#include "libft.h"
#include<fcntl.h>

/*
 gcc ft_putstr_fd.c test_putstr_fd.c ft_strlen.c
 * */
int main(){
	ft_putstr_fd("gogehoge", 1);

	int fd1 = open("./test.txt", O_RDWR | O_CREAT);
	if (fd1 == -1)
		ft_putstr_fd("open failed", 1);
	ft_putstr_fd("man second hoge", fd1);
	close(fd1);
}
