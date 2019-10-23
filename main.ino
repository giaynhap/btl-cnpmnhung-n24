 
SEMAPHORE_DECL(sem, 0);

static THD_WORKING_AREA(waThread1, 32);
static THD_FUNCTION(Thread1, arg) {
  (void)arg;
  while (true) {
    screen->input();
    chThdSleepMilliseconds(10);
  }
}
  
void main_loop(){
    screen->loop();
   if ( screen->sc_ori() == 1 ){
    screenRotate();
   }else{
    undoRotate();
   }
    BeginDraw();
    do {
      screen->draw();
    } while(EndDraw());
  
}

void chSetup() {
 
  chThdCreateStatic(waThread1, sizeof(waThread1),
  NORMALPRIO  , Thread1, NULL);
   
} 
 
