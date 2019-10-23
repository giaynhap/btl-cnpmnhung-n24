#ifdef BUILD
U8GLIB_ST7920_128X64_4X u8g(13,11,10);
#else
U8GLIB_KS0108_128 u8g(8,9,10,11,4,5,6,7,A4,A1,A0,A3,A2);
#endif

 
void setupDevice(){
   
}
void screenRotate(){
  if (rotate==0 ){
    u8g.setRot90(); 
    rotate = 1;
  }
}
void undoRotate(){
   if (rotate==1){
      u8g.undoRotation();
     rotate = 0; 
  }
}
void drawBitmap(uint8_t bmap[],int x,int y,int w,int h){
      u8g.drawXBMP( x, y, w, h, bmap); 
} 
void BeginDraw(){
 
    u8g.firstPage();
   
}

bool EndDraw(){
  return u8g.nextPage();
}
void clearLCD(){
    u8g.firstPage();  
    do {
    } while( u8g.nextPage() );
}

 
void setFont(const u8g_fntpgm_uint8_t *font){
  u8g.setFont(font);
}
void drawString(int x, int y, char content[]){
  u8g.drawStr( x, y, content);
}

void drawBox(int x,int y ,int w,int h){
  u8g.drawBox(x,y,w,h);
}
void drawPixel(int x, int y){
  u8g.drawPixel(x,y);
}
void drawMapPixel(int x,int y){
  u8g.drawBox(x,y,4,3);
}
void drawVLine(u8g_uint_t x, u8g_uint_t y, u8g_uint_t h) {
  u8g.drawLine( 0, y,128,y ); 
 }
 void drawLine(u8g_uint_t x, u8g_uint_t y, u8g_uint_t x2,u8g_uint_t y2) {
  u8g.drawLine( x, y,x2,y2 ); 
 }
