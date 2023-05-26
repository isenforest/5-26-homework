/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody
*/

#include "pitches.h"
#define ROW1 13
#define ROW2 12
#define ROW3 11
#define ROW4 10
#define ROW5 9
#define ROW6 8
#define ROW7 7
#define ROW8 6

#define COL1 5
#define COL2 4
#define COL3 3
#define COL4 A4
#define COL5 A3
#define COL6 A2
#define COL7 A1
#define COL8 A0


const int row[] = {
  ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7, ROW8};
const int col[] = {
  COL1,COL2, COL3, COL4, COL5, COL6, COL7, COL8};

byte scan[8][8] = {
  {1,0,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,0,1,0},
  {0,0,0,0,0,0,0,1}
};

byte circle[8][8] = {
  {1,1,0,0,0,0,1,1},
  {1,0,1,1,1,1,0,1},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {1,0,1,1,1,1,0,1},
  {1,1,0,0,0,0,1,1}};

byte line[8][8] = {
  {1,1,1,0,0,1,1,1},
  {1,1,1,0,0,1,1,1},
  {1,1,1,0,0,1,1,1},
  {1,1,1,0,0,1,1,1},
  {1,1,1,0,0,1,1,1},
  {1,1,1,0,0,1,1,1},
  {1,1,1,0,0,1,1,1},
  {1,1,1,0,0,1,1,1}};


byte previousState=1, presentState=1, patternNumber=0;


// notes in the melody:
int melody1[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int melody2[] = {
  NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations1[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

int noteDurations2[] = {
  4, 8, 8, 4, 8, 8, 4, 4
};

int thisNote = -1, noteDuration = 0;
long previousTime = 0, presentTime = 0, pauseBetweenNotes = 0;
int buttonState = 0;

void setup() {
  for (byte i = 0; i <= sizeof(row); i++) {
    pinMode(row[i], OUTPUT);
  }
  for (byte i = 0; i <= sizeof(col); i++) {
    pinMode(col[i], OUTPUT);
  }  

  pinMode(2, INPUT_PULLUP);

  // iterate over the notes of the melody:

}

bool change = true;
void checktoPlay1() {
  presentTime = millis();
    if(presentTime - previousTime >= pauseBetweenNotes) {
      thisNote += 1;
      if(thisNote >= 8){
        thisNote = -1;
        pauseBetweenNotes = 100;
        previousTime = millis();
      }else {
        noteDuration = 1000 / noteDurations1[thisNote];
        tone(A5, melody1[thisNote], noteDuration);
        pauseBetweenNotes = noteDuration * 1.2;
        previousTime = millis();
      }
    }  

}
void checktoPlay2() {
  presentTime = millis();
    if(presentTime - previousTime >= pauseBetweenNotes) {
      thisNote += 1;
      if(thisNote >= 8){
        thisNote = -1;
        pauseBetweenNotes = 100;
        previousTime = millis();
      }else {
        noteDuration = 1000 / noteDurations2[thisNote];
        tone(A5, melody2[thisNote], noteDuration);
        pauseBetweenNotes = noteDuration * 1.2;
        previousTime = millis();
      }
    }  

}*/
void loop() {
  // no need to repeat the melody.
  //buttonState = digitalRead(2);
  //if(buttonState == LOW) change = !change;
  //if(change == true){
    for(int i = 0; i < 8; i++) {
      showPattern(circle);  
      checktoPlay1();
      delay(1);    
    }    
  /*}else{
    for(int i = 0; i < 8; i++) {
      showPattern(line);  
      checktoPlay2();
      delay(1);    
    }    
  }*/
}

void showPattern(byte matrix[8][8]){
  for(byte i = 0; i < 8; i++){
    for(byte j = 0; j < 8; j++){
      digitalWrite(row[j], 1 - scan[i][j]);
      digitalWrite(col[j], 1 - matrix[i][j]);	
    }
    for(byte j = 0; j < 8; j++){
      digitalWrite(row[j], HIGH);
      digitalWrite(col[j], LOW);	
    }
  }
}
