/*
SafetyCircuitHL = D37;
signal1HL = D39;
signal2HL = D40;
signal3HL = D41;
sensor1HL = D42;
sensor2HL = D43;
sensor3HL = D44;
sensorErrorType2 = D45;
sensorErrorType1 = D46;
sensorNumGRP3 = D47;
sensorNumGRP2 = D48;
sensorNumGRP1 = D49;
imOkWire = D50;
rxTxMegaNano = D51;
testing1Tx = D52;
testing2Tx = D53 ;
*/

#include <ros.h>
#include <std_msgs/Int8.h>
#include <std_msgs/Empty.h>
#include "sensor_mannager/safetyIO.h"
#include "sensor_mannager/sensorData.h"
#include "sensor_mannager/sensorIO.h"


void messageCb(const sensor_mannager::sensorIO& sensorIO)
{
  //Switch sensor 1 ON and advertise state to safety circuit
  if(sensorIO.sensor1IO == 1)
  {
    digitalWrite (42, HIGH);
    digitalWrite (51, LOW);
  }

  //Advertise state to safety sercuit and switch sensor 1 OFF
  if (sensorIO.sensor1IO == 0)
  {
    digitalWrite (51, HIGH);
    digitalWrite (42, LOW);
  }

  //Switch sensor 2 ON and advertise state to safety circuit  
  if(sensorIO.sensor2IO == 1)
  {
    digitalWrite (43, HIGH);
    digitalWrite (51, LOW);  
  }

  //Advertise state to safety sercuit and switch sensor 2 OFF
  if (sensorIO.sensor2IO == 0)
  {
    digitalWrite (51, HIGH);
    digitalWrite (43, LOW);
  }
  
  //Switch sensor 3 ON and advertise state to safety circuit//
  if(sensorIO.sensor3IO == 1)
  {
    digitalWrite (44, HIGH);
    digitalWrite (51, LOW);
  }

  //Advertise state to safety sercuit and switch sensor 3 OFF
  if (sensorIO.sensor3IO == 0)
  {
    digitalWrite (51, HIGH);
    digitalWrite (44, LOW);
  }
}
void handlingCb(const sensor_mannager::safetyIO& safetyIO)
{
  //Switch safety circuit OFF
  if (safetyIO.safetyState == 0)
  {
    digitalWrite (37, LOW);
  }

  //Switch safety circuit ON
  if (safetyIO.safetyState == 1)
  {
    digitalWrite (37, HIGH);
  }
}    

ros::NodeHandle  nh;

sensor_mannager::sensorData msg1;
ros::Publisher saspub("sensorAndSafetyTopic", &msg1);

ros::Subscriber<sensor_mannager::sensorIO> sub("sensorStateTopic", &messageCb);
//ros::Subscriber<sensor_mannager::safetyIO> sub("safetyStateTopic", &handlingCb);

//----------------//----------------//----------------//----------------//----------------//
//Global variables//Global variables//Global variables//Global variables//Global variables//
//----------------//----------------//----------------//----------------//----------------//


//------------//------------//------------//------------//------------//------------//------------//
//Global setup//Global setup//Global setup//Global setup//Global setup//Global setup//Global setup//
//------------//------------//------------//------------//------------//------------//------------//

void setup() 
{
  pinMode (37, OUTPUT);
  pinMode (39, INPUT);
  pinMode (40, INPUT);
  pinMode (41, INPUT);
  pinMode (42, OUTPUT);
  pinMode (43, OUTPUT);
  pinMode (44, OUTPUT);
  pinMode (45, INPUT);
  pinMode (46, INPUT);
  pinMode (47, INPUT);
  pinMode (48, INPUT);
  pinMode (49, INPUT);
  pinMode (50, INPUT);
  pinMode (51, OUTPUT);

  digitalWrite (37,HIGH);
  digitalWrite (39,LOW);
  digitalWrite (40,LOW);
  digitalWrite (41,LOW);
  digitalWrite (42,LOW);
  digitalWrite (43,LOW);
  digitalWrite (44,LOW);
  digitalWrite (45,LOW);
  digitalWrite (46,LOW);
  digitalWrite (47,LOW);
  digitalWrite (48,LOW);
  digitalWrite (49,LOW);
  digitalWrite (50,HIGH);
  digitalWrite (51,LOW);


  nh.initNode();
  nh.advertise(saspub);
  nh.subscribe(sub);
}

//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//
//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//
//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//

void loop()
{
    //Sensor IC status
    msg1.sensorICStatus = 1;
    saspub.publish( &msg1);
    
    // Contact 1
    if (digitalRead (39) == HIGH)
    {
      msg1.contact1 = 1;
      saspub.publish( &msg1);
    }
    // Contact 2
    if (digitalRead (40) == HIGH)
    {
      msg1.contact2 = 1;
      saspub.publish( &msg1);
    }
    // Contact 3
    if (digitalRead (41) == HIGH)
    {
      msg1.contact3 = 1;
      saspub.publish( &msg1);
    }
    // safetyNotOk
    if ((digitalRead (50) == LOW) && (digitalRead (37) == HIGH))
    {
      msg1.safetyNotOK = 1;
      saspub.publish( &msg1);
    }

    //Safety ok
    if (digitalRead (50) == HIGH)
    {
      msg1.safetyOk = 1;
      saspub.publish( &msg1);
    }

    //Safety OFF
    if ((digitalRead (50) == LOW) && (digitalRead (37) == LOW))
    {
      msg1.safetyOff = 1;
      saspub.publish( &msg1);
    }
    
    //sensor1Error1
    if ((digitalRead (49) == HIGH) && (digitalRead (46) == HIGH))
    {
      msg1.sensor1Error1 = 1;
      saspub.publish( &msg1);
    }
    //sensor1Error2
    if ((digitalRead (49) == HIGH) && (digitalRead (45) == HIGH))
    {
      msg1.sensor1Error2 = 1;
      saspub.publish( &msg1);
    }
    //sensor2Error1
    if ((digitalRead (48) == HIGH) && (digitalRead (46) == HIGH))
    {
      msg1.sensor2Error1 = 1;
      saspub.publish( &msg1);
    }
    //sensor2Error2
    if ((digitalRead (48) == HIGH) && (digitalRead (45) == HIGH))
    {
      msg1.sensor2Error2 = 1;
      saspub.publish( &msg1);
    }
    //sensor3Error1
    if ((digitalRead (47) == HIGH) && (digitalRead (46) == HIGH))
    {
      msg1.sensor3Error1 = 1;
      saspub.publish( &msg1);
    }
    //sensor3Error2
    if ((digitalRead (47) == HIGH) && (digitalRead (45) == HIGH))
    {
      msg1.sensor3Error2 = 1;
      saspub.publish( &msg1);
    }
    nh.spinOnce();
    delay(100);
}
