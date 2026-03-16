/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:41:37 by nleoni            #+#    #+#             */
/*   Updated: 2023/12/28 15:41:38 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (d == s)
		return (dest);
	if (s < d)
	{
		while (n--)
			*(d + n) = *(s + n);
		return (dest);
	}
	while (n--)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dest);
}

// int	main(void)
// {
// 	//void *dest;
// 	//const void *src = "Hello World";
// 	size_t n = 5;
// 	char dest1[20];
// 	char src1[] = "Hello World";

// 	//dest1 = (char *)dest;
// 	//src1 = (char *)src;
// 	printf("Orig: %p\n", memmove(dest1, src1, n));
//     printf("Orig: %s\n", dest1);
// 	printf("Mine: %p\n", ft_memmove(dest1, src1, n));
//     printf("Mine: %s\n", dest1);
// }