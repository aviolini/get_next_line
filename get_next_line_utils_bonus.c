/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 10:27:55 by aviolini          #+#    #+#             */
/*   Updated: 2021/01/31 19:17:19 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list *ft_checkfd(t_list **lst, int fd)
{
	t_list *newlist;

	if(*lst)
	{
		while (*lst)
		{
			if((*lst)->fd == fd)
				return (*lst);
			(*lst) = (*lst)->next;
		}
		newlist = (t_list *)malloc(sizeof(t_list));
		newlist->fd = fd;
		newlist->next = NULL;
		(*lst)->next = newlist;
		return (newlist);
	}
	(*lst) = (t_list *)malloc(sizeof(t_list));
	(*lst)->next = NULL;
	(*lst)->fd = fd;
	return (*lst);
}

void 	ft_clearone(t_list *lst)
{
	t_list *ptr;

		ptr = lst->next;
		lst->next = lst;
		free (ptr);
		return;
}

int 	ft_count(t_list **lst)
{
	int i;

	i = 1;
	if (!(*lst))
		return (0);
	while ((*lst)->next)
	{
		*lst = (*lst)->next;
		i++;
	}
	return i;
}

char	*ft_newline(char **line, char *ptr, int r)
{
	int i;
	int y;
	char *newline;
	int tot;

	i = -1;
	y = 0;
	if (*line)
	{
		y = ft_strlen(*line);
		newline = (char *)malloc(sizeof(char) * (y + r + 1));
	}
	else
		newline = (char *)malloc(sizeof(char) * (r + 1));
	while(++i < y)
		newline[i] =  line[0][i];
	i = 0;
	tot = r + y;
	while(y < tot)
		newline[y++] = ptr[i++];
	newline[y] = '\0';
	if (y > i)
		free(*line);
	return (newline);
}

int ft_refresh_index(char **line, char *index)
{
	int x;
	int y;

	x = ft_strchr(index);
	y = ft_strlen(index);
	if (x == -1)
	{
		*line = ft_newline(line, index, y);
		ft_clean(index);
	}
	else
	{
		*line = ft_newline(line, index, x);
		ft_index(index, index, x + 1);
		return (1);
	}
	return (0);
}

void ft_clean(char *ptr)
{
	int i;

	i = 0;
	while(ptr[i])
		ptr[i++] = '\0';
}
