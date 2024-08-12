#include "get_next_line.c"
#include "get_next_line_utils.c"
#include <stdio.h>
int main()
{
	char *name = "hello.txt";
	int fileisame = open(name, O_RDONLY);
	char *temp = NULL;
	int x = 0;
	printf("hhii\n");
	while (x++ < 6)
	{
		temp = get_next_line(fileisame);
		printf("line%d: %s\n",x, temp);
		free(temp);
	}
}