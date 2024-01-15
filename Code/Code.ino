//Prateek
//https://justdoelectronics.com
//https://www.youtube.com/c/JustDoElectronics/videos
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

#define in 8  // In Sensor
#define out 9 // Out Sensor
#define bulb 10 // Bulb(Relay)

int count = 0; // count Value

void setup()
{
  lcd.begin(16,2); 
  lcd.print("Visitor Counter"); 
  delay(2000); 
  pinMode(in,INPUT); 
  pinMode(out,INPUT); 
  pinMode(bulb,OUTPUT);  
  lcd.clear(); 
  lcd.print("Person In Room:"); 
  lcd.setCursor(0,1); 
  lcd.print(count); 
}

void loop()
{  
  int in_value = digitalRead(in); 
  int out_value = digitalRead(out); 
  
  if(in_value == LOW)
  {
    count++;
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
  }                                                       
  
  if(out_value == LOW)
  {
    count--;
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
  }                                                    
 
  if(count==0)
  {
    lcd.clear();
    digitalWrite(bulb,HIGH);
    lcd.clear();
    lcd.print("Nobody In Room");
    lcd.setCursor(0,1);
    lcd.print("Light is Off");
    delay(200);
  }                                                    
  
  else
  {
    digitalWrite(bulb,LOW);    
  }                                                   
}
