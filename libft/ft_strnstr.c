/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:50:04 by nleoni            #+#    #+#             */
/*   Updated: 2024/01/06 21:15:42 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (i + j < len && big[i + j] && big[i + j] == little[j])
				j++;
			if (!little[j])
				return ((char *)(&big[i]));
			i++;
		}
		else
			i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char * empty = (char *)"";
// 	printf("\n%s\n", empty);
// 	printf("mine: %s\n", ft_strnstr(empty, "coucou", -1));
// }
