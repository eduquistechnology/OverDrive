/* include library */
#include <ESP8266WiFi.h>

/* define port */
WiFiClient client;
WiFiServer server(80);

/* WIFI settings */
const char* ssid = "sagar";
const char* password = "sagar1234";

/* data received from application */
String  data =""; 

/* define L298N or L293D motor control pins */
int leftMotorForward = 2;     /* GPIO2(D4) -> IN3   d4*/
int rightMotorForward = 15;   /* GPIO15(D8) -> IN1 d8 */
int leftMotorBackward = 0;    /* GPIO0(D3) -> IN4   d3*/
int rightMotorBackward = 13;  /* GPIO13(D7) -> IN2  d7*/
int armMotorUp = 16;          /* GPIO16(D0) -> IN1 d0*/
int armMotorDown = 5;         /* GPIO5(D1) -> IN2 d1*/
int clawMotorOpen = 4;        /* GPIO4(D2) -> IN3 d2*/
int clawMotorClose = 14;      /* GPIO14(D5) -> IN4 d5*/

void setup()
{
  /* initialize motor control pins as output */
  pinMode(leftMotorForward, OUTPUT);
  pinMode(rightMotorForward, OUTPUT); 
  pinMode(leftMotorBackward, OUTPUT);  
  pinMode(rightMotorBackward, OUTPUT);
  pinMode(armMotorUp, OUTPUT);
  pinMode(armMotorDown, OUTPUT);
  pinMode(clawMotorOpen, OUTPUT);
  pinMode(clawMotorClose, OUTPUT);
  /* start server communication 192.168.43.141*/
  server.begin();
}

void loop()
{
    /* If the server available, run the "checkClient" function */  
    client = server.available();
    if (!client) return; 
    data = checkClient ();
/************************ Run function according to incoming data from application *************************/
    /* If the incoming data is "forward", run the "MotorForward" function */
    if (data == "forward") MotorForward();
    /* If the incoming data is "backward", run the "MotorBackward" function */
    else if (data == "backward") MotorBackward();
    /* If the incoming data is "left", run the "TurnLeft" function */
    else if (data == "left") TurnLeft();
    /* If the incoming data is "right", run the "TurnRight" function */
    else if (data == "right") TurnRight();
    /* If the incoming data is "stop", run the "MotorStop" function */
    else if (data == "stop") MotorStop();
    /* If the incoming data is "opne", run the "OpenClaw" function */
    else if (data == "open") OpenClaw();
    /* If the incoming data is "close", run the "CloseClaw" function */
    else if (data == "close") CloseClaw();
    /* If the incoming data is "up", run the "ArmUp" function */
    else if (data == "up") ArmUp();
    /* If the incoming data is "up", run the "ArmUp" function */
    else if (data == "down") ArmDown();
} 

/********************************************* FORWARD *****************************************************/
void MotorForward(void)   
{
  digitalWrite(leftMotorForward,HIGH);
  digitalWrite(rightMotorForward,HIGH);
  digitalWrite(leftMotorBackward,LOW);
  digitalWrite(rightMotorBackward,LOW);
}

/********************************************* BACKWARD *****************************************************/
void MotorBackward(void)   
{
  digitalWrite(leftMotorBackward,HIGH);
  digitalWrite(rightMotorBackward,HIGH);
  digitalWrite(leftMotorForward,LOW);
  digitalWrite(rightMotorForward,LOW);
}

/********************************************* TURN LEFT *****************************************************/
void TurnLeft(void)   
{
  digitalWrite(leftMotorForward,LOW);
  digitalWrite(rightMotorForward,HIGH);
  digitalWrite(rightMotorBackward,LOW);
  digitalWrite(leftMotorBackward,HIGH);  
}

/********************************************* TURN RIGHT *****************************************************/
void TurnRight(void)   
{
  digitalWrite(leftMotorForward,HIGH);
  digitalWrite(rightMotorForward,LOW);
  digitalWrite(rightMotorBackward,HIGH);
  digitalWrite(leftMotorBackward,LOW);
}

/********************************************* STOP *****************************************************/
void MotorStop(void)   
{
  digitalWrite(leftMotorForward,LOW);
  digitalWrite(leftMotorBackward,LOW);
  digitalWrite(rightMotorForward,LOW);
  digitalWrite(rightMotorBackward,LOW);
  digitalWrite(armMotorUp,LOW);
  digitalWrite(armMotorDown,LOW);
  digitalWrite(clawMotorOpen,LOW);
  digitalWrite(clawMotorClose,LOW);
}

String checkClient (void)
{
  while(!client.available()) delay(1); 
  String request = client.readStringUntil('\r');
  request.remove(0, 5);
  request.remove(request.length()-9,9);
  return request;
}
