// PIECE 2 — THE TRANSLATOR (Tier 2).   Owner: Arul
//
// Tier 2 reads the score and turns it into what Tier 3 can act on: hertz and milliseconds.
//   noteToHz(pitch)      a note number from song.h  ->  its frequency in hertz (0 for REST)
//   eighthsToMs(eighths) a length in eighth notes   ->  how many milliseconds to hold it
//
// Right now: every note comes out as 440 Hz, and every note lasts 250 ms.
// Your job:
//   1. noteToHz: NOTE_A4 (number 69) is 440 Hz. One octave up (12 numbers) doubles the frequency,
//      and each single step multiplies it by the twelfth root of 2. In code that is
//          440.0 * pow(2.0, (pitch - 69) / 12.0)
//      Check two notes against your Week 7 note table. And a REST has to come back as 0.
//   2. eighthsToMs: at TEMPO quarter notes a minute, one quarter note lasts 60000 / TEMPO ms.
//      An eighth note is half of that.
//   3. Hand it off to your receiver: they say back what noteToHz(NOTE_C5) gives, and why.

const int TEMPO = 120;   // quarter notes a minute

float noteToHz(int pitch) {
  
  return 440.0 * pow(2.0, (pitch - 69) / 12.0);
}

int eighthsToMs(int eighths) {
  return 30000*eighths/TEMPO;
}
