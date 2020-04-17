/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_trigonometry.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:49:02 by iwillens          #+#    #+#             */
/*   Updated: 2020/04/14 21:40:19 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** applies the rotation matrix around the vertical angle (z)
** which means 'looking' left or right, according to the following
** rotation matrix formula:
**
** |x'|   |  cos(a)  sin(a)   0 |   | x |
** |y'| = | -sin(a)  cos(a)   0 | * | y |
** |z'|   |    0       0      1 |   | z |
**
** ps: z is ignored in this case as its position does not change.
**
** this function returns a new x or y. If the matrix is to rotate an element
** instead of getting a position just relative to it, in and *out must
** be the same.
**
** As the adopted coordinate system is in degrees and the C Math Lib uses
** radians, a conversion is made:
** (degrees * (PI / 180)) --> deg * 0.01745329252.
*/

void	rotate_horizontal(double a, t_xy in, t_xy *out)
{
	double tmpx;
	double tmpy;
	double radian;

	radian = a * (M_PI / 180);
	tmpx = in.x;
	tmpy = in.y;
	out->x = (cos(radian) * tmpx) + (sin(radian) * tmpy);
	out->y = (-sin(radian) * tmpx) + (cos(radian) * tmpy);
}
