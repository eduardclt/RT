/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 17:52:46 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/06/09 13:21:39 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	if (n >= 10 || n <= -10)
	{
		ft_putnbr(ft_abs(n / 10));
		ft_putnbr(ft_abs(n % 10));
	}
	else
		ft_putchar('0' + ft_abs(n));
}
