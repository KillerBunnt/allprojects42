#include "get_next_line_bonus.c"
#include "get_next_line_utils_bonus.c"
#include <stdio.h>
int main()
{
	char *name[3] = {"hello.txt","goodbye.txt","fuckyou.txt"};
	int fileisame[3] = {open(name[0], O_RDONLY),open(name[1], O_RDONLY),open(name[2], O_RDONLY)};
	char *temp = NULL;
	int x = 0;
	int y = 0;
	printf("hhii\n");
	// while (y < 2)
	// {
	// 	printf("now printing %s:\n",name[y]);
	// 	while (x++ < 6)
	// 	{
	// 		temp = get_next_line(fileisame[y]);
	// 		printf("line%d: %s|\n",x, temp);
	// 		free(temp);
	// 	}
	// 	x =0;
	// 	y++;
	// }
	temp = get_next_line(fileisame[0]);
	printf("line1: %s|\n", temp);
	free(temp);
	temp = get_next_line(fileisame[1]);
	printf("line2: %s|\n", temp);
	free(temp);
	temp = get_next_line(fileisame[2]);
	printf("line3: %s|\n", temp);
	free(temp);
	temp = get_next_line(fileisame[0]);
	printf("line4: %s|\n", temp);
	free(temp);
	temp = get_next_line(fileisame[1]);
	printf("line5: %s|\n", temp);
	free(temp);
	temp = get_next_line(fileisame[2]);
	printf("line6: %s|\n", temp);
	free(temp);
	temp = get_next_line(fileisame[0]);
	printf("line7: %s|\n", temp);
	free(temp);
	temp = get_next_line(fileisame[1]);
	printf("line8: %s|\n", temp);
	free(temp);
	temp = get_next_line(fileisame[2]);
	printf("line9: %s|\n", temp);
	free(temp);
}