/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_fl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 10:02:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/13 10:03:05 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line_fl.h"

char	*join_me(char *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*res_str;

	s1_len = 0;
	s2_len = 0;
	res_str = NULL;
	if (s1 != NULL && s2 != NULL)
	{
		s1_len = ft_strlen(s1);
		s2_len = ft_strlen(s2);
		res_str = ft_strnew(s1_len + s2_len + 1);
		if (res_str)
		{
			ft_strncpy(res_str, s1, s1_len);
			free(s1);
			ft_strncpy((res_str + s1_len), s2, s2_len);
		}
		else
			return (NULL);
	}
	return (res_str);
}

static char	*string_sub(char *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	string_len;
	size_t	j;

	j = 0;
	substring = NULL;
	string_len = ft_strlen(s);
	if (s[start] == '\n')
		start++;
	if (s && start < string_len + 1 && len < string_len + 1)
	{
		substring = malloc(sizeof(char) * len + 1);
		if (substring == NULL)
			return (NULL);
		while (start < string_len && j < len)
		{
			substring[j] = s[start];
			start++;
			j++;
		}
		substring[j] = '\0';
	}
	free(s);
	return (substring);
}

static void	set_line(char **res_str, char **line)
{
	int	str_len;
	int	counter;

	str_len = ft_strlen(*res_str);
	counter = 0;
	while ((*res_str)[counter] != '\n' && (*res_str)[counter] != '\0')
	{
		counter++;
	}
	*line = ft_strnew(counter);
	*line = ft_strncpy(*line, *res_str, counter);
	*res_str = string_sub(*res_str, counter, (str_len - counter));
}

int	get_next_line_fl(const int fd, char **line)
{
	static char	*res_str;
	char		buffer[BUFF_SIZE + 1];
	int			read_bytes;

	read_bytes = 0;
	if (fd < 0 || BUFF_SIZE < 0 || line == NULL)
		return (-1);
	if (!res_str)
		res_str = ft_strnew(1);
	while (!(ft_strchr(res_str, '\n')))
	{
		read_bytes = read(fd, buffer, BUFF_SIZE);
		if (read_bytes < 0)
			return (-1);
		buffer[read_bytes] = '\0';
		res_str = join_me(res_str, buffer);
		if (*res_str == '\0' && read_bytes == 0)
			return (0);
		else if (read_bytes == 0)
			break ;
	}
	set_line(&res_str, line);
	return (1);
}
