// STAFF — THE SCREEN. Read it; don't edit it.
//
// The screen is 240 dots wide and 135 tall; (0, 0) is the top left corner.
// At text size 2, each letter is 12 dots wide and 16 tall.
/*
void showChoice(int s, int v) {
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(6, 6);
  tft.print(SONG_NAME[s]);
  tft.setTextColor(ST77XX_YELLOW);
  tft.setCursor(6, 32);
  tft.print(VERSION_NAME[v]);
  tft.setTextColor(ST77XX_GREEN);
  tft.setCursor(6, 110);
  tft.print("D1 next  D2 play");
}


void showPlaying(int s, int v) {
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_GREEN);
  tft.setCursor(6, 6);
  tft.print("Playing:");
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(6, 32);
  tft.print(SONG_NAME[s]);
  tft.setTextColor(ST77XX_YELLOW);
  tft.setCursor(6, 58);
  tft.print(VERSION_NAME[v]);
} */


// Catppuccin Mocha Theme Colors converted to RGB565
#define BASE       0x18E5  // #1E1E2E
#define MAUVE      0xCD3E  // #CBA6F7
#define LAVENDER   0xB5FF  // #B4BEFE
#define MAROON     0xF455  // #F38BA8
#define PEACH      0xFD90  // #FAB387

void showEverything(int s, int v) {
  tft.fillScreen(BASE);
  tft.setTextSize(2);
  tft.setTextColor(LAVENDER);
  tft.setCursor(6, 6);
  tft.print("Playing:");
  tft.setTextColor(MAROON);
  tft.setCursor(6, 24);
  tft.print(SONG_NAME[s]);
  tft.setTextColor(LAVENDER);
  tft.setCursor(6, 48);
  tft.print("Mode:");
  tft.setTextColor(MAROON);
  tft.setCursor(6, 66);
  tft.print(VERSION_NAME[v]);
  tft.setTextColor(PEACH);
  tft.setCursor(6, 110);
  tft.print("D1 next  D2 play");
}

// notes for self: y=88-102 is FREE. Ideally use (6,88) for label and a 10 segment bar from x=48 to x=228 
