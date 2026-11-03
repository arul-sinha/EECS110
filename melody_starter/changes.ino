// PIECE 4 — THE CHANGES.   Owner: gabe
//
// The lecture asked which way of writing a program makes a change easy. Here are two of
// its changes, written two ways.
//
//   FUNCTIONAL: a rule. octaveUp(n) and twiceAsFast(n) each get a copy of ONE row and give
//   back a new row. playSong applies the rule to every row as it plays. The song itself is
//   never touched.
//
//   PROCEDURAL: octaveUpEverywhere(song, length) walks the song and edits every row in
//   place. The song stays changed afterward.
//
// Right now: all three do nothing; every version sounds like the song as written.
// Your job:
//   1. octaveUp: add 12 to the row's pitch, unless it is a REST. Return the row.
//   2. twiceAsFast: halve the row's eighths. Return the row. Then play Ode to Joy, or your
//      own song, twice as fast and listen for a missing note. Why does it vanish?
//   3. octaveUpEverywhere: a while loop over every row, adding 12 to each pitch that isn't
//      a REST. Play "octave up, edited", then "as written" again. What happened, and why?
//   4. Hand it off to your receiver: they say back which way changed the song for good.

Note asWritten(Note n) {
  return n;
}

Note octaveUp(Note n) {
  n.pitch = n.pitch + 8;
  return n;
}

Note twiceAsFast(Note n) {
  n.eighths = n.eighths/2;
  return n;
}

void octaveUpEverywhere(Note song[], int length) {
  for (int i = 0; i<length; i++){
    song[i].pitch = song[i].pitch + 8;
  }
}

Note octaveDown(Note n) {
  n.pitch = pitch - 8;
  return n;
}
void octaveDownEverywhere(Note song[], int length) {
  for (int i = 0; i < length; i++){
    song[i].pitch = song[i].pitch-8;
  }
}
