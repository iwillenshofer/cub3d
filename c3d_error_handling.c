/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_error_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 03:32:14 by iwillens          #+#    #+#             */
/*   Updated: 2020/04/15 07:54:29 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_error(int err)
{
	if (err == ERR_FILE_INVALIDARG)
		return ("no file argument defined");
	else if (err == ERR_MAP_INVALIDARG)
		return ("invalid arguments in map file");
	else if (err == ERR_MAP_UNKNOWN_CHAR)
		return ("unknown character in map");
	else if (err == ERR_MAP_LINE_SPACES)
		return ("line break after map");
	else if (err == ERR_MAP_INVALID)
		return ("unknown character in map");
	else if (err == ERR_PLAYER_POS_ALRSET)
		return ("player position is set more than once in map");
	else if (err == ERR_PLAYER_POS_NOTSET)
		return ("player position has not been set in map");
	else if (err == ERR_TEXTURE_NOLOAD)
		return ("texture could not be loaded");
	else if (err == ERR_TEXTURE_INVALID)
		return ("invalid texture file");
	else if (err == ERR_FILE_PROBLEM)
		return ("could not open file to write BMP");
	else if (err == ERR_INVALID_SEC_ARG)
		return ("second argument is invalid. Try --save");
	else if (err == ERR_FILE_INVALIDFNAME)
		return ("Invalid Filename");
	return ("Unknown error");
}

/*
** exit code >=1 quits the program freing variables
** exit code 0 quits the program without freing variables
** (as none has been malloc'd yet)
*/

void	error_show(t_game *game, int exit_code)
{
	ft_putstr("Error\n*** (");
	ft_putnbr(g_error_number);
	ft_putstr(") --> ");
	ft_putstr(get_error(g_error_number));
	ft_putstr(".\n");
	if (exit_code >= GAME_CLOSE_CLEAR)
		exit_program(game, g_error_number);
	else if (exit_code == GAME_CLOSE_NOCLEAR)
		exit(g_error_number);
}
