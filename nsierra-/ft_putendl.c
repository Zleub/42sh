#include <stddef.h>
#include <unistd.h>

static size_t		st_strlen(const char *str)
{
	const char		*keep;

	keep = str;
	if (str)
	{
		while (*str != '\0')
			++str;
	}
	return (str - keep);
}

void				ft_putendl(const char *str)
{
	size_t			str_size;

	str_size = st_strlen(str);
	write(1, str, str_size);
	write(1, "\n", 1);
}
