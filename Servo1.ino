#include <Servo.h>

Servo myservo;
#define servoPin 3
#define pushButtonPin 2

int angle =0;
int angle =45;
int angle =90;
int angle =135;
int angle =180;
int angleStep =10;
const int minAngle = 0;
const int maxAngle = 180;

const int type =1;

int buttonPushed =0;

void setup() {

   Serial.begin (9600);
   myservo.attach (servoPin);
   pinMode (pushButtonPin, INPUT_PULLUP);
    myservo.write(angle);
}

void loop () {
  if(digitalRead(pushButtonPin) == LOW) {
    buttonPushed = 1;
  }
   if( buttonPushed) {  

      buttonPushed =0;

      angle = random(180);
      myservo.write(angle);
      Serial.print("Moved to: ");
      Serial.print(angle);
      Serial.println(" degree");
      delay(1000);

  }

}
