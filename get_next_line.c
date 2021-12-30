/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:08:07 by hbombur           #+#    #+#             */
/*   Updated: 2021/12/01 20:30:42 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*write_after_n(char *end_of_line)
{
	char	*line;
	int		i;
	int		j;
	// char	*tmp;

	j = 0;
	i = 1;
	line = NULL;
	// tmp = ft_strchr(end_of_line, '\n');
	// if (tmp)
	// {
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
	// }
	if (end_of_line)
		free(end_of_line);
	if (line[0] == '\0')
	{
		free(line);
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
	if (itm[0] == '\0')
	{
		free(itm);
		return (NULL);
	}
	if (end_of_line[i] == '\n')
		itm[j++] = end_of_line[i++];
	itm[j] = '\0';
	return (itm);
}

char	*file_read(int fd, char *end_of_line, char *buff)
{
	char	*tmp;
	int		read_byte;

	read_byte = 1;
	tmp = NULL;
	if (!end_of_line)
		end_of_line = NULL;
	while (!(ft_strchr(buff, '\n')) && read_byte)//end cycle before join buff
	{
		tmp = end_of_line;
		read_byte = read(fd, buff, BUFFER_SIZE);
		if (read_byte < 0 || !buff)
			return (NULL);
		buff[read_byte] = '\0';
		if (!buff)
			return (NULL);
		if (!end_of_line)
			end_of_line = ft_strdup(buff);
		else
			end_of_line = ft_strjoin(end_of_line, buff);
		if (tmp)
			free(tmp);
	}
	// if (read_byte == 1)
	// 	end_of_line = ft_strjoin(end_of_line, buff);
	return (end_of_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*end_of_line;
	char		*buff;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	end_of_line = file_read(fd, end_of_line, buff);
	if (buff)
		free(buff);
	if (!end_of_line)
		return (NULL);
	line = write_before_n(end_of_line);
	if (!line)
	{
		if (end_of_line)
			free(end_of_line);
		return (NULL);
	}
	end_of_line = write_after_n(end_of_line);
	return (line);
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("multiple_line_with_nl", O_RDONLY);

	line = get_next_line(fd);
	printf("!-! 1 line !-! %s", line);
	// printf("%s", line);
	line = get_next_line(fd);
	// printf("%s", line);
	printf("!-! 2 line !-! %s", line);
	line = get_next_line(fd);
	// printf("%s", line);
	printf("!-! 3 line !-! %s", line);
	line = get_next_line(fd);
	// printf("%s", line);
	printf("!-! 4 line !-! %s", line);
	line = get_next_line(fd);
	// printf("%s", line);
	printf("!-! 5 line !-! %s", line);
	line = get_next_line(fd);
	// printf("%s", line);
	printf("!-! 6 line !-! %s", line);
	// line = get_next_line(fd);
	// // printf("%s", line);
	// printf("!-! 7 line !-! %s", line);
	// line = get_next_line(fd);
	// // printf("%s", line);
	// printf("!-! 8 line !-! %s", line);
	// line = get_next_line(fd);
	// // printf("%s", line);
	// printf("!-! 9 line !-! %s", line);
	return (0);
}
