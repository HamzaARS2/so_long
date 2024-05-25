#include "so_long.h"

t_event render_game(mlx_t *mlx, t_map *map)
{
    t_player *player;
    t_event event;
    t_components components;

    player = load_player(mlx, get_starting_pos(map->grid));
    components = load_components(mlx);
    render_map(mlx, map, components);
    render_player(mlx, player);
    return ((t_event){mlx, player, map, components});
}