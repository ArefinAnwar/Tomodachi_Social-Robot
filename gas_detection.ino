void Gas_Checker() {

  if (flag == 1) lcd.clear();
  flag = 0;

  lcd.setCursor(5, 0);
  lcd.print("Tomodachi");
  int analogSensor = analogRead(gas_sensor);

  Serial.print("Readings: ");
  Serial.println(analogSensor);
  
  if (analogRead(gas_sensor) > 400)
  {
    //Serial.println("Gas Leakage!!!");
    bluetooth.print("Gas Leakage!!!");
    bluetooth.println("\n");
    lcd.setCursor(2, 2);
    lcd.print("Gas Leakage!!!");

  }
  else
  {
    //Serial.println(" ");
    lcd.setCursor(2, 2);
    lcd.print("No Gas Leakage");
  }
  delay(50);
}
