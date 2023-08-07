//Prateek
//wwww.prateeks.in
//https://www.youtube.com/c/JustDoElectronics/videos

#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

#define in A0
#define out A5
//#define relay 2

int count = 0;

void IN() {
  count++;
  lcd.clear();
  lcd.print("Person In Room:");
  lcd.setCursor(0, 1);
  lcd.print(count);
  delay(1000);
}

void OUT() {
  count--;
  lcd.clear();
  lcd.print("Person In Room:");
  lcd.setCursor(0, 1);
  lcd.print(count);
  delay(1000);
}

void setup() {
  lcd.begin(16, 2);
  lcd.print("Visitor Counter");
  delay(2000);
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  pinMode(relay, OUTPUT);
  lcd.clear();
  lcd.print("Person In Room:");
  lcd.setCursor(0, 1);
  lcd.print(count);
}

void loop() {

  if (digitalRead(in))
    IN();
  if (digitalRead(out))
    OUT();

  if (count <= 0) {
    lcd.clear();
    digitalWrite(relay, LOW);
    lcd.clear();
    lcd.print("Nobody In Room");
    lcd.setCursor(0, 1);
    lcd.print("Light Is Off");
    delay(200);
  }

  else
    digitalWrite(relay, HIGH);
}
