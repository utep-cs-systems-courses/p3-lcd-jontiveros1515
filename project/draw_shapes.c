#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_shapes.h"


int left_score = 0;
int right_score = 0;

Rectangle rectangle1;
Rectangle rectangle2;
Circle circle1;

void 
init_shapes()
{
    update_text();
    
    // Rectangle 1
    rectangle1.row = screenHeight/2;
    rectangle1.col = screenWidth / 1.1;
    rectangle1.old_row = screenHeight/2;
    rectangle1.old_col = screenWidth / 1.1;
    rectangle1.height = 50;
    rectangle1.width = 10;

    // Rectangle 2
    rectangle2.row = screenHeight/2;
    rectangle2.col = screenWidth / 8;
    rectangle2.old_row = screenHeight/2;
    rectangle2.old_col = screenWidth / 8;
    rectangle2.height = 50;
    rectangle2.width = 10;

    // Circle
    circle1.y = screenHeight/4;
    circle1.x = screenWidth / 2;
    circle1.old_y = screenHeight/4;
    circle1.old_x = screenWidth / 2;
    circle1.r = 5;
}


void
draw_shapes()
{
    // Draw rectangle1 at its current position
    fillRectangle(rectangle1.col - (rectangle1.width / 2), rectangle1.row - (rectangle1.height / 2), rectangle1.width, rectangle1.height, COLOR_GREEN);

    // Draw rectangle2 at its current position
    fillRectangle(rectangle2.col - (rectangle2.width / 2), rectangle2.row - (rectangle2.height / 2), rectangle2.width, rectangle2.height, COLOR_GREEN);

    // Draw circle1 at the middle top of the screen
    draw_circle(circle1.x, circle1.y, circle1.r, COLOR_RED);

}

void 
move_rectangles(Rectangle* rect, Direction direction) 
{
  // Erase the old rectangle
  fillRectangle(rect->old_col - (rect->width / 2), rect->old_row - (rect->height / 2), rect->width, rect->height, COLOR_BLACK);

  // Update the rectangle's position based on the direction
  if (direction == UP) {
    rect->row -= 10; // Move up by 5 pixels
  } else if (direction == DOWN) {
    rect->row += 10; // Move down by 5 pixels
  }

  // Make sure the rectangle doesn't go out of bounds
  if (rect->row < rect->height / 2) {
    rect->row = rect->height / 2;
  } else if (rect->row > screenHeight - rect->height / 2) {
    rect->row = screenHeight - rect->height / 2;
  }

  // Redraw the updated rectangle
  fillRectangle(rect->col - (rect->width / 2), rect->row - (rect->height / 2), rect->width, rect->height, COLOR_GREEN);

  // Update the old position to the new position for the next move
  rect->old_row = rect->row;
}

void 
draw_circle(int x, int y, int r, u_int color)
{
    // Draw the new circle at the specified position
    for (int dx = -r; dx <= r; dx++)
    {
        for (int dy = -r; dy <= r; dy++)
        {
            if (dx * dx + dy * dy <= r * r)
            {
                drawPixel(x + dx, y + dy, color);
            }
        }
    }
}


void
move_circle(void)
{
  static int x_vel = 2;
  static int y_vel = 5;

  draw_circle(circle1.x, circle1.y, circle1.r, COLOR_BLACK);

  // save current position
  circle1.old_x = circle1.x;
  circle1.old_y = circle1.y;

  // update position
  circle1.x += x_vel;
  circle1.y += y_vel;
  
  // check boundaries, see if rectangle has hit the edges
  if ( (circle1.x + circle1.r) >= screenWidth || (circle1.x - circle1.r) <= 0) {
    // top or bottom hit, reverse x velocity
    x_vel = x_vel * -1;
  }

  // Check for collision with rectangle1
    if (circle1.x + circle1.r >= rectangle1.col - rectangle1.width / 2 &&
        circle1.x - circle1.r <= rectangle1.col + rectangle1.width / 2 &&
        circle1.y + circle1.r >= rectangle1.row - rectangle1.height / 2 &&
        circle1.y - circle1.r <= rectangle1.row + rectangle1.height / 2)
    {
        x_vel = x_vel * -1;
    }

    // Check for collision with rectangle2
    if (circle1.x + circle1.r >= rectangle2.col - rectangle2.width / 2 &&
        circle1.x - circle1.r <= rectangle2.col + rectangle2.width / 2 &&
        circle1.y + circle1.r >= rectangle2.row - rectangle2.height / 2 &&
        circle1.y - circle1.r <= rectangle2.row + rectangle2.height / 2)
    {
        x_vel = x_vel * -1;
    
  }
  if ( ( circle1.y - circle1.r ) <= 0 ||            // left boundary
       ( circle1.y + circle1.r ) >= screenHeight ) { // right boundary
    // right or left hit, reverse y velocity
    y_vel = y_vel * -1;
  }

   // check if circle has hit left or right boundaries
  if((circle1.x + circle1.r) >= screenWidth) { 
    reset_circle();
    left_score++;

  }
  if((circle1.x - circle1.r) <= 0){/
    reset_circle();
    right_score++;

  }

  draw_circle(circle1.x, circle1.y, circle1.r, COLOR_RED);
}

void 
reset_circle()
{

    circle1.y = screenHeight/4;
    circle1.x = screenWidth / 2;
    circle1.old_y = screenHeight/4;
    circle1.old_x = screenWidth / 2;
    circle1.r = 5;
    draw_circle(circle1.x, circle1.y, circle1.r, COLOR_RED);
}

void
update_text()
{
  const u_char text_row = 20;
  const u_char text_col = 40;
  const u_char char_width = 12;
  static u_char blue = 31, green = 16, red = 31;
  u_int on_color  =                (green << 5) | red;
  u_int off_color = (blue << 11)                | red;

  drawChar5x7(text_col, text_row, left_score+'0',on_color, COLOR_BLACK);
  drawChar5x7(text_col + char_width, text_row, right_score+'0',on_color, COLOR_BLACK);
  
}