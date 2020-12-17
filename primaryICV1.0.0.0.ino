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
    digitalWrite (D42, HIGH);
    digitalWrite (D51, LOW);
  }

  //Advertise state to safety sercuit and switch sensor 1 OFF
  if (sensorIO.sensor1IO == 0)
  {
    digitalWrite (D51, HIGH);
    digitalWrite (D42, LOW);
  }

  //Switch sensor 2 ON and advertise state to safety circuit  
  if(sensorIO.sensor2IO == 1)
  {
    digitalWrite (D43, HIGH);
    digitalWrite (D51, LOW);  
  }

  //Advertise state to safety sercuit and switch sensor 2 OFF
  if (sensorIO.sensor2IO == 0)
  {
    digitalWrite (D51, HIGH);
    digitalWrite (D43, LOW);
  }
  
  //Switch sensor 3 ON and advertise state to safety circuit//
  if(sensorIO.sensor3IO == 1)
  {
    digitalWrite (D44, HIGH);
    digitalWrite (D51, LOW);
  }

  //Advertise state to safety sercuit and switch sensor 3 OFF
  if (sensorIO.sensor3IO == 0)
  {
    digitalWrite (D51, HIGH);
    digitalWrite (D44, LOW);
  }
}
void handlingCb(const sensor_mannager::safetyIO& safetyIO)
{
  //Switch safety circuit OFF
  if (sensorIO.safetyState == 0)
  {
    digitalWrite (D37, LOW);
  }

  //Switch safety circuit ON
  if (sensorIO.safetyState == 1)
  {
    digitalWrite (D37, HIGH);
  }
}    

ros::NodeHandle  nh;

std_msgs::Int8 sensorIO;
ros::Publisher chatter("sensorAndSafetyTopic", &sensorData);

ros::Subscriber<safety_mannager::sensorIO> sub("sensorStateTopic", &messageCb);
ros::Subscriber<safety_mannager::safetyIO> sub("safetyStateTopic", &handlingCb);

//----------------//----------------//----------------//----------------//----------------//
//Global variables//Global variables//Global variables//Global variables//Global variables//
//----------------//----------------//----------------//----------------//----------------//


//------------//------------//------------//------------//------------//------------//------------//
//Global setup//Global setup//Global setup//Global setup//Global setup//Global setup//Global setup//
//------------//------------//------------//------------//------------//------------//------------//

void setup() 
{
  pinMode (D37, OUTPUT);
  pinMode (D39, INPUT);
  pinMode (D40, INPUT);
  pinMode (D41, INPUT);
  pinMode (D42, OUTPUT);
  pinMode (D43, OUTPUT);
  pinMode (D44, OUTPUT);
  pinMode (D45, INPUT);
  pinMode (D46, INPUT);
  pinMode (D47, INPUT);
  pinMode (D48, INPUT);
  pinMode (D49, INPUT);
  pinMode (D50, INPUT);
  pinMode (D51, OUTPUT);

  digitalWrite (D37,HIGH);
  digitalWrite (D39,LOW);
  digitalWrite (D40,LOW);
  digitalWrite (D41,LOW);
  digitalWrite (D42,LOW);
  digitalWrite (D43,LOW);
  digitalWrite (D44,LOW);
  digitalWrite (D45,LOW);
  digitalWrite (D46,LOW);
  digitalWrite (D47,LOW);
  digitalWrite (D48,LOW);
  digitalWrite (D49,LOW);
  digitalWrite (D50,HIGH);
  digitalWrite (D51,LOW);

  nh.initNode();
  nh.advertise(sensorAndSafetyTopic);
  nh.subscribe(sub);
}

//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//
//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//
//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//

void loop()
{
  while (ros::ok())
  {
    //Sensor IC status
    sensorData.sensorICStatus = 1;
    sensorAndSafetyTopic.publish( &sensorData);
    
    // Contact 1
    if (digitalRead (D39) = HIGH)
    {
      sensorData.contact1 = 1;
      sensorAndSafetyTopic.publish( &sensorData);  
    }
    // Contact 2
    if (digitalRead (D40) = HIGH)
    {
      sensorData.contact2 = 1;
      sensorAndSafetyTopic.publish( &sensorData); 
    }
    // Contact 3
    if (digitalRead (D41) = HIGH)
    {
      sensorData.contact3 = 1;
      sensorAndSafetyTopic.publish( &sensorData); 
    }
    // safetyNotOk
    if ((digitalRead (D50) = LOW) && (digitalRead (D37) = HIGH))
    {
      sensorData.safetyNotOk = 1;
      sensorAndSafetyTopic.publish( &sensorData); 
    }

    //Safety ok
    if (digitalRead (D50) = HIGH)
    {
      sensorData.safetyOk = 1;
      sensorAndSafetyTopic.publish( &sensorData);
    }

    //Safety OFF
    if ((digitalRead (50) = LOW) && (digitalRead (D37) = LOW))
    {
      sensorData.safetyOff = 1;
      sensorAndSafetyTopic.publish( &sensorData);
    }
    
    //sensor1Error1
    if ((digitalRead (D49) = HIGH) && (digitalRead (D46) = HIGH))
    {
      sensorData.sensor1error1 = 1;
      sensorAndSafetyTopic.publish( &sensorData);
    }
    //sensor1Error2
    if ((digitalRead (D49) = HIGH) && (digitalRead (D45) = HIGH))
    {
      sensorData.sensor1error2 = 1;
      sensorAndSafetyTopic.publish( &sensorData); 
    }
    //sensor2Error1
    if ((digitalRead (D48) = HIGH) && (digitalRead (D46) = HIGH))
    {
      sensorData.sensor2error1 = 1;
      sensorAndSafetyTopic.publish( &sensorData);
    }
    //sensor2Error2
    if ((digitalRead (D48) = HIGH) && (digitalRead (D45) = HIGH))
    {
      sensorData.sensor2error2 = 1;
      sensorAndSafetyTopic.publish( &sensorData); 
    }
    //sensor3Error1
    if ((digitalRead (D47) = HIGH) && (digitalRead (D46) = HIGH))
    {
      sensorData.sensor3error1 = 1;
      sensorAndSafetyTopic.publish( &sensorData); 
    }
    //sensor3Error2
    if ((digitalRead (D47) = HIGH) && (digitalRead (D45) = HIGH))
    {
      sensorData.sensor3error2 = 1;
      sensorAndSafetyTopic.publish( &sensorData);
    }
    nh.spinOnce();
    delay(100);
  }
}
