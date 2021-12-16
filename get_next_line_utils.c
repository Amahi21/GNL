/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:50:05 by amahi             #+#    #+#             */
/*   Updated: 2021/11/25 20:18:31 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	ssize_t	j;
	char	*res;
	
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (!res)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			res[i] = s1[i];
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

char	*ft_strchr(const char *str, int ch)
{
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	if (ch == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char) ch)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*filling_result(char *one_str)
{
	char	*result;
	int		i;

	i = 0;
	if (!one_str[i])
		return (NULL);
	while(one_str[i] != '\n' && one_str[i])
		i++;
	result = (char *)malloc(sizeof(char) * (i + 2));
	if (!result)
		return (NULL);
	i = 0;		
	while(one_str[i] != '\n' && one_str[i])
	{
		result[i] = one_str[i];
		i++;
	}
	if (one_str[i] == '\n')
	{
		result[i] = one_str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
char *cat_one_str(char *one_str)
{
	int		i;
	int		j;
	char	*remaider;

	i = 0;
	while (one_str[i] != '\n' && one_str[i])
		i++;
	if (!one_str[i])
	{
		free(one_str);
		return (NULL);
	}
	remaider = (char *)malloc(sizeof(char) * (ft_strlen(one_str) - i + 1));
	if (!remaider)
		return (NULL);
	i++;
	j = 0;
	while(one_str[i])
		remaider[j++] = one_str[i++];
	remaider[j] = '\0';
	free(one_str);
	return(remaider);
}