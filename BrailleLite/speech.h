/* BrailleLite/speech.h - definitions for rudimentary speech support
 * N. Nair, 11 September 1998
 */

#define SPKNAME "BrailleLite"

#ifdef SPEECH_C
#undef SPEECH_C

/* These sequences are sent to the Braille Lite before and after the
 * speech data itself.  The first byte is the length, so embedded nuls are
 * allowed.
 */
#define PRE_SPEECH "\006\0050B\0051O"
#define POST_SPEECH "\007\r\0050O\0051B"

/* This is sent to mute the speech.  The format is the same as above. */
#define MUTE_SEQ "\015\0050B\0051O\030\0050O\0051B"

/* The speech data itself is translated character by character.  If a
 * character is less than 33 (i.e. space or control), it is replaced by a
 * space.  If the character is more than MAX_TRANS, it is passed through
 * as is.  Otherwise the character n is replaced by the string vocab[n - 33].
 */

#define MAX_TRANS 32

#if MAX_TRANS > 32
static unsigned char *vocab[MAX_TRANS - 32] =
{
  " exclamation ",
  " double quote ",
  " hash ",
  " dollar ",
  " percent ",
  " ampersand ",
  " quote ",
  " left paren ",
  " right paren ",
  " star ",
  " plus ",
  " comma ",
  " dash ",
  " dot ",
  " slash ",
  "0",
  "1",
  "2",
  "3",
  "4",
  "5",
  "6",
  "7",
  "8",
  "9",
  " colon ",
  " semicolon ",
  " less than ",
  " equals ",
  " greater than ",
  " question ",
  " at ",
  "A",
  "B",
  "C",
  "D",
  "E",
  "F",
  "G",
  "H",
  "I",
  "J",
  "K",
  "L",
  "M",
  "N",
  "O",
  "P",
  "Q",
  "R",
  "S",
  "T",
  "U",
  "V",
  "W",
  "X",
  "Y",
  "Z",
  " left bracket ",
  " backslash ",
  " right bracket ",
  " uparrow ",
  " underline ",
  " accent ",
  "a",
  "b",
  "c",
  "d",
  "e",
  "f",
  "g",
  "h",
  "i",
  "j",
  "k",
  "l",
  "m",
  "n",
  "o",
  "p",
  "q",
  "r",
  "s",
  "t",
  "u",
  "v",
  "w",
  "x",
  "y",
  "z",
  " left brace ",
  " bar ",
  " right brace ",
  " tilde "
};
#endif /* MAX_TRANS > 32 */

#endif /* defined(SPEECH_C) */