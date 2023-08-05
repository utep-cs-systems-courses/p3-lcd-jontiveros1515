#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "stateMachine.h"
#include "lcdutils.h"
#include "lcddraw.h"


void main(void)
{
  configureClocks();
  enableWDTInterrupts();
  buzzer_init();
  lcd_init();
  switch_init();
  clearScreen(COLOR_BLUE);
  drawTempo(60);
  drawTime();

  or_sr(0x18);  // CPU off, GIE on
}
