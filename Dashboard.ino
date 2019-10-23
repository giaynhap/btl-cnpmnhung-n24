void Dashboard::draw(){
  setFont(u8g_font_baby);
  drawString(10,20,"GAME MENU");
  for (int i=0;i<num_item;i++){
    drawString(10,50+i*15,items[i]);
    if (forcus == i){
      drawBox(4,45+i*15,5,5);
    }
  }
 
}
void Dashboard::loop(){

  
}
void Dashboard::reset(){
  
}
 
void Dashboard::select(){
 
  switch(forcus){
    case 0:
    screen = (BaseGame *)(dino);
    break;
    case 1:
    screen = (BaseGame *)(flapy);
    break;
     case 2:
    screen = (BaseGame *)(snake);
    break;
      case 3:
    screen = (BaseGame *)(planes);
    break;
  }
 screen->reset();
}


void Dashboard::input(){
 
  if (digitalRead(3) == HIGH){
      forcus += 1;
      if (forcus>=num_item){
        forcus = num_item-1;
      }
       
       tone(7,NOTE_B4, 10);
       chThdSleepMilliseconds(400);
  }
   if (digitalRead(4) == HIGH){
      forcus -= 1;
      if (forcus<0){
        forcus = 0;
      }
      tone(7,NOTE_B4, 10);
      chThdSleepMilliseconds(400);
  }
   if (digitalRead(2) == HIGH){
       select();
       tone(7,NOTE_G3, 10);
       chThdSleepMilliseconds(400);
  }
 
}
