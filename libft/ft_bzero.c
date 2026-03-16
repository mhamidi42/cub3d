/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:44:56 by nleoni            #+#    #+#             */
/*   Updated: 2023/12/28 15:37:58 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			((char *)s)[i] = '\0';
			i++;
		}
	}
}

/*int	main(void)
{
	char str[12] = "Hello World";
	int		n = 13;

	printf("Original : %ld\n", sizeof(str));

	printf("Apres : %s\n", str);

	//ft_bzero(str, 12);

	printf("Original2 : %s\n", str);

	ft_bzero(str, n);

	printf("apres void : %s\n", str);
}*/