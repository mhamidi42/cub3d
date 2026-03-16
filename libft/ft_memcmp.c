/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:46:24 by nleoni            #+#    #+#             */
/*   Updated: 2023/12/28 15:41:12 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	int				diff;
	unsigned char	*a;
	unsigned char	*b;

	diff = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		diff = (int)a[i] - (int)b[i];
		if (diff != 0)
			return (diff);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	// char *s1 = "Hello wf";
// 	// char *s2 = "Hello Wf";
// 	// size_t n = 7;
// 	char s[] = {128, 0, 127, 0};
// 	// char sCpy[] = {-12, 0, 127, 0};
// 	char s2[] = {-128, 0, 127, 0};
// 	// char s3[] = {0, 0, 42, 0};

// 	printf("Orig: %d\n", memcmp(s, s2, 1));

// 	printf("Mine: %d\n", ft_memcmp(s, s2, 1));
// }