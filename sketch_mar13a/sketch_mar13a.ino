void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(byte i=0;i<14;i++){
    pinMode(i,OUTPUT);
  }
  pinMode(A0,OUTPUT);
  for(byte i=0;i<14;i++){
    digitalWrite(i,LOW);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    byte a = Serial.read();
    while(!Serial.available()){};
    byte b = Serial.read();
    if( b==0x48 ){// H
      if(a==13){
        digitalWrite(A0,HIGH);
      }else{
        digitalWrite(a,HIGH);
      }
      
    }else if(b==0x4c){// L
      if(a==13){
        digitalWrite(A0,LOW);
      }else{
        digitalWrite(a,LOW);
      }
      
    }
  }
}
