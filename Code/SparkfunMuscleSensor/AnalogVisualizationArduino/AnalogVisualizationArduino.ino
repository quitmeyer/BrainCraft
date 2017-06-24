// reads analog input from the five inputs from your arduino board 
// and sends it out via serial

// variables for input pins and
int analogInput[6];
  
// variable to store the value 
int value[6]; 
 
void setup()
{
  // declaration of pin modes
  for(int i=0;i<6;i++)
  {
    analogInput[i] = i+1;
    value[i] = 0;     
    pinMode(analogInput[i], INPUT);    
  }
  
  // begin sending over serial port
  Serial.begin(9600);
}

void loop()
{

    value[0] = analogRead(analogInput[0]);
Serial.println(value[1]);
  delay(10);
}


