#include "so_long.h"

t_event *render_game(mlx_t *mlx, t_map *map)
{
    t_player *player;
    t_event *event;

    event = malloc(sizeof(t_event));
    if (!event)
        return (NULL);
    event->mlx = mlx;
    event->map = map;
    event->player = load_player(mlx, get_starting_pos(map->grid));
    event->components = load_components(mlx);
    if (!event->components)
    {
        clean_resources(event);
        exit(1);
        return (NULL);
    }
    render_map(mlx, event->map, event->components);
    render_player(mlx, event->player);
    return (event);
}