/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:47:00 by nleoni            #+#    #+#             */
/*   Updated: 2023/12/28 15:42:03 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		((char *)s)[i] = (char)c;
		i++;
		n--;
	}
	return (s);
}

/*int	main(void)
{
	char s[] = "Ouiaaa je suis la";

	printf("mine: %p\n", ft_memset(s + 2, '8', 4));
	printf("oui: %s\n", s);
	printf("memset: %p\n", memset(s, '8', 4));
}*/