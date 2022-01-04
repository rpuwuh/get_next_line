#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);
char	*ft_strdup(const char	*s1);
void	*ft_memcpy(void	*dst, const void	*src, size_t	n);
size_t	ft_strlen(const char	*c);
char	*ft_strjoin(char const	*s1, char const	*s2);
char	*ft_strchr(const char	*s, int	c);
void	*ft_calloc(size_t	count, size_t	size);
void	*ft_bzero(void	*s, size_t	n);
void	ft_cleanfreestring(char **s);

#endif
