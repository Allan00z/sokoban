/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-mysokoban-allan.branco
** File description:
** case_gest
*/
#include "../include/my.h"
char **case_o_manager(char **map, int x, int y, pos_t P_Pos)
{
    char c;
    char temp;

    if (map[P_Pos.x + x + x][P_Pos.y + y + y] == 'O') {
        temp = map[P_Pos.x][P_Pos.y];
        map[P_Pos.x][P_Pos.y] = ' ';
        c = map[P_Pos.x + x][P_Pos.y + y];
        map[P_Pos.x + x][P_Pos.y + y] = temp;
        map[P_Pos.x + x + x][P_Pos.y + y + y] = c;
    }
    map = push_the_box(map, x, y, P_Pos);
    return (map);
}

void print_map_or_warn(char *file, char **map)
{
    if (LINES < map_nb_lines(file) || COLS < my_strlen(map[0]))
        printw("La fenetre n'est pas assez grande !");
    else {
        for (int i = 0; i < map_nb_lines(file); i++)
            printw(map[i]);
    }
}

int verify_map(char *buf, int count)
{
    for (int i = 0; i < count; i++) {
        if (buf[i] != '#' && buf[i] != 'P' && buf[i] != 'X' && buf[i] != ' '
        && buf[i] != 'O' && buf[i] != '\n' && buf[i] != '\0')
            return (84);
    }
    return (0);
}

void gest_end_game(char *file, char **map)
{
    clear();
    for (int i = 0; i < map_nb_lines(file); i++)
        printw(map[i]);
    refresh();
    endwin();
}

int number_objects(int count, char *buf)
{
    int hole = 0;
    int player = 0;
    int box = 0;

    for (int i = 0; i < count; i++) {
        if (buf[i] == 'X')
            box++;
        if (buf[i] == 'O')
            hole++;
        if (buf[i] == 'P')
            player++;
    }
    if (box != hole || player != 1)
        return (84);
    return (0);
}