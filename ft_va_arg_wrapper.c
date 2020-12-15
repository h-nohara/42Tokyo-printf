#include "ft_printf.h"

char	*ft_va_arg_s(va_list *args)
{
	char *s;

	s = va_arg(*args, char*);
	if (!s)
		return ("(null)");
	else
		return (s);
}

char	*ft_va_arg_p(va_list *args)
{
	void	*p;

	p = va_arg(*args, void*);
	if (p == NULL)
		return ("0");
	else
		return (ft_convert_to_hex((int64_t)p, 0));
}
