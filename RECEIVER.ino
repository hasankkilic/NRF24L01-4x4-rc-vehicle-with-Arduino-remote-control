#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define CE_PIN   9
#define CSN_PIN 10
#include<Servo.h>



const int motor1 = 6;
int x_hiz=0;
int y_hiz=0;


Servo sg90;
const byte y = 3;
int potundegeri;


const uint64_t pipe = 0xE8E8F0F0E1LL;

RF24 radio(CE_PIN, CSN_PIN); 

int sebeke[9]; 

void setup()   
{
 pinMode(motor1,OUTPUT);

 
 sg90.attach(3);


  
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();;


  
}


void loop() {
  if ( radio.available() ) //Eğer sinyal algılarsan...
  {
    radio.read(sebeke, sizeof(sebeke) ); 
    



hareket(sebeke[0],sebeke[1],sebeke[2],sebeke[3],sebeke[4],sebeke[5],sebeke[6],sebeke[7],sebeke[8]);

  }
}

void hareket(int x, int y, int but, int sg90, int button3, int button4, int button5, int button6, int button7) {
 
 x_hiz= map(x,0,1023,0,255);
 analogWrite(motor1, x_hiz);

  potundegeri = analogRead(y);
  int y_hiz= map(potundegeri,0,1023,0,180);
//  sg90.write( y_hiz);
// analogWrite(sg90, y_hiz);

  }

