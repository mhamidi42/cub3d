/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:26:46 by nleoni            #+#    #+#             */
/*   Updated: 2023/12/28 19:02:56 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '+') || (str[i] == '-'))
		i++;
	while (ft_isdigit(str[i]))
		result = (result * 10) + (str[i++] - 48);
	return (result * sign);
}

// int	main(void)
// {
// 	char escape[] = {9, 10, 11, 12, 13, 0};
// 	string e(escape);

// 	printf("Original : %d\n", atoi(e + "1"));
// 	printf("Copie : %d\n", ft_atoi(e + "1"));
//     return (0);
// }