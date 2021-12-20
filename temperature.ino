void Display_Temp() {
  lcd.setCursor(5, 0);
  lcd.print("Tomodachi");
  lcd.setCursor(1, 1);
  lcd.print("Temperature: ");
  lcd.print(mlx.readObjectTempC()); // Displaying object temperature
}
