/** This is a sample code for LED chaser
Connection :
Led1 (+ve) --> D3
Led2 (+ve) --> D4
Led3 (+ve) --> D6
Led1,2,3 (-ve) --> GND
**/

void setup(){
pinMode(D3,OUTPUT);
pinMode(D4,OUTPUT);
pinMode(D6,OUTPUT);
}

void loop(){
digitalWrite(D3,HIGH);
delay(100);
digitalWrite(D3,LOW);
digitalWrite(D4,HIGH);
delay(100);
digitalWrite(D4,LOW);
digitalWrite(D6,HIGH);
delay(100);
digitalWrite(D6,LOW);
delay(1000);
}
