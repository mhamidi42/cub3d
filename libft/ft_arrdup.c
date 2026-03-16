/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinto- <espinto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:57:37 by espinto-          #+#    #+#             */
/*   Updated: 2024/11/25 17:26:57 by espinto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

static void	free_dup(char **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_arrdup(char **arr)
{
	char	**new;
	int		i;
	int		size;

	size = ft_arrlen(arr);
	new = malloc((size + 1) * sizeof(new));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new[i] = ft_strdup(arr[i]);
		if (new[i] == NULL)
		{
			free_dup(new, i);
			return (NULL);
		}
		i++;
	}
	new[i] = NULL;
	return (new);
}
