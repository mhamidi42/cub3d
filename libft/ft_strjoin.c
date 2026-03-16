/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:37:14 by nleoni            #+#    #+#             */
/*   Updated: 2024/01/06 21:00:09 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		a;
	int		b;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	a = ft_strlen((char *)s1);
	b = ft_strlen((char *)s2);
	str = (char *)malloc(sizeof(char) * (a + b + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

/*int	main(void)
{
	printf("return: %s\n", ft_strjoin("Hello ", "World"));
}*/
