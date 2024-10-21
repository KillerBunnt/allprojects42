# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# include "libft.h"
# include "ft_printf.h"


size_t			ft_strlen(const char *str);
int		ft_printf(const char *str, ...);


int main()
{
	ft_printf("strlen of hello is %d", ft_strlen("hello"));
}