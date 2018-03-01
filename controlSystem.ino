
#include "control.h"

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define outputXB 50
#define outputXA 51
int counterX = 0;
int aStateX;
int aLastStateX;

#define outputYB 31
#define outputYA 30
int counterY = 0;
int aStateY;
int aLastStateY;

#define outputZB 52
#define outputZA 53
int counterZ = 0;
int aStateZ;
int aLastStateZ;

#define onOffX 41
#define onOffY 40
#define onOffZ 39
String x  = "N";
String y  = "N";
String z = "N";

void setup() {
  lcd.begin(16, 2);
  lcd.print("X    Y     Z");


  ////////////////
  pinMode (outputXA, INPUT);
  pinMode (outputXB, INPUT);
  pinMode (outputYA, INPUT);
  pinMode (outputYB, INPUT);
  pinMode (outputZA, INPUT);
  pinMode (outputZB, INPUT);
  /////////////////

  pinMode (onOffX, INPUT);
  pinMode (onOffY, INPUT);
  pinMode (onOffZ, INPUT);

  // pinMode (stateX,INPUT);
  //   pinMode (stateY,INPUT);
  //   pinMode (stateZ,INPUT);


  /////////////
  Serial.begin (9600);
  // Reads the initial state of the outputA
  aLastStateX = digitalRead(outputXA);
  aLastStateY = digitalRead(outputYA);
  aLastStateY = digitalRead(outputZA);

}

void loop() {

  rotaryEncoder(aStateX, aLastStateX, outputXA, outputXB, counterX, "X " );
  rotaryEncoder(aStateY, aLastStateY, outputYA, outputYB, counterY, "Y " );
  rotaryEncoder(aStateZ, aLastStateZ, outputZA, outputZB, counterX, "Z " );

if(toggle(onOffX)){
Serial.println("x is on");
}
  lcd.setCursor(0, 0);
  lcd.print("X:" + x +  " Y:" + y + " Z:" + z);
  lcd.setCursor(0, 1);
  lcd.print( String(counterX) + "   " + String(counterY) + "  " + String(counterZ) );
}




