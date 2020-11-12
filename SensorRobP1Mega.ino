/*
sensor1HL = D38;
signal1HL = D39;
sensor2HL = D40;
signal2HL = D41;
sensor3HL = D42;
signal3HL = D43;
sensorErrorType2 = D44;
sensorErrorType1 = D45;
sensorNumGRP3 = D46;
sensorNumGRP2 = D47;
sensorNumGRP1 = D48;
imOkWire = D49;
rxTxMegaNano = D50;
testing1Tx = D51;
testing2Tx = D52 ;
*/

//----------------//----------------//----------------//----------------//----------------//
//Global variables//Global variables//Global variables//Global variables//Global variables//
//----------------//----------------//----------------//----------------//----------------//


//------------//------------//------------//------------//------------//------------//------------//
//Global setup//Global setup//Global setup//Global setup//Global setup//Global setup//Global setup//
//------------//------------//------------//------------//------------//------------//------------//

void setup() {

  pinMode (D38, OUTPUT);
  pinMode (D39, INPUT);
  pinMode (D40, OUTPUT);
  pinMode (D41, INPUT);
  pinMode (D42, OUTPUT);
  pinMode (D43, INPUT);
  pinMode (D44, INPUT);
  pinMode (D45, INPUT);
  pinMode (D46, INPUT);
  pinMode (D47, INPUT);
  pinMode (D48, INPUT);
  pinMode (D49, INPUT);
  pinMode (D50, OUTPUT);
  pinMode (D51, OUTPUT);
  pinMode (D52, OUTPUT);
  
  digitalWrite (D38,LOW);
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
  digitalWrite (D50,LOW);
  digitalWrite (D51,LOW);
  digitalWrite (D52,LOW);


//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//
//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//
//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//

}

void loop() {
  if /*something input ROS*/{
    digitalWrite (D38, HIGH);
    digitalWrite (D50, LOW);
  }
  if /*something input ROS*/{
    digitalWrite (D40, HIGH);
    digitalWrite (D50, LOW);  
  }
  if /*something input ROS*/{
    digitalWrite (D42, HIGH);
    digitalWrite (D50, LOW);
  }
  if digitalRead (D39) = HIGH {
    /*something output ROS*/  
  }
  if digitalRead (D41) = HIGH {
    /*something output ROS*/  
  }
  if digitalRead (D43) = HIGH {
    /*something output ROS*/  
  }
  if digitalRead (D49) = LOW {
    /*something output ROS*/
  }
  if (digitalRead (D48) = HIGH) && (digitalRead (D45) = HIGH) {
    /*something output ROS*/ 
  }
  if (digitalRead (D48) = HIGH) && (digitalRead (D44) = HIGH) {
    /*something output ROS*/ 
  }
  if (digitalRead (D47) = HIGH) && (digitalRead (D45) = HIGH) {
    /*something output ROS*/ 
  }
  if (digitalRead (D47) = HIGH) && (digitalRead (D44) = HIGH) {
    /*something output ROS*/ 
  }
  if (digitalRead (D46) = HIGH) && (digitalRead (D45) = HIGH) {
    /*something output ROS*/ 
  }
  if (digitalRead (D46) = HIGH) && (digitalRead (D44) = HIGH) {
    /*something output ROS*/ 
  }
}

//------------------//------------------//------------------//------------------//------------------//
//Function libraries//Function libraries//Function libraries//Function libraries//Function libraries//
//------------------//------------------//------------------//------------------//------------------//
