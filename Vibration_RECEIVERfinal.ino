#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

const int rs = 2, e = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(13,OUTPUT);
  pinMode(12, OUTPUT);
  mySerial.begin(38400);
}


void loop() {
  while (Serial.available()) {
    lcd.home();
    lcd.clear();
    int Hz = Serial.readStringUntil(59).toInt();
    lcd.print(Hz/1000.0);
    lcd.print(" Seconds");
    if (Hz/1000.0 > 5) {
      digitalWrite(13,HIGH);
      digitalWrite(12,HIGH);
      lcd.setCursor(0, 1);
      lcd.print("Machine In Risk");
      mySerial.println("Machine In Risk");
      delay(250);
    
    }
    else {
      digitalWrite(13,LOW);
      digitalWrite(12, LOW);
    }
    mySerial.println(Hz/1000.0);
    mySerial.println(" Seconds"); 
  }

}
