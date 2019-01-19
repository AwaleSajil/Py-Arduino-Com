char serialData;
int pin = 13;
int state = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){

    serialData = Serial.read();
  }
    if(serialData == '1'){
      state = 1;
    }
    else if (serialData == '0'){
      state = 0;
    }
    else{}
    
  digitalWrite(pin, state);

}
