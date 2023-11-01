/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:39:39 by hakobaya          #+#    #+#             */
/*   Updated: 2023/06/10 07:21:53 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	c_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != '\0' && s[i] != c)
				i++;
			count++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (count);
}

static void	set_array(char **sp, char const *s, char c, size_t i)
{
	size_t	j;

	j = 0;
	while (*s != '\0' && *s != c)
	{
		sp[i][j] = *s;
		j++;
		s++;
	}
}

static char	**set_split(char **sp, char const *s, char c, size_t *i)
{
	size_t	count;

	while (*s != '\0')
	{
		count = 0;
		while (*s != '\0' && *s != c)
		{
			count++;
			s++;
		}
		if (count != 0)
		{
			sp[*i] = ft_calloc(count + 1, sizeof(char));
			if (!sp[*i])
				return (sp);
			s -= count;
			set_array(sp, s, c, *i);
			s += count;
			(*i)++;
		}
		else
			s++;
	}
	return (sp);
}

static void	ft_free(char **sp)
{
	size_t	i;

	i = 0;
	while (sp[i] != NULL)
	{
		free(sp[i]);
		i++;
	}
	free(sp);
}

char	**ft_split(char const *s, char c)
{
	char	**sp;
	size_t	num;
	size_t	i;

	if (s == NULL)
		return (NULL);
	num = c_count(s, c) + 1;
	sp = ft_calloc(num, sizeof(char *));
	if (!sp)
		return (NULL);
	i = 0;
	sp = set_split(sp, s, c, &i);
	if (i != num - 1)
	{
		ft_free(sp);
		return (NULL);
	}
	return (sp);
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>

//int	main(void)
//{
//	char	**tab1;
//	char	**tab2;
//	int		i;

//	tab1 = ft_split("hello,world,42,tokyo", ',');
//	tab2 = ft_split(",,,hello,,,world,,,42,,,tokyo,,,,", ',');
//	i = 0;
//	while (tab1[i])
//	{
//		printf("%d: [%s]\n", i, tab1[i]);
//		i++;
//	}
//	i = 0;
//	while (tab2[i])
//	{
//		printf("%d: [%s]\n", i, tab2[i]);
//		i++;
//	}
//}

//printf("%s %d\n", __func__, __LINE__);

//static char	**set_split(char **sp, char const *s, char c, size_t num)
//{
//	size_t	index;
//	size_t	count;
//	size_t	i;

//	index = 0;
//	i = 0;
//	while (s[index] != '\0')
//	{
//		count = 0;
//		while (s[index] != '\0' && s[index] != c)
//		{
//			count++;
//			index++;
//		}
//		if (count != 0)
//		{
//			sp[i] = ft_calloc(count + 1, sizeof(char));
//			if (!sp[num])
//				return (NULL);
//			index -= count;
//			set_array(sp, s, c, index, i);
//			index += count;
//			i++;
//		}
//		else
//			index++;
//	}
//	return (sp);
//}