//void pulse_and_oximeter()
//{
//  Serial.println("PO called!!!");
//  bufferLength = 100; //buffer length of 100 stores 4 seconds of samples running at 25sps
//
//  //read the first 100 samples, and determine the signal range
//
//
//  //calculate heart rate and SpO2 after first 100 samples (first 4 seconds of samples)
//  maxim_heart_rate_and_oxygen_saturation(irBuffer, bufferLength, redBuffer, &spo2, &validSPO2, &heartRate, &validHeartRate);
//
//  //Continuously taking samples from MAX30102.  Heart rate and SpO2 are calculated every 1 second
//
//
//  //dumping the first 25 sets of samples in the memory and shift the last 75 sets of samples to the top
//  
//  //take 25 sets of samples before calculating the heart rate.
//  for (byte i = 75; i < 100; i++)
//  {
//    while (particleSensor.available() == false) //do we have new data?
//      particleSensor.check(); //Check the sensor for new data
//
//    digitalWrite(readLED, !digitalRead(readLED)); //Blink onboard LED with every data read
//
//    redBuffer[i] = particleSensor.getRed();
//    irBuffer[i] = particleSensor.getIR();
//    particleSensor.nextSample(); //We're finished with this sample so move to next sample
//
//    //send samples and calculation result to terminal program through UART
//    Serial.print(F("red="));
//    Serial.print(redBuffer[i], DEC);
//    Serial.print(F(", ir="));
//    Serial.print(irBuffer[i], DEC);
//
//    Serial.print(F(", HR="));
//    Serial.print(heartRate, DEC);
//
//    Serial.print(F(", HRvalid="));
//    Serial.print(validHeartRate, DEC);
//
//    Serial.print(F(", SPO2="));
//    Serial.print(spo2, DEC);
//
//    Serial.print(F(", SPO2Valid="));
//    Serial.println(validSPO2, DEC);
//
//
//    //After gathering 25 new samples recalculate HR and SP02
//    maxim_heart_rate_and_oxygen_saturation(irBuffer, bufferLength, redBuffer, &spo2, &validSPO2, &heartRate, &validHeartRate);
//  }
//
//}
