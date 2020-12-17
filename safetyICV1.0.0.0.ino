/*
rxTxMegaNano = D0;
imOkWire = D1;
sensorNumGRP1 = D2;
sensorNumGRP2 = D3;
sensorNumGRP3 = D4;
sensorErrorType1 = D5;
sensorErrorType2 = D6;
sensor1Anode = D7;
sensor2Anode = D8;
sensor3Anode = D9;
sensor1Katode = D10;
sensor2Katode = D11;
sensor3Katode = D12;
*/


//----------------//----------------//----------------//----------------//----------------//
//Global variables//Global variables//Global variables//Global variables//Global variables//
//----------------//----------------//----------------//----------------//----------------//

//------------//------------//------------//------------//------------//------------//------------//
//Global setup//Global setup//Global setup//Global setup//Global setup//Global setup//Global setup//
//------------//------------//------------//------------//------------//------------//------------//

void setup() {
  pinMode (D0, INPUT);
  pinMode (D1, OUTPUT);
  pinMode (D2, OUTPUT);
  pinMode (D3, OUTPUT);
  pinMode (D4, OUTPUT);
  pinMode (D5, OUTPUT);
  pinMode (D6, OUTPUT);
  pinMode (D7, INPUT);
  pinMode (D8, INPUT);
  pinMode (D9, INPUT);
  pinMode (D10, INPUT);
  pinMode (D11, INPUT);
  pinMode (D12, INPUT);
  
  digitalWrite (D0,LOW);
  digitalWrite (D1,LOW);
  digitalWrite (D2,LOW);
  digitalWrite (D3,LOW);
  digitalWrite (D4,LOW);
  digitalWrite (D5,LOW);
  digitalWrite (D6,LOW);
  digitalWrite (D7,HIGH);
  digitalWrite (D8,HIGH);
  digitalWrite (D9,HIGH);
  digitalWrite (D10,HIGH);
  digitalWrite (D11,HIGH);
  digitalWrite (D12,HIGH);
}

//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//
//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//
//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//

}

void loop() {
  //Advertise safety circuit ok
  digitalWrite (D1,HIGH);

  //Check if power is set to not be off
  if digitalRead (D0) = LOW {

    //No power at sensor 1
    if digitalRead (D7) = LOW {
      digitalWrite (D1, LOW);
      digitalWrite (D2, HIGH);
      digitalWrite (D5, HIGH);
    }

    //No power at sensor 2
    if digitalRead (D8) = LOW {
      digitalWrite (D1, LOW);
      digitalWrite (D3, HIGH);
      digitalWrite (D5, HIGH);
    }

    //No power at sensor 3
    if digitalRead (D9) = LOW {
      digitalWrite (D1, LOW);
      digitalWrite (D4, HIGH);
      digitalWrite (D5, HIGH);
    }

    //Short circuit in sensor 1
    if digitalRead (D10) = LOW {
      digitalWrite (D1, LOW);
      digitalWrite (D2, HIGH);
      digitalWrite (D6, HIGH);
    }

    //Short circuit in sensor 2
    if digitalRead (D11) = LOW {
      digitalWrite (D1, LOW);
      digitalWrite (D3, HIGH);
      digitalWrite (D6, HIGH);
    }

    //Short circuit in sensor 3
    if digitalRead (D12) = LOW {
      digitalWrite (D1, LOW);
      digitalWrite (D4, HIGH);
      digitalWrite (D6, HIGH);
    } 
  }  
}
//------------------//------------------//------------------//------------------//------------------//
//Function libraries//Function libraries//Function libraries//Function libraries//Function libraries//
//------------------//------------------//------------------//------------------//------------------//

  
