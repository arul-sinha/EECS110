// melody_starter — EECS 110, Week 8 lab. The team's song player. This tab joins the pieces; nobody edits it.
//
// THE ROLL FACTORY, AS A PROGRAM. Four pieces, one per teammate:
//
//   song.h         PIECE 1  Tier 1, the songs: each row a note and how many eighth notes it lasts
//   translate.ino  PIECE 2  Tier 2, the translator: a note number becomes hertz; eighth notes become milliseconds
//   play.ino       PIECE 3  Tier 3, the player: plays a song row by row, a gap after each note, stops at the end
//   changes.ino    PIECE 4  the lecture's changes, an octave up and twice as fast, written two ways
//
//   buttons.ino, screen.ino   STAFF. Reading the buttons and drawing the screen. Read them; don't edit them.
//
// HOW THIS TAB WORKS — read it top to bottom once before you start.
//   setup() runs once when the board starts: it wakes the screen, the speaker pin and the buttons.
//   loop() runs over and over, forever:
//     1. readButtons() says which button was just pressed: NEXT, PLAY, or NONE.
//     2. NEXT (D1, middle): move to the next choice. A choice is a song plus a version of it.
//     3. PLAY (D2, bottom): play the chosen song, with the chosen change applied to each row.
//   Version 3 is different on purpose: it EDITS the song before playing it. Try playing
//   "as written" again afterward, and listen.
//
// Speaker: pin 5 -> 100 ohm resistor -> speaker -> GND, as in Week 7.
// Board: Adafruit Feather ESP32-S3 Reverse TFT.  Library: Adafruit ST7735 and ST7789 Library.

#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
#include "song.h"

#ifndef TFT_CS                 // the board package defines these; the fallbacks are this board's pins
  #define TFT_CS         7
  #define TFT_DC        39
  #define TFT_RST       40
  #define TFT_BACKLITE  45
  #define TFT_I2C_POWER 21
#endif

const int SPEAKER_PIN = 5;
const int NONE = 0;   // what readButtons() can say: nothing was pressed,
const int NEXT = 1;   // the next button was pressed,
const int PLAY = 2;   // or the play button was pressed

const int VERSIONS = 4;
const char* VERSION_NAME[VERSIONS] = { "as written", "octave up", "twice as fast", "octave up, edited" };

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
int choice = 0;       // which song and version: song = choice / VERSIONS, version = choice % VERSIONS

void setup() {
#ifdef TFT_I2C_POWER
  pinMode(TFT_I2C_POWER, OUTPUT);
  digitalWrite(TFT_I2C_POWER, HIGH);
  delay(10);
#endif
#ifdef TFT_BACKLITE
  pinMode(TFT_BACKLITE, OUTPUT);
  digitalWrite(TFT_BACKLITE, HIGH);
#endif
  tft.init(135, 240);
  tft.setRotation(3);
  tft.setTextWrap(false);
  pinMode(SPEAKER_PIN, OUTPUT);
  setupButtons();
  showChoice(choice / VERSIONS, choice % VERSIONS);
}

void loop() {
  int pressed = readButtons();
  int s = choice / VERSIONS;          // which song
  int v = choice % VERSIONS;          // which version of it

  if (pressed == NEXT) {
    choice = choice + 1;
    if (choice >= SONG_COUNT * VERSIONS) {
      choice = 0;                     // past the last choice, back to the first
    }
    showChoice(choice / VERSIONS, choice % VERSIONS);
  }

  if (pressed == PLAY) {
    showPlaying(s, v);
    if (v == 0) {
      playSong(SONGS[s], SONG_LENGTH[s], asWritten);    // PIECE 3, with PIECE 4's rules
    }
    if (v == 1) {
      playSong(SONGS[s], SONG_LENGTH[s], octaveUp);
    }
    if (v == 2) {
      playSong(SONGS[s], SONG_LENGTH[s], twiceAsFast);
    }
    if (v == 3) {
      octaveUpEverywhere(SONGS[s], SONG_LENGTH[s]);      // PIECE 4: edits the song itself
      playSong(SONGS[s], SONG_LENGTH[s], asWritten);
    }
    showChoice(s, v);
  }
}
