#include "../minilibx/mlx.h"
#include "../includes/all.h"

static int getlines(t_map *map, int mapfd, unsigned int index);
static int coloratoi(char *str);
static void fillarray(t_map *map, char **splithold, unsigned int index);

int loadmap(t_map *map, char *mapstr)
{
	int mapfd;

	mapfd = open(mapstr, O_RDONLY);
	if (mapfd == -1)
	{
		ft_printf("FILE PROVIDED DOES NOT EXIST\n");
		return (1);
	}
	return (getlines(map, mapfd, 0));
}

static int getlines(t_map *map, int mapfd, unsigned int index)
{
	char	*test;
	char	**splithold;
	unsigned int		linesize;

	test = get_next_line(mapfd);
	if (test)
		getlines(map, mapfd, index + 1);
	else if (index == 0)
	{
		ft_printf("FILE PROVIDED IS EMPTY");
		return (1);
	}
	else
	{
		map->mapwidth = index;
		map->map = ft_calloc(index + 1, sizeof(int **));
		return (0);
	}
	splithold = ft_split(test, ' ');
	linesize = 0;
	while (splithold[linesize])
		linesize++;
	if (splithold[linesize - 1][0] == '\n')
		linesize--;
	if (!map->maplength && linesize)
		map->maplength = linesize;
	map->map[index] = ft_calloc(linesize + 1, sizeof(int *));
	fillarray(map, splithold, index);
	free(test);
	return (0);
}

static void fillarray(t_map *map, char **splithold
	, unsigned int index)
{
	unsigned int	linesize;
	char	**innersplit;

	linesize = 0;
	while(splithold[linesize])
	{
		map->map[index][linesize] = ft_calloc(4, sizeof(int));
		innersplit = ft_split(splithold[linesize], ',');
		map->map[index][linesize][0] = ft_atoi(innersplit[0]);
		if (innersplit[1])
			map->map[index][linesize][1] = coloratoi(innersplit[1]);
		else
			map->map[index][linesize][1] = -1;
		free(innersplit[0]);
		free(innersplit[1]);
		free(innersplit);
		free(splithold[linesize]);
		linesize++;
	}
	free(splithold[linesize]);
	free(splithold);
}

static int coloratoi(char *str)
{
	int	startindex;
	int	power;
	int	total;
	int	index;
	char	*base;

	base = "0123456789ABCDEF";
	total = 0;
	power = -1;
	startindex = 8;
	while(--startindex > 1)
	{
		index = 0;
		while (str[startindex] != base[index])
			index++;
		total += index * pow(16, ++power);
	}
	return (total);
}