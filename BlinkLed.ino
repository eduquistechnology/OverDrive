/**
This is a sample code to blink an LED on D7 port in the Node MCU.
Connection diagram: Led(+ve)--> D7
                    Led(-ve) --> GND
**/

void setup(){
pinMode (D7, OUTPUT);
}

void loop(){
digitalWrite(D7, HIGH);
delay(1000);
digitalWrite(D7, LOW);
delay(1000);
}
