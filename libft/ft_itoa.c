/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:40:30 by nleoni            #+#    #+#             */
/*   Updated: 2023/12/28 18:32:16 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put_nbr(char *dest, unsigned int n)
{
	if (n < 10)
	{
		*dest = n + '0';
	}
	else
	{
		*dest = n % 10 + '0';
		ft_put_nbr(dest - 1, n / 10);
	}
}

static size_t	ft_num_len(int n)
{
	size_t	c;

	c = 0;
	while (n)
	{
		n /= 10;
		c++;
	}
	return (c);
}

static size_t	ft_set_len(int n)
{
	size_t	len;

	if (n < 0)
		len = ft_num_len(n) + 1;
	else
		len = ft_num_len(n);
	return (len);
}

static unsigned int	ft_set_sign(int n, unsigned int num)
{
	if (n < 0)
		return (-num);
	return (num);
}

char	*ft_itoa(int n)
{
	size_t			i;
	unsigned int	num;
	char			*str;

	num = n;
	if (n == 0)
		return (ft_strdup("0"));
	else
	{
		i = ft_set_len(n);
		str = malloc(sizeof(char) * (i + 1));
		if (!str)
			return (NULL);
		num = ft_set_sign(n, num);
		ft_put_nbr(str + i - 1, num);
		if (n < 0)
			*str = '-';
		str[i] = '\0';
	}
	return (str);
}

/*int main()
{
	char *pt_itoa1 = ft_itoa(5);
	char *pt_itoa2 = ft_itoa(-5);
	char *pt_itoa3 = ft_itoa(0);
	char *pt_itoa4 = ft_itoa(15);
	printf("itoa1: %s\n", pt_itoa1);
	printf("itoa2: %s\n", pt_itoa2);
	printf("itoa3: %s\n", pt_itoa3);
	printf("itoa4: %s\n", pt_itoa4);

	return (0);
}*/