#include <Servo.h>//including servo library
#define second 1000
#define minute 60000
#define hour 3600000

Servo servo;//making object of servo class

//Setting all the necessary requirements
const int servoPin = 9;
const int time_1 = 200;
const int time_2 = 200;
const int angle_1 = 120;
const int angle_2 = 10;
const int ledPin = 13;
String msg1="ENTER TIME INTERVALS YOU WANT TO FEED YOUR PET(in minutes)";
String msg2="THE TIME INTERVAL IS:";
unsigned long lastFeeding=0;

void setup ()
{
    servo.attach(servoPin);
    servo.write(angle_1);//Setting servo to required position
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);
    delay(1000);
    servo.detach();//Detaching Servo pin till its further use
}

void loop () 
{
  if(millis() - lastFeeding>30*minute)//checking if the required condition is met
    {
      digitalWrite(ledPin,HIGH);//glowing ledpin which is in arduino board
      delay(100);
      dispense();//calling dispense function
      digitalWrite(ledPin,LOW);
  }
  delay(10);
}
void dispense()
{
    lastFeeding=millis();//storing the last feeding time
    servo.attach(servoPin);
    servo.write(angle_2);
    delay(time_1);//To increase portion size increase Time 1 and time 2
    servo.write(angle_1);
    delay(time_2);//the time it has to stay in open position
    servo.detach();//removing servo pin
    delay(5000);
  }
