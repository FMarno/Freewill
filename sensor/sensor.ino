/* Robot Line Follow */

#include <ArduinoRobot.h> // include the robot library

#define HIGHSPEED 120
#define MEDIUMSPEED 100
#define LOWSPEED 80
#define THRESHOLD 850

long timerOrigin; // used for counting elapsed time
int running = 0;

void setup() {
  // initialize the Robot, SD card, display, and speaker
  Robot.begin();
  Robot.beginTFT();
  Robot.beginSD();

  //set the motor board into line-follow mode
  Robot.setMode(MODE_SIMPLE);

  Robot.motorsWrite(0,0);
  Robot.clearScreen();
}
void loop() {
  
    Robot.updateIR();
    
    showSensors();

    if (Robot.IRarray[0] < THRESHOLD && Robot.IRarray[1] < THRESHOLD){
      running = 0;
      right();
    } else if (Robot.IRarray[3] < THRESHOLD && Robot.IRarray[4] < THRESHOLD){
      running = 0;
      left();
    } else if (Robot.IRarray[0] < THRESHOLD){
      running = 0;
      hardRight();
    } else if (Robot.IRarray[4] < THRESHOLD){
      running = 0;
      hardLeft();
    } else if (Robot.IRarray[1] < THRESHOLD){
      running = 0;
      right();
    } else if (Robot.IRarray[3] < THRESHOLD){
      running = 0;
      left();
    } else if (Robot.IRarray[2] < THRESHOLD){
      running = 0;
      forward();
    } else {
      running++;
      if (running > 50){
        Robot.motorsWrite(-50, -50);
      }
    }

}

void hardLeft(){
  Robot.motorsWrite(-LOWSPEED, LOWSPEED);
}
void hardRight(){
  Robot.motorsWrite(LOWSPEED, -LOWSPEED);
}
void left(){
  Robot.motorsWrite(LOWSPEED, HIGHSPEED);
}
void right(){
  Robot.motorsWrite(HIGHSPEED, LOWSPEED);
}
void forward(){
  Robot.motorsWrite(MEDIUMSPEED, MEDIUMSPEED);
}

void showSensors() {
    Robot.fill(0, 0, 0);
    Robot.stroke(0, 0, 0);
    
    if (Robot.IRarray[0] < THRESHOLD){
      Robot.rect(110,60,10,10);
    }
    
    if (Robot.IRarray[1] < THRESHOLD){
      Robot.rect(90,60,10,10);
    }
    
    if (Robot.IRarray[2] < THRESHOLD){
      Robot.rect(60,60,10,10);
    }
    
    if (Robot.IRarray[3] < THRESHOLD){
      Robot.rect(30,60,10,10);
    }
    
    if (Robot.IRarray[4] < THRESHOLD){
      Robot.rect(10,60,10,10);
    }
    
    Robot.fill(255, 255, 255);
    Robot.stroke(255, 255, 255);
    
    if (Robot.IRarray[0] > THRESHOLD){
      Robot.rect(110,60,10,10);
    }
    
    if (Robot.IRarray[1] > THRESHOLD){
      Robot.rect(90,60,10,10);
    }
    
    if (Robot.IRarray[2] > THRESHOLD){
      Robot.rect(60,60,10,10);
    }
    
    if (Robot.IRarray[3] > THRESHOLD){
      Robot.rect(30,60,10,10);
    }
    
    if (Robot.IRarray[4] > THRESHOLD){
      Robot.rect(10,60,10,10);
    }
}
