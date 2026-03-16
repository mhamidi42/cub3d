/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:49:03 by nleoni            #+#    #+#             */
/*   Updated: 2024/01/06 20:28:36 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t sz)
{
	size_t	i;
	size_t	j;
	size_t	a;
	size_t	b;

	if (dst == NULL && sz == 0)
		return (0);
	i = 0;
	a = ft_strlen(dst);
	j = a;
	b = ft_strlen(src);
	if (sz == 0 || sz <= a)
		return (b + sz);
	while (src[i] && (a + i) < (sz - 1))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	if ((a + i) == sz && a < sz)
		dst[--j] = '\0';
	else
		dst[j] = '\0';
	return (a + b);
}

/*int     main (void)
{
	char * src = (char *)"AAAAAAAAA";
	char dst[30];

	memset(dst, 0, 30);
	dst[0] = 'B';
	memset(dst, 'B', 4);
	ft_strlcat(dst, src, 6);
	//strlcat(dst, src, 6);
	printf("dst: %s\n", dst);
	printf("%ld\n", ft_strlcat(dst, src, 6));
}*/
