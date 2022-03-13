#include <Servo.h>
Servo servo1;

const int button1State = 0, button2State = 0;
const int button1 = 13, button2 = 6, servo_pin = 10;
int servo_pos = 0;
void setup() {
  // put your setup code here, to run once:
servo1.attach(servo_pin);
servo1.write(servo_pos);
pinMode(button1,INPUT);
pinMode(button2,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
button1State = digitalRead(button1);
button2State = digitalRead(button2);
Serial.println(button1State);
Serial.println(button2State);

if (button1State == HIGH && button2State == HIGH){
  Serial.println("ERROR COMMAND");
}
else if (button1State == HIGH && servo_pos < 180){
  servo_pos += 5;
  servo1.write(servo_pos);
  Serial.println(servo_pos);
  delay(10);
}
else if (button2State == HIGH && servo_pos > 0){
  servo_pos -= 5;
  servo1.write(servo_pos);
  Serial.println(servo_pos);
  delay(10);
}

}
