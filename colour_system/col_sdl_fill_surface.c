/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_SDL_fill_surface.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 13:18:27 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/01 16:49:14 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "col_prototype.h"

int	col_sdl_fill_surface(SDL_Surface *surface, t_colour **buff, t_options opts)
{
	int				w;
	int				h;
	unsigned int	*pix;

	h = -1;
	pix = (unsigned int *)surface->pixels;
	while (++h < surface->h)
	{
		w = -1;
		while (++w < surface->w)
			pix[h * surface->w + w] = col_to_int(buff[h
					* (int)opts.aa][w * (int)opts.aa]);
	}
	return (0);
}
