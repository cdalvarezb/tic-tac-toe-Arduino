#include <Adafruit_TFTLCD.h> 
#include <Adafruit_GFX.h>    
#include <TouchScreen.h>

#define LCD_CS A3 
#define LCD_CD A2 
#define LCD_WR A1 
#define LCD_RD A0 
#define LCD_RESET A4 

#define TS_MINX 122
#define TS_MINY 111
#define TS_MAXX 942
#define TS_MAXY 890

#define YP A3
#define XM A2
#define YM 9
#define XP 8

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

int turn, win_Case, numb_Turns;
int SQUARE1,SQUARE2,SQUARE3,SQUARE4,SQUARE5,SQUARE6,SQUARE7,SQUARE8,SQUARE9;
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 364);

boolean buttonEnabled = true; //DEFINE COMO BOTÓN EL CUADRO 1X1
boolean buttonEnabled1 = true;//DEFINE COMO BOTÓN EL CUADRO 1X2
boolean buttonEnabled2 = true;//DEFINE COMO BOTÓN EL CUADRO 1X3
boolean buttonEnabled3 = true;//DEFINE COMO BOTÓN EL CUADRO 2X1
boolean buttonEnabled4 = true;//DEFINE COMO BOTÓN EL CUADRO 2X2
boolean buttonEnabled5 = true;//DEFINE COMO BOTÓN EL CUADRO 2X3
boolean buttonEnabled6 = true;//DEFINE COMO BOTÓN EL CUADRO 3X1
boolean buttonEnabled7 = true;//DEFINE COMO BOTÓN EL CUADRO 3X2
boolean buttonEnabled8 = true;//DEFINE COMO BOTÓN EL CUADRO 3X3

void setup() {
tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  tft.setRotation(1);
  tft.fillScreen(BLUE);
  
    tft.drawRect(0,0,107,80,WHITE);
    tft.drawRect(0,80,107,80,WHITE);
    tft.drawRect(0,160,107,80,WHITE);
    tft.drawRect(107,0,107,80,WHITE);
    tft.drawRect(107,80,107,80,WHITE);
    tft.drawRect(107,160,107,80,WHITE);
    tft.drawRect(214,0,107,80,WHITE);
    tft.drawRect(214,80,107,80,WHITE);
    tft.drawRect(214,160,107,80,WHITE);


}

void loop() 
{

{
  if ((numb_Turns == 0) || (numb_Turns == 2) || (numb_Turns == 4) || (numb_Turns == 6) || (numb_Turns == 8))
  {
    turn = 1; 
  }
  else if ((numb_Turns == 1) || (numb_Turns == 3) || (numb_Turns == 5) || (numb_Turns == 7))
  {
    turn = 2; 
  }


 TSPoint p = ts.getPoint();
 TSPoint p1 = ts.getPoint();
  
  if (p.z > ts.pressureThreshhold) {
    
   p.x = map(p.x, TS_MAXX, TS_MINX,0, 320);
  
   p.y = map(p.y, TS_MAXY, TS_MINY, 0, 240);
       
   if(p.x>0 && p.x<107 && p.y>0 && p.y<80&& buttonEnabled && SQUARE1==0)
   {
   
    if (turn == 1 ) //CASO PARA EL TURNO 1
    {
    buttonEnabled = false;
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    tft.setCursor(35,15);
    tft.setTextColor(BLACK);
    tft.setTextSize(7);
    tft.print("X");
    numb_Turns++;
    SQUARE1=1;
    }

else if (turn == 2 )//CASO PARA EL TURNO 2
   
   {
   buttonEnabled = false;
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    tft.setCursor(35,15);
    tft.setTextColor(BLACK);
    tft.setTextSize(7);
    tft.print("O");
    numb_Turns++;
     SQUARE1=2;
   }
   }
   
    //AQUÍ SE TERMINA PARA EL PRIMER CUADRITO
   
   if (p.x>0 && p.x<107 && p.y>80 && p.y<160 && buttonEnabled1 && SQUARE2==0)
   {
   
   if (turn == 1) //CASO PARA EL TURNO 1
    {
    buttonEnabled1 = false;
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    tft.setCursor(142,15); //ESTO ES LO UNICO QUE CAMBIA DE CUADRO A CUADRO
    tft.setTextColor(BLACK);
    tft.setTextSize(7);
    tft.print("X");
    numb_Turns++;
     SQUARE2=1;
    }

  
   
   else if (turn == 2)  //CASO PARA EL TURNO 2
   {
   buttonEnabled1 = false;
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    tft.setCursor(142,15); //ESTO ES LO UNICO QUE CAMBIA DE CUADRO A CUADRO
    tft.setTextColor(BLACK);
    tft.setTextSize(7);
    tft.print("O");
    numb_Turns++;
     SQUARE2=2;
   }
   }
   

if(p.x>0 && p.x<107 && p.y>160 && p.y<240 && buttonEnabled2 && SQUARE3==0)
   {
  
    if (turn == 1 ) //CASO PARA EL TURNO 1
    {
    buttonEnabled2 = false;
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    tft.setCursor(249,15);
    tft.setTextColor(BLACK);
    tft.setTextSize(7);
    tft.print("X");
    numb_Turns++;
     SQUARE3=1;
    }

else if (turn == 2 )//CASO PARA EL TURNO 2
   
   {
   buttonEnabled2 = false;
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    tft.setCursor(249,15);
    tft.setTextColor(BLACK);
    tft.setTextSize(7);
    tft.print("O");
    numb_Turns++;
     SQUARE3=2;
   }
   }
   
if(p.x>107 && p.x<214 && p.y>0 && p.y<80 && buttonEnabled3 && SQUARE4==0)
   
    if (turn == 1 ) //CASO PARA EL TURNO 1
    {
    buttonEnabled3 = false;
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    tft.setCursor(35,95);
    tft.setTextColor(BLACK);
    tft.setTextSize(7);
    tft.print("X");
    numb_Turns++;
     SQUARE4=1;
    }

else if (turn == 2 )//CASO PARA EL TURNO 2
   
   {
   buttonEnabled3 = false;
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    tft.setCursor(35,95);
    tft.setTextColor(BLACK);
    tft.setTextSize(7);
    tft.print("O");
    numb_Turns++;
     SQUARE4=2;
   }
   }
 
if(p.x>107 && p.x<214 && p.y>80 && p.y<160 && buttonEnabled4 && SQUARE5==0)
 {
  
    if (turn == 1 ) //CASO PARA EL TURNO 1
    {
    buttonEnabled4 = false;
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    tft.setCursor(142,95);
    tft.setTextColor(BLACK);
    tft.setTextSize(7);
    tft.print("X");
    numb_Turns++;
     SQUARE5=1;
    }

else if (turn == 2 )//CASO PARA EL TURNO 2
   
   {
   buttonEnabled4 = false;
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    tft.setCursor(142,95);
    tft.setTextColor(BLACK);
    tft.setTextSize(7);
    tft.print("O");
    numb_Turns++;
     SQUARE5=2;
   }
 }
  
if(p.x>107 && p.x<214 && p.y>160 && p.y<240 && buttonEnabled5 && SQUARE6==0)
{
  
    if (turn == 1 ) //CASO PARA EL TURNO 1
    {
    buttonEnabled5 = false;
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    tft.setCursor(249,95);
    tft.setTextColor(BLACK);
    tft.setTextSize(7);
    tft.print("X");
    numb_Turns++;
     SQUARE6=1;
    }

else if (turn == 2 )//CASO PARA EL TURNO 2
   
   {
   buttonEnabled5 = false;
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    tft.setCursor(249,95);
    tft.setTextColor(BLACK);
    tft.setTextSize(7);
    tft.print("O");
    numb_Turns++;
     SQUARE6=2;
   }
   }

if(p.x>214 && p.x<320 && p.y>0 && p.y<80 && buttonEnabled6 && SQUARE7==0)
{
  
    if (turn == 1 ) //CASO PARA EL TURNO 1
    {
    buttonEnabled6 = false;
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    tft.setCursor(35,175);
    tft.setTextColor(BLACK);
    tft.setTextSize(7);
    tft.print("X");
    numb_Turns++;
     SQUARE7=1;
    }

else if (turn == 2 )//CASO PARA EL TURNO 2
   
   {
   buttonEnabled6 = false;
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    tft.setCursor(35,175);
    tft.setTextColor(BLACK);
    tft.setTextSize(7);
    tft.print("O");
    numb_Turns++;
     SQUARE7=2;
   }
   }

if(p.x>214 && p.x<320 && p.y>80 && p.y<160 && buttonEnabled7 && SQUARE8==0)
{
   
    if (turn == 1 ) //CASO PARA EL TURNO 1
    {
    buttonEnabled7 = false;
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    tft.setCursor(142,175);
    tft.setTextColor(BLACK);
    tft.setTextSize(7);
    tft.print("X");
    numb_Turns++;
     SQUARE8=1;
    }

else if (turn == 2 )//CASO PARA EL TURNO 2
   
   {
   buttonEnabled7 = false;
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    tft.setCursor(142,175);
    tft.setTextColor(BLACK);
    tft.setTextSize(7);
    tft.print("O");
    numb_Turns++;
     SQUARE8=2;
   }
   
}
if(p.x>214 && p.x<320 && p.y>160 && p.y<240 && buttonEnabled8 && SQUARE9==0)
{
   
    if (turn == 1 ) //CASO PARA EL TURNO 1
    {
    buttonEnabled8 = false;
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    tft.setCursor(249,175);
    tft.setTextColor(BLACK);
    tft.setTextSize(7);
    tft.print("X");
    numb_Turns++;
     SQUARE9=1;
    }

else if (turn == 2 )//CASO PARA EL TURNO 2
   
   {
   buttonEnabled8 = false;
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    tft.setCursor(249,175);
    tft.setTextColor(BLACK);
    tft.setTextSize(7);
    tft.print("O");
    numb_Turns++;
     SQUARE9=2;
   }
}
}

 if (((SQUARE1 == 1) && (SQUARE2 == 1) &&( SQUARE3 == 1))||((SQUARE4 == 1) && (SQUARE5 == 1 ) && (SQUARE6 == 1))|| 
((SQUARE7 == 1) && (SQUARE8 == 1) && ( SQUARE9 == 1)) || ((SQUARE1 == 1 )&& (SQUARE4 == 1 ) && ( SQUARE7 == 1)) ||
((SQUARE2 == 1) && (SQUARE5 == 1) && ( SQUARE8 == 1))|| ((SQUARE3 ==1) && (SQUARE6 == 1) &&( SQUARE9 == 1))||
((SQUARE1 == 1 ) && ( SQUARE5== 1) && ( SQUARE9 == 1))|| ((SQUARE3 == 1) && (SQUARE5 == 1 ) && (SQUARE7 == 1)))
{
  
tft.fillScreen(WHITE);
    tft.drawRect(0,0,319,240,YELLOW);
     tft.setCursor(45,70);
    tft.setTextColor(BLACK);
    tft.setTextSize(4);
    tft.print(" PLAYER 1 \n\n    WINS");
    delay(2000);

}

else if (((SQUARE1 == 2) && (SQUARE2 == 2) &&( SQUARE3 == 2))||((SQUARE4 == 2) && (SQUARE5 == 2 ) && (SQUARE6 == 2))|| 
((SQUARE7 == 2) && (SQUARE8 == 2) && ( SQUARE9 == 2)) || ((SQUARE1 == 2 )&& (SQUARE4 == 2 ) && ( SQUARE7 == 2)) ||
((SQUARE2 == 2) && (SQUARE5 == 2) && ( SQUARE8 == 2))|| ((SQUARE3 ==2) && (SQUARE6 == 2) &&( SQUARE9 == 2))||
((SQUARE1 == 2 ) && ( SQUARE5== 2) && ( SQUARE9 == 2))|| ((SQUARE3 == 2) && (SQUARE5 == 2 ) && (SQUARE7 == 2)))

{

  tft.fillScreen(WHITE);
    tft.drawRect(0,0,319,240,YELLOW);
    tft.setCursor(45,70);
    tft.setTextColor(BLACK);
    tft.setTextSize(4);
    tft.print(" PLAYER 2 \n\n    WINS");
    delay (2000);
      
  }

 if (numb_Turns == 9)
  {
    tft.fillScreen(WHITE);
    tft.setCursor(20,100);
    tft.setTextColor(BLACK);
    tft.setTextSize(6);
    tft.print("END GAME");
delay (3000);
  }
}
