/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_rt_prototype.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:12:19 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/01 17:32:40 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_RT_PROTOTYPE_H
# define CORE_RT_PROTOTYPE_H

# include <math.h>
# include "librt.h"
# include "libobj.h"
# include "read_prototype.h"
# include "col_prototype.h"
# include "core_rt_struct.h"
# include <pthread.h>
# include <stdlib.h>
# include "libft.h"
# include <SDL.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

void					*start_primary_rays(void *info);
int						init_buff(t_options *opts, t_colour ***buff);
int						init_thread_info(t_thread_info thread_info[THREAD_NUM],
		t_thread_info main_info, char *str);
int						init_scene_info(char *file, t_scene_info *scene_info);
int						show_progress_bar(int progress, char *title);
int						sdl_render(t_colour **buff, t_options opts);
void					show_render_progress(t_thread_info
		thread_info[THREAD_NUM], t_options opts);
t_colour				find_colour(t_ray ray, t_scene_info info);
t_intsect_info			trace_ray(t_ray *ray, t_object *obj_list);
typedef int				(*t_intsct_fnc)(t_ray *ray, void *ptr);
typedef void			(*t_s_info_fnc)(t_ray *ray, t_intsect_info *info);
typedef	t_light_info	(*t_l_info_fnc)(t_intsect_info *info, void *ptr);
typedef	t_colour		(*t_grey_mask_fnc)(t_colour col);
#endif
