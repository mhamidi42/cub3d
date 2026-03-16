/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:54:35 by nleoni            #+#    #+#             */
/*   Updated: 2023/12/28 15:44:21 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

// int     main()
// {
// 	printf("\n%d\n", 't' + 256);
//     char s[] = "tripouille";
//     printf("Mine: %s\n", ft_strchr(s, 't' + 256));
//     printf("strchr: %s\n", strchr(s, 't' + 256));
// }