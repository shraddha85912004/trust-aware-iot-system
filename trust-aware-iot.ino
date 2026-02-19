#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int gasPin = A0;
int tempPin = A1;
int ldrPin  = A2;

float gasTrust = 1.0;
float tempTrust = 1.0;

int prevGas = 0;
int prevTemp = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(8, OUTPUT);   // GREEN LED
  pinMode(9, OUTPUT);   // RED LED
}

void loop() {

  int gas = analogRead(gasPin);
  int tempRaw = analogRead(tempPin);
  float temp = (tempRaw * 5.0 / 1023.0) * 100; // TMP36 approx

  // Trust adjustment logic
  if (abs(gas - prevGas) > 80) gasTrust -= 0.05;
  else gasTrust += 0.01;

  if (abs(temp - prevTemp) > 5) tempTrust -= 0.05;
  else tempTrust += 0.01;

  gasTrust = constrain(gasTrust, 0.2, 1.0);
  tempTrust = constrain(tempTrust, 0.2, 1.0);

  float effectiveGas = gas * gasTrust;
  float effectiveTemp = temp * tempTrust;

  lcd.clear();

  if (effectiveGas > 300 || effectiveTemp > 35) {
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);

    lcd.setCursor(0, 0);
    lcd.print("ALERT!");
    lcd.setCursor(0, 1);
    lcd.print("G:");
	lcd.print(gasTrust, 2);
	lcd.print(" T:");
	lcd.print(tempTrust, 2);
  } else {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);

    lcd.setCursor(0, 0);
    lcd.print("System SAFE");
    lcd.setCursor(0, 1);
    lcd.print("Stable Trust");
  }

  prevGas = gas;
  prevTemp = temp;
  delay(1500);
}
