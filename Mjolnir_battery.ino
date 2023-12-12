
#include "Adafruit_NeoPixel.h"

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        4 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 9 // Popular NeoPixel ring size

//========================USEFUL VARIABLES=============================
int led_ring_brightness = 255; // Adjust it 0 to 255
int flag =0;

// When setting up the NeoPixel library, we tell it how many pixels,
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup() {

  pinMode(4, OUTPUT);
  pinMode(14, INPUT_PULLUP);
  Serial.begin(9600);
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(led_ring_brightness);
  
}

void loop() {

  // switch on the ring in blue
  pixels.clear(); // Set all pixel colors to 'off'

//  //Back to the future 
    for(int i=0; i<9;i++){
  pixels.setPixelColor(i, pixels.Color(0,150,255));
  }

  if((digitalRead(14) == false) && (flag == 0)){
   pixels.setBrightness(0);
   pixels.show();
  flag=1;
  delay(200);
  }

if((digitalRead(14) == false) && (flag == 1)){
   pixels.setBrightness(255);
   pixels.show();
  flag=0;
  delay(200);
  }


pixels.show();


}

