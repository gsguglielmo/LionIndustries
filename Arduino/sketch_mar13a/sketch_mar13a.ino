void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (byte i = 0; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  for (byte i = 0; i < 14; i++) {
    digitalWrite(i, LOW);
  }
  digitalWrite(A0, LOW);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    byte a = Serial.read();
    while (!Serial.available()) {};
    byte b = Serial.read();
    if ( b == 0x48 ) { // H
      if (a == 13) {
        digitalWrite(A0, HIGH);
      } else {
        digitalWrite(a, HIGH);
      }

    } else if (b == 0x4c) { // L
      if (a == 13) {
        digitalWrite(A0, LOW);
      } else {
        digitalWrite(a, LOW);
      }
    } else if (b == 0x4d) { // M
      if (a == 0x4c){ // L - Left
        digitalWrite(A1,HIGH);
        digitalWrite(A2,LOW);
      }else if( a == 0x52){ // R - Right
        digitalWrite(A1,LOW);
        digitalWrite(A2,HIGH);
      }else if( a == 0x53){ // S - Stop
        digitalWrite(A1,HIGH);
        digitalWrite(A2,HIGH);
      }
    }
  }
}
