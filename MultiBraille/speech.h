/*
 * BRLTTY - Access software for Unix for a blind person
 *          using a soft Braille terminal
 *
 * Copyright (C) 1995-2000 by The BRLTTY Team, All rights reserved.
 *
 * Web Page: http://www.cam.org/~nico/brltty
 *
 * BRLTTY comes with ABSOLUTELY NO WARRANTY.
 *
 * This is free software, placed under the terms of the
 * GNU General Public License, as published by the Free Software
 * Foundation.  Please see the file COPYING for details.
 */

/* CombiBraille/speech.h - definitions for rudimentary speech support
 * N. Nair, 3 September 1996
 * $Id: speech.h,v 1.2 1996/09/21 23:34:52 nn201 Exp $
 */

#define SPKNAME "MultiBraille"

/* These sequences are sent to the CombiBraille before and after the
 * speech data itself.  The first byte is the length, so embedded nuls are
 * allowed.
 */
#define PRE_SPEECH "\002\033S"
#define POST_SPEECH "\001\015"

/* This is sent to mute the speech.  The format is the same as above. */
#define MUTE_SEQ "\003\033S\030"

/* The speech data itself is translated character by character.  If a
 * character is less than 33 (i.e. space or control), it is replaced by a
 * space.  If the character is more than MAX_TRANS, it is passed through
 * as is.  Otherwise the character n is replaced by the string vocab[n - 33].
 */

#define MAX_TRANS 126
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