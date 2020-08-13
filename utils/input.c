#include "../includes/input.h"
#include "../includes/basics.h"

int		count_lines(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

char	**string_to_string_array(char *str)
{
	char	**ret;
	int		linecount;
	int		i;
	int		len;
	int		pos;

	i = 0;
	pos = 0;
	linecount = count_lines(str);
	ret = malloc(sizeof(char **) * (linecount + 1));
	if (!ret)
		return (NULL);
	ret[linecount] = NULL;
	while (i < linecount)
	{
		ret[i] = ft_strccpy(str + pos, '\n');
		if (!ret[i])
			return (NULL);
		pos += ft_strclen(str + pos, '\n') + 1;
		i++;
	}
	free(str);
	return (ret);
}

int		append(char **pos, char *suf)
{
	char	*temp;
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = *pos;
	new = malloc(sizeof(char) * (ft_strlen(*pos) + ft_strlen(suf) + 1));
	if (!new)
		return (-1);
	while (temp[i])
	{
		new[i] = temp[i];
		i++;
	}
	while (suf[j])
	{
		new[i + j] = suf[j];
		j++;
	}
	new[i + j] = '\0';
	free(*pos);
	*pos = new;
	return (0);
}

char	*file_to_string(int fd)
{
	char	*ret;
	char	*buf;

	ret = malloc(1);
	ret[0] = '\0';
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	buf[BUFFER_SIZE] = '\0';
	while (read(fd, buf, BUFFER_SIZE))
	{
		if (append(&ret, buf) == -1)
			return (NULL);
		ft_bzero((char **)&buf, BUFFER_SIZE);
	}
	free(buf);
	return (ret);
}

char	**get_input(char *filename)
{
	int		fd;
	char	*str;
	char	**ret;

	fd = open(filename, O_RDONLY);
	str = file_to_string(fd);
	close(fd);
	if (!str)
		return (NULL);
	ret = string_to_string_array(str);
	if (!ret)
		return (NULL);
	return (ret);
}
