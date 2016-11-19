/*************************************************** 
  This is a library for our I2C LED Backpacks

  Designed specifically to work with the Adafruit LED Matrix backpacks 
  ----> http://www.adafruit.com/products/872
  ----> http://www.adafruit.com/products/871
  ----> http://www.adafruit.com/products/870

  These displays use I2C to communicate, 2 pins are required to 
  interface. There are multiple selectable I2C addresses. For backpacks
  with 2 Address Select pins: 0x70, 0x71, 0x72 or 0x73. For backpacks
  with 3 Address Select pins: 0x70 thru 0x77

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

void setup() {
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");
  matrix.begin(0x70);  // pass in the address
  

}

static const uint8_t PROGMEM
  
  row1[] =
  { 
  B00000000,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111 },
  row2[] =
  { 
  B00000000,
  B00000000,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111
  },
 row3[] =
  {  
  B00000000,
  B00000000,
  B00000000,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111 },
  row4[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B11111111,
  B11111111,
  B11111111,
  B11111111
},
row5[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B11111111,
  B11111111,
  B11111111
},
  row6[]={
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B11111111,
  B11111111
},
  row7[]={
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B11111111
},
  last8[]={
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B01111111
},
  last7[]={
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00111111
},
  last6[]={
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00011111
},
  last5[]={
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00001111
},
  last4[]={
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000111
},
  last3[]={
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000011
},
  last2[]={
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000001
},
  last1[]={
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
},
  allon[]={
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111
  },
  go[]={
  B00000000,
  B00000000,
  B01100110,
  B10011001,
  B10001001,
  B10111001,
  B10011001,
  B01100110
}
;

void loop() {
  matrix.setBrightness(0);
  for(int8_t x = 3; x != 0; x--){
  matrix.setRotation(0);
  matrix.clear();
  matrix.setCursor(1,1);
  matrix.print(x);
  matrix.writeDisplay();
  delay(1000);

  for (int8_t y=0; y>=-10; y--) {
    matrix.clear();
    matrix.setCursor(1,y);
    matrix.print(x);
    matrix.writeDisplay();
    delay(45);
  }
  }
  
  matrix.clear();
  matrix.drawBitmap(0, 0, go, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(1000);
  
  matrix.clear();
  matrix.drawBitmap(0, 0, allon, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(8000);
  
  matrix.clear();
  matrix.drawBitmap(0, 0, row1, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(8000);

  matrix.clear();
  matrix.drawBitmap(0, 0, row2, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(8000);

  matrix.clear();
  matrix.drawBitmap(0, 0, row3, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(8000);

  matrix.clear();
  matrix.drawBitmap(0, 0, row4, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(8000);

  matrix.clear();
  matrix.drawBitmap(0, 0, row5, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(8000);

  matrix.clear();
  matrix.drawBitmap(0, 0, row6, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(8000);

  matrix.clear();
  matrix.drawBitmap(0, 0, row7, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(8000);

  matrix.clear();
  matrix.drawBitmap(0, 0, last8, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(1000);

  matrix.clear();
  matrix.drawBitmap(0, 0, last7, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(1000);

  matrix.clear();
  matrix.drawBitmap(0, 0, last6, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(1000);

  matrix.clear();
  matrix.drawBitmap(0, 0, last5, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(1000);

  matrix.clear();
  matrix.drawBitmap(0, 0, last4, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(1000);

  matrix.clear();
  matrix.drawBitmap(0, 0, last3, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(1000);

  matrix.clear();
  matrix.drawBitmap(0, 0, last2, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(1000);

  matrix.clear();
  matrix.drawBitmap(0, 0, last1, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(1000);


  matrix.clear();      // clear display
  matrix.drawPixel(0, 0, LED_ON);  
  matrix.writeDisplay();  // write the changes we just made to the display
  delay(500);

  matrix.clear();
  matrix.drawLine(0,0, 7,7, LED_ON);
  matrix.writeDisplay();  // write the changes we just made to the display
  delay(500);

  matrix.clear();
  matrix.drawRect(0,0, 8,8, LED_ON);
  matrix.fillRect(2,2, 4,4, LED_ON);
  matrix.writeDisplay();  // write the changes we just made to the display
  delay(500);

  matrix.clear();
  matrix.drawCircle(3,3, 3, LED_ON);
  matrix.writeDisplay();  // write the changes we just made to the display
  delay(500);

  matrix.setTextSize(1);
  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextColor(LED_ON);
  for (int8_t x=0; x>=-36; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("Hello");
    matrix.writeDisplay();
    delay(100);
  }
  matrix.setRotation(3);
  for (int8_t x=7; x>=-36; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("World");
    matrix.writeDisplay();
    delay(100);
  }
  matrix.setRotation(0);
  
 
}
