/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:48:55 by amahi             #+#    #+#             */
/*   Updated: 2021/11/25 20:29:36 by amahi            ###   ########.fr       */
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
	static char	*one_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	one_str = filling_one_str(fd, one_str);
	if(!one_str)
		return (NULL);
	result = filling_result(one_str);
	one_str = cat_one_str(one_str);
	return (result);
}

// int main(void)
// {
// 	int		fd;

// 	fd = open("text.txt", O_RDONLY);
// 	printf("first string: 	%s", get_next_line(fd));
// // 	// printf("Вторая строчка: 	%s\n\n", get_next_line(fd));
// // 	// printf("Третья строчка: 	%s\n\n", get_next_line(fd));
// // 	// printf("Четвертая строчка: 	%s\n\n", get_next_line(fd));
// // 	// printf("Пятая строчка: 		%s\n\n", get_next_line(fd));
// // 	// printf("Шестая строчка: 	%s\n\n", get_next_line(fd));
// // 	// printf("Седьмая строчка: 	%s\n\n", get_next_line(fd));
// // 	// printf("Восьмая строчка: 	%s\n\n", get_next_line(fd));
// // 	// printf("Девятая строчка: 	%s\n\n", get_next_line(fd));
// // 	// printf("Десятая строчка: 	%s\n\n", get_next_line(fd));
	
// }