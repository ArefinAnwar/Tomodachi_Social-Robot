void colourDetection()
{
  lcd.setCursor(5, 0);
  lcd.print("Tomodachi");
  lcd.setCursor(2, 2);
  lcd.print("Colour Detection");
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(S3, HIGH);
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(S2, HIGH);
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

  if (red < blue && red < green && red < 20) {
    lcd.setCursor(5, 3);
    lcd.print("Red Colour");
  }
  else if (blue < red && blue < green) {
    lcd.setCursor(5, 3);
    lcd.print("Blue Colour");
  }
  else if (green < red && green < blue) {
    lcd.setCursor(5, 3);
    lcd.print("Green Colour");
  }
}
