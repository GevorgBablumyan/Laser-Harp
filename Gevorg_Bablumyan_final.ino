#include <MIDI.h>

#define Do3 48
#define Re3 50
#define Mi3 52
#define Fa3 53
#define Sol3 55
#define La3 57
#define Si3 59
#define Do4 60

MIDI_CREATE_DEFAULT_INSTANCE();

int notes[] = { Do3, Re3, Mi3, Fa3, Sol3, La3, Si3, Do4 };
int LDR1;
int LDR2;
int LDR3;
int LDR4;
int LDR5;
int LDR6;
int LDR7;
int LDR8;
bool status1;
bool status2;
bool status3;
bool status4;
bool status5;
bool status6;
bool status7;
bool status8;

void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);

  pinMode(A0, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A2, INPUT);
  digitalWrite(A0, 0);
  digitalWrite(A4, 1);

  pinMode(6, INPUT);
  pinMode(7, OUTPUT);  

}

void loop() {
  int channel = map(analogRead(A2), 0, 1023, 1, 4);

  LDR1 = digitalRead(2);
  if (LDR1 == LOW && status1 == 0) {
    MIDI.sendNoteOn(notes[0], 100, channel);
    status1 = 1;

  } else if (LDR1 == HIGH && status1 == 1) {
    MIDI.sendNoteOff(notes[0], 100, channel);
    status1 = 0;
  }

  LDR2 = digitalRead(3);
  if (LDR2 == LOW && status2 == 0) {
    MIDI.sendNoteOn(notes[1], 100, channel);
    status2 = 1;

  } else if (LDR2 == HIGH && status2 == 1) {
    MIDI.sendNoteOff(notes[1], 100, channel);
    status2 = 0;
  }

  LDR3 = digitalRead(4);
  if (LDR3 == LOW && status3 == 0) {
    MIDI.sendNoteOn(notes[2], 100, channel);
    status3 = 1;

  } else if (LDR3 == HIGH && status3 == 1) {
    MIDI.sendNoteOff(notes[2], 100, channel);
    status3 = 0;
  }

  LDR4 = digitalRead(5);
  if (LDR4 == LOW && status4 == 0) {
    MIDI.sendNoteOn(notes[3], 100, channel);
    status4 = 1;

  } else if (LDR4 == HIGH && status4 == 1) {
    MIDI.sendNoteOff(notes[3], 100, channel);
    status4 = 0;
  }

  LDR5 = digitalRead(8);
  if (LDR5 == LOW && status5 == 0) {
    MIDI.sendNoteOn(notes[4], 100, channel);
    status5 = 1;

  } else if (LDR5 == HIGH && status5 == 1) {
    MIDI.sendNoteOff(notes[4], 100, channel);
    status5 = 0;
  }

  LDR6 = digitalRead(9);
  if (LDR6 == LOW && status6 == 0) {
    MIDI.sendNoteOn(notes[5], 100, channel);
    status6 = 1;

  } else if (LDR6 == HIGH && status6 == 1) {
    MIDI.sendNoteOff(notes[5], 100, channel);
    status6 = 0;
  }

  LDR7 = digitalRead(10);
  if (LDR7 == LOW && status7 == 0) {
    MIDI.sendNoteOn(notes[6], 100, channel);
    status7 = 1;

  } else if (LDR7 == HIGH && status7 == 1) {
    MIDI.sendNoteOff(notes[6], 100, channel);
    status7 = 0;
  }

  LDR8 = digitalRead(11);
  if (LDR8 == LOW && status8 == 0) {
    MIDI.sendNoteOn(notes[7], 100, channel);
    status8 = 1;

  } else if (LDR8 == HIGH && status8 == 1) {
    MIDI.sendNoteOff(notes[7], 100, channel);
    status8 = 0;
  }


  digitalWrite(7, LOW);
  delayMicroseconds(10);
  digitalWrite(7, HIGH);
  delayMicroseconds(10);
  digitalWrite(7, LOW);

  int duration = pulseIn(6, HIGH);
  int distance = duration * 0.03 / 2;
  delay(5);
  if(distance > 5 && distance < 50) {
    int value = map(distance, 0, 600, 0, 127);
    MIDI.sendControlChange(1, value, channel);
  }
}
