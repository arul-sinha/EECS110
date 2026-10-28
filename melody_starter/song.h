// PIECE 1 — THE SONGS (Tier 1).   Owner: ______________
//
// You write the score; the other pieces turn it into sound.
//
// Right now: Mary is complete. OUR_SONG is three rows long, just to make the sketch run.
// Your job:
//   1. Write your team's song in OUR_SONG: at least 16 rows. Pick something the team can hum.
//      Each row is {note, eighths}. A rest is {REST, 2}. Use the note names below.
//   2. Give it a name in SONG_NAME, short enough for the screen: about 14 letters.
//   3. Hand it off to your receiver: they say back what the third row plays, and for how long.
#pragma once

// A song is a list of rows, like the roll factory's: each row is one note and how long it lasts.
// A struct groups two numbers into one row.
struct Note {
  int pitch;     // which note: a number from the list below, or REST for silence
  int eighths;   // how long: 1 is an eighth note, 2 a quarter, 4 a half, 8 a whole
};

// Note numbers. Middle C is 60, each key up the keyboard adds 1, so an octave is 12.
// NOTE_FS4 is F-sharp. (The board already uses plain names like A4 for its pins, hence NOTE_.)
const int REST = 0;
const int NOTE_C4 = 60, NOTE_D4 = 62, NOTE_E4 = 64, NOTE_F4 = 65, NOTE_FS4 = 66, NOTE_G4 = 67, NOTE_A4 = 69, NOTE_B4 = 71;
const int NOTE_C5 = 72, NOTE_D5 = 74, NOTE_E5 = 76, NOTE_F5 = 77, NOTE_FS5 = 78, NOTE_G5 = 79, NOTE_A5 = 81, NOTE_B5 = 83, NOTE_C6 = 84;

// STAFF: a rule from changes.ino takes one row and gives back a row. play.ino uses it.
typedef Note (*Change)(Note);

// An array is a numbered list. MARY[0] is the first row, MARY[1] the second, and so on.
// This is the whole song from the lecture's roll factory, 26 rows.
Note MARY[] = {
  {NOTE_B4, 2}, {NOTE_A4, 2}, {NOTE_G4, 2}, {NOTE_A4, 2}, {NOTE_B4, 2}, {NOTE_B4, 2}, {NOTE_B4, 4},
  {NOTE_A4, 2}, {NOTE_A4, 2}, {NOTE_A4, 4},
  {NOTE_B4, 2}, {NOTE_D5, 2}, {NOTE_D5, 4},
  {NOTE_B4, 2}, {NOTE_A4, 2}, {NOTE_G4, 2}, {NOTE_A4, 2}, {NOTE_B4, 2}, {NOTE_B4, 2}, {NOTE_B4, 2},
  {NOTE_B4, 2}, {NOTE_A4, 2}, {NOTE_A4, 2}, {NOTE_B4, 2}, {NOTE_A4, 2}, {NOTE_G4, 8},
};

// The team's song. Replace these three rows with yours.
Note OUR_SONG[] = {
  {NOTE_C4, 2}, {NOTE_E4, 2}, {NOTE_G4, 4},
};
const char* SONG_NAME[2] = { "Mary", "Our song" };

// STAFF: the list of songs, and how many rows each has. sizeof counts the rows for you.
const int SONG_COUNT = 2;
Note* SONGS[SONG_COUNT] = { MARY, OUR_SONG };
const int SONG_LENGTH[SONG_COUNT] = { sizeof(MARY) / sizeof(Note), sizeof(OUR_SONG) / sizeof(Note) };
