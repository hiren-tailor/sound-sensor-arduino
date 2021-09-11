#include <Servo.h>
Servo htservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position

int sound_pin = 3;
int red = 8;
int green = 9;
int blue = 10;
int count = 0;

void setup() {
  pinMode (sound_pin, INPUT_PULLUP);
  htservo.attach(4);  // attaches the servo on pin 4 to the servo object
  htservo.write(pos);
  pinMode (red, OUTPUT);
  pinMode (green, OUTPUT);
  pinMode (blue, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(sound_pin),sound_ISR,RISING);
  //digitalWrite (red, HIGH);
  Serial.begin(9600);
}

void loop() {
  Serial.print("outer count: ");
  Serial.println(count);
  delay(10000);
  if (count == 1 && count <= 3)
  {
    digitalWrite (red, HIGH);
    digitalWrite (green, LOW);
    digitalWrite (blue, LOW);
    pos = 60;
    htservo.write(pos);
    Serial.println(count);
    delay(1000);
  }
  else if (count == 2 && count <= 3)
  {
    digitalWrite (red, LOW);
    digitalWrite (green, HIGH);
    digitalWrite (blue, LOW);
    pos = 120;
    htservo.write(pos);
    Serial.println(count);
    delay(1000);
  }
  else if (count == 3 && count <= 3)
  {
    digitalWrite (red, LOW);
    digitalWrite (green, LOW);
    digitalWrite (blue, HIGH);
    pos = 180;
    htservo.write(pos);
    Serial.println(count);
    delay(1000);
  }
  else
  {
    digitalWrite (red, LOW);
    digitalWrite (green, LOW);
    digitalWrite (blue, LOW);
    pos = 0;
    htservo.write(pos);
  }
}

void sound_ISR()
{
  if (count <= 2)
  {
    count++;
  }
  else
  {
    count = 0;
  }
}
