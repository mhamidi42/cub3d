/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:46:01 by nleoni            #+#    #+#             */
/*   Updated: 2023/12/28 15:38:24 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	b;
	void			*p;

	if (count > 0 && 2147483647 / count < size)
		return (NULL);
	if (size > 0 && 2147483647 / size < count)
		return (NULL);
	b = count * size;
	p = malloc(b);
	if (p == NULL)
		return (NULL);
	else
		ft_bzero(p, b);
	return (p);
}

// int	main(void)
// {
// 	printf("%p\n", ft_calloc(0, 0));
// 	size_t nmemb;
// 	size_t size;
// 	int *ptr;
// 	size_t i = 0;
// 	size = 0;
// 	nmemb = 0;
// 	ft_calloc(nmemb, size);
// 	ptr = (int *)calloc(nmemb, size);
// 	while (i < nmemb)
// 	{
// 		i++;
// 		printf("\ncalloc: %d", ptr[i]);
// 	}
// }