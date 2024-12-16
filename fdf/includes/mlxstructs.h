#ifndef MLXSTRUCTS_H
# define MLXSTRUCTS_H

typedef struct s_mlxtools
{
	void *link;
	void *win;

	void *screenimg;
	char *screenimgdata;
	int bpp;
	int linesize;
	int multibyteorder;
} t_mlxtools;

typedef struct s_map
{
	int ***map;
	unsigned int maplength;
	unsigned int mapwidth;
	unsigned int outerwidth;
	unsigned int outerlength;
	int originx;
	int originy;
	int largest;
	int smallest;
	int *colors;
}t_map;
#endif