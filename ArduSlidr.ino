/*

  ArduSlidr
  v0.03 David McGahan
  17 Jan 2015
  @dizymac
  http://www.davidmcgahan.co.nz/ArduSlidr

*/

#include <AccelStepper.h>
AccelStepper drive;

const int startButton = 2; // Start button Pin
int startButtonStatus = 0;

const int resetButton = 3; // Stop and Reset button Pin
int resetButtonStatus = 0;

const int endStop = 4; // Pin for endstop
int endStopStatus = 0;

int shutterTrigger = 5; // Shutter trigger switch

int timeValue = 250; // delay between movement

void setup()
{
  drive.setMaxSpeed(3000);
  drive.setAcceleration(1000);
  
  pinMode(startButton, INPUT);
  pinMode(resetButton, INPUT);
  pinMode(endStop, INPUT);
  pinMode(shutterTrigger, OUTPUT);
}

void loop()
{
  // read input value for Button pins
  startButtonStatus = digitalRead(startButton);
  resetButtonStatus = digitalRead(resetButton);
  endStopStatus = digitalRead(endStop);
   
  //start of loop 
  if (startButtonStatus == HIGH)
  {    
    while(endStopStatus != HIGH)
    {
      for(int i=0; i < 10; i++)
      {
        drive(10500);
        digitalWrite(shutterTrigger, HIGH);
        delay(timeValue);
        digitalWrite(shutterTrigger, LOW);
      }
    }
  }
}
