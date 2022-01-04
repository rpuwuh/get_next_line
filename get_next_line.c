/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:08:07 by hbombur           #+#    #+#             */
/*   Updated: 2022/01/05 02:38:43 by mikhail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_cleanfreestring(char **s)
{
	if (!s || !*s)
		return ;
	free(*s);
	*s = 0;
	return ;
}

char	*write_after_n(char *end_of_line)
{
	char	*line;
	int		i;
	int		j;

	j = 0;
	i = 0;
	line = NULL;
	while (end_of_line[i] != '\n' && (end_of_line[i] != '\0'))
		i++;
	line = malloc((ft_strlen(end_of_line) - i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	if (end_of_line[i] == '\n')
		i++;
	while (end_of_line[i])
		line[j++] = end_of_line[i++];
	line[j] = '\0';
	ft_cleanfreestring(&end_of_line);
	if (line[0] == '\0')
	{
		ft_cleanfreestring(&line);
		return (NULL);
	}
	return (line);
}

char	*write_before_n(char *end_of_line)
{
	int		i;
	char	*itm;
	int		j;

	i = 0;
	j = 0;
	itm = NULL;
	while (end_of_line[i] != '\n' && end_of_line[i] != '\0')
		i++;
	itm = malloc((i + 2) * sizeof(char));
	if (!itm)
		return (NULL);
	i = 0;
	while (end_of_line[i] != '\n' && end_of_line[i] != '\0')
		itm[j++] = end_of_line[i++];
	if (end_of_line[i] == '\n')
		itm[j++] = end_of_line[i];
	itm[j] = '\0';
	if (itm[0] == '\0')
	{
		ft_cleanfreestring(&itm);
		return (NULL);
	}
	return (itm);
}

char	*file_read(int fd, char *end_of_line, char *buff)
{
	char	*tmp;
	int		read_byte;

	read_byte = 1;
	tmp = NULL;
	while (read_byte && !(ft_strchr(end_of_line, '\n')))
	{
		tmp = end_of_line;
		read_byte = read(fd, buff, BUFFER_SIZE);
		if (read_byte < 0 || !buff)
		{
			ft_cleanfreestring(&end_of_line);
			return (NULL);
		}
		buff[read_byte] = '\0';
		if (!buff)
			return (NULL);
		if (!end_of_line)
			end_of_line = ft_strdup(buff);
		else
			end_of_line = ft_strjoin(end_of_line, buff);
		ft_cleanfreestring(&tmp);
	}
	return (end_of_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*end_of_line;
	char		*buff;

	line = NULL;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	end_of_line = file_read(fd, end_of_line, buff);
	ft_cleanfreestring(&buff);
	if (!end_of_line)
		return (NULL);
	line = write_before_n(end_of_line);
	if (!line)
	{
		ft_cleanfreestring(&end_of_line);
		return (NULL);
	}
	end_of_line = write_after_n(end_of_line);
	return (line);
}

// int	main(void)
// {
// 	char	*line;
// 	int		fd;

// 	fd = open("empty", O_RDONLY);

// 	line = get_next_line(fd);
// 	printf("!-! 1 line !-! %s", line);
// 	line = get_next_line(fd);
// 	printf("!-! 2 line !-! %s", line);
// 	line = get_next_line(fd);
// 	printf("!-! 3 line !-! %s", line);
// 	line = get_next_line(fd);
// 	printf("!-! 4 line !-! %s", line);
// 	line = get_next_line(fd);
// 	printf("!-! 5 line !-! %s", line);
// 	line = get_next_line(fd);
// 	printf("!-! 6 line !-! %s", line);
// 	line = get_next_line(fd);
// 	printf("!-! 7 line !-! %s", line);
// 	line = get_next_line(fd);
// 	printf("!-! 8 line !-! %s", line);
// 	line = get_next_line(fd);
// 	printf("!-! 9 line !-! %s", line);
// 	return (0);
// }
