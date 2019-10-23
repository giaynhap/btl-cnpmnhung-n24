



#include "sound.h"
#define BUILD 
typedef char string[16];
class BaseGame{
  public:
  virtual void draw()=0;
  virtual void loop()=0;
  virtual void input()=0;
  virtual void reset()=0;
  virtual int sc_ori()=0;
  
};


class FlappyBird:BaseGame{
  public:
   void draw();
   void loop();
   void input();
   void reset();
   void death();
   void gameover();
   int sc_ori(){
      return 1;
   };
   private:
    float bird_pos[2]= {0,0},flap = 0;
    float speed = 1;
    float box_pos[2]={49,50};
    char gamestt = 0;
    char diem=0;
};

class Dashboard:BaseGame{
  public:
   void draw();
   void loop();
   void input();
   void select();
   void reset();
  
   int sc_ori(){
      return 1;
   };
   private:
   char forcus = 0;
   string items[4] = {"Dino Trex","Flappybird","Snake","PlanesBattle"};
   char num_item = 4;
};

typedef struct enemy_dino{
  int x;
  int y;
  u8g_uint_t type = 0;
  
  
};
#define NUM_ENEMY_DINO 3
class Dino:BaseGame{
  public:
  void draw();
  void loop();
  void input();
  void reset();
  void jump();
  void randomEnemy(u8g_uint_t);
  void drawEntry();
  void drawEnemy(int x, int y ,int type );
  char collect(int x,int y ,char w,char h,int x2,int y2 ,char w2,char h2);
  char collectEnemy(int enemy);
   int sc_ori(){
      return 0;
     };
    private:
    float dino_pos[2] = {2,20};
    char frame = 0;
    char max_y = 32;
    char status = 0 ;
    char dino_vecy=0;
    float random_blox = 0;
    float gamespeed = 4;
    enemy_dino enemy[NUM_ENEMY_DINO];
    char lastx = 0;
    char cpu_time = 0;
    int score =0;
    int gamestate =0;
    long timex = millis();
    int addspeed =0;
};

  typedef struct duoi{
    char x;
    char y;
   }
   duoi_t;
  
class Snake:BaseGame{
  public:
   void draw();
   void loop();
   void input();
   void select();
   void reset();
   void death();
   void move();
   char collect(int x,int y ,char w,char h,int x2,int y2 ,char w2,char h2);
  void setCorss();
 
  
   int sc_ori(){
      return 0;
   };
   private:
   float speed=0.4;
   float snake_pos[2]= {12,21},flap = 0;
   float gamestt=0;
   char diem=0;
   int length=0;
   float food_pos[2]={12,36};
   int chieu = 0;
   float gameover;
   duoi_t duoiran[120];
   int n=0;
  
   
};

extern int rotate;


typedef struct enemy_str{
  int x;
  int y;
  u8g_uint_t type = 0;
} enemy_str_t;
typedef struct fire_str{
  int x;
  int y;
  u8g_uint_t type = 0;
} fire_str_t;
#define NUM_AMMO  20
#define NUM_MONSTER 5
class PlanesBattle:BaseGame{
  public:
   void draw();
   void loop();
   void input();
   void reset();
   void death();
   void gameover();
    char collect(int x,int y ,char w,char h,int x2,int y2 ,char w2,char h2);
   int sc_ori(){
      return 1;
   };
   private:
    float speed = 2;
    u8g_uint_t num_monster = 4;
    float plane_pos[2] = {28, 110};
    float monster_pos[2] ={50, -8};
    enemy_str_t monsters[NUM_MONSTER];
    fire_str_t fires[NUM_AMMO];
    char gamestt = 0;
    int score = 0;
    char plane_vector  = 0;
    size_t recode = millis();
    size_t recode2 = millis();
};
