/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:27:44 by amahi             #+#    #+#             */
/*   Updated: 2021/11/25 20:32:05 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*filling_one_str(int fd, char *one_str)
{
	char	*buff;
	int		bwr;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bwr = 1;
	while (!ft_strchr(one_str, '\n') && bwr)
	{
		bwr = read(fd, buff, BUFFER_SIZE);
		if (bwr < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[bwr] = '\0';
		one_str = ft_strjoin(one_str, buff);
	}
	free(buff);
	return (one_str);
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*one_str[32768];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	one_str[fd] = filling_one_str(fd, one_str[fd]);
	if(!one_str[fd])
		return (NULL);
	result = filling_result(one_str[fd]);
	one_str[fd] = cat_one_str(one_str[fd]);
	return (result);
}