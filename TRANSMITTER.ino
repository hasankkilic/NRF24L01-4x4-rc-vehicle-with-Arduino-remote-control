#include <SPI.h> 
#include <nRF24L01.h>
#include <RF24.h>
#include<Servo.h>

#define CE_PIN   9
#define CSN_PIN 10
#define x A0 // x 
#define y A1 //y 




Servo sg90;
const byte pot_pini = 3;
int potundegeri;



const uint64_t pipe = 0xE8E8F0F0E1LL; 
RF24 radio(CE_PIN, CSN_PIN); 
int sebeke[9];  
int msg[1];

void setup() 
{
  sg90.attach(3);
  radio.begin();
  radio.openWritingPipe(pipe);
 
 

  
  
  
}

void loop()   
{

  sebeke[0] = analogRead(x);
  sebeke[1] = analogRead(y);
 
 
  radio.write( sebeke, sizeof(sebeke) ); 
 if (radio.available()){

bool done = false;
 }
}
