NAME = cub3D

SRCDIR = srcs

OBJDIR = .obj

SRCS = main.c \
	check_map.c \
	cleaning_functions.c \
	color_and_textures.c \
	detect_walls.c \
	drawing_functions.c \
	error_management.c \
	hook_functions.c \
	init_program.c \
	map_utils.c \
	map_scan.c \
	move_functions.c \
	ray_caster.c \
	read_cub_file.c \
	save_view_as_bmp.c \
	sprite_caster.c \
	utils.c

OBJS =			$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

DPDCS =			$(OBJS:.o=.d)

INCLUDES =		-I include/ -I libft/include/

LIB =			libft/libft.a

CFLAGS =		-Wall -Wextra -Werror

LIBX_FLAGS =	-Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT_FLAGS =	-Llibft -lft

opti:
	@make -j all

all : 
	@printf "[libft] " && make -C libft
	@printf "[mlx] " && make -C mlx
	@make $(NAME)

-include $(DPDCS)

$(NAME) : $(OBJS) $(LIB)
	@printf "[$(NAME)] "
	@gcc $(CFLAGS) $(LIBX_FLAGS) $(LIBFT_FLAGS) $(OBJS) -o $(NAME)
	@echo Compiled $(NAME) successfully !
	@echo $(NAME) > .gitignore

$(OBJDIR)/%.o : $(SRCDIR)/%.c | $(OBJDIR)
	gcc $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

$(OBJDIR) :
	@mkdir -p .obj

norme :
	#@make norme -C libft
	@(norminette srcs/*.c)
	@(norminette include/*.h)

clean :
	@(rm -rf $(OBJDIR))
	@(make clean -C libft)

cleanlib :
	@(make fclean -C libft)

fclean : cleanlib clean
	@(rm -rf $(NAME))
	@(rm -f libft.a)
	@(rm -rf a.out.dSYM)
	@(rm -f a.out)

re :
	@make fclean
	@make opti
