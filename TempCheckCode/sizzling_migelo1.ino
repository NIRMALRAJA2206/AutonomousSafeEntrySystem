int const servo=7;
int const trigPin=10;
int const echoPin=9;
int const motorPin=6;
int const buzzerpin=13;
int long duration;
int distance;
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
#include<Servo.h>
Servo myservo;
int celsius; 
int const tempin = A0;

void setup()
{
Serial.begin(9600); 
lcd.begin(16, 2); 
Serial.println("Temp Display"); 
pinMode(echoPin,INPUT);
pinMode(trigPin,OUTPUT);
pinMode(buzzerpin,OUTPUT);
pinMode(6,OUTPUT);
pinMode(8,OUTPUT);  
myservo.attach(servo);
myservo.write(0);
  Serial.begin(9600);  
}
void loop()
{
celsius = analogRead(tempin);
lcd.setCursor(0,0); 
lcd.clear(); 
  lcd.print("WELCOME");
  delay(1000);
  lcd.setCursor(0,1);
  if(celsius > 37){
    lcd.print("NOT ALLOWED");
    Serial.println("NOT ALLOWED"); 
    lcd.setCursor(0,1);
    delay(1000);
  }
  else{
    digitalWrite(trigPin,LOW);
delayMicroseconds(2); 
digitalWrite(trigPin,HIGH);
delayMicroseconds(10); 
digitalWrite(trigPin,LOW);
duration=pulseIn(echoPin,HIGH);
distance=(duration*0.034/2);
Serial.print("distance "); 
Serial.println(distance); 
  if(distance<=15){
    tone(buzzerpin,100);
    delay(500);
    noTone(buzzerpin);
    myservo.write(45);
    delay(100);
    myservo.write(90);
    delay(100);
    myservo.write(135);
    delay(100);
  myservo.write(180);
    delay(1000);
    myservo.write(0);
    delay(1000);
    lcd.print("ALLOWED"); 
     Serial.println("ALLOWED"); 
  lcd.setCursor(0,1);
    delay(1000);
   digitalWrite(motorPin, HIGH);
    delay(2000);
    digitalWrite(motorPin, LOW);
  }}

    
}
