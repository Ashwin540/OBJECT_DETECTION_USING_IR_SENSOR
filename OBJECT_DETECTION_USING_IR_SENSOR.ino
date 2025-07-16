#define IRPIN 13    // D0 of IR sensor
#define LEDPIN 14   // LED connected to GPIO14
#define buzzer 27   // buzzer TO GPIO 27

void setup() {
  Serial.begin(115200);
  pinMode(IRPIN, INPUT);     // IR sensor input
  pinMode(LEDPIN, OUTPUT);   // LED output
   pinMode(buzzer, OUTPUT); //BUZZER OUTPUT 
  delay(1000);
}

void loop() {
  int val = digitalRead(IRPIN);  // Read IR sensor value

  Serial.print("IR Sensor Value: ");
  Serial.println(val);  // 0 = Object detected, 1 = No object

  if (val == 0) {
    digitalWrite(LEDPIN, HIGH); 
    digitalWrite(buzzer, HIGH); 
     // Turn ON LED when object detected
  } else {
    digitalWrite(LEDPIN, LOW); 
    digitalWrite(buzzer, LOW);  // Turn OFF LED
  }

  delay(100);  // Short delay for stability
}
