#ifndef _DRAW_SHAPES_H_
#define _DRAW_SHAPES_H_


#include <lcdutils.h>

typedef struct 
{
    int row;
    int col;
    int old_row;
    int old_col;
    u_char height;
    u_char width;
} Rectangle;

typedef struct 
{
    int x;
    int y;
    int old_x;
    int old_y;
    int r;
} Circle;

typedef enum {
    UP,
    DOWN
} Direction;

extern Rectangle rectangle1;
extern Rectangle rectangle2;
extern Circle circle1;

void init_shapes();
void draw_shapes();
void move_rectangles(Rectangle* rect, Direction direction);
void draw_circle(int x, int y, int r, u_int color);
void move_circle();
void reset_circle();
void update_text();
#endif