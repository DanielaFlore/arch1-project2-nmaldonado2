#include <stdlib.h>
#include <msp430.h>
#include "led.h"
#include "simon.h"
#include "llist.h"
#include "led_configs.h"

void light_num(char num){
  if (num == 1) {
    timed_green_on(100);
  }
  else {
    timed_red_on(100);
  }
}

void light_on_based_on_num(List *list){
  Item *curr = list->root;
  while (curr && curr->next) {
    light_num(curr->btn_num);
    curr = curr->next;
  }

  char new_light = rand() % (2) + 1;
  if (!curr) {
    add_new_head(list, new_light);
  }
  else {
    add_item_after(curr, new_light);
  }
  light_num(new_light);
}

void play_simon() {
  List *light_pattern = init_llist();
  int i = 5;
  while(i-- > 0) {
    light_on_based_on_num(light_pattern);
 
    
    
  }

  free_history(light_pattern);
}
