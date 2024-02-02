
int entreeAnalogique = 2;
int entreeAnalogique2 = 14;

 

#define R1 430.0F
 
void setup()
{
pinMode(5, OUTPUT);

Serial.begin(115200);
}
 
 
void loop()
{


float valeurLue = (float)analogRead(entreeAnalogique);
float valeurLue2 = (float)analogRead(entreeAnalogique2);
 

float resistanceLue = (valeurLue * R1) / (1023.0F - valeurLue);
float resistanceLue2 = (valeurLue2 * R1) / (1023.0F - valeurLue2);


if(abs(resistanceLue) < 950 && abs(resistanceLue2) > 750){
  tone(5, 900);
  delay(500);
  noTone(5);
}


if(abs(resistanceLue2) <810 && abs(resistanceLue) > 950){
  tone(5, 500);
  delay(500);
  noTone(5);
}
 
 

Serial.print("Resistance 1: ");
Serial.print(abs(resistanceLue));
Serial.println("Ohms");

Serial.print("Resistance 2: ");
Serial.print(abs(resistanceLue2));
Serial.println("Ohms");




delay(250);
}
