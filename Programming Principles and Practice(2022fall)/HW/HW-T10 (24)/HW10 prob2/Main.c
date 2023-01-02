#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int myargc = 1, i;
	char my_cmd_line[1000]; 
	char *myargv[20]={"fsize", NULL};
	char *token = NULL;

	chdir("/usr/lib/gcc/x86_64-linux-gnu/11");
	gets(my_cmd_line);
	
	token = strtok(my_cmd_line, " ");
	
	while (token) {
		myargv[myargc++] = token;
		token = strtok(NULL, " ");
	}

	return mymain(myargc, myargv);
}

int mymain(int argc, char *argv[]) {
	FILE *fd = fopen(argv[1], "r");

	if (fd == NULL)
		printf("Usage : fsize <file>");

	else {
		fseek(fd, 0, SEEK_END);
		long filesize = ftell(fd);
		fclose(fd);
		printf("File %s size : %d\n", argv[1], filesize);
	}
	
	
	return 0;
}