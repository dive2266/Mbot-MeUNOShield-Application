#include <MeShield.h>
Me7SegmentDisplay seg7(3);
MeRGBLed rgbled(6,4);
MeJoystick joystick(7);
MePotentiometer potentiometer(8);
MeUltrasonicSensor ultraSensor(4);

int num=1;
float x=0;
float change =0;
int d = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    change = potentiometer.read();
    d = ultraSensor.distanceCm();
    Serial.println(d);
  if ( d < 15)
  {
    rgblight();
  }
  else
  {
  for(int i=1;i<=6;i++)
  {
    change = potentiometer.read();
    d = ultraSensor.distanceCm();
    if(i<4)
    {
      seg7.display(int(num));
      num=num*10;
      delay(300);
    }
    else
    {
      seg7.display(int(num));
      num=num/10;
      delay(300);
    }
  }
  seg7.display(int(num));
  delay(300);
  num++;
  if(num==10)
  {
    num=1;
  }

  if(d<15){
    rgblight();
  }
  
  x= joystick.read(1);

  if(x>200)
  {
    led_1(change);
  }
  else if (x<-200)
  {
    led_2(change);
  }
  else
  {
    led_3(change);
  }
  }
}


void led_1(float change){
    for(int j=1;j<=4;j++)
  {
    rgbled.setColor(j-1,0,0,0);
    rgbled.show();
    rgbled.setColor(j,0,0,change);
    rgbled.show();
    delay(100);
  }
}


void led_2(float change){
    for(int j=1;j<=4;j++)
  {
    rgbled.setColor(j-1,0,0,0);
    rgbled.show();
    rgbled.setColor(j,change,0,0);
    rgbled.show();
    delay(100);
  }
}


void led_3(float change){
    for(int j=1;j<=4;j++)
  {
    rgbled.setColor(j-1,0,0,0);
    rgbled.show();
    rgbled.setColor(j,0,change,0);
    rgbled.show();
    delay(100);
  }
}

void rgblight(){
  int n=5;
    for(int k=1;k<=5;k++)
    {
     rgbled.setColor(0,255,0,0);
     rgbled.show();
     seg7.display(int(n--));
     delay(1000);
    }
    n=5;
    for(int m=1;m<=5;m++)
    {
     rgbled.setColor(0,0,255,0);
     rgbled.show();
     seg7.display(int(n--));
     delay(1000);
    }
    n=2;
    for(int o=1;o<=2;o++)
    {
     rgbled.setColor(0,255,100,0);
     rgbled.show();
     seg7.display(int(n--));
     delay(1000);
    }
}

