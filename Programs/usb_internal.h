/*
 * BRLTTY - A background process providing access to the Linux console (when in
 *          text mode) for a blind person using a refreshable braille display.
 *
 * Copyright (C) 1995-2004 by The BRLTTY Team. All rights reserved.
 *
 * BRLTTY comes with ABSOLUTELY NO WARRANTY.
 *
 * This is free software, placed under the terms of the
 * GNU General Public License, as published by the Free Software
 * Foundation.  Please see the file COPYING for details.
 *
 * Web Page: http://mielke.cc/brltty/
 *
 * This software is maintained by Dave Mielke <dave@mielke.cc>.
 */

#ifndef _USB_DEFINITIONS_H
#define _USB_DEFINITIONS_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "queue.h"

struct UsbInputElement {
  struct UsbInputElement *next;
  struct UsbInputElement *previous;
  void *request;
};

struct UsbDeviceStruct {
  UsbDeviceDescriptor descriptor;
  Queue *endpoints;
  int file;
  int interface;
  uint16_t language;
};

typedef struct {
  UsbDevice *device;
  UsbEndpointDescriptor *descriptor;

  union {
    struct {
      struct UsbInputElement *elements;
      void *request;
      unsigned char *buffer;
      int length;
    } input;

    struct {
    } output;
  } direction;
} UsbEndpoint;

extern UsbDevice *usbTestDevice (
  const char *path,
  UsbDeviceChooser chooser,
  void *data
);

extern int usbReadDeviceDescriptor (
  UsbDevice *device
);

extern UsbEndpoint *usbGetEndpoint (
  UsbDevice *device,
  unsigned char endpointAddress
);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _USB_DEFINITIONS_H */
