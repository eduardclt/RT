/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 13:53:09 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/07/06 15:18:07 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_2d_arr(void ***arr, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		free(*(*arr + i));
		i++;
	}
	free(*arr);
	*arr = NULL;
}