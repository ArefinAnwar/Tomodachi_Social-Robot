void emergencySystem()
{
  int buttonState = digitalRead(emergency_button);
  int sound_level = analogRead(sound_level_sensor);

  if (buttonState == LOW) {
   bluetooth.println("Help Help Help!!!");
   delay(1000);
   ringBuzzer();
 }
  else {
    ////dsdsadasd
  }



  //  if (buttonState == LOW || sound_level > 480) {
  //
  //    bluetooth.print("Help Help Help!!!");
  //    bluetooth.println("\n");
  //
  //  }
  //
  //  else {
  //    //Emni disi :p
  //  }
}
