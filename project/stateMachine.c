#include <msp430.h>
#include "stateMachine.h"
#include "switches.h"
#include "draw_shapes.h"

void state_advance(int state){
 switch (state) {
    case 1:
      move_rectangles(&rectangle1, UP);
      break;
    case 2:
      move_rectangles(&rectangle1, DOWN);
      break;
    case 3:
      move_rectangles(&rectangle2, UP);
      break;
    case 4:
      move_rectangles(&rectangle2, DOWN);
      break;
    default:
      break;
  }
}
