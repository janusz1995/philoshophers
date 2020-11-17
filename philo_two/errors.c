
#include "philosophers.h"

int 	error_arguments(char *str)
{
	write(1, str, ft_strlen(str));
	return (0);
}

int		malloc_error(char *str)
{
	ft_putstr_fd(str,1);
	return (0);
}