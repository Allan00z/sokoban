/*
** EPITECH PROJECT, 2022
** Sokoban
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <ncurses.h>
    #include <sys/ioctl.h>

typedef struct position {
    int x;
    int y;
    int o_nb;
}pos_t;

void free_map(char **map, pos_t *O_pos, char *file);
void print_map_or_warn(char *file, char **map);
void gest_end_game(char *file, char **map);

int setup_ncurses(char **map, pos_t *O_pos, char *file);
int arg_checker(int argc, char **argv);
int main(int argc, char **argv);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
int my_text_map_len(char *path);
int help_write(void);
int game_start(char *file);
int map_nb_lines(char *path);
int my_linelen(char const *str);
int win_or_loose(char **map, pos_t *O_pos, char *file);
int find_char_nb(char **map, char *file, char c);
int check_loose(char **map, pos_t *O_pos, char *file);
int *move_init(int x, int y);
int verify_map(char *buf, int count);
int number_objects(int count, char *buf);
int verify_box(int box, int block);

char *my_strcpy_line(char *buf, int lines);
char *my_malloc_str(int len);

char **map_init(char *file);
char **check_pos_object(char **map, pos_t *O_Pos);
char **case_o_manager(char **map, int x, int y, pos_t P_pos);
char **push_the_box(char **map, int x, int y, pos_t P_Pos);

pos_t find_char(char **map, char c);
pos_t *find_o(char **map, char *file);

#endif /* !MY_H_ */
