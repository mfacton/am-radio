const byte ANTENNA = 9;

int note;

byte note_c = 0;
long start_note;

//C#6 - 26
//B5 - 24
//F#5 - 22
//D6 - 27

int note_time[] = {10000, 500,9000, 200, 11000, 500,9000, 200, 12000, 500,9000, 200};
byte len = sizeof(note_time)/4;

void setup()
{
  // set up Timer 1
  TCCR1A = _BV (COM1A0);
  TCCR1B = _BV(WGM12) | _BV(CS10);
  OCR1A =  9;//800khz
  
  note = note_time[note_c*2];
  start_note = millis();
}

void loop()
{
  if (millis() - start_note >= note_time[(note_c*2)+1]) {
    note_c ++;
    if (note_c >= len) {
      note_c = 0;
    }
    note = note_time[note_c*2];
    start_note = millis();
  }
  pinMode (ANTENNA, OUTPUT);
  delayMicroseconds(note);
  pinMode (ANTENNA, INPUT);
  delayMicroseconds(note);
}
