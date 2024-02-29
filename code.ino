#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
////////////////////
#include <U8g2lib.h>
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

/////////////////
void setup() 
{
   ///////////////////
  u8g2.begin(); 

  //////////////////
  Serial.begin(9600);
  //Serial1.begin(9600);
   mlx.begin(); }
void loop()
{
u8g2.clearBuffer();
 
 
  mlx.begin(); 
   float body=(mlx.readObjectTempC()+1.99);
     u8g2.setFontDirection(2);
     u8g2.setFont(u8g2_font_pxplusibmvga9_tf);
     u8g2.setCursor(111, 50);
     u8g2.print("AmT=");
     u8g2.print(body);
     u8g2.print(char(176));
     u8g2.print("c");

///////////////////////////////////

//Serial1.print("Ambient="); 
//Serial1.print(mlx.readAmbientTempC()); 
//Serial1.print("----------Object Temperatur=");
//Serial1.print(mlx.readObjectTempC());// Serial.println("*C");
//Serial1.println("  ");

Serial.print("Ambient="); 
Serial.print(mlx.readAmbientTempC()); 
Serial.print("----BODY TemperaturE=");
Serial.print(mlx.readObjectTempC());// Serial.println("*C");
Serial.println("  ");

/////////////////////////////
   

     
     u8g2.setCursor(110, 10);
     u8g2.setFont(u8g2_font_helvB24_tf);
     u8g2.print(mlx.readObjectTempC());
     u8g2.print(char(176));
     u8g2.print("c");
   
////////////////////////////////////////////////////////////
   int val=(map((mlx.readObjectTempC()),-70,382,0,122));
   u8g2.setFlipMode(1);
   u8g2.drawRFrame(118,7,5,57,2);
   u8g2.drawRBox(118, 7,5,val,2);
   u8g2.drawEllipse(120, 5, 5, 5, U8G2_DRAW_ALL);
    
   u8g2.drawFilledEllipse(120, 5, 3, 3, U8G2_DRAW_ALL);
   u8g2.sendBuffer();
////////////////////////////////////////////////////////////

  } 
