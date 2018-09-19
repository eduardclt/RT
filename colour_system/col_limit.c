/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_limit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 20:53:18 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/01 13:33:04 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "col_prototype.h"

t_colour	col_limit(t_colour col)
{
	t_colour	ret;

	ret.r = ft_clamp(0, 255, col.r);
	ret.g = ft_clamp(0, 255, col.g);
	ret.b = ft_clamp(0, 255, col.b);
	return (ret);
}
