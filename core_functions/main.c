/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 11:37:28 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/01 17:34:37 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_rt_prototype.h"

int		error_checks(t_thread_info *main_info, int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl("No file given, usage: ./RT file");
		return (-1);
	}
	if ((init_scene_info(argv[1], &main_info->scene_info)) == -1)
		return (-1);
	main_info->opts = main_info->scene_info.opts;
	if (init_buff(&(main_info->opts), &(main_info->buff)) == -1)
	{
		ft_putendl("Could not initalize buffer.");
		return (-1);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_thread_info	main_info;
	t_thread_info	thread_info[THREAD_NUM];
	pthread_t		thread[THREAD_NUM];
	int				indx;

	indx = -1;
	if (error_checks(&main_info, argc, argv) == -1)
		return (0);
	if (init_thread_info(thread_info, main_info, argv[1]) == -1)
		return (0);
	while (++indx < THREAD_NUM)
		pthread_create(&thread[indx], NULL,
			&start_primary_rays, (void *)&thread_info[indx]);
	show_render_progress(thread_info, main_info.opts);
	indx = -1;
	while (++indx < THREAD_NUM)
		pthread_join(thread[indx], NULL);
	if (main_info.opts.aa > 1)
		col_apply_aa_blend(main_info.buff, main_info.opts);
	ft_putstr("\nFINISHED\n");
	sdl_render(main_info.buff, main_info.opts);
	return (0);
}
