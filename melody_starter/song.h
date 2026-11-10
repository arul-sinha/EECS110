// PIECE 1 — THE SONGS (Tier 1).   Owner: ______________
//
// This file is the song database for the player. It stores note arrays, names,
// and helper metadata so the rest of the system can stay simple and reliable.
#pragma once

// Note numbers. Middle C is 60, each key up the keyboard adds 1, so an octave is 12.
// NOTE_FS4 is F-sharp. (The board already uses plain names like A4 for its pins, hence NOTE_.)
const int NOTE_C3 = 48, NOTE_CS3 = 49, NOTE_D3 = 50, NOTE_DS3 = 51, NOTE_E3 = 52, NOTE_F3 = 53, NOTE_FS3 = 54, NOTE_G3 = 55, NOTE_GS3 = 56, NOTE_A3 = 57, NOTE_AS3 = 58, NOTE_B3 = 59;
const int NOTE_C4 = 60, NOTE_CS4 = 61, NOTE_D4 = 62, NOTE_DS4 = 63, NOTE_E4 = 64, NOTE_F4 = 65, NOTE_FS4 = 66, NOTE_G4 = 67, NOTE_GS4 = 68, NOTE_A4 = 69, NOTE_AS4 = 70, NOTE_B4 = 71;
const int NOTE_C5 = 72, NOTE_CS5 = 73, NOTE_D5 = 74, NOTE_DS5 = 75, NOTE_E5 = 76, NOTE_F5 = 77, NOTE_FS5 = 78, NOTE_G5 = 79, NOTE_GS5 = 80, NOTE_A5 = 81, NOTE_AS5 = 82, NOTE_B5 = 83;
const int NOTE_C6 = 84, NOTE_CS6 = 85, NOTE_D6 = 86, NOTE_DS6 = 87, NOTE_E6 = 88, NOTE_F6 = 89, NOTE_FS6 = 90, NOTE_G6 = 91, NOTE_GS6 = 92, NOTE_A6 = 93, NOTE_AS6 = 94, NOTE_B6 = 95;
const int NOTE_C7 = 96;



// A song is a list of rows. Each row is a note plus how long it lasts.
// This data model is easy to reason about and easy to transform in memory.
struct Note {
  int pitch;     // which note: a number from the list below, or REST for silence
  int eighths;   // how long: 1 is an eighth note, 2 a quarter, 4 a half, 8 a whole

  bool isRest() const {
    return pitch == REST;
  }
};

// STAFF: a rule from changes.ino takes one row and gives back a row. play.ino uses it.
typedef Note (*Change)(Note);

// More robust than repeating sizeof(...) everywhere: compute the length once.
template <size_t N>
constexpr size_t noteCount(const Note (&)[N]) {
  return N;
}

bool isValidPitch(int pitch) {
  return pitch == REST || (pitch >= NOTE_C4 && pitch <= NOTE_C6);
}

bool isValidDuration(int eighths) {
  return eighths > 0;
}

// A song record gives the program a clear name, data, and size.
struct SongDefinition {
  const char* name;
  const Note* notes;
  int length;
};

// An array is a numbered list. MARY[0] is the first row, MARY[1] the second, and so on.
// This is the whole song from the lecture's roll factory, 26 rows.
const Note MARY[] = {
  {NOTE_B4, 2}, {NOTE_A4, 2}, {NOTE_G4, 2}, {NOTE_A4, 2}, {NOTE_B4, 2}, {NOTE_B4, 2}, {NOTE_B4, 4},
  {NOTE_A4, 2}, {NOTE_A4, 2}, {NOTE_A4, 4},
  {NOTE_B4, 2}, {NOTE_D5, 2}, {NOTE_D5, 4},
  {NOTE_B4, 2}, {NOTE_A4, 2}, {NOTE_G4, 2}, {NOTE_A4, 2}, {NOTE_B4, 2}, {NOTE_B4, 2}, {NOTE_B4, 2},
  {NOTE_B4, 2}, {NOTE_A4, 2}, {NOTE_A4, 2}, {NOTE_B4, 2}, {NOTE_A4, 2}, {NOTE_G4, 8},
};

// The team's song. Replace these rows with your own melody and keep the array length accurate.
const Note OUR_SONG[] = {
  {NOTE_C4, 2}, {NOTE_E4, 2}, {NOTE_G4, 4},
};

const char* SONG_NAME[2] = { "Mary", "Our song" };

// STAFF: the list of songs, and how many rows each has.
const int SONG_COUNT = 2;
const Note* SONGS[SONG_COUNT] = { MARY, OUR_SONG };
const int SONG_LENGTH[SONG_COUNT] = {
  noteCount(MARY),
  noteCount(OUR_SONG)
};

const SongDefinition SONG_DEFS[SONG_COUNT] = {
  { SONG_NAME[0], MARY, SONG_LENGTH[0] },
  { SONG_NAME[1], OUR_SONG, SONG_LENGTH[1] }
};
