void Dino::input(){
  if ( digitalRead(2) == HIGH){
      if (gamestate==0){
        gamestate = 1;
      }
      else{
        if (gamestate!=2)
         jump();
      }
 }else
 if ( digitalRead(3) == HIGH){
         reset();
 }
 else
 if ( digitalRead(4) == HIGH){
          screen = (BaseGame *)dashboard;
    }  
}

void Dino::loop(){
  if (max_y>dino_pos[1]){
    dino_pos[1]+=(2-dino_vecy*2);
    addspeed=2;
     
  }
  if (max_y < dino_pos[1] )
  {
    dino_pos[1] = max_y;
    status = 0;
    dino_vecy = 0;
    addspeed = 0;
  }
  
  if (status==0){
    frame++;
    if (frame>5)
    {
      frame = 0;
    }
  }else{
    frame = (dino_vecy>0)?1:0;
  }
  if (gamestate == 1){
    for (int i =0 ;i< NUM_ENEMY_DINO ;i++){
      
      enemy[i].x-=1*(gamespeed+addspeed);
      if ( enemy[i].x<-10){
        randomEnemy(i);
        enemy[i].x = enemy[lastx].x+120;
        lastx = i;
      }
      if ( enemy[i].type>0){
        if (collectEnemy(i) == 1){
            gamestate = 2;
            tone(7,NOTE_B0, 500);
            return;
        }
      }
    }
    if (random_blox>-120)
    {    
      random_blox -= 1*(gamespeed+addspeed);
    }
    else {
      random_blox = 128+rand()%100+ (gamespeed-5)*5;
    }
     if(millis()-timex>500){
        timex = millis();
        score++;
        
      }
  }
 
  if (cpu_time==1){
    cpu_time = 0;
     if (dino_vecy>-2){
      dino_vecy--;
    }
 
  }
  cpu_time++;
 
  delay(20);
}

void Dino::jump(){
  if (status==0){
    dino_pos[1] -=2;
    dino_vecy = 6;
    status = 1;
     tone(7,NOTE_D8, 50);
  }
}
void Dino::drawEnemy(int x, int y ,int type ){

 if (x>128)
 return;
 int size =-2;
 char next = 6;
 if (type==1){
  size = -2;
  y+=2;
 }
 else if (type==2){
  size = 0;
 
 }
  else if (type==3){
  size = 2;
   y-=2 ;
 }
 else if (type==4){
   size = 6;
   y-=6 ;
 }
 if (x>next)
  drawLine(x+0,y+6,x+0,y+12+size);
 if (x+2>next){
  drawLine(x+2,y+12,x+2,y+16+size);
  drawLine(x+2,y+1,x+2,y+8+size);

 }
 if (x+1>next){
  drawPixel(x+1,y+5);
  drawPixel(x+1,y+12+size);
 }
 if (x+4>next){
  drawLine(x+3,y+0,x+4,y+0);
 }
 if (x+5>next){
   drawLine(x+5,y+11+size,x+5,y+16+size);
   drawLine(x+5,y+1,x+5,y+8+size);
     drawLine(x+2,y+17+size,x+5,y+17+size);
 }
 if (x+6>next){
   drawPixel(x+6,y+3);
   drawPixel(x+6,y+11+size);
 }
 if (x+7>next)
 {
  drawPixel(x+7,y+4);
  drawPixel(x+7,y+10+size);
 }
 if (x+8>next)
 {
  drawLine(x+8,y+5,x+8,y+9+size);
 }
  
}
void Dino::drawEntry(){

drawLine(random_blox,57,random_blox+5,57);
drawLine(random_blox+68,58,random_blox+70,58);
drawLine(random_blox-10,58,random_blox-8,58);
drawVLine(0,55,1);

}
char Dino::collectEnemy(int e){
  int x = enemy[e].x;
  int y = enemy[e].y;
  char w = 8;
  char h = 17;
  if (enemy[e].type==1){
    h-=2;
    y-=2;
  }else if (enemy[e].type==3){
    h+=2;
    y+=2;
  }else if (enemy[e].type==4){
    h+=6;
    y+=6;
  }
  
  return collect(x,y,w,h,dino_pos[0],dino_pos[1],20,20);
 
}
void Dino::draw(){


  if (gamestate==2){
    setFont(u8g_font_9x15B); 
   drawString(20,20,"Game over");
   setFont(u8g_font_baby);
     drawString(30,30,"Press B to restart");
  }else if (gamestate==0){
     setFont(u8g_font_baby);
    drawString(30,30,"Press A to start");
  }
     setFont(u8g_font_baby);

  char strDiem[16];
  sprintf(strDiem,"Score:%d",score);
  drawString(80,10,strDiem);
  drawEntry();

  
 for (int i =0 ;i< NUM_ENEMY_DINO ;i++){
    if (enemy[i].type>0){
       drawEnemy( enemy[i].x, enemy[i].y, enemy[i].type);
    }
  }
  if (frame>2){
    drawBitmap(dino1, dino_pos[0], dino_pos[1],24,24);
  }
  else{
    drawBitmap(dino2, dino_pos[0], dino_pos[1],24,24);
  }

 
 
}

void Dino::randomEnemy(u8g_uint_t i){
 
   enemy[i].y = 55 - 17;
   enemy[i].type = 1+ rand()%3;
}
void Dino::reset(){
  int start = 128;
  gamestate = 0 ;
   score = 0 ;
   status = 0;
   
  for (int i =0 ;i< NUM_ENEMY_DINO ;i++){
    enemy[i].x = 0;
     randomEnemy(i);
     enemy[i].x+=start+i*120;
     lastx = i;
  }
}
char Dino::collect(int x,int y ,char w,char h,int x2,int y2 ,char w2,char h2){
  if (x <x2+w2 && x+w >x2 &&  y  < y2+h2  && y+h >y2){
    return 1;
  }
  return 0;
}
