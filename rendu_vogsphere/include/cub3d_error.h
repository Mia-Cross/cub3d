/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:44:12 by lemarabe          #+#    #+#             */
/*   Updated: 2020/02/27 17:12:52 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_ERROR_H
# define CUB3D_ERROR_H

# define EXIT_MSG "\t------------\n\nBye-bye cub3D, see you soon :)\n\n"
# define BMP_EXIT_MSG "You can now find <first_view.bmp> in your repo :)\n"

# define MALLOC_ERR "Memory allocation failed somewhere...\n"
# define MLX_INIT_ERR "Mlx_init failed :(\n"
# define WINDOW_ERR "Couldn't open window :(\n"
# define XPM_ERR "Could not convert xpm file to mlx image\n"
# define DATA_ADDR_ERR "Could not get data address\n"
# define NEW_IMG_ERR "Failed to create new_image :(\n"
# define MISS_ARG_ERR "Missing a map file :(\n"
# define CUB_EXT_ERR "Map file is not .cub !\n"
# define INVALID_FILE_ERR "Couldn't open map file :(\n"
# define MULT_ARGS_ERR "Too many arguments !\n"
# define SAVE_ARG_ERR "2nd argument is not --save !\n"

# define MISS_MAP_ERR "File doesn't contain a map :(\n"
# define NO_PLAYER_ERR "Invalid map >> no player >.<\n"
# define MULT_PLAYER_ERR "Invalid map >> more than one player >.<\n"
# define INVALID_CHAR_ERR "Invalid map >> contains invalid character >.<\n"
# define EMPTY_LINE_ERR "Invalid map >> empty line >.<\n"
# define N_SIDE_ERR "Invalid map >> NORTH side not closed >.<\n"
# define S_SIDE_ERR "Invalid map >> SOUTH side not closed >.<\n"
# define W_SIDE_ERR "Invalid map >> WEST side not closed >.<\n"
# define E_SIDE_ERR "Invalid map >> EAST side not closed >.<\n"

# define RES_ERR "Invalid resolution\n"
# define N_KEY_ERR "NORTH texture is invalid\n"
# define SO_KEY_ERR "SOUTH texture is invalid\n"
# define W_KEY_ERR "WEST texture is invalid\n"
# define E_KEY_ERR "EAST texture is invalid\n"
# define SP_KEY_ERR "SPRITE texture is invalid\n"
# define FLOOR_ERR "Invalid color for FLOOR\n"
# define CEIL_ERR "Invalid color for CEILING\n"
# define MISS_RES_ERR "Resolution is missing\n"

# define DD_RES_ERR "Resolution : multiple definition\n"
# define DD_N_KEY_ERR "NORTH texture : multiple definition\n"
# define DD_SO_KEY_ERR "SOUTH texture : multiple definition\n"
# define DD_W_KEY_ERR "WEST texture : multiple definition\n"
# define DD_E_KEY_ERR "EAST texture : multiple definition\n"
# define DD_SP_KEY_ERR "SPRITE texture : multiple definition\n"
# define DD_FLOOR_ERR "FLOOR : multiple definition\n"
# define DD_CEIL_ERR "CEILING : multiple definition\n"
# define UNKNOWN_KEY_ERR "Unknown parameter ¯\\_(ツ)_/¯\n"

# define MISS_N_KEY_ERR "NORTH texture is missing\n"
# define MISS_SO_KEY_ERR "SOUTH texture is missing\n"
# define MISS_W_KEY_ERR "WEST texture is missing\n"
# define MISS_E_KEY_ERR "EAST texture is missing\n"
# define MISS_SP_KEY_ERR "SPRITE texture is missing\n"
# define MISS_FLOOR_ERR "FLOOR color is missing\n"
# define MISS_CEIL_ERR "CEILING color is missing\n"

#endif
