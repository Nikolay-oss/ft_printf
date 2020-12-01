#include "ft_handlers.h"
#include "libft.h"

void	ft_display_special(t_specifier *spec, char *str)
{
	while (*str != '%')
		str--;
	spec->bytes_count += ft_putnstr(str, '\0');
}
