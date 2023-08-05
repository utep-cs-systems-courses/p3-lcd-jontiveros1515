#include <stdio.h>
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "stateMachine.h"

char beatmax = 3;
char beat = 3;
void advanceState(){
  if (beat>=beatmax){ 
    buzzer_set_period(1000);
    beat=0;
  }
  else{
    buzzer_set_period(2000);
    beat++;
  }
}
void increaseBeatMax(){
  if(beatmax<6){
    beatmax++;
    drawTime();
  }
}
void decreaseBeatMax(){
  if(beatmax>3){
    beatmax--;
    drawTime();
  }
}

void forloop(int  col, int  row){
  fillRectangle(centerCol-20,centerRow-20, 40, 22, COLOR_BLUE); 
  for(int i = 0; i < 20; i++){
    drawPixel(centerCol+(i*col), centerRow+(i*col), COLOR_PINK);
  }
}


void drawTempo(int tempo){
  char snum[3];
  sprintf(snum, "%d", tempo);
  fillRectangle(screenWidth-64, screenHeight-32, 64, 32, COLOR_BLUE);
  drawString11x16(screenWidth-64, screenHeight-32, snum, COLOR_RED, COLOR_BLUE);
}
void drawTime(){
  fillRectangle(20, screenHeight-32, 20, 32, COLOR_BLUE);
  drawChar11x16(20, screenHeight-33, beatmax+1+'0', COLOR_RED, COLOR_BLUE);
  drawChar11x16(20, screenHeight-16, '4', COLOR_RED, COLOR_BLUE);
}
