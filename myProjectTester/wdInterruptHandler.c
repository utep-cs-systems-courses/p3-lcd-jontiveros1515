#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "stateMachine.h"

int count = 0;
char count2 = 1;
float tempo = 60;
void __interrupt_vec(WDT_VECTOR) WDT(){
  if (count>=(250/(tempo/30))){
    advanceState2();
    if(count2>=2){
      advanceState();
      count2=0;
    }
    count = 0;
    count2++;
  }
  if (count==10){
    buzzer_set_period(10);
  }
  count++;
}
void increaseTempo(){
  if (tempo<100){
    tempo+=5;
    drawTempo((int)tempo);
  }
}
void decreaseTempo(){
  if (tempo>30){
    tempo-=5;
    drawTempo((int)tempo);
  }
}
