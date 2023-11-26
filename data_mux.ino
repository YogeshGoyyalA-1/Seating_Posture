const int analogInPin = A0;      // Analog input pin connected to the mux output
const int s0 = 2;            // Pin connected to S0 control pin of the mux
const int s1 = 3;            // Pin connected to S1 control pin of the mux
const int s2 = 4;            // Pin connected to S2 control pin of the mux
const int s3 = 5;   
void setup() {
  // put your setup code here, to run once:
  pinMode(s0,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  Serial.begin(9600);

}
int mux[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
void setMuxChannel(int channel)
{
    digitalWrite(s0,bitRead(channel,0));
    digitalWrite(s1,bitRead(channel,1));
    digitalWrite(s2,bitRead(channel,2));
    digitalWrite(s3,bitRead(channel,3));
}
void displayData()
// dumps captured data from array to serial monitor
{
   for (int i = 0; i < 15; i++) {
    Serial.print(mux[i]);
    if (i < 14) {
      Serial.print(",");
    }
  }
  Serial.println();  // Move to the next line after printing the values
}

void loop() {
//   Serial.println(mux[0]);
  // put your main code here, to run repeatedly:
  for(int i=0;i<15;i++)
  {
    setMuxChannel(i);
    if(i>8 && analogRead(analogInPin)>420)
    {
         mux[i]=analogRead(analogInPin);
    }
    else if(i<=8&&analogRead(analogInPin)>200)
     {
      mux[i]=analogRead(analogInPin);
     
     }
     else
     {
       mux[i]=0;
     }
 
    delay(5);
    
  }
  displayData();
//  for(int i=0;i<15;i++)
//  {
//    mux[i]=0;
//  }
  delay(25); 
  

}
