/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 12:16:15 by iwillens          #+#    #+#             */
/*   Updated: 2020/04/14 21:39:32 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int g_error_number;

int		exit_program(t_game *game, int ret_value)
{
	mem_freemap(game);
	mem_freerays(game);
	mem_freescreen(game);
	mem_free_filedata(game);
	mem_free_textures(game);
	exit(ret_value);
}

int		start_program(t_game *game)
{
	init_position(game);
	if (!(load_file(game, game->file.filename)) ||
		!(init_default(game)) ||
		!(init_textures(game)))
		return (0);
	mem_allocsprites(game);
	window_init(&game->screen);
	return (1);
}

/*
** returns 1 to run the game
** returns 2 to save the file
*/

int		check_args(t_game *game, int argc, char **argv)
{
	if (argc <= 1)
		g_error_number = ERR_FILE_INVALIDARG;
	else if (ft_strlen(argv[1]) <= 4 || ft_strncmp(argv[1] +
				(ft_strlen(argv[1]) - 4), ".cub", 4) != 0)
		g_error_number = ERR_FILE_INVALIDFNAME;
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6) != 0)
		g_error_number = ERR_INVALID_SEC_ARG;
	if (g_error_number)
		return (0);
	game->file.filename = argv[1];
	return (argc - 1);
}

int		main(int argc, char **argv)
{
	t_game	game;
	int		args;

	if (!(game.screen.mlx = mlx_init()))
	{
		g_error_number = ERR_MLX;
		error_show(&game, GAME_CLOSE_NOCLEAR);
	}
	args = check_args(&game, argc, argv);
	if (!(args))
		error_show(&game, GAME_CLOSE_NOCLEAR);
	if (!(start_program(&game)))
		error_show(&game, GAME_CLOSE_CLEAR);
	calculate_rays(&game);
	setup_hooks(&(game));
	if (args == 2 && !(convert_to_bmp(&game)))
		error_show(&game, GAME_CLOSE_CLEAR);
	if (args == 2)
		exit_program(&game, 0);
	mlx_loop(game.screen.mlx);
	return (0);
}
