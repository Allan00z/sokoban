/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-mysokoban-allan.branco
** File description:
** pos_object
*/
#include "../include/my.h"

int blocked(char **map, int x, int y, pos_t *O_pos)
{
    int block = 2;

    if ((map[x - 1][y] == '#' || map[x - 1][y] == 'X') &&
    (map[x][y - 1] == '#' || map[x][y - 1] == 'X'))
        return (2);
    if ((map[x + 1][y] == '#' || map[x + 1][y] == 'X') &&
    (map[x][y + 1] == '#' || map[x][y + 1] == 'X'))
        return (2);
    if ((map[x + 1][y] == '#' || map[x + 1][y] == 'X') &&
    (map[x][y - 1] == '#' || map[x][y - 1] == 'X'))
        return (2);
    if ((map[x - 1][y] == '#' || map[x - 1][y] == 'X') &&
    (map[x][y + 1] == '#' || map[x][y + 1] == 'X'))
        return (2);
    for (int a = 0; a < O_pos[0].o_nb; a++) {
        if (x == O_pos[a].x && y == O_pos[a].y)
            return (0);
    }
    return (1);
}

int check_loose(char **map, pos_t *O_pos, char *file)
{
    int y = 0;
    int box = 0;
    int block = 0;

    for (int a = 0; a != map_nb_lines(file); y++) {
        if (map[a][y] == 'X' && blocked(map, a, y, O_pos) >= 2) {
            block++;
            box++;
        }
        if (map[a][y] == 'X' && blocked(map, a, y, O_pos) == 0)
            box++;
        if (map[a][y] == 'X' && blocked(map, a, y, O_pos) == 1)
            return (0);
        if (map[a][y] == '\n' || map[a][y] == '\0') {
            a++;
            y = -1;
        }
    }
    return (verify_box(box, block));
}

int win_or_loose(char **map, pos_t *O_pos, char *file)
{
    int nb_o = O_pos[0].o_nb;

    if (check_loose(map, O_pos, file) == 1)
        return (1);
    for (int i = 0; i < nb_o; i++) {
        if (i + 1 == nb_o && map[O_pos[i].x][O_pos[i].y] == 'X')
            return (0);
        if (map[O_pos[i].x][O_pos[i].y] != 'X')
            return (2);
    }
}

pos_t find_char(char **map, char c)
{
    int x = 0;
    int y = 0;
    pos_t C_pos;

    for (x = 0, y = 0; map[x][y] != c; y++) {
        if (map[x][y] == '\n') {
            x++;
            y = -1;
        }
    }
    C_pos.x = x;
    C_pos.y = y;
    return (C_pos);
}

char **check_pos_object(char **map, pos_t *O_pos)
{
    int nb_o = O_pos[0].o_nb;
    for (int a = 0; a < nb_o; a++) {
        if (map[O_pos[a].x][O_pos[a].y] == ' ')
            map[O_pos[a].x][O_pos[a].y] = 'O';
    }
    return (map);
}