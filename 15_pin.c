#define button A3
#define button2 A4
#define button3 A5
const int pin1 = 2;
const int pin2 = 3;                            
const int pin3 = 4;
const int pin4 = 5;                               //*Declare 15 pin for Output
const int pin5 = 6;
const int pin6 = 7;
const int pin7 = 8;
const int pin8 = 9;                              
const int pin9 = 10;
const int pin10 = 11;
const int pin11 = 12;
const int pin12 = 13;
const int pin13 = A0;  
const int pin14 = A1;
const int pin15 = A2;
const byte LEDPinArray[15] = {pin1,pin2,pin3,pin4,pin5,pin6,pin7,pin8,pin9,pin10,pin11,pin12,pin13,pin14,pin15};
int buttonvalue1=0;
int buttonvalue2=0;
int buttonvalue3=0;
int find1 =0;
int find2=0;
int find3=0;
int running =0;
void InitAllLEDs()                                         //@Initialization Pin Mode
{
  for (int i = 0; i < 15; i++) {
    pinMode(LEDPinArray[i], OUTPUT);           //*Declare 15-Pin Output
  }
}
void On_thePin(int Pin_Onstatus,int Delay_seconds){       //@On the Pin 
  for(int Led=0;Led<15;Led++){
    digitalWrite(LEDPinArray[Led], HIGH);
    delay(100);      
  }
}

void Off_thePin(int Pin_Offstatus,int Delay_seconds){     //@On the Pin
  for(int Led=0;Led<15;Led++){
    digitalWrite(LEDPinArray[Led], LOW);
    delay(100);      
  }
}
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
InitAllLEDs();
pinMode(button, INPUT_PULLUP);
pinMode(button2,INPUT_PULLUP );
pinMode(button3,INPUT_PULLUP );
//pinMode(buttonvalue, OUTPUT);
//pinMode(2, OUTPUT);
}

void loop() {
if(find1==0){
  buttonvalue1= digitalRead(button);
  //int buu = buttonvalue1;
  if(!buttonvalue1){
    find1=1;
    running=1;
  }
}
if(find2==0){
  buttonvalue2= digitalRead(button2);
  //int buu = buttonvalue1;
  if(!buttonvalue2){
    find2=1;
    running=0;
  }
}
if(find3==0){
  buttonvalue3= digitalRead(button3);
  //int buu = buttonvalue1;
  if(!buttonvalue3){
    find3=1;
    running=1;
  }
}
if (find1==1){
  find1=0;
  //digitalWrite(2, HIGH);
  On_thePin(1,1);
  Serial.println(buttonvalue1);
  //delay(10); 
}
if (find2==1){
  find2=0;

  //digitalWrite(2, LOW);
  Off_thePin(1,1);
  Serial.println(buttonvalue2);
  //delay(10); 
}
}
