
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 #include "U8glib.h"

 
void FlappyBird::draw()
{
   
// drawString(10,20,"Hello");
// drawBitmap(bird3,40,80,16,45);
  if (gamestt==1) {
    setFont(u8g_font_baby);
    this->gameover();
    return;
  }
  
  if (gamestt==-1){
      setFont(u8g_font_baby);
      drawString(1,50,"Press A to flap");
  }
  setFont(u8g_font_9x15B);
  char strDiem[4];
  sprintf(strDiem,"%d",diem);
   
   drawString(30,20,strDiem);
 
 if (flap>-1){
  drawBitmap(bird, bird_pos[0], bird_pos[1],16,16);
 }  
 else{
  drawBitmap(bird2, bird_pos[0], bird_pos[1],16,16);
 }

 drawBox( box_pos[0] ,0 ,15,box_pos[1]-20);
 drawBox( box_pos[0] ,box_pos[1]+20 ,15,128);
 drawLine( 0,120,64,120);
 


 
}



  void FlappyBird::loop(){
if (gamestt==1 || gamestt==-1) {
  return;
  }
    if (bird_pos[1]<128)
        {
           bird_pos[1]+=(1- flap)*speed;
          
        }else{
          bird_pos[1] = 127;
        }
        if (flap> -3){
          flap-=1*speed;
        }

        if (box_pos[0]<-20)
        {
          box_pos[0]=64;
          box_pos[1]=40+  rand() % 48;
          diem++;
          
        }
        box_pos[0]-=1*speed;
        if (  (box_pos[1]-20>=bird_pos[1] || box_pos[1]+20<=bird_pos[1]+10 )  &&  ( box_pos[0]<bird_pos[0]+10&& bird_pos[0]<box_pos[0]+15) || (bird_pos[1]>=110 ) ){
          
            this->death();
        }


         
        
  }
  void FlappyBird::input(){
     int buttonState = digitalRead(2);
      if (buttonState == HIGH){
         flap = 5;
         tone(7,NOTE_D8, 50);
         if (gamestt==-1)
         gamestt=0;
   
      }else
      if ( digitalRead(3) == HIGH){
         reset();
      }else if ( digitalRead(4) == HIGH) {
       screen = (BaseGame *)dashboard;
       }
  }
  void FlappyBird::reset(){
    this->gamestt=-1;
    flap =0 ;
    box_pos[0]=64;
    diem = 0;
    bird_pos[1] = 20;
    bird_pos[0] = 0;
  }
 
 void FlappyBird::death(){
    this->gamestt=1;
      tone(7,NOTE_B0, 500);
 
  }
 
void FlappyBird::gameover(){
  drawString(10,50,"gameover");
  char strDiem[32];
  sprintf(strDiem,"Score: %d",diem);
  drawString(10,40,strDiem);
  
  
    
}
