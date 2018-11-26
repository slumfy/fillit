/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:25:28 by varuiz            #+#    #+#             */
/*   Updated: 2018/11/21 09:07:08 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		line_copy(char **line, char *content, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = *line;
	while (content[i] && content[i] != c)
		i++;
	if (!(*line = ft_strndup(content, i)))
		return (0);
	return (i);
}

t_list	*get_live(int fd, t_list **prev)
{
	t_list	*tmp;

	if (!prev)
		return (NULL);
	tmp = *prev;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", fd);
	ft_lstadd(prev, tmp);
	return (tmp);
}

int		ft_read(const int fd, char **content)
{
	int		result;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];

	while ((result = read(fd, buf, BUFF_SIZE)))
	{
		buf[result] = '\0';
		tmp = *content;
		if (!(*content = ft_strjoin(*content, buf)))
			return (-1);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (result);
}

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	size_t			result;
	static t_list	*prev;
	t_list			*live;
	char			*tmp;

	if (fd < 0 || !line || (read(fd, buf, 0)) < 0 ||
		(!(live = get_live(fd, &prev))))
		return (-1);
	tmp = live->content;
	result = ft_read(fd, &tmp);
	live->content = tmp;
	if (!result && !*tmp)
		return (0);
	result = line_copy(line, live->content, '\n');
	tmp = live->content;
	if (tmp[result] != '\0')
	{
		live->content = ft_strdup(&((live->content)[result + 1]));
		free(tmp);
	}
	else
		tmp[0] = '\0';
	return (1);
}
