
#include <DFRobot_DHT11.h>
#include <LiquidCrystal_I2C.h>
DFRobot_DHT11 DHT;
#define DHT11_PIN 2
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup(){
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop(){
  DHT.read(DHT11_PIN);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("T : ");
  lcd.print(DHT.temperature);
  lcd.write(223); lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("H : ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  delay(1000);
  Serial.print("temp:");
  Serial.print(DHT.temperature);
  Serial.print("  humi:");
  Serial.println(DHT.humidity);
  if (DHT.temperature >= 21 && DHT.temperature <= 29) {
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW); 
    lcd.setCursor(11,0);
    lcd.print("STAT:");
    lcd.setCursor(12,1);
    lcd.print("FINE");
    delay(4000);
  }
  else if (DHT.temperature > 29) {
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH); 
    lcd.setCursor(11,0);
    lcd.print("STAT:");
    lcd.setCursor(13,1);
    lcd.print("HOT");
    delay(4000);
  }
   else {
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    lcd.setCursor(11,0);
    lcd.print("STAT:");
    lcd.setCursor(12,1);
    lcd.print("COLD");
    delay(4000);
  }
}
