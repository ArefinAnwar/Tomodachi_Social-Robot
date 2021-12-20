void maskSystem() {
  int statusSensor = digitalRead (IRSensor);

  if (statusSensor == 1) {
    mask_servo.write(0, 255, true);
    
  }

  else
  {
    mask_servo.write(90, 255, true);
    
  }
}
