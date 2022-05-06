/*
** EPITECH PROJECT, 2022
** Sokoban
** File description:
** sokoban_main
*/
#include "../include/my.h"

int find_char_nb(char **map, char *file, char c)
{
    int nb_char = 0;
    int a = 0;

    for (int i = 0; i <= map_nb_lines(file); a++) {
        if (map[i][a] == c)
            nb_char++;
        if (map[i][a] == '\n') {
            i++;
            a = -1;
        }
    }
    return (nb_char);
}

int setup_ncurses(char **map, pos_t *O_pos, char *file)
{
    initscr();
    curs_set(0);
    noecho();
    raw();
    keypad(stdscr, TRUE);
    clear();
    return (check_loose(map, O_pos, file));
}

pos_t *find_o(char **map, char *file)
{
    int nb_o = find_char_nb(map, file, 'O');
    pos_t *pos_O = malloc(sizeof(pos_t) * (nb_o + 1));
    int a = 0;
    int nb = 0;

    for (int i = 0; i <= map_nb_lines(file); a++) {
        if (map[i][a] == 'O') {
            pos_O[nb].x = i;
            pos_O[nb].y = a;
            pos_O[nb].o_nb = nb_o;
            nb++;
        }
        if (map[i][a] == '\n') {
            i++;
            a = -1;
        }
    }
    return (pos_O);
}

void free_map(char **map, pos_t *O_pos, char *file)
{
    for (int i = 0; i < map_nb_lines(file); i++)
        free(map[i]);
    free(O_pos);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (84);
    else
        return (arg_checker(argc, argv));
}