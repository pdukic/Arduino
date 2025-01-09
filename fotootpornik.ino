
int fotootpornik=A1;
int crvenaLED=3;
int zelenaLED=9;

const int prag = 307;
int svjetlost = 0;
float napon = 0;
int ocitanje = 0;
 

void setup()
{
  pinMode(A1, INPUT);
  pinMode(3, OUTPUT);
  pinMode(9, OUTPUT);
  
  Serial.begin(9600);
  
}

void loop()
{
  
  
  
  svjetlost=analogRead(A1);
  Serial.println(svjetlost);
  
  
  if (svjetlost > prag )
  {
    
    ocitanje=analogRead(A1);
    napon = ocitanje * (5.0/1023.0);
    Serial.println(napon);
    
    if(napon > 2.0 ){
    
    for (int i=127; i<256; i+=5)
    {
      digitalWrite(9 ,i);
      delay(3);
    }
  
    for (int i= 256; i > 127; i--){
  	digitalWrite(9, i);
    delay(3);
  }
  }
  }
  
  else 
  {
	digitalWrite(3, HIGH);
    digitalWrite(9, LOW);
  }
  
  
 
}