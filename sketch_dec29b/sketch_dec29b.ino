void setup() {
  Serial.begin(9600);
  Serial.print("Setup Completed\n");
  
}

void loop() {

  if(Serial.available())
   {
    int temp=Serial.read();
    Serial.print(temp);
    Serial.print("\n");
    
   }
   else 
   Serial.print("No data found\n");
   delay(2000);
   
}
