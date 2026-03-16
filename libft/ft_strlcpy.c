/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:49:25 by nleoni            #+#    #+#             */
/*   Updated: 2024/01/06 20:27:18 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (i < (size - 1) && i < src_len)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}

// int     main(void)
// {
//     size_t      i;
//     char src[] = "coucou";
// 	char dest[10];

//     i = 0;
//     memset(dest, 'A', 10);
//     printf("dest[0]: %d\n", dest[0]);
//     printf("function: %ld\n", ft_strlcpy(dest, src, 0));
//     while(dest[i] && i < 10)
//     {
//            printf("autres: %d\n", dest[i]);
//            i++;
//     }
// }
