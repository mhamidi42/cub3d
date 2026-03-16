/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:50:22 by nleoni            #+#    #+#             */
/*   Updated: 2024/01/02 22:23:25 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_set(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_count(const char *s1, const char *set)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (!ft_char_set(set, s1[i]))
			return (i);
		i++;
	}
	return (i);
}

static size_t	ft_rev_count(const char *s1, const char *set, size_t a)
{
	while (a > 0)
	{
		a--;
		if (!ft_char_set(set, s1[a]))
			return (a + 1);
	}
	return (a + 1);
}

static void	ft_trim_len(char *dst, const char *s1, size_t i, size_t a)
{
	size_t	j;

	j = 0;
	while (i < a)
	{
		dst[j] = s1[i];
		j++;
		i++;
	}
	dst[j] = '\0';
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	a;
	char	*dst;

	if (s1 == NULL || set == NULL)
		return (NULL);
	a = ft_strlen(s1);
	i = ft_count(s1, set);
	if (i != a)
		a = ft_rev_count(s1, set, a);
	dst = (char *)malloc((a - i) + 1 * sizeof(char));
	if (dst != NULL)
		ft_trim_len(dst, s1, i, a);
	return (dst);
}

/*int     main()
{
    printf("%s\n", ft_strtrim("0  1234567892102", "012"));
}*/