// PIECE 3 — THE PLAYER (Tier 3).   Owner: Evan
//
// Tier 3 does each row exactly, deciding nothing. playSong gets:
//   song     the rows, from song.h
//   length   how many rows there are
//   change   a rule from changes.ino; change(song[i]) gives back row i with the rule applied
//
// Right now: it plays the first row only.
// Your job: the rules you ran out loud, in code.
//   1. Repeat for every row: a while loop, from i = 0 while i is less than length,
//      adding 1 to i at the end of each pass.
//   2. A REST makes no sound: noteToHz gives 0, so only call tone() IF hz is more than 0.
//   3. After every note, a short silence (GAP_MS), so two of the same note don't run together.
//   4. Hand it off to your receiver: they say back how the loop knows the song is over.

const int GAP_MS = 30;

void playSong(Note song[], int length, Change change) {
  int i = 0;
  while (i < length){
    Note n = change(song[i]);
    float hz = noteToHz(n.pitch);
    tone(SPEAKER_PIN, (int)(hz + 0.5));
    delay(eighthsToMs(n.eighths));
    noTone(SPEAKER_PIN);
    
    i ++;
  }
  
}
