/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:41:46 by nleoni            #+#    #+#             */
/*   Updated: 2023/12/28 15:40:58 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return (p + i);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char s[] = {0, 1, 2, 3, 4, 5};
// 	int n = 3;
// 	int c = 2;
// 	char *test;// = NULL;
// 	char *ptr = memchr(s, c, n);
// 	test = ft_memchr(s, c, n);
// 	printf("Original : %d\n", *ptr);

// 	printf("position : %ld\n", ptr - s + 1);
// 	printf("character found : %s\n", ptr);

//     printf("Mine : %p\n", ft_memchr(s, c, n));
// 	printf("Mine 2 : %d\n", *test);
// }