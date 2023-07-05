#include "get_next_line.h"

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len_s2)
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}

char	*ft_strdup(const char *str)
{
	char	*duplicate;
	size_t	length;
	size_t	i;

	length = ft_strlen(str);
	duplicate = (char *)malloc((length + 1) * sizeof(char));
	if (!duplicate)
		return (NULL);
	i = 0;
	while (i <= length)
	{
		duplicate[i] = str[i];
		i++;
	}
	return (duplicate);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}