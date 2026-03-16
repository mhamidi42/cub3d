/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:06:36 by nleoni            #+#    #+#             */
/*   Updated: 2024/10/17 23:40:35 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_empty_str(void)
{
	char	*empty_str;

	empty_str = (char *)malloc(1);
	if (empty_str == NULL)
		return (NULL);
	empty_str[0] = '\0';
	return (empty_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	size_t			i;
	unsigned int	a;

	if (s == NULL)
		return (NULL);
	i = 0;
	a = ft_strlen((char *)s);
	if (start > (a - 1))
		return (ft_empty_str());
	if (len > a - start)
		len = a - start;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL || ((a - start) < len))
		return (NULL);
	while (s[start] && i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

// int	main(void)
// {
// 	printf("ft_substr: %s\n", ft_substr("0123456789", 4, 5));
// }
