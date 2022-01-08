//Shreeya Bhonsle - 213

// define pins numbers  
const int trigPin = 4;
const int echoPin = 7;
const int led1 = 5;
const int led2 = 6;
const int led3 = 8;
const int led4 = 9;


// define variables
long duration;
int distance;

void setup() {
  
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds  
  distance= duration*0.034/2; // Calculating the distance  
  Serial.print("Distance: "); // Prints the distance on the Serial Monitor
  Serial.println(distance);

  if(distance < 100)
  {
    digitalWrite(led1,HIGH);
    if(distance < 70)
    {
      digitalWrite(led2,HIGH);
    }
    else
    {
      digitalWrite(led2,LOW);
    }
    if(distance < 40)
    {
      digitalWrite(led3,HIGH);
    }
    else
    {
      digitalWrite(led3,LOW);
    }
    if(distance < 20)
    {
      digitalWrite(led4,HIGH);
      digitalWrite(trigPin,HIGH);
    }
    else
    {
      digitalWrite(led4,LOW);
    }
    
  }
  else
  {
    digitalWrite(trigPin,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
  }
}
