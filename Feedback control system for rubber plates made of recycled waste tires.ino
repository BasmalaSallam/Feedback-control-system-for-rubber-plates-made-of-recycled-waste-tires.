
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int ledPinwhite = 12;
const int ledPingreen = 13;

// defines variables
long duration;
float distance;
float safetyDistance;


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(ledPinwhite, OUTPUT);
pinMode(ledPingreen, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}


void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

safetyDistance = distance;
if ( 8.78 > safetyDistance && 8.53 < safetyDistance){
  
  digitalWrite(ledPingreen, HIGH);
  digitalWrite(ledPinwhite, LOW);
}
else
{
  digitalWrite(ledPingreen, LOW);
  digitalWrite(ledPinwhite, HIGH);
}

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
delay (500);
}
