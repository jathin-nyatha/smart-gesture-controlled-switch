#include "Adafruit_APDS9960.h"
Adafruit_APDS9960 apds;
#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4,5,6,7);
int buz =8;
int r1 = 9;
int r2 =10;
// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  pinMode(buz, OUTPUT);
   pinMode(r1, OUTPUT);
    pinMode(r2, OUTPUT);
  digitalWrite(buz, HIGH);
    digitalWrite(r1, LOW);
    digitalWrite(r2, LOW);
  delay(200);
  digitalWrite(buz, LOW);
  digitalWrite(r1, HIGH);
  digitalWrite(r2, HIGH);
  delay(200);
  lcd.begin(16, 2);
  lcd.print("HAND GESTURE");
  lcd.setCursor(5,1);
   lcd.print("SYSTEM");
   delay(1000);
  if(!apds.begin()){
    Serial.println("failed to initialize device! Please check your wiring.");
  }
  else Serial.println("Device initialized!");

  //gesture mode will be entered once proximity mode senses something close
  apds.enableProximity(true);
  apds.enableGesture(true);
  lcd.clear();
}

// the loop function runs over and over again forever
void loop() {
  //read a gesture from the device
    lcd.setCursor(0,0);
    lcd.print("GESTURE : ");
     
 
    uint8_t gesture = apds.readGesture();
    if(gesture == APDS9960_DOWN) 
    {
        digitalWrite(buz, HIGH);
        digitalWrite(r1, HIGH);
        digitalWrite(r2, HIGH);
  delay(500);
  
       lcd.setCursor(5,1);
   lcd.print("DOWN");
   delay(3000);
      Serial.println("v");
      lcd.clear();
      digitalWrite(buz, LOW);
  delay(200);
    }
    if(gesture == APDS9960_UP)
    {  
       digitalWrite(r1, LOW);
        digitalWrite(r2, LOW);
      digitalWrite(buz, HIGH);
  delay(500);

  lcd.setCursor(5,1);
   lcd.print("UP");
   delay(3000);
       Serial.println("^");
       lcd.clear();
       digitalWrite(buz, LOW);
  delay(200);
    }
    if(gesture == APDS9960_LEFT) 
    {
       digitalWrite(r1, LOW);
      digitalWrite(buz, HIGH);
  delay(500);

      Serial.println("<");
        lcd.setCursor(5,1);
   lcd.print("LEFT");
   delay(3000);
   lcd.clear();
   digitalWrite(buz, LOW);
  delay(200);
     
    }
    if(gesture == APDS9960_RIGHT) 
    {
        digitalWrite(r1, HIGH);
      digitalWrite(buz, HIGH);
     delay(500);
      Serial.println(">");
       lcd.setCursor(5,1);
   lcd.print("RIGHT");
   delay(3000);
   lcd.clear();
   digitalWrite(buz, LOW);
  delay(200);
    }
}