int tmpPin = A0;    
int ledPin = 13;    
int buzzerPin = 9;  

float temperature;  

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  
  int sensorValue = analogRead(tmpPin);

  
  temperature = (sensorValue - 20) * 0.48876;

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");

  if (temperature > 37.0) {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 3047, 400);
    delay(1000);
    noTone(buzzerPin);
  } else {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin); 
  }

  delay(2000);  
}
