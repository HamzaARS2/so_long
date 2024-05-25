#include "so_long.h"

t_event render_game(mlx_t *mlx, t_map *map)
{
    t_player *player;
    t_event event;

    player = load_player(mlx, get_starting_pos(map->grid));
    render_map(mlx, map);
    render_player(mlx, player);
    return ((t_event){mlx, player, map});
}