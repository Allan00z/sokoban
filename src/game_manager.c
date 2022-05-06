/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-mysokoban-allan.branco
** File description:
** game_manager
*/
#include "../include/my.h"

char **push_the_box(char **map, int x, int y, pos_t P_Pos)
{
    char c;
    char temp;

    if (map[P_Pos.x + x + x][P_Pos.y + y + y] == ' ') {
        temp = map[P_Pos.x][P_Pos.y];
        map[P_Pos.x][P_Pos.y] = ' ';
        c = map[P_Pos.x + x][P_Pos.y + y];
        map[P_Pos.x + x][P_Pos.y + y] = temp;
        map[P_Pos.x + x + x][P_Pos.y + y + y] = c;
    }
    return (map);
}

char **switch_char_part_two(char **map, int *pos, pos_t P_Pos, pos_t *O_pos)
{
    char temp;

    if (map[P_Pos.x + pos[0]][P_Pos.y + pos[1]] == 'O') {
        temp = map[P_Pos.x][P_Pos.y];
        map[P_Pos.x][P_Pos.y] = ' ';
        map[P_Pos.x + pos[0]][P_Pos.y + pos[1]] = temp;
    }
    return (map);
}

char **switch_char(char **map, int x, int y, pos_t *O_pos)
{
    char temp;
    char c;
    pos_t P_Pos = find_char(map, 'P');
    int *move = move_init(x, y);

    if (map[P_Pos.x + x][P_Pos.y + y] == ' ') {
        temp = map[P_Pos.x][P_Pos.y];
        map[P_Pos.x][P_Pos.y] = map[P_Pos.x + x][P_Pos.y + y];
        map[P_Pos.x + x][P_Pos.y + y] = temp;
    } else if (map[P_Pos.x + x][P_Pos.y + y] == 'X') {
        case_o_manager(map, x, y, P_Pos);
    } else
        map = switch_char_part_two(map, move, P_Pos, O_pos);
    return (map);
}

char **move_player(char **map, char *file, pos_t *O_pos)
{
    int ch;
    pos_t P_pos = find_char(map, 'P');

    clear();
    print_map_or_warn(file, map);
    ch = getch();
    if (ch == KEY_DOWN)
        map = switch_char(map, 1, 0, O_pos);
    if (ch == KEY_LEFT)
        map = switch_char(map, 0, -1, O_pos);
    if (ch == KEY_UP)
        map = switch_char(map, -1, 0, O_pos);
    if (ch == KEY_RIGHT)
        map = switch_char(map, 0, 1, O_pos);
    if (ch == 32)
        map = map_init(file);
    return (map);
}

int game_start(char *file)
{
    int fd = open(file, O_RDONLY);
    int count = my_text_map_len(file);
    char **map = map_init(file);
    int status = 2;
    pos_t *O_pos = find_o(map, file);

    if (setup_ncurses(map, O_pos, file) == 1)
        status = 1;
    while (status == 2) {
        clear();
        map = move_player(map, file, O_pos);
        map = check_pos_object(map, O_pos);
        status = win_or_loose(map, O_pos, file);
        clear();
        refresh();
    }
    gest_end_game(file, map);
    free_map(map, O_pos, file);
    free(map);
    return (status);
}