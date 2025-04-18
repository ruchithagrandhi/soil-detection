#define MOISTURE_PIN A0    
#define PUMP_PIN 7         
#define THRESHOLD 400      

void setup() {
  Serial.begin(9600);         
  pinMode(PUMP_PIN, OUTPUT);  
  digitalWrite(PUMP_PIN, LOW); 
}

void loop() {
  int moistureValue = analogRead(MOISTURE_PIN); 
  Serial.print("Moisture Level: ");
  Serial.println(moistureValue);

  if (moistureValue > THRESHOLD) { 
    digitalWrite(PUMP_PIN, HIGH);  
    Serial.println("Watering...");
    delay(5000);                   
    digitalWrite(PUMP_PIN, LOW);   
  } else {
    Serial.println("Soil is wet, no action.");
  }
  delay(1000); 
}