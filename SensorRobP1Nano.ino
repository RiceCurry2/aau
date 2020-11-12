/*
rxTxMegaNano = D0;
imOkWire = D1;
sensorNumGRP1 = D2;
sensorNumGRP2 = D3;
sensorNumGRP3 = D4;
sensorErrorType1 = D5;
sensorErrorType2 = D6;
sensor1Anode = D7;
sensor1Katode = D8;
sensor2Anode = D9;
sensor2Katode = D10;
sensor3Anode = D11;
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
  digitalWrite (D7,LOW);
  digitalWrite (D8,LOW);
  digitalWrite (D9,LOW);
  digitalWrite (D10,LOW);
  digitalWrite (D11,LOW);
  digitalWrite (D12,LOW);
}

//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//
//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//Main//
//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//----//

}

void loop() {
   digitalWrite (D1,HIGH);
  if digitalRead (D0) = LOW {
    if digitalRead (D7) = LOW {
      digitalWrite (D1, LOW);
      digitalWrite (D2, HIGH);
      digitalWrite (D5, HIGH);
    }
    if digitalRead (D8) = LOW {
      digitalWrite (D1, LOW);
      digitalWrite (D2, HIGH);
      digitalWrite (D6, HIGH);
    }
    if digitalRead (D9) = LOW {
      digitalWrite (D1, LOW);
      digitalWrite (D3, HIGH);
      digitalWrite (D5, HIGH);
    }
    if digitalRead (D10) = LOW {
      digitalWrite (D1, LOW);
      digitalWrite (D3, HIGH);
      digitalWrite (D6, HIGH);
    } 
    if digitalRead (D11) = LOW {
      digitalWrite (D1, LOW);
      digitalWrite (D4, HIGH);
      digitalWrite (D5, HIGH);
    }
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

  
