
 #include <LiquidCrystal.h>
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
   pinMode (outputXA,INPUT);
   pinMode (outputXB,INPUT);
   pinMode (outputYA,INPUT);
   pinMode (outputYB,INPUT);
   pinMode (outputZA,INPUT);
   pinMode (outputZB,INPUT);
/////////////////

   pinMode (onOffX,INPUT);
   pinMode (onOffY,INPUT);
   pinMode (onOffZ,INPUT);

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
 
  
  lcd.setCursor(0, 0);
  
  if(digitalRead(onOffX) == LOW){
           x = "1";
  } else {
          x = "0";
  }
  if(digitalRead(onOffY) == LOW){
           y = "1";
  } else {
          y = "0";
  }
  if(digitalRead(onOffZ) == LOW){
           z = "1";
  } else {
          z = "0";
  }
  lcd.print("X:" + x +  " Y:" + y + " Z:" + z);

  lcd.setCursor(0, 1);
  
 lcd.print( String(counterX) + "   " + String(counterY) + "  " + String(counterZ) );

   aStateX = digitalRead(outputXA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aStateX != aLastStateX){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputXB) != aStateX) { 
       counterX ++;
     } else {
       counterX --;
     }
     Serial.print("Position X : ");
     Serial.println(counterX);
   } 
   aLastStateX= aStateX; // Updates the previous state of the outputA with the current state
    
    
   aStateY = digitalRead(outputYA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aStateY != aLastStateY){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputYB) != aStateY) { 
       counterY ++;
     } else {
       counterY --;
     }
     Serial.print("Position Y : ");
     Serial.println(counterY);
   } 
   aLastStateY= aStateY; // Updates the previous state of the outputA with the current state
   
   aStateZ = digitalRead(outputZA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aStateZ != aLastStateZ){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputZB) != aStateZ) { 
       counterZ ++;
     } else {
       counterZ --;
     }
     Serial.print("Position Z : ");
     Serial.println(counterZ);
   } 
   aLastStateZ= aStateZ; // Updates the previous state of the outputA with the current state
 }
