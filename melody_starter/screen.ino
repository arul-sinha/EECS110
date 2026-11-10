// STAFF — THE SCREEN. Read it; don't edit it.
//
// The screen is 240 dots wide and 135 tall; (0, 0) is the top left corner.
// At text size 2, each letter is 12 dots wide and 16 tall.

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
}

void showEverything(int s, int v) {
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_YELLOW);
  tft.setCursor(6,6);
  tft.print("Playing:");
  tft.setcursor(6,24);
  tft.print("Mode:");
  tft.setcursor(6,42);
  tft.print("Setting:");
  tft.setTextColor(ST77XX_WHITE);
  tft.setcursor(130,6);
  tft.print(SONG_NAME[s]);
  tft.setcursor(130, 24);
  tft.print(VERSION_NAME[v]);
  tft.setcursor(130, 42);
}
