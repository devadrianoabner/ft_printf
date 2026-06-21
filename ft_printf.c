#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int	num_bytes;
	int	i;
	int	c;

	i = 0;
	num_bytes = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(args, int);
				num_bytes = num_bytes + write(1, &c, 1);
			}

		}
		else
		num_bytes = num_bytes + write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (num_bytes);
}
