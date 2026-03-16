/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:45:59 by nleoni            #+#    #+#             */
/*   Updated: 2023/12/28 15:39:29 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c > 31 && c <= 126)
		return (1);
	return (0);
}

/*int	main(void)
{
	char    n = '5';

	printf("original : %d\n", isprint(n));
	printf("ma version : %d\n", ft_isprint(n));
}*/