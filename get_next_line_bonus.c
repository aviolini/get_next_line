/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 10:27:58 by aviolini          #+#    #+#             */
/*   Updated: 2021/01/31 16:36:20 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int   get_next_line(int fd, char **line)
{
	static char index[BUFFER_SIZE + 1];
	static t_list **lst;
	//static t_list *lst;
	int x;
	if (!lst)
	{
		lst = (t_list **)malloc(sizeof(t_list));
		//lst->next = NULL;
		*lst = NULL;
	}
	printf ("*lst %p\n", *lst);
	printf ("lst %p\n", lst);
//	printf ("lst->next %p\n", lst->next);
  x = 0;
  if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
  *lst = ft_checkfd(lst,fd);
    if (index[0] != '\0')
        if ((x = ft_refresh_index(line, index)) == 1)
		      return (1);
ft_clean(index);
    while (x == 0)
		x = ft_read(fd, line, index);
    if (x == -2)
    {
        if (!*line)
        {
            *line = (char *)malloc(sizeof(char));
             line[0][0] = '\0';
        }
        x = 0;
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