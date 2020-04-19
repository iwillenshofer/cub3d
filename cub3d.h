/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 03:24:28 by iwillens          #+#    #+#             */
/*   Updated: 2020/04/19 03:26:50 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"
# include "cub3d_errors.h"

# define BUFFER_SIZE 48

# define PI 3.14159265
# define RADIAN 0.0174533

# define ANGLE_N 0
# define ANGLE_E 90
# define ANGLE_S 180
# define ANGLE_W 270

# define GAME_CLOSE_NOCLEAR 0
# define GAME_CLOSE_CLEAR 1
# define KEY_ESC 65307
# define KEY_A 97
# define KEY_D 100
# define KEY_W 119
# define KEY_S 115
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

/*
** X11 Events
*/

# define X11_KEYPRESS 2
# define X11_DESTROY 17

typedef struct	s_intxy
{
	int x;
	int y;
}				t_intxy;

typedef struct	s_xy
{
	double x;
	double y;
}				t_xy;

typedef struct	s_map
{
	int **worldmap;
	int w;
	int h;
}				t_map;

typedef struct	s_screen
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
	double	fov;
}				t_screen;

typedef struct	s_player
{
	t_xy		pos;
	t_xy		dir;
	double		plane_dist;
}				t_player;

typedef struct	s_sprites
{
	int		type;
	t_intxy	pos;
	t_xy	rel_pos;
	double	angle;
	double	pdist;
	t_xy	sdist;
	t_xy	step;
	t_xy	dir;
	int		wall;
	int		side;
	int		draw_w;
	int		draw_h;
}				t_sprites;

/*
** dir: direction (vector) of the ray (x and y, -1 to 1)
** ddist: (delta distance). according to the direction (angle),
**  how much must be ** traveled in x and y to find the next
**  side of the box. --> Xa = 1/tan(angle);
** step:
*/

typedef struct	s_rays
{
	t_xy		pos;
	t_xy		dir;
	t_xy		ddist;
	t_xy		sdist;
	t_xy		step;
	double		size;
	double		angle_x;
	double		dist;
	double		pdist;
	int			side;
	int			wall;
	int			max_sprites;
	double		*z_buffer;
}				t_rays;

typedef struct	s_textures
{
	char	*img;
	void	*mlx;
	int		width;
	int		height;
	int		bpx;
	int		size_line;
	int		endian;
	int		set;
}				t_textures;

/*
** the keys array shall store the values of the arguments in the file.
** the order of the arguments are to be stored as follows:
** {0: "NO", 1: "SO", 2: "WE", 3: "EA", 4: "R", 5: "S", 6: "F", 7: "C"};
** this order is defined in a constant in the read_textures file.
*/

typedef struct	s_file
{
	char *filename;
	char **data;
	char *keys[5];
}				t_file;

typedef struct	s_game
{
	t_player	player;
	t_map		map;
	t_screen	screen;
	t_rays		rays;
	t_textures	*textures;
	t_file		file;
	t_sprites	*sprites;
	double		rotation_angle;
	double		walk_speed;
	int			color_c;
	int			color_f;
}				t_game;

/*
**	init
*/

void			init_position(t_game *game);
void			window_init(t_screen *screen);
void			init_file(t_file *file);
int				init_default(t_game *game);
int				exit_program(t_game *game, int ret_value);
/*
**	raycasting
*/

void			calculate_rays(t_game *game);
void			write_pixel(t_screen *img, int x, int y, int color);

/*
** mem alloc
*/

void			mem_allocsprites(t_game *game);
int				**bmp_alloc(t_game *game);

/*
** mem free
*/

void			mem_freemap(t_game *game);
void			mem_freerays(t_game *game);
void			mem_free_filedata(t_game *game);
void			mem_freescreen(t_game *game);
void			mem_free_textures(t_game *game);

/*
** trigonometry
*/

void			rotate_horizontal(double a, t_xy in, t_xy *out);

/*
** movement
*/

void			move_up(t_game *game);
void			move_down(t_game *game);
void			move_left(t_game *g);
void			move_right(t_game *g);

/*
** keys
*/

int				get_keystroke(int keycode, t_game *game);
void			setup_hooks(t_game *game);

/*
**	map utils
*/

void			print_map(t_game *game);
void			invert_map(t_game *game);
int				check_borders(t_map *map, t_intxy pos);
int				check_validmap(t_map *map);

/*
**	map
*/

int				read_map(t_game *game);
int				parse_map(t_game *game, int start_map);
int				get_map_char(t_game *game, t_intxy pos, int start_map);

/*
** read_gnl
*/

int				get_next_line(char **line, int fd);
char			*gnl_join(char *s1, char *s2);

/*
** read_file
*/

int				load_file(t_game *game, char *filename);
char			**read_file(char *filename);
int				get_width(char **str, int start, int end);

/*
** textures
*/

int				get_tex_color(t_textures *tex, int x, int y);
void			drawtexture(t_game *game, int x);
int				init_textures(t_game *game);
int				get_texturepixel(t_game *game, int x, int y, int index);

/*
** read textures
*/

int				read_textures(t_game *game);
/*
** error handling
*/

void			error_show(t_game *game, int exit);

/*
** draw sprites
*/

void			clear_sprites(t_game *game);
void			add_sprite(t_game *game, int x, int y);
void			draw_sprites(t_game *game);

/*
** bmp
*/

int				convert_to_bmp(t_game *game);

/*
** gfx utils
*/

int				set_resolution(t_game *game, char *w, char *h);
int				rgb_toint(char *r, char *g, char *b);

#endif
