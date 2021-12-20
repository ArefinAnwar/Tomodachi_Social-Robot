void stop_motors()
{
  digitalWrite(FrontMotorLeft, LOW);
  digitalWrite(FrontMotorRight, LOW);
  digitalWrite(RearMotorLeft, LOW);
  digitalWrite(RearMotorRight, LOW);
  analogWrite(FrontMotorLeftSpeed, 0);
  analogWrite(FrontMotorRightSpeed, 0);
}


void go_forward()
{
  digitalWrite(RearMotorLeft, LOW);
  digitalWrite(RearMotorRight, LOW);
  digitalWrite(FrontMotorLeft, HIGH);
  digitalWrite(FrontMotorRight, HIGH);
  analogWrite(FrontMotorLeftSpeed, 220);
  analogWrite(FrontMotorRightSpeed, 215 );
}

void go_left()
{
  digitalWrite(RearMotorLeft, LOW);
  digitalWrite(RearMotorRight, LOW);
  digitalWrite(FrontMotorLeft, HIGH);
  digitalWrite(FrontMotorRight, HIGH);
  analogWrite(FrontMotorLeftSpeed, 250);
  analogWrite(FrontMotorRightSpeed, 00);
}

void go_right()
{
  digitalWrite(RearMotorLeft, LOW);
  digitalWrite(RearMotorRight, LOW);
  digitalWrite(FrontMotorLeft, HIGH);
  digitalWrite(FrontMotorRight, HIGH);
  analogWrite(FrontMotorLeftSpeed, 0);
  analogWrite(FrontMotorRightSpeed, 250);
}

void reverse() {
  digitalWrite(FrontMotorLeft, LOW);
  digitalWrite(FrontMotorRight, LOW);
  delay(1000);
  digitalWrite(RearMotorLeft, HIGH);
  digitalWrite(RearMotorRight, HIGH);
  analogWrite(FrontMotorLeftSpeed, 220);
  analogWrite(FrontMotorRightSpeed, 215 );
}
