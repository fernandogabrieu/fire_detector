#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  lcd.init(); 
  lcd.backlight(); // Serve para ligar a luz do display
  lcd.clear(); // Serve para limpar a tela do display
}

void loop()
{
  //Serial.println(digitalRead(2));
  //Serial.println(digitalRead(3));
  Serial.println(analogRead(A0));
  if (digitalRead(2) == 0 || digitalRead(3) == 0 || analogRead(A0) > 230) {
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    //lcd.setBacklight(HIGH);
    lcd.setCursor(1, 0);
    lcd.print("Danger!");
    lcd.setCursor(0, 1);
    lcd.print("Fire Detected");
    delay(125); // Wait for 100 millisecond(s)
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    lcd.clear();
    delay(125); // Wait for 100 millisecond(s)
  } else {
    //lcd.clear();
    lcd.setBacklight(LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    delay(125); // Wait for 100 millisecond(s)
  }
}

