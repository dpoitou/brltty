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

/* Festival/speech.c - Speech library
 * For the Festival text to speech package
 * Maintained by Nikhil Nair <nn201@cus.cam.ac.uk>
 */

#define SPEECH_C 1

#include <stdio.h>
#include <string.h>

#include "speech.h"		/* for speech definitions */
#include "../spk.h"
#include "../spk_driver.h"
#include "../misc.h"


static FILE *festival;


static void
identspk (void)
{
  LogAndStderr(LOG_NOTICE, "Using the Festival text to speech package.");
}


static void
initspk (void)
{
  unsigned char init_speech[] = { INIT_SPEECH };

  festival = popen ("festival", "w");
  if (festival && init_speech[0])
    {
      fwrite (init_speech + 1, init_speech[0], 1, festival);
      fflush (festival);
    }
}


static void
say (unsigned char *buffer, int len)
{
  unsigned char pre_speech[] = { PRE_SPEECH};
  unsigned char post_speech[] = { POST_SPEECH };
  unsigned char tempbuff[40];
  unsigned char c;
  int i;

  if (!festival)
    return;

  if (pre_speech[0])
    fwrite (pre_speech + 1, pre_speech[0], 1, festival);
  for (i = 0; i < len; i++)
    {
      c = buffer[i];
      if (c < 33)	/* space or control character */
	{
	  tempbuff[0] = ' ';
	  fwrite (tempbuff, 1, 1, festival);
	}
      else if (c > MAX_TRANS)
	fwrite (&c, 1, 1, festival);
      else
	{
	  memcpy (tempbuff, vocab[c - 33], strlen (vocab[c - 33]));
	  fwrite (tempbuff, strlen (vocab[c - 33]), 1, festival);
	}
    }
  if (post_speech[0])
    fwrite (post_speech + 1, post_speech[0], 1, festival);
  fflush (festival);
}


static void
mutespk (void)
{
  unsigned char mute_seq[] = { MUTE_SEQ };

  if (!festival)
    return;
  fwrite (mute_seq + 1, mute_seq[0], 1, festival);
  fflush (festival);
}


static void
closespk (void)
{
  if (festival)
    pclose (festival);
}