// C++ code
//
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop()
{
  if (0.01723 * readUltrasonicDistance(4, 5) < 5) {
    digitalWrite(10, HIGH);
    digitalWrite(13, LOW);
    // pino 2 liga e desliga o relé
    digitalWrite(2, LOW);
  } else {
    digitalWrite(2, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(13, HIGH);
  }
  delay(1000); // Wait for 1000 millisecond(s)
}