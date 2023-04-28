
#include <coleco.h>

const byte NAMERLE_TITLE[] = {
  0xFC, 0x00, 0x83, 0x00, 0x1C, 0x30, 0x38, 0x34, 0x3C, 0x32, 0x00, 0x36, 0x00, 0x40, 0x48,
  0x42, 0x4A, 0x44, 0x4C, 0x34, 0x3C, 0x46, 0x4E, 0x00, 0x50, 0x58, 0x52, 0x54, 0xFA, 0xF8, 0x34,
  0x3C, 0x56, 0x5E, 0x82, 0x00, 0x1C, 0x31, 0x39, 0x35, 0x3D, 0x33, 0x3B, 0x37, 0x3F, 0x41, 0x49,
  0x43, 0x4B, 0x45, 0x4D, 0x35, 0x3D, 0x47, 0x4F, 0x00, 0x51, 0x59, 0x53, 0x55, 0xFB, 0xF9, 0x35,
  0x3D, 0x57, 0x5F, 0xFE, 0x00, 0x8E, 0x00, 0x07, 0x10, 0x12, 0x05, 0x13, 0x05, 0x0E, 0x14, 0x13,
  0x9D, 0x00, 0x00, 0x78, 0x94, 0x00, 0x0F, 0x7B, 0x7D, 0x7F, 0x81, 0x83, 0x85, 0x87, 0x00, 0x78,
  0x00, 0x7B, 0x89, 0x8B, 0x8D, 0x8F, 0x91, 0x8F, 0x00, 0x06, 0x7C, 0x7E, 0x80, 0x82, 0x84, 0x86,
  0x88, 0x82, 0x00, 0x05, 0x7C, 0x8A, 0x8C, 0x8E, 0x90, 0x92, 0xD3, 0x00, 0x07, 0x0D, 0x15, 0x13,
  0x09, 0x03, 0x00, 0x02, 0x19, 0xB3, 0x00, 0x0F, 0x04, 0x01, 0x0E, 0x09, 0x05, 0x0C, 0x00, 0x00,
  0x02, 0x09, 0x05, 0x0E, 0x16, 0x05, 0x0E, 0x15, 0xCF, 0x00, 0x0F, 0x25, 0x00, 0x00, 0x1D, 0x1B,
  0x1C, 0x1C, 0x00, 0x0D, 0x2E, 0x0C, 0x0F, 0x15, 0x16, 0x05, 0x14, 0xC7, 0x00, 0xFF};

const byte PATTERNRLE_TITLE[] = {
  0x87, 0x00, 0x11, 0x20, 0x50, 0x88, 0x88, 0xF8, 0x88, 0x88, 0x00, 0xF0, 0x88, 0x88, 0xF0,
  0x88, 0x88, 0xF0, 0x00, 0x70, 0x88, 0x82, 0x80, 0x03, 0x88, 0x70, 0x00, 0xF0, 0x84, 0x88, 0x0D,
  0xF0, 0x00, 0xF8, 0x80, 0x80, 0xF0, 0x80, 0x80, 0xF8, 0x00, 0xF8, 0x80, 0x80, 0xF0, 0x82, 0x80,
  0x01, 0x00, 0x78, 0x82, 0x80, 0x03, 0x98, 0x88, 0x78, 0x00, 0x82, 0x88, 0x00, 0xF8, 0x82, 0x88,
  0x01, 0x00, 0x70, 0x84, 0x20, 0x01, 0x70, 0x00, 0x84, 0x08, 0x0A, 0x88, 0x70, 0x00, 0x88, 0x90,
  0xA0, 0xC0, 0xA0, 0x90, 0x88, 0x00, 0x85, 0x80, 0x05, 0xF8, 0x00, 0x88, 0xD8, 0xA8, 0xA8, 0x82,
  0x88, 0x09, 0x00, 0x88, 0x88, 0xC8, 0xA8, 0x98, 0x88, 0x88, 0x00, 0x70, 0x84, 0x88, 0x05, 0x70,
  0x00, 0xF0, 0x88, 0x88, 0xF0, 0x82, 0x80, 0x01, 0x00, 0x70, 0x82, 0x88, 0x14, 0xA8, 0x90, 0x68,
  0x00, 0xF0, 0x88, 0x88, 0xF0, 0xA0, 0x90, 0x88, 0x00, 0x70, 0x88, 0x80, 0x70, 0x08, 0x88, 0x70,
  0x00, 0xF8, 0x85, 0x20, 0x00, 0x00, 0x85, 0x88, 0x01, 0x70, 0x00, 0x84, 0x88, 0x02, 0x50, 0x20,
  0x00, 0x82, 0x88, 0x81, 0xA8, 0x0D, 0xD8, 0x88, 0x00, 0x88, 0x88, 0x50, 0x20, 0x50, 0x88, 0x88,
  0x00, 0x88, 0x88, 0x50, 0x83, 0x20, 0x12, 0x00, 0xF8, 0x08, 0x10, 0x20, 0x40, 0x80, 0xF8, 0x00,
  0x70, 0x88, 0x98, 0xA8, 0xC8, 0x88, 0x70, 0x00, 0x20, 0x60, 0x83, 0x20, 0x2D, 0x70, 0x00, 0x70,
  0x88, 0x08, 0x30, 0x40, 0x80, 0xF8, 0x00, 0xF8, 0x08, 0x10, 0x30, 0x08, 0x88, 0x70, 0x00, 0x10,
  0x30, 0x50, 0x90, 0xF8, 0x10, 0x10, 0x00, 0xF8, 0x80, 0xF0, 0x08, 0x08, 0x88, 0x70, 0x00, 0x38,
  0x40, 0x80, 0xF0, 0x88, 0x88, 0x70, 0x00, 0xF8, 0x08, 0x10, 0x20, 0x82, 0x40, 0x19, 0x00, 0x70,
  0x88, 0x88, 0x70, 0x88, 0x88, 0x70, 0x00, 0x70, 0x88, 0x88, 0x78, 0x08, 0x10, 0xE0, 0x00, 0x7E,
  0x81, 0xBD, 0xA1, 0xA1, 0xBD, 0x81, 0x7E, 0x1F, 0x82, 0x04, 0x83, 0x00, 0x03, 0x44, 0x6C, 0x54,
  0x54, 0x83, 0x00, 0x06, 0x40, 0xA0, 0xA0, 0x40, 0xA8, 0x90, 0x68, 0x83, 0x00, 0x00, 0xF8, 0x83,
  0x00, 0x0E, 0x20, 0xA8, 0x70, 0x20, 0x70, 0xA8, 0x20, 0x00, 0x50, 0x50, 0xF8, 0x50, 0xF8, 0x50,
  0x50, 0x84, 0x00, 0x81, 0x20, 0x00, 0x40, 0x83, 0x00, 0x00, 0xF8, 0x89, 0x00, 0x00, 0x20, 0x82,
  0x00, 0x02, 0x20, 0x00, 0x20, 0x83, 0x00, 0x01, 0x07, 0x0F, 0x89, 0x1F, 0x03, 0x0F, 0x07, 0x00,
  0x00, 0x89, 0x1E, 0x83, 0x1F, 0x81, 0x00, 0x03, 0x07, 0x0F, 0x1F, 0x1F, 0x85, 0x1E, 0x81, 0x1F,
  0x03, 0x0F, 0x07, 0x00, 0x00, 0x89, 0x1E, 0x83, 0x1F, 0x81, 0x00, 0x0D, 0xE0, 0xF0, 0xF8, 0xF8,
  0x78, 0x78, 0x00, 0x00, 0x78, 0x78, 0xF8, 0xF8, 0xF0, 0xE0, 0x8B, 0x00, 0x83, 0xF8, 0x81, 0x00,
  0x03, 0xE0, 0xF0, 0xF8, 0xF8, 0x85, 0x78, 0x81, 0xF8, 0x01, 0xF0, 0xE0, 0x8B, 0x00, 0x83, 0xF8,
  0x81, 0x00, 0x82, 0x1F, 0x81, 0x1E, 0x82, 0x1F, 0x81, 0x1E, 0x83, 0x1F, 0x81, 0x00, 0x01, 0x07,
  0x0F, 0x89, 0x1F, 0x03, 0x0F, 0x07, 0x00, 0x00, 0x82, 0x0F, 0x8A, 0x03, 0x81, 0x00, 0x05, 0x07,
  0x0F, 0x1F, 0x1F, 0x1E, 0x1E, 0x82, 0x1F, 0x84, 0x1E, 0x81, 0x00, 0x82, 0xF8, 0x81, 0x00, 0x82,
  0xE0, 0x81, 0x00, 0x83, 0xF8, 0x81, 0x00, 0x0F, 0xE0, 0xF0, 0xF8, 0xF8, 0x78, 0x78, 0x00, 0x00,
  0x78, 0x78, 0xF8, 0xF8, 0xF0, 0xE0, 0x00, 0x00, 0x82, 0xF0, 0x8A, 0xC0, 0x81, 0x00, 0x07, 0xE0,
  0xF0, 0xF8, 0xF8, 0x78, 0x78, 0xF0, 0xE0, 0x82, 0xF0, 0x82, 0x78, 0x81, 0x00, 0x82, 0x1E, 0x82,
  0x0F, 0x82, 0x07, 0x82, 0x03, 0x81, 0x01, 0x81, 0x00, 0x8D, 0x1E, 0x81, 0x00, 0x01, 0x03, 0x07,
  0x84, 0x0F, 0x0A, 0x07, 0x03, 0x00, 0x0F, 0x0F, 0x07, 0x03, 0x00, 0x00, 0x3C, 0x3C, 0x82, 0x3E,
  0x83, 0x3F, 0x82, 0x3D, 0x81, 0x3C, 0x81, 0x00, 0x82, 0x3C, 0x82, 0x78, 0x82, 0xF0, 0x82, 0xE0,
  0x81, 0xC0, 0x88, 0x00, 0x18, 0x05, 0x2A, 0x55, 0x2A, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55,
  0xAA, 0x55, 0xAA, 0x55, 0xAA, 0xAA, 0x55, 0xAA, 0x55, 0x2A, 0x55, 0x2A, 0x05, 0x00, 0x8D, 0xF0,
  0x98, 0x00, 0x17, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55,
  0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0xA7, 0x00, 0x17, 0xA0, 0x54,
  0xAA, 0x54, 0xAA, 0x55, 0xAA, 0x55, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA,
  0x55, 0xAA, 0x54, 0xAA, 0x54, 0xA0, 0xCF, 0x00, 0x8C, 0xFF, 0x00, 0xFC, 0x88, 0xFE, 0x00, 0xFC,
  0x84, 0xFF, 0x00, 0xDC, 0x82, 0xCE, 0x02, 0xCC, 0xD8, 0xCC, 0x82, 0xCE, 0x00, 0xDC, 0x84, 0xFF,
  0x01, 0xE5, 0xCC, 0x86, 0x8C, 0x01, 0xCC, 0xE5, 0x84, 0xFF, 0x0A, 0xE1, 0xF1, 0x8E, 0x87, 0xC7,
  0xC7, 0xC3, 0x83, 0x83, 0xFF, 0xE3, 0x84, 0xFF, 0x00, 0xC3, 0x82, 0xC7, 0x81, 0xB8, 0x83, 0xC7,
  0x00, 0x83, 0x84, 0xFF, 0x00, 0xF7, 0x83, 0x8C, 0x00, 0x89, 0x83, 0x8C, 0x00, 0xF7, 0x84, 0xFF,
  0x06, 0xE6, 0x98, 0x90, 0x90, 0xEF, 0xFF, 0xFF, 0x82, 0x80, 0x00, 0xFE, 0x84, 0xFF, 0x0A, 0xE7,
  0xF2, 0x8F, 0x87, 0xC7, 0xC3, 0xE3, 0xE1, 0xF1, 0x86, 0xC6, 0x84, 0xFF, 0x00, 0x83, 0x87, 0xC7,
  0x01, 0xC6, 0x84, 0x84, 0xFF, 0x83, 0xF8, 0x81, 0xFC, 0x04, 0xEC, 0xF0, 0xFE, 0xDE, 0x8C, 0x84,
  0xFF, 0x0A, 0xF9, 0xF3, 0xF3, 0xF0, 0x8F, 0x8F, 0x83, 0x80, 0xC8, 0xC8, 0xEE, 0x84, 0xFF, 0x04,
  0xA5, 0x9A, 0xDE, 0xDE, 0xC1, 0x82, 0xE1, 0x81, 0x9E, 0x00, 0xC3, 0x84, 0xFF, 0x02, 0xD8, 0xC8,
  0xC8, 0x86, 0xC0, 0x00, 0xE0, 0xFE, 0x00, 0xFE, 0x00, 0xFE, 0x00, 0xFE, 0x00, 0xFE, 0x00, 0xFE,
  0x00, 0xAE, 0x00, 0x8D, 0x1E, 0x81, 0x00, 0x0D, 0xF0, 0xF8, 0xFC, 0x3C, 0x00, 0xF0, 0xF8, 0xFC,
  0xFC, 0x3C, 0x3C, 0xFC, 0xF8, 0xF0, 0xA0, 0x00, 0xFF};

const byte COLORRLE_TITLE[] = {
  0x87, 0x41, 0xFE, 0xF1, 0xFE, 0xF1, 0xF9, 0xF1, 0x8F, 0xD1, 0x8F, 0x81, 0x8F, 0x61, 0x8F,
  0xB1, 0x8F, 0xD1, 0x87, 0x41, 0x87, 0x81, 0x8F, 0x61, 0x87, 0x41, 0x87, 0xB1, 0x8F, 0x31, 0x8F,
  0x41, 0x8F, 0xD1, 0x8F, 0x91, 0x8F, 0x31, 0x8F, 0x41, 0x8F, 0xD1, 0x8F, 0x91, 0x8F, 0xB1, 0x8F,
  0x31, 0x9F, 0x41, 0x8F, 0xB1, 0x87, 0xD1, 0x97, 0xA1, 0x8F, 0x41, 0x8F, 0xB1, 0x87, 0x41, 0x97,
  0xA1, 0x97, 0x41, 0x87, 0xB1, 0x87, 0x41, 0x97, 0xA1, 0x8F, 0x41, 0x8F, 0x31, 0xAF, 0x41, 0x8C,
  0x10, 0x8A, 0x18, 0x84, 0x10, 0x8A, 0x81, 0x84, 0x10, 0x8A, 0x18, 0x84, 0x10, 0x81, 0x18, 0x86,
  0x81, 0x01, 0x10, 0x18, 0x84, 0x10, 0x83, 0x18, 0x81, 0x81, 0x84, 0x18, 0x84, 0x10, 0x00, 0x81,
  0x88, 0x18, 0x00, 0x81, 0x84, 0x10, 0x0A, 0x18, 0x61, 0x81, 0x81, 0x18, 0x10, 0x10, 0x81, 0x81,
  0x61, 0x18, 0x84, 0x10, 0x81, 0x81, 0x86, 0x18, 0x81, 0x81, 0x84, 0x10, 0x8A, 0x18, 0x84, 0x10,
  0x88, 0x18, 0x01, 0x16, 0x18, 0x84, 0x10, 0x83, 0x18, 0x83, 0x81, 0x02, 0x61, 0x81, 0x81, 0x84,
  0x10, 0x03, 0x81, 0x16, 0x18, 0x18, 0x83, 0x81, 0x81, 0x18, 0x00, 0x81, 0x84, 0x10, 0x8A, 0x81,
  0x87, 0x00, 0x9F, 0x41, 0x8F, 0xD1, 0xAF, 0x41, 0x8F, 0xB1, 0xAF, 0x41, 0x8F, 0xB1, 0xAF, 0x41,
  0x8F, 0x31, 0xAF, 0x41, 0x87, 0xD1, 0xF7, 0x41, 0x8F, 0xD1, 0xFE, 0x41, 0xB0, 0x41, 0x8F, 0x91,
  0xAF, 0x41, 0x8F, 0x91, 0xEF, 0x41, 0x8F, 0xD1, 0xAF, 0x41, 0xFF};