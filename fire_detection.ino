int fire_detection()
{

  byte sensorMin = 0;     // sensor minimum
  unsigned int sensorMax = 1024;  // sensor maximum

  int sensorReading = analogRead(flame_sensor);
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);

  switch (range) {
    case 0:    // A fire closer than 1.5 feet away
      //Serial.println("** Close Fire **");
      lcd.setCursor(3, 3);
      lcd.print("Fire Detected");
      bluetooth.print("Fire Detected");
      bluetooth.println("\n");

      break;

    case 2:    // No fire detected.
      //Serial.println("No Fire");
      lcd.setCursor(1, 3);
      lcd.print("No Fire Detected");
      break;
  }
  delay(50);
}
