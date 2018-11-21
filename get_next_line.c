/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:33:42 by akam              #+#    #+#             */
/*   Updated: 2018/11/21 17:30:48 by akam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void

int		get_sub_line(char **line, char *buff, int *i_buff)
{
	char	*i;

	if (!(i = ft_strchr(buff + *i_buff, '\n')))
	{
		*line = ft_strjoin(*line, buff + *i_buff);
		*i_buff = 0;
		return (0);
	}
	*line = ft_strsub(buff, *i_buff, i - (buff + *i_buff));
	*i_buff += i - (buff + *i_buff);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	buff[BUFF_SIZE];
	int		nb_r;
	static int		index;

	index = 0;
	if (fd < 0 || !line)
        return (-1);
	while ((nb_r = read(fd, &buff, BUFF_SIZE)) > 0)
	{
		if (!nb_r)
			return (0);
		if (get_sub_line(line, buff, &index))
		{
			
			return (1)
		}
	}
	return (nb_r);
}

int main()
{
	int fd = open("test", O_RDONLY);
	char *line = "";

	while (get_next_line(fd, line))
	{
		printf("%s\n", line);
	}
}
