#include <Arduino.h>

#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978

int bpm = 119;

struct Note
{
  int frequency;
  float time;
  float duration;
};
//FADED - Note notes[] = {{NOTE_FS5, 0, 0.5}, {NOTE_FS5, 0.5, 0.5}, {NOTE_DS5, 1, 0.5}, {NOTE_FS5, 1.5, 0.5}, {NOTE_DS5, 2, 0.5}, {NOTE_FS5, 2.5, 0.5}, {NOTE_GS5, 3, 0.5}, {NOTE_AS5, 3.5, 1}, {NOTE_FS5, 4.5, 0.5}, {NOTE_FS5, 5, 0.5}, {NOTE_CS5, 5.5, 0.75}, {NOTE_AS5, 6.25, 3.25}, {NOTE_FS5, 10, 0.5}, {NOTE_FS5, 10.5, 0.5}, {NOTE_FS5, 11, 0.5}, {NOTE_E5, 11.5, 1.5}, {NOTE_E5, 13, 0.5}, {NOTE_E5, 13.5, 0.5}, {NOTE_DS5, 14, 0.5}, {NOTE_FS5, 14.5, 1}, {NOTE_FS5, 16, 0.5}, {NOTE_FS5, 16.5, 0.5}, {NOTE_DS5, 17, 0.5}, {NOTE_FS5, 17.5, 0.5}, {NOTE_DS5, 18, 0.5}, {NOTE_FS5, 18.5, 0.5}, {NOTE_GS5, 19, 0.5}, {NOTE_AS5, 19.5, 1}, {NOTE_FS5, 20.5, 0.5}, {NOTE_FS5, 21, 0.5}, {NOTE_CS5, 21.5, 0.75}, {NOTE_AS5, 22.25, 2.25}, {NOTE_FS5, 26, 0.5}, {NOTE_FS5, 26.5, 0.5}, {NOTE_GS5, 27, 2}, {NOTE_AS5, 30, 0.5}, {NOTE_AS5, 30.5, 0.5}, {NOTE_AS5, 31, 0.5}};

Note notes[] = {{NOTE_GS5, 0, 0.5}, {NOTE_GS5, 0.5, 0.5}, {NOTE_GS4, 1, 0.5}, {NOTE_GS4, 1.5, 0.5}, {NOTE_DS5, 2, 0.5}, {NOTE_DS5, 2.5, 0.5}, {NOTE_GS4, 3, 0.5}, {NOTE_GS4, 3.5, 0.5}, {NOTE_GS5, 4, 0.5}, {NOTE_GS5, 4.5, 0.5}, {NOTE_E5, 5, 0.5}, {NOTE_B4, 5.5, 0.5}, {NOTE_FS5, 6, 0.5}, {NOTE_FS5, 6.5, 0.5}, {NOTE_FS4, 7, 0.5}, {NOTE_FS4, 7.5, 0.5}, {NOTE_GS5, 8, 0.5}, {NOTE_GS5, 8.5, 0.5}, {NOTE_GS4, 9, 0.5}, {NOTE_GS4, 9.5, 0.5}, {NOTE_DS5, 10, 0.5}, {NOTE_DS5, 10.5, 0.5}, {NOTE_GS4, 11, 0.5}, {NOTE_GS4, 11.5, 0.5}, {NOTE_GS5, 12, 0.5}, {NOTE_GS5, 12.5, 0.5}, {NOTE_E5, 13, 0.5}, {NOTE_B4, 13.5, 0.5}, {NOTE_FS5, 14, 0.5}, {NOTE_FS5, 14.5, 0.5}, {NOTE_FS4, 15, 0.5}, {NOTE_FS4, 15.5, 0.5}, {NOTE_B5, 16, 0.5}, {NOTE_B5, 16.5, 0.5}, {NOTE_B5, 17, 0.5}, {NOTE_B5, 17.5, 0.5}, {NOTE_B5, 18, 0.5}, {NOTE_B5, 18.5, 0.5}, {NOTE_B5, 19, 0.5}, {NOTE_B5, 19.5, 0.5}, {NOTE_B5, 20, 0.5}, {NOTE_B5, 20.5, 0.5}, {NOTE_B5, 21, 0.5}, {NOTE_B5, 21.5, 0.5}, {NOTE_CS5, 22, 0.5}, {NOTE_B5, 22.5, 0.25}, {NOTE_CS5, 23, 0.5}, {NOTE_B5, 23.5, 0.25}, {NOTE_DS6, 24, 0.5}, {NOTE_DS6, 24.5, 0.5}, {NOTE_DS6, 25, 0.5}, {NOTE_DS6, 25.5, 0.5}, {NOTE_DS6, 26, 0.5}, {NOTE_DS6, 26.5, 0.5}, {NOTE_DS6, 27, 0.5}, {NOTE_DS6, 27.5, 0.5}, {NOTE_DS6, 28, 0.5}, {NOTE_DS6, 28.5, 0.5}, {NOTE_DS6, 29, 0.5}, {NOTE_DS6, 29.5, 0.5}, {NOTE_E6, 30, 0.5}, {NOTE_DS6, 30.5, 0.25}, {NOTE_E6, 31, 0.5}, {NOTE_DS6, 31.5, 0.25}, {NOTE_B5, 32, 0.5}, {NOTE_B5, 32.5, 0.5}, {NOTE_B5, 33, 0.5}, {NOTE_B5, 33.5, 0.5}, {NOTE_B5, 34, 0.5}, {NOTE_B5, 34.5, 0.5}, {NOTE_B5, 35, 0.5}, {NOTE_B5, 35.5, 0.5}, {NOTE_B5, 36, 0.5}, {NOTE_B5, 36.5, 0.5}, {NOTE_B5, 37, 0.5}, {NOTE_B5, 37.5, 0.5}, {NOTE_CS5, 38, 0.5}, {NOTE_B5, 38.5, 0.25}, {NOTE_CS5, 39, 0.5}, {NOTE_B5, 39.5, 0.25}, {NOTE_DS6, 40, 0.5}, {NOTE_DS6, 40.5, 0.5}, {NOTE_DS6, 41, 0.5}, {NOTE_DS6, 41.5, 0.5}, {NOTE_DS6, 42, 0.5}, {NOTE_DS6, 42.5, 0.5}, {NOTE_DS6, 43, 0.5}, {NOTE_DS6, 43.5, 0.5}, {NOTE_DS6, 44, 0.5}, {NOTE_DS6, 44.5, 0.5}, {NOTE_DS6, 45, 0.5}, {NOTE_DS6, 45.5, 0.5}, {NOTE_E6, 46, 0.5}, {NOTE_DS6, 46.5, 0.25}, {NOTE_E6, 47, 0.5}, {NOTE_DS6, 47.5, 0.25}};


void setup()
{
  Serial.begin(9600);
  
}

void loop()
{
  int millisBeginning = millis();

  for (unsigned int i = 0; i < sizeof(notes) / sizeof(notes[0]); i++)
  {
    int beat_length = 60.0 / bpm * 1000;

    int delayMillis = beat_length * notes[i].time - (millis() - millisBeginning);
    Serial.println(delayMillis);
    if (delayMillis > 0)
      delay(delayMillis);

    int noteDuration = beat_length * notes[i].duration - 10;
    Serial.println(noteDuration);

    tone(A0, notes[i].frequency, noteDuration);
    delay(noteDuration);
    noTone(A0);
  }
}