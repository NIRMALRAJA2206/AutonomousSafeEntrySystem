#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int c=0;
void setup() {
 
  lcd.begin(16, 2);
  
  pinMode(13,INPUT); //Exit gate
  pinMode(8,INPUT); // Entry gate
  pinMode(6,OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Count of people");
  int f,b;
  f=digitalRead(8);
  b=digitalRead(13);
  if (c>=10) digitalWrite(6,0);
  else digitalWrite(6,1);
  Serial.print(f);
  Serial.println(b);
  
  if (!f && c<10) c++;
  if (!b && c) c--;
  
  lcd.setCursor(0, 1);
  lcd.print(c);
  delay(1000);
}
