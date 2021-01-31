/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 10:27:53 by aviolini          #+#    #+#             */
/*   Updated: 2021/01/31 16:16:29 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include   <unistd.h>
# include   <stdio.h>
# include   <stdlib.h>
# include   <sys/types.h>
# include   <sys/stat.h>
# include   <fcntl.h>


typedef struct s_list
{
        char			content[BUFFER_SIZE + 1];
		int 			fd;
		struct s_list	*next;
}	t_list;

int		get_next_line(int fd, char **line);
void	ft_index(char *index, char *ptr, int x);
int		ft_read(int fd, char **line, char *index);
int		ft_strchr(char *str);
int		ft_strlen(char *str);
char	*ft_newline(char **line, char *ptr, int r);
int		ft_refresh_index(char **line, char *index);
void    ft_clean(char *ptr);
t_list	*ft_checkfd(t_list **lst, int fd);

#endif
