#include<stdio.h> 
#include<fcntl.h> 
#include<errno.h> 
#include <stdlib.h>
#include "get_next_line.h"

int main()
{
    int fd = open("foo.txt", O_RDONLY);
    char *c;
    c = get_next_line(fd);
	
    printf("c = %s", c);
    free(c);
    c = get_next_line(fd);
    printf("c = %s", c);
    free(c);
    c = get_next_line(fd);
    printf("c = %s", c);
    free(c);
    c = get_next_line(fd);
    printf("c = %s", c);
    free(c);
    return 0;
}