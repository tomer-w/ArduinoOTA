/*
  Copyright (c) 2017 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _OTA_STORAGE_H_INCLUDED
#define _OTA_STORAGE_H_INCLUDED

#ifdef ARDUINO_SAM_ZERO
#define SKETCH_START_ADDRESS        (0x4000)
#else
#define SKETCH_START_ADDRESS        (0x2000)
#endif

class OTAStorage {
public:
  virtual int open(int length) = 0;
  virtual size_t write(uint8_t) = 0;
  virtual void close() = 0;
  virtual void clear() = 0;
  virtual void apply() = 0;

  virtual long maxSize() {
    return ((256 * 1024) - SKETCH_START_ADDRESS);
  }
};

#endif
