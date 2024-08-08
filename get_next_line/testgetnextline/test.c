#include "get_next_line.c"
#include "get_next_line_utils.c"
#include <stdio.h>
int main()
{
	char *name = "hello.txt";
	int fileisame = open(name, O_RDONLY);

	printf("hhii\n");
	printf("line1: %s\n", get_next_line(fileisame));
	printf("line2: %s\n", get_next_line(fileisame));
	printf("line3: %s\n", get_next_line(fileisame));
	printf("line4: %s\n", get_next_line(fileisame));
	printf("line5: %s\n", get_next_line(fileisame));
	printf("line6: %s\n", get_next_line(fileisame));
	printf("line7: %s\n", get_next_line(fileisame));
}