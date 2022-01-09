void setup() {
  pinMode(8,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Initaialiting\n");
  digitalWrite(8,HIGH);
  delay (2000);
  digitalWrite(8,LOW);
   delay (2000);
   
}
