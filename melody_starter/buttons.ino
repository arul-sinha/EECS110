// STAFF — BUTTON HANDLING. Read it; don't edit it.
//
// readButtons() reports which button was JUST pressed: NEXT (D1), PLAY (D2), or NONE.
// "Just pressed" matters: loop() asks thousands of times a second, and a finger stays on a
// button for a tenth of a second or more. So this remembers what each button read last time,
// and reports a press only when a button goes from not pressed to pressed. Holding it down
// counts once.
//
// On this board D1 and D2 read HIGH while pressed and LOW when not.

const int NEXT_BUTTON = 1;   // D1
const int PLAY_BUTTON = 2;   // D2
int lastNext = LOW;          // what each button read last time
int lastPlay = LOW;

void setupButtons() {
  pinMode(NEXT_BUTTON, INPUT_PULLDOWN);
  pinMode(PLAY_BUTTON, INPUT_PULLDOWN);
}

int readButtons() {
  int next = digitalRead(NEXT_BUTTON);
  int play = digitalRead(PLAY_BUTTON);
  delay(20);                       // a button chatters for a few ms when it moves; wait it out
  int result = NONE;
  if (next == HIGH && lastNext == LOW) {
    result = NEXT;
  }
  if (play == HIGH && lastPlay == LOW) {
    result = PLAY;
  }
  lastNext = next;
  lastPlay = play;
  return result;
}
