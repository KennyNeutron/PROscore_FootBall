void battery_init(){
    analogReference(EXTERNAL);
    pinMode(batteryPin, INPUT);
    pinMode(LED_RED, OUTPUT);

    digitalWrite(LED_RED, LOW);
}

void check_battery(){
int sensorValue = analogRead(A2); // read voltage at A0 pin
  //Serial.print("Analog A2: ");
  //Serial.println(sensorValue);

  //>=335 (DEFAU)
  if(sensorValue>=330){
    digitalWrite(LED_RED, HIGH);
  }else{
    digitalWrite(LED_RED, LOW);
  }
}
