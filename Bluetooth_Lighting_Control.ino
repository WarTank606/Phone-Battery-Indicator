#include <AltSoftSerial.h>
AltSoftSerial ASSserial; 
 
byte LEDPin25 = 2;
byte LEDPin50 = 3;
byte LEDPin75 = 4;
byte LEDPin100 = 5;

char Indicator=' ';
char gotdata = ' ';
char Statue = ' ';



void setup() 
{
    Serial.begin(9600);
    Serial.print("Sketch:   ");   Serial.println(__FILE__);
    Serial.print("Uploaded: ");   Serial.println(__DATE__);
    Serial.println(" ");
 
    ASSserial.begin(9600);  
    Serial.println("ASSserial started at 9600");
    Serial.println(" ");
 
    pinMode(LEDPin25, OUTPUT); 
    pinMode(LEDPin50, OUTPUT); 
    pinMode(LEDPin75, OUTPUT); 
    pinMode(LEDPin100, OUTPUT); 

}
 
void loop()
{     
     // Read from the Bluetooth module and turn the LED on and off
    if (ASSserial.available())
    {
      
        gotdata = ASSserial.read();
        
        Serial.print("Indicator: ");
        Serial.println(Indicator);

        Serial.print("Statue: ");
        Serial.println(Statue);

        if (gotdata == 49 or gotdata == 50 or gotdata == 51 or gotdata == 52)
        {
          Indicator = gotdata;   
        }
        else
        {
          Statue = gotdata;
        }
 
        // The ascii code for 1 is dec 49
        // The ascii code for 2 is dec 50
        // The ascii code for 3 is dec 51
        // The ascii code for 4 is dec 52
        
        // The ascii code for 5 is dec 53
        // The ascii code for 6 is dec 54
        
        if ( Indicator== 49) 
        {
          digitalWrite(LEDPin25, HIGH);
          digitalWrite(LEDPin50, LOW);
          digitalWrite(LEDPin75, LOW);
          digitalWrite(LEDPin100, LOW); 
        }
        else if ( Indicator== 50) 
        { 
          digitalWrite(LEDPin25, LOW);
          digitalWrite(LEDPin50, HIGH);
          digitalWrite(LEDPin75, LOW);
          digitalWrite(LEDPin100, LOW);
        }
        else if ( Indicator== 51) 
        { 
          digitalWrite(LEDPin25, LOW);
          digitalWrite(LEDPin50, LOW);
          digitalWrite(LEDPin75, HIGH);
          digitalWrite(LEDPin100, LOW);
        }
        else if ( Indicator== 52) 
        { 
          digitalWrite(LEDPin25, LOW);
          digitalWrite(LEDPin50, LOW);
          digitalWrite(LEDPin75, LOW);
          digitalWrite(LEDPin100, HIGH);
        }



        if (Statue == 54 and Indicator == 49)
        {
            delay(1000);
            digitalWrite(LEDPin25, LOW);
            delay(1000);
            digitalWrite(LEDPin25, HIGH);
            delay(1000);
            digitalWrite(LEDPin25, LOW);
            delay(1000);
            digitalWrite(LEDPin25, HIGH);
            delay(1000);
            digitalWrite(LEDPin25, LOW);
            delay(1000);
            digitalWrite(LEDPin25, HIGH);
            delay(1000);
            digitalWrite(LEDPin25, LOW);
            delay(1000); 
        }
        else if (Statue == 54 and Indicator == 50)
        {
            delay(1000);
            digitalWrite(LEDPin50, LOW);
            delay(1000);
            digitalWrite(LEDPin50, HIGH);
            delay(1000);
            digitalWrite(LEDPin50, LOW);
            delay(1000);
            digitalWrite(LEDPin50, HIGH);
            delay(1000);
            digitalWrite(LEDPin50, LOW);
            delay(1000);
            digitalWrite(LEDPin50, HIGH);
            delay(1000);
            digitalWrite(LEDPin50, LOW);   
        }
        else if (Statue == 54 and Indicator == 51)
        {
            delay(1000);
            digitalWrite(LEDPin75, LOW);
            delay(1000);
            digitalWrite(LEDPin75, HIGH);
            delay(1000);
            digitalWrite(LEDPin75, LOW);
            delay(1000);
            digitalWrite(LEDPin75, HIGH);
            delay(1000);
            digitalWrite(LEDPin75, LOW);
            delay(1000);
            digitalWrite(LEDPin75, HIGH);
            delay(1000);
            digitalWrite(LEDPin75, LOW);
        }
        else if (Statue == 54 and Indicator == 52)
        {
            delay(1000);
            digitalWrite(LEDPin100, LOW);
            delay(1000);
            digitalWrite(LEDPin100, HIGH);
            delay(1000);
            digitalWrite(LEDPin100, LOW);
            delay(1000);
            digitalWrite(LEDPin100, HIGH);
            delay(1000);
            digitalWrite(LEDPin100, LOW);
            delay(1000);
            digitalWrite(LEDPin100, HIGH);
            delay(1000);
            digitalWrite(LEDPin100, LOW);
        }
    }
}
