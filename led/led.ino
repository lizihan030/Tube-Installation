 #include <Adafruit_NeoPixel.h>
#define PIN            6
#define NUMPIXELS      140

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int temp,data; 
int NUM;
int p=140;
void setup() 
{ 
Serial.begin(9600);
pixels.begin(); 
} 

void loop() 
{ 
int temp = analogRead(0);  
//Serial.println(temp); 
delay(50);
NUM=(temp-600)*2;
Serial.println(NUM);

if(p==-1)p=NUMPIXELS;
if( (p-NUM)<5) 
{
 
      p=NUM+3;
}

else{
    for(int j=p-3; j<p; j++){
    pixels.setPixelColor(j, pixels.Color(250,100,0));
    }
    for(int j=p; j<NUMPIXELS; j++){
    pixels.setPixelColor(j, pixels.Color(0,0,0));
    }
    pixels.show();
    p--;
}

if(NUM>0)sound();
}

void sound()
{
  for(int i=0;i<NUM;i++)
{
   pixels.setPixelColor(i, pixels.Color(0,150,0));
   pixels.show();
   delay(10);
}

for(int i=NUM;i>=0;i--)
{
   pixels.setPixelColor(i, pixels.Color(0,0,0));
   pixels.show(); 
   delay(10);
}
}












