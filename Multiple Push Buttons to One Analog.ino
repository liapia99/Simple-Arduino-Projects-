int buttonPin = A0;     //Button and LED pin numbers
int ledGreen = 2;
int ledRed = 3;
int ledBlue = 4;


void setup() 
{
    pinMode(ledGreen, OUTPUT);    //Define LED pins
    pinMode(ledRed, OUTPUT);
    pinMode(ledBlue, OUTPUT);
    Serial.begin(9600);           //Serial monitor used to determine limit values
}

void loop() {
  int temp = analogRead(buttonPin);   //Read the analogue input
  Serial.println(temp);               //Display the read value in the Serial monitor
  if (temp < 100)                     //Lower limit for first button - if below this limit then no button is pushed and LEDs are turned off
  {
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, LOW);
    digitalWrite(ledBlue, LOW);
  }
  else if (temp < 150)                //First button limit - if below this limit but above previous limit then the first button is pressed
  {
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledBlue, HIGH);
  }
  else if (temp < 250)                //Second button limit
  {
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledBlue, LOW);
  }
  else if (temp < 350)                //Third button limit
  {
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, LOW);
    digitalWrite(ledBlue, HIGH);
  }
  else if (temp < 850)                //Fourth button limit
  {
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledBlue, LOW);
  }
  else                                //If none of the previous buttons are pressed, then the fifth button must be pressed
  {
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, LOW);
    digitalWrite(ledBlue, LOW);
  }
  delay(100);                         //Delay for stability
}
