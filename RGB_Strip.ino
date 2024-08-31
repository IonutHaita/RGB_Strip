const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
volatile int ledPin = 9;
int redValue = 0;
int greenValue = 0;
int blueValue = 0;
volatile int colorStep = 0;
volatile int currentColor = 0;
volatile int i = 0;
const int button = 2;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(button);
  analogWrite(ledPin, LOW);
  if (buttonState == LOW) { 
    analogWrite(ledPin, LOW);
    delay(1000);
    currentColor = (currentColor + 1) % 8; 
  }
  if (currentColor < 4){
    analogWrite(ledPin, HIGH);
    displayColor(currentColor);
  }
  else if (currentColor == 4) {
    analogWrite(ledPin, LOW);
    delay(10);
    displayAnimation();
  }
  else if(currentColor == 5){
  analogWrite(redPin, LOW);
  analogWrite(greenPin, LOW);
  analogWrite(bluePin, LOW);
  displayCandle(9);}
  else if(currentColor == 6){displayCandle(10);}
  else if(currentColor == 7){displayCandle(11);}
  
}
void displayColor(int color) {
  switch (color) {
    case 0:
      ledPin = redPin;
      break;
    case 1:
      ledPin = greenPin;
      break;
    case 2:
      ledPin = bluePin;
      break;
  }
}

void displayAnimation(){
  redValue = (redValue + 5) % 255;
  greenValue = (greenValue + 10) % 255;
  blueValue = (blueValue + 15) % 255;

  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);

  delay(50); // Adjust delay for animation speed
}

void displayCandle(int selection){
      ledPin = selection;
      volatile int brightness = random(50, 150);
      analogWrite(ledPin, brightness);
      delay(random(240, 350)); // Adjust these values to your liking
      i++;
      if(i==80){analogWrite(ledPin, LOW);delay(40);i=0;}
}
