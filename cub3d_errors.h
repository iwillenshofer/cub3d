/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_errors.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 01:24:56 by iwillens          #+#    #+#             */
/*   Updated: 2020/04/14 21:15:33 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_ERRORS_H
# define CUB3D_ERRORS_H

#define ERR_MAP_INVALIDARG 2
#define ERR_FILE_INVALIDARG 3 // no file argument defined
#define ERR_MAP_UNKNOWN_CHAR 4
#define ERR_MAP_LINE_SPACES 5 // spaces after map
#define ERR_MAP_INVALID 6
#define ERR_PLAYER_POS_ALRSET 10 // player position already set
#define ERR_PLAYER_POS_NOTSET 11 // player position not set
#define ERR_TEXTURE_NOLOAD 15 // could not load texture
#define ERR_TEXTURE_INVALID 16 // could not load texture
#define ERR_FILE_PROBLEM 20 // could not open file for write (bmp)
#define ERR_INVALID_SEC_ARG 22 // invalid second argument
#define ERR_FILE_INVALIDFNAME 25
#define ERR_MLX 30

/*
** global variable to simulate the behaviour of errno.
** originally declared in cub3d.c
*/

extern int g_error_number;

#endif