/*
** EPITECH PROJECT, 2022
** Sokoban
** File description:
** arg_options
*/
#include "../include/my.h"

int *move_init(int x, int y)
{
    int *move = malloc(sizeof(int) * 3);

    move[0] = x;
    move[1] = y;
    return (move);
}

char **map_init(char *file)
{
    char **map = malloc(sizeof(char *) * my_text_map_len(file));
    int fd = open(file, O_RDONLY);
    int count = my_text_map_len(file);
    int lines = 0;
    char *buf = malloc(sizeof(char) * count);

    read(fd, buf, count);
    for (int i = 0; i < map_nb_lines(file) + 1; i++)
        map[i] = my_strcpy_line(buf, i);
    free(buf);
    return (map);
}

int map_checker(char *path)
{
    int fd = open(path, O_RDONLY);
    int count = my_text_map_len(path);
    char *buf = malloc(sizeof(char) * count);
    int box = 0;
    int hole = 0;
    int player = 0;

    read(fd, buf, count);
    if (verify_map(buf, count) == 84)
        return (84);
    if (number_objects(count, buf) == 84)
        return (84);
    close(fd);
    free(buf);
    return (0);
}

int help_write(void)
{
    write(1, "USAGE\n\t./my_sokoban map\nDESCRIPTION\n\tmap file repre", 51);
    write(1, "senting the warehouse map, containing '#' for walls,\n \t", 55);
    write(1, "    'P' for the player, 'X' for boxes and 'O' ", 46);
    write(1, "for storage locations.\n", 23);
    return (0);
}

int arg_checker(int argc, char **argv)
{
    if (my_strcmp(argv[1], "-h") == 0)
        return (help_write());
    if (map_checker(argv[1]) == 0) {
        return (game_start(argv[1]));
    } else {
        return (84);
    }
}