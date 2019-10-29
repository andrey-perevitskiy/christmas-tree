#ifndef NCURAPI_H
#define NCURAPI_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ncurses.h>

#define random(min, max) (min + rand() % (max - min + 1))

#define TRUNK_HEIGHT_MIN 2
#define TRUNK_HEIGHT_MAX 4

#define GARLAND_RISE 2
#define GARLAND_SYM 'O'

#define TREE_TIP_SIZE_MIN 3
#define TREE_TIP_SIZE_MAX 5
#define TREE_PARTS_MIN 2
#define TREE_PARTS_MAX 6
#define TREE_PARTS_SIZE_OFFSET 5

struct triangle {
    int x;
    int y;
    char sym;

    /* Compress coefficient.
     * Doesn't know what for it may be used  :\ */
    int k;

    int size;
    bool base;
    bool fill;
    int *line;
};

struct trunk {
    int x;
    int y;
    char sym;
    int thickness;
    int height;
};

struct tree {
    int x;
    int y;
    char sym;
    int k;
    int count;
    bool garland;
    struct triangle *tr;
    struct trunk *tru;
};

void pos_set(int x, int y);
void sym_set(char sym, int x, int y);
bool colors_check(void);
void color_on(int index);
void color_off(int index);

bool colors_support;

#endif /* NCURAPI_H */
