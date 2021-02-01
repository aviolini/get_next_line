/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 10:27:58 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/01 09:39:50 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int   get_next_line(int fd, char **line)
{
	static t_list **lst;
	int x;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		  return (-1);
		 *line = NULL;
	if (!lst)
	{
		lst = (t_list **)malloc(sizeof(t_list));
		*lst = NULL;
	}
  x = 0;
  *lst = ft_checkfd(lst,fd);
	if ((*lst)->content[0] != '\0')
		if ((x = ft_refresh_index(line, ((*lst)->content))) == 1)
		      return (1);
	ft_clean((*lst)->content);
    while (x == 0)
		x = ft_read((*lst)->fd, line, (*lst)->content);
	if (x == -2)
    {
	//	if (ft_count(lst) == 1)
	//	{
	//		free(*lst);
//
//			free(lst);
//		}
//		else
			if (*lst)
			//	ft_clearone(*lst);
				free(*lst);
			free(lst);
			//ft_clearone(*lst);
        if (!*line)
        {
            *line = (char *)malloc(sizeof(char));
             line[0][0] = '\0';
        }
        x = 0;
    }
	if(x == -1)
	{
		free(*lst);
		free(lst);
	}

	return (x);
}

void   ft_index(char *index, char *ptr, int x)
{
  int i;
  i = 0;
  while (ptr[x])
    index[i++] = ptr[x++];
while (index[i])
index[i++] = '\0';
}

int   ft_read(int fd, char **line, char *index)
{
  int r;
  int x;
  char ptr[BUFFER_SIZE  + 1];

	r = 1;
	while (r)
	{
	  if ((r = read(fd, ptr, BUFFER_SIZE)) == -1)
	  	return (-1);
	ptr[r] = '\0';
		if (r == 0)
            return (-2);
	  if ((x = ft_strchr(ptr)) == -1)
	  	{
			*line = ft_newline(line, ptr, r);
			ft_clean(ptr);
            return (0);
	  	}
			*line = ft_newline(line, ptr, x);
			ft_index(index, ptr, x + 1);
			break;
    }
    return (1);
}


int ft_strchr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
			if(str[i] == '\n')
				return (i);
	}
	return (-1);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
