
#include <coleco.h>

const byte NAMERLE4_1[] = {
  0x87, 0x78, 0x02, 0xC3, 0xC6, 0xC3, 0x89, 0x20, 0x02, 0xD1, 0xCE, 0xD1, 0x8F, 0x78, 0x02,
  0xC3, 0xC6, 0xC3, 0x89, 0x20, 0x02, 0xD1, 0xCE, 0xD1, 0x8F, 0x78, 0x02, 0xC3, 0xC6, 0xC3, 0x89,
  0x20, 0x04, 0xD1, 0xCE, 0xD1, 0x78, 0x72, 0x84, 0x71, 0x00, 0x73, 0x87, 0x78, 0x02, 0xC3, 0xC6,
  0xC3, 0x89, 0x20, 0x04, 0xD1, 0xCE, 0xD1, 0x78, 0x71, 0x84, 0x00, 0x00, 0x71, 0x87, 0x78, 0x02,
  0xC3, 0xC6, 0xC3, 0x89, 0x20, 0x04, 0xD1, 0xCE, 0xD1, 0x78, 0x71, 0x84, 0x00, 0x00, 0x71, 0x87,
  0x78, 0x02, 0xC3, 0xC6, 0xC3, 0x89, 0x20, 0x04, 0xD1, 0xCE, 0xD1, 0x78, 0x71, 0x84, 0x00, 0x00,
  0x71, 0x87, 0x78, 0x02, 0xC3, 0xC6, 0xC3, 0x89, 0x20, 0x04, 0xD1, 0xCE, 0xD1, 0x78, 0x71, 0x84,
  0x00, 0x00, 0x71, 0x87, 0x78, 0x02, 0xC3, 0xC6, 0xC3, 0x89, 0x20, 0x04, 0xD1, 0xCE, 0xD1, 0x78,
  0x71, 0x84, 0x00, 0x00, 0x71, 0x87, 0x78, 0x07, 0xC3, 0xC6, 0xC3, 0x00, 0x20, 0x20, 0x00, 0x00,
  0x84, 0x20, 0x04, 0xD1, 0xCE, 0xD1, 0x78, 0x75, 0x84, 0x71, 0x00, 0x74, 0x87, 0x78, 0x03, 0xC3,
  0xC6, 0xC3, 0x00, 0x82, 0x20, 0x00, 0x00, 0x82, 0x20, 0x04, 0x00, 0x20, 0xD1, 0xCE, 0xD1, 0x8F,
  0x78, 0x03, 0xC3, 0xC6, 0xC3, 0x00, 0x82, 0x20, 0x00, 0x00, 0x82, 0x20, 0x81, 0x00, 0x02, 0xD1,
  0xCE, 0xD1, 0x8F, 0x78, 0x03, 0xC3, 0xC6, 0xC3, 0x00, 0x82, 0x20, 0x00, 0x00, 0x83, 0x20, 0x03,
  0x00, 0xD1, 0xCE, 0xD1, 0x89, 0x78, 0x01, 0xB0, 0xB8, 0x83, 0x78, 0x02, 0xC3, 0xC6, 0xC3, 0x83,
  0x20, 0x00, 0x00, 0x82, 0x20, 0x81, 0x00, 0x02, 0xD1, 0xCE, 0xD1, 0x89, 0x78, 0x0D, 0xB1, 0xB9,
  0x7D, 0x80, 0x78, 0x78, 0xC3, 0xC6, 0xC3, 0x00, 0x20, 0x20, 0x00, 0x00, 0x82, 0x20, 0x81, 0x00,
  0x0A, 0xD1, 0xCE, 0xD1, 0x78, 0x78, 0x7D, 0x80, 0x7D, 0x80, 0x78, 0x78, 0x87, 0x79, 0x06, 0xC3,
  0xC6, 0xC3, 0x00, 0x20, 0x20, 0x00, 0x83, 0x20, 0x81, 0x00, 0x02, 0xD1, 0xCE, 0xD1, 0x82, 0x79,
  0x04, 0x81, 0x87, 0x8C, 0x92, 0x79, 0x87, 0x7A, 0x1B, 0xC3, 0xC6, 0xC3, 0x00, 0x20, 0x20, 0x00,
  0x20, 0x20, 0x00, 0x20, 0x00, 0x20, 0xD1, 0xCE, 0xD1, 0x7A, 0x7B, 0x7B, 0x82, 0x88, 0x8D, 0x93,
  0x99, 0x7A, 0x7A, 0x7B, 0x7B, 0x83, 0x7A, 0x02, 0xC3, 0xC6, 0xC3, 0x86, 0x00, 0x82, 0x20, 0x02,
  0xD1, 0xCE, 0xD1, 0x82, 0x7A, 0x04, 0x83, 0x89, 0x8E, 0x94, 0x9A, 0x82, 0x7A, 0x83, 0x7B, 0x03,
  0x7A, 0xC3, 0xC6, 0xC3, 0x86, 0x00, 0x05, 0x20, 0x00, 0x20, 0xD1, 0xCE, 0xD1, 0x82, 0x7A, 0x04,
  0x84, 0x8A, 0x8F, 0x7A, 0x9B, 0x85, 0x7A, 0x04, 0x7B, 0x7A, 0xC3, 0xC6, 0xC3, 0x85, 0x00, 0x81,
  0x20, 0x81, 0x00, 0x04, 0xD1, 0xCE, 0xD1, 0x7A, 0x7A, 0x82, 0x7B, 0x01, 0x90, 0x95, 0x88, 0x7A,
  0x03, 0xC3, 0xC6, 0xC3, 0x20, 0x84, 0x00, 0x82, 0x20, 0x03, 0x00, 0xD1, 0xCE, 0xD1, 0x82, 0x7B,
  0x05, 0x7A, 0x7B, 0x91, 0x96, 0x7A, 0x7A, 0x85, 0x7B, 0x06, 0x7A, 0xC3, 0xC6, 0xC3, 0x20, 0x00,
  0x00, 0x85, 0x20, 0x03, 0x00, 0xD1, 0xCE, 0xD1, 0x83, 0x7A, 0x81, 0x7B, 0x0C, 0x97, 0x9C, 0x7B,
  0x7B, 0x7A, 0x7A, 0x7B, 0x7B, 0x7A, 0x7A, 0xC3, 0xC6, 0xC3, 0x87, 0x20, 0x81, 0x00, 0x02, 0xD1,
  0xCE, 0xD1, 0x83, 0x7B, 0x05, 0x7E, 0x85, 0x98, 0x98, 0x7A, 0x7A, 0x82, 0x7B, 0x82, 0x7A, 0x02,
  0xC4, 0xC7, 0xCA, 0x8A, 0xCC, 0x0C, 0xCF, 0xD2, 0x7B, 0x7B, 0x7E, 0x85, 0x7F, 0x86, 0x8B, 0x8B,
  0x7A, 0x7A, 0x7B, 0x84, 0x7A, 0x02, 0xC5, 0xC8, 0xCB, 0x8A, 0xCD, 0x09, 0xD0, 0xD3, 0x7B, 0x7B,
  0x7F, 0x86, 0x8B, 0x8B, 0x86, 0x8B, 0xFF};

  const byte NAMERLE4_2[] = {
  0x87, 0xFC, 0x02, 0xC3, 0xC6, 0xC3, 0x89, 0x20, 0x02, 0xD1, 0xCE, 0xD1, 0x8F, 0xFC, 0x02,
  0xC3, 0xC6, 0xC3, 0x89, 0x20, 0x02, 0xD1, 0xCE, 0xD1, 0x8F, 0xFC, 0x02, 0xC3, 0xC6, 0xC3, 0x89,
  0x20, 0x04, 0xD1, 0xCE, 0xD1, 0xFC, 0x72, 0x84, 0x71, 0x00, 0x73, 0x87, 0xFC, 0x02, 0xC3, 0xC6,
  0xC3, 0x89, 0x20, 0x04, 0xD1, 0xCE, 0xD1, 0xFC, 0x71, 0x84, 0x00, 0x00, 0x71, 0x87, 0xFC, 0x02,
  0xC3, 0xC6, 0xC3, 0x89, 0x20, 0x04, 0xD1, 0xCE, 0xD1, 0xFC, 0x71, 0x84, 0x00, 0x00, 0x71, 0x87,
  0xFC, 0x02, 0xC3, 0xC6, 0xC3, 0x89, 0x20, 0x04, 0xD1, 0xCE, 0xD1, 0xFC, 0x71, 0x84, 0x00, 0x00,
  0x71, 0x87, 0xFB, 0x02, 0xC3, 0xC6, 0xC3, 0x89, 0x20, 0x04, 0xD1, 0xCE, 0xD1, 0xFB, 0x71, 0x84,
  0x00, 0x00, 0x71, 0x87, 0xFA, 0x02, 0xC3, 0xC6, 0xC3, 0x89, 0x20, 0x04, 0xD1, 0xCE, 0xD1, 0xFA,
  0x71, 0x84, 0x00, 0x00, 0x71, 0x87, 0xFA, 0x07, 0xC3, 0xC6, 0xC3, 0x00, 0x20, 0x20, 0x00, 0x00,
  0x84, 0x20, 0x04, 0xD1, 0xCE, 0xD1, 0xFA, 0x75, 0x84, 0x71, 0x00, 0x74, 0x83, 0xFA, 0x07, 0xD8,
  0xE0, 0xE8, 0xFA, 0xC3, 0xC6, 0xC3, 0x00, 0x82, 0x20, 0x00, 0x00, 0x82, 0x20, 0x04, 0x00, 0x20,
  0xD1, 0xCE, 0xD1, 0x8B, 0xFA, 0x07, 0xD9, 0xE1, 0xE9, 0xFA, 0xC3, 0xC6, 0xC3, 0x00, 0x82, 0x20,
  0x00, 0x00, 0x82, 0x20, 0x81, 0x00, 0x02, 0xD1, 0xCE, 0xD1, 0x8B, 0xFA, 0x07, 0xDA, 0xE2, 0xEA,
  0xFA, 0xC3, 0xC6, 0xC3, 0x00, 0x82, 0x20, 0x00, 0x00, 0x83, 0x20, 0x03, 0x00, 0xD1, 0xCE, 0xD1,
  0x88, 0xFA, 0x00, 0xF0, 0x83, 0xF1, 0x04, 0xF2, 0xFA, 0xC3, 0xC6, 0xC3, 0x83, 0x20, 0x00, 0x00,
  0x82, 0x20, 0x81, 0x00, 0x02, 0xD1, 0xCE, 0xD1, 0x87, 0xFA, 0x0F, 0xF8, 0xF9, 0xF8, 0xF9, 0xF8,
  0xF9, 0xF8, 0xF9, 0xC3, 0xC6, 0xC3, 0x00, 0x20, 0x20, 0x00, 0x00, 0x82, 0x20, 0x81, 0x00, 0x0A,
  0xD1, 0xCE, 0xD1, 0xF9, 0xF8, 0xF9, 0xF8, 0xF9, 0xF8, 0xF9, 0xF8, 0x83, 0xFD, 0x0A, 0xF5, 0xFD,
  0xFD, 0xF5, 0xC3, 0xC6, 0xC3, 0x00, 0x20, 0x20, 0x00, 0x83, 0x20, 0x81, 0x00, 0x02, 0xD1, 0xCE,
  0xD1, 0x83, 0xFD, 0x00, 0xF5, 0x83, 0xFD, 0x00, 0xF5, 0x85, 0xFD, 0x11, 0xC3, 0xC6, 0xC3, 0x00,
  0x20, 0x20, 0x00, 0x20, 0x20, 0x00, 0x20, 0x00, 0x20, 0xD1, 0xCE, 0xD1, 0xFD, 0xF5, 0x85, 0xFD,
  0x87, 0xFE, 0x02, 0xC3, 0xC6, 0xC3, 0x86, 0x00, 0x82, 0x20, 0x02, 0xD1, 0xCE, 0xD1, 0x8F, 0xFE,
  0x02, 0xC3, 0xC6, 0xC3, 0x86, 0x00, 0x05, 0x20, 0x00, 0x20, 0xD1, 0xCE, 0xD1, 0x87, 0xFE, 0x81,
  0xFF, 0x00, 0xF4, 0x84, 0xFF, 0x02, 0xC3, 0xC6, 0xC3, 0x85, 0x00, 0x81, 0x20, 0x81, 0x00, 0x02,
  0xD1, 0xCE, 0xD1, 0x85, 0xFF, 0x00, 0xF4, 0x88, 0xFF, 0x03, 0xC3, 0xC6, 0xC3, 0x20, 0x84, 0x00,
  0x82, 0x20, 0x06, 0x00, 0xD1, 0xCE, 0xD1, 0xFF, 0xFF, 0xF4, 0x84, 0xFF, 0x0D, 0xF4, 0xFF, 0xDB,
  0xE3, 0xEB, 0xFF, 0xF4, 0xFF, 0xC3, 0xC6, 0xC3, 0x20, 0x00, 0x00, 0x85, 0x20, 0x03, 0x00, 0xD1,
  0xCE, 0xD1, 0x85, 0xFF, 0x00, 0xF4, 0x82, 0xFF, 0x02, 0xDC, 0xE4, 0xEC, 0x82, 0xFF, 0x02, 0xC3,
  0xC6, 0xC3, 0x87, 0x20, 0x81, 0x00, 0x02, 0xD1, 0xCE, 0xD1, 0x83, 0xFF, 0x00, 0xF4, 0x82, 0xFF,
  0x87, 0xF3, 0x02, 0xC4, 0xC7, 0xCA, 0x8A, 0xCC, 0x01, 0xCF, 0xD2, 0x8F, 0xF3, 0x02, 0xC5, 0xC8,
  0xCB, 0x8A, 0xCD, 0x01, 0xD0, 0xD3, 0x87, 0xF3, 0xFF};
  
const byte PATTERNRLE4[] = {
  0x87, 0x00, 0x00, 0xFE, 0x84, 0x82, 0x03, 0xFE, 0xFF, 0x83, 0x82, 0x82, 0xBA, 0x02, 0x82,
  0x83, 0xFF, 0x87, 0xF0, 0x07, 0x00, 0x18, 0x18, 0x7E, 0x7E, 0x18, 0x18, 0x00, 0x87, 0x0F, 0x06,
  0x00, 0x18, 0x18, 0x7E, 0x7E, 0x18, 0x18, 0x90, 0x00, 0x81, 0xFF, 0x8D, 0x00, 0x84, 0x03, 0x81,
  0xFF, 0x83, 0x00, 0x81, 0x18, 0x82, 0x00, 0x84, 0xC0, 0x81, 0xFF, 0x04, 0x00, 0x80, 0xB0, 0xCF,
  0xC0, 0x86, 0x80, 0x04, 0xC0, 0xCF, 0xB0, 0x80, 0xFF, 0x8D, 0x00, 0x81, 0xFF, 0x87, 0x00, 0x87,
  0xC0, 0x87, 0x00, 0x87, 0x03, 0x0F, 0xFC, 0xE5, 0xE6, 0xF6, 0xFA, 0x9D, 0x9D, 0xFA, 0x9D, 0x9D,
  0xFA, 0xF6, 0xE6, 0xE5, 0xFC, 0xFF, 0xC9, 0x00, 0x04, 0x0C, 0x18, 0x30, 0x00, 0x60, 0x82, 0x00,
  0x81, 0x66, 0x85, 0x00, 0x21, 0x66, 0xFF, 0x66, 0xFF, 0x66, 0x00, 0x18, 0x3E, 0x60, 0x3C, 0x06,
  0x7C, 0x18, 0x00, 0xFF, 0x81, 0xB9, 0xA5, 0xB9, 0xA5, 0x81, 0xFF, 0x3C, 0x66, 0x3C, 0x38, 0x67,
  0x66, 0x3F, 0x80, 0x00, 0x00, 0x18, 0x30, 0x85, 0x00, 0x00, 0x18, 0x82, 0x30, 0x00, 0x18, 0x82,
  0x00, 0x00, 0x18, 0x82, 0x0C, 0x00, 0x18, 0x82, 0x00, 0x04, 0x5A, 0x3C, 0x7E, 0x3C, 0x5A, 0x82,
  0x00, 0x81, 0x18, 0x02, 0x7E, 0x18, 0x18, 0x85, 0x00, 0x01, 0x18, 0x30, 0x84, 0x00, 0x00, 0x7E,
  0x88, 0x00, 0x00, 0x18, 0x82, 0x00, 0x04, 0x0C, 0x18, 0x30, 0x60, 0xC0, 0x82, 0x00, 0x04, 0x7C,
  0xCE, 0xD6, 0xE6, 0x7C, 0x82, 0x00, 0x04, 0x18, 0x38, 0x18, 0x18, 0x7E, 0x82, 0x00, 0x04, 0x7C,
  0x06, 0x7E, 0x60, 0x7E, 0x82, 0x00, 0x04, 0x7C, 0x06, 0x7C, 0x06, 0x7C, 0x82, 0x00, 0x81, 0xCC,
  0x02, 0xFE, 0x0C, 0x0C, 0x82, 0x00, 0x04, 0x7E, 0x60, 0x7C, 0x06, 0x7C, 0x82, 0x00, 0x04, 0x3E,
  0x60, 0x7C, 0x66, 0x3C, 0x82, 0x00, 0x04, 0xFE, 0x06, 0x0C, 0x18, 0x30, 0x82, 0x00, 0x04, 0x3C,
  0x66, 0x3C, 0x66, 0x3C, 0x82, 0x00, 0x04, 0x3C, 0x66, 0x3C, 0x06, 0x7C, 0x83, 0x00, 0x02, 0x18,
  0x00, 0x18, 0x84, 0x00, 0x0A, 0x18, 0x00, 0x18, 0x30, 0x0E, 0x18, 0x30, 0x60, 0x30, 0x18, 0x0E,
  0x84, 0x00, 0x0A, 0x7E, 0x00, 0x7E, 0x00, 0x00, 0x18, 0x0C, 0x06, 0x0C, 0x18, 0x70, 0x83, 0x00,
  0x04, 0x38, 0x6C, 0x08, 0x00, 0x18, 0x8A, 0x00, 0x04, 0x7C, 0xC6, 0xFE, 0xC6, 0xC6, 0x82, 0x00,
  0x04, 0xFC, 0xC6, 0xFC, 0xC6, 0xFC, 0x82, 0x00, 0x04, 0x7C, 0xC6, 0xC0, 0xC6, 0x7C, 0x82, 0x00,
  0x00, 0xFC, 0x82, 0xC6, 0x00, 0xFC, 0x82, 0x00, 0x04, 0xFE, 0xC0, 0xFE, 0xC0, 0xFE, 0x82, 0x00,
  0x04, 0xFE, 0xC0, 0xFE, 0xC0, 0xC0, 0x82, 0x00, 0x04, 0x7E, 0xC0, 0xDC, 0xC6, 0x7C, 0x82, 0x00,
  0x81, 0xC6, 0x02, 0xFE, 0xC6, 0xC6, 0x82, 0x00, 0x00, 0xFC, 0x82, 0x30, 0x00, 0xFC, 0x82, 0x00,
  0x04, 0xFE, 0x06, 0x06, 0xC6, 0x7C, 0x82, 0x00, 0x04, 0xC6, 0xCC, 0xF8, 0xCC, 0xC6, 0x82, 0x00,
  0x83, 0xC0, 0x00, 0xFE, 0x82, 0x00, 0x04, 0xC6, 0xEE, 0xFE, 0xD6, 0xC6, 0x82, 0x00, 0x04, 0xC6,
  0xE6, 0xFE, 0xCE, 0xC6, 0x82, 0x00, 0x00, 0x7C, 0x82, 0xC6, 0x00, 0x7C, 0x82, 0x00, 0x04, 0xFC,
  0xC6, 0xFC, 0xC0, 0xC0, 0x82, 0x00, 0x04, 0x7C, 0xC6, 0xC6, 0xCC, 0x76, 0x82, 0x00, 0x04, 0xFC,
  0xC6, 0xFC, 0xCC, 0xC6, 0x82, 0x00, 0x04, 0x7E, 0xC0, 0x7C, 0x06, 0xFC, 0x82, 0x00, 0x00, 0xFC,
  0x83, 0x30, 0x82, 0x00, 0x83, 0xC6, 0x00, 0x7C, 0x82, 0x00, 0x82, 0xC6, 0x01, 0x6C, 0x38, 0x82,
  0x00, 0x04, 0xC6, 0xD6, 0xFE, 0xEE, 0xC6, 0x82, 0x00, 0x04, 0xC6, 0x6C, 0x38, 0x6C, 0xC6, 0x82,
  0x00, 0x81, 0xC6, 0x02, 0x7E, 0x06, 0xFC, 0x82, 0x00, 0x1D, 0xFC, 0x18, 0x30, 0x60, 0xFC, 0x00,
  0xFA, 0xD5, 0xAA, 0xD5, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55,
  0x55, 0xAA, 0x55, 0xAA, 0xD5, 0xAA, 0xD5, 0xFA, 0x90, 0x00, 0x81, 0x7F, 0x81, 0x60, 0x81, 0x7F,
  0x01, 0x00, 0xFE, 0x84, 0x82, 0x03, 0xFE, 0xFF, 0x83, 0x82, 0x82, 0xBA, 0x1A, 0x82, 0x83, 0xFF,
  0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55,
  0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0x90, 0x00, 0x81, 0xFF, 0x81, 0x00, 0x81, 0xFF,
  0x90, 0x00, 0x1B, 0x5F, 0xAB, 0x55, 0xAB, 0x55, 0xAA, 0x55, 0xAA, 0xAA, 0x55, 0xAA, 0x55, 0xAA,
  0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAB, 0x55, 0xAB, 0x5F, 0x80, 0xB0, 0xCF, 0xC0, 0x86,
  0x80, 0x43, 0xC0, 0xCF, 0xB0, 0x80, 0xFF, 0x00, 0xFE, 0xFE, 0x06, 0x06, 0xFE, 0xFE, 0x00, 0xAA,
  0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xFA, 0xD5, 0xAA, 0xD5, 0xAA, 0x55, 0xAA, 0x55, 0x5F,
  0xAB, 0x55, 0xAB, 0x55, 0xAA, 0x55, 0xAA, 0xAA, 0x55, 0xAA, 0x55, 0xAB, 0x55, 0xAB, 0x5F, 0x55,
  0xAA, 0x55, 0xAA, 0xD5, 0xAA, 0xD5, 0xFA, 0xFC, 0xE5, 0xE6, 0xF6, 0xFA, 0x9D, 0x9D, 0xFA, 0x9D,
  0x9D, 0xFA, 0xF6, 0xE6, 0xE5, 0xFC, 0x89, 0xFF, 0x82, 0xAA, 0x8B, 0xFF, 0x07, 0xDF, 0xFE, 0xFB,
  0xDF, 0xFF, 0xFD, 0xBF, 0xF7, 0x88, 0xFF, 0x1F, 0xFE, 0xFD, 0xFC, 0xF8, 0xF0, 0xE0, 0xBF, 0xFF,
  0xFF, 0xF0, 0xEF, 0xEF, 0xDF, 0xC0, 0x80, 0x80, 0xCA, 0x80, 0x80, 0xD5, 0xAA, 0xD5, 0xAA, 0x80,
  0xBF, 0x9F, 0xCF, 0xE7, 0xE3, 0xF1, 0xF8, 0xFF, 0x82, 0xAA, 0x81, 0xFB, 0x81, 0xF7, 0x16, 0xF9,
  0xEA, 0xF3, 0xE5, 0xF1, 0xFB, 0xF7, 0xEF, 0xEF, 0xDF, 0xDF, 0xBD, 0x9B, 0xBC, 0x98, 0x80, 0x90,
  0xAF, 0xB7, 0x96, 0xA1, 0xDF, 0xE0, 0x84, 0xFF, 0x07, 0xA0, 0xBF, 0xFF, 0xF5, 0xBA, 0xA0, 0xFF,
  0xFF, 0x83, 0xAA, 0x4F, 0xFF, 0x9B, 0x98, 0xFB, 0xF7, 0xA6, 0xA4, 0xA5, 0xBE, 0x90, 0xF1, 0xE6,
  0xF2, 0xE1, 0xFE, 0xAA, 0x80, 0x80, 0xFF, 0xFF, 0xFB, 0xFD, 0xFC, 0xCC, 0xE8, 0xD9, 0xB6, 0x92,
  0xDD, 0xC1, 0xFE, 0xFF, 0xAA, 0xAB, 0xAA, 0xD4, 0xAA, 0xAB, 0xAA, 0xAB, 0xFF, 0xDF, 0xEF, 0xEE,
  0xF0, 0x82, 0xBB, 0xBB, 0xA9, 0xF6, 0x8B, 0xFE, 0x83, 0xC1, 0xA2, 0xC1, 0x9F, 0xAF, 0xFF, 0xFD,
  0xFE, 0x9F, 0xEF, 0x88, 0xB7, 0x91, 0xFB, 0xBD, 0x8D, 0x92, 0xBB, 0x89, 0xDD, 0xD3, 0xEE, 0xEE,
  0xF1, 0xFB, 0xB8, 0xFD, 0x82, 0xFE, 0x07, 0xDF, 0xFF, 0xFD, 0xBF, 0xF7, 0xFF, 0xAA, 0xC0, 0x82,
  0xDF, 0x81, 0xBF, 0x26, 0x80, 0xE0, 0xE7, 0xDB, 0xDB, 0xB5, 0xF6, 0xED, 0x82, 0x92, 0x8C, 0x83,
  0x87, 0xF3, 0xFD, 0xFE, 0xFF, 0xBF, 0xC0, 0xA8, 0xDF, 0xC4, 0xE4, 0x88, 0xDF, 0xEF, 0x9F, 0x88,
  0xB2, 0xBB, 0xDB, 0xE6, 0xFB, 0xFC, 0xFF, 0xF7, 0xBF, 0xFF, 0xF7, 0x83, 0xFF, 0x84, 0xFE, 0x86,
  0xFF, 0x18, 0x80, 0xBF, 0x9F, 0x90, 0xD7, 0xD7, 0xB7, 0xBB, 0x84, 0xF5, 0xEE, 0xFD, 0xF3, 0xEB,
  0xF7, 0xE7, 0xFF, 0xBF, 0xAF, 0x88, 0xB7, 0xCD, 0xF3, 0xFC, 0xFF, 0xFE, 0x00, 0x98, 0x00, 0x03,
  0x80, 0xB0, 0xCF, 0xC0, 0x86, 0x80, 0x04, 0xC0, 0xCF, 0xB0, 0x80, 0xFF, 0xAF, 0x00, 0x0F, 0xFC,
  0xE5, 0xE6, 0xF6, 0xFA, 0x9D, 0x9D, 0xFA, 0x9D, 0x9D, 0xFA, 0xF6, 0xE6, 0xE5, 0xFC, 0xFF, 0xC7,
  0x00, 0x01, 0x81, 0x99, 0x82, 0x81, 0x00, 0x99, 0x84, 0x81, 0x0C, 0x9F, 0xF8, 0x92, 0xF8, 0x97,
  0xF8, 0x97, 0xF8, 0x92, 0xF8, 0x9F, 0x8A, 0x8A, 0x82, 0xC0, 0x82, 0xFF, 0x84, 0xC0, 0x0C, 0xFC,
  0xF3, 0xA4, 0xF3, 0xF4, 0xF3, 0xF4, 0xF3, 0xA4, 0xF3, 0xFC, 0xA8, 0xA8, 0x8B, 0xFF, 0x88, 0x80,
  0x92, 0xFF, 0x82, 0x81, 0x82, 0xFF, 0x82, 0x81, 0x81, 0xFE, 0x0E, 0x9F, 0x98, 0x92, 0x98, 0x97,
  0x98, 0x97, 0x98, 0x92, 0x98, 0x9F, 0xF5, 0xF5, 0xC0, 0xCC, 0x82, 0xC0, 0x00, 0xCC, 0x84, 0xC0,
  0x0C, 0xFC, 0xF0, 0xA4, 0xF0, 0xF4, 0xF0, 0xF4, 0xF0, 0xA4, 0xF0, 0xFC, 0xA8, 0xA8, 0xA0, 0x00,
  0x03, 0x01, 0x03, 0x07, 0x07, 0x83, 0x0F, 0x07, 0x1E, 0x19, 0x2B, 0x3B, 0x2F, 0x37, 0x1F, 0xF0,
  0x82, 0xFC, 0x12, 0xF0, 0x80, 0x81, 0x81, 0x00, 0x01, 0x03, 0x0F, 0x1F, 0x1A, 0x1A, 0xC2, 0x41,
  0x7C, 0x7C, 0x7E, 0x1C, 0x1E, 0x0E, 0x98, 0x00, 0x14, 0x80, 0x00, 0x34, 0x36, 0x60, 0x38, 0x1C,
  0xFE, 0x7F, 0x30, 0x33, 0x6D, 0x12, 0x61, 0x41, 0x61, 0xED, 0xF3, 0xC0, 0xE1, 0x63, 0x83, 0x00,
  0x0A, 0xFC, 0x00, 0x80, 0x80, 0xE0, 0xF0, 0xF0, 0x8F, 0x8B, 0xC3, 0xE7, 0x82, 0xEF, 0x98, 0x00,
  0x04, 0x80, 0xE0, 0xF0, 0xF8, 0xF8, 0x82, 0xFC, 0x1E, 0x03, 0x23, 0x27, 0x66, 0x05, 0x72, 0x09,
  0x75, 0x03, 0x0F, 0x1F, 0x0F, 0x03, 0x71, 0x70, 0x70, 0xC0, 0xF0, 0xF8, 0xFC, 0x3F, 0x1F, 0x0F,
  0x0F, 0xE2, 0x56, 0x36, 0x76, 0x76, 0x6D, 0x6C, 0x98, 0x00, 0x08, 0xFF, 0x80, 0x40, 0x20, 0x10,
  0x0F, 0x00, 0x00, 0xFF, 0x83, 0x00, 0x18, 0xFF, 0x00, 0x00, 0xFF, 0x01, 0x02, 0x04, 0x08, 0xF0,
  0x00, 0x00, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x00, 0x00, 0x18, 0x24, 0x24, 0x18,
  0x83, 0x00, 0x03, 0x18, 0x24, 0x24, 0x18, 0x91, 0x00, 0x81, 0xFF, 0x09, 0x30, 0x0F, 0xFE, 0x10,
  0x00, 0x00, 0xC7, 0x30, 0xF8, 0x80, 0x8B, 0x00, 0x07, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA,
  0x55, 0x8F, 0x00, 0x07, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0x87, 0x00, 0xFF};

const byte COLORRLE4[] = {
  0x87, 0x41, 0x81, 0xF1, 0x83, 0xF4, 0x09, 0xF1, 0x10, 0x1F, 0xF1, 0xE1, 0x91, 0x91, 0xF1,
  0x1F, 0x10, 0x87, 0xA6, 0x87, 0xA1, 0x87, 0xA6, 0x87, 0xF1, 0x8F, 0x41, 0x87, 0xA6, 0x87, 0x66,
  0x86, 0xA1, 0x00, 0xA6, 0x87, 0xB1, 0x86, 0xA1, 0x03, 0xA6, 0x1F, 0xF1, 0x91, 0x88, 0xF6, 0x03,
  0x91, 0xF1, 0x1F, 0x10, 0x87, 0x41, 0x87, 0xA6, 0x87, 0x41, 0x87, 0x01, 0x87, 0x41, 0x87, 0x01,
  0x09, 0xF1, 0x1F, 0x91, 0xE1, 0xE1, 0x6F, 0x6F, 0x91, 0x6F, 0x6F, 0x82, 0x91, 0x02, 0x1F, 0xF1,
  0x10, 0xFE, 0x41, 0xFE, 0x41, 0xFE, 0x41, 0xFE, 0x41, 0x9B, 0x41, 0x97, 0x1A, 0x8F, 0x41, 0x87,
  0x1A, 0x81, 0xF1, 0x0D, 0xF4, 0xFF, 0xF4, 0xF4, 0xF1, 0x10, 0x1F, 0xF1, 0xE1, 0xFF, 0x91, 0xF1,
  0x1F, 0x10, 0x97, 0x1A, 0x8F, 0x41, 0x87, 0x1A, 0x8F, 0x41, 0x97, 0x1A, 0x03, 0x1F, 0xF1, 0x91,
  0xFF, 0x86, 0xF6, 0x04, 0xFF, 0x91, 0xF1, 0x1F, 0x10, 0x87, 0x1A, 0xA7, 0x4A, 0x0F, 0xF1, 0x1F,
  0x91, 0xFF, 0xE1, 0x6F, 0x6F, 0x91, 0x6F, 0x6F, 0x91, 0xFF, 0x91, 0x1F, 0xF1, 0x10, 0x87, 0x40,
  0x03, 0x10, 0x6B, 0xB6, 0x6B, 0x8B, 0xB0, 0x83, 0xB6, 0x00, 0xB0, 0x82, 0xB6, 0x87, 0xF0, 0x02,
  0x40, 0x41, 0x41, 0x83, 0x46, 0x02, 0x61, 0xB0, 0xB0, 0x83, 0xB1, 0x81, 0x1B, 0x03, 0x1A, 0x6B,
  0x1A, 0x1A, 0x83, 0x6B, 0x00, 0x14, 0x82, 0x41, 0x81, 0xD1, 0x81, 0x61, 0x03, 0x10, 0x6B, 0xB6,
  0x6B, 0x82, 0xB1, 0x84, 0xA1, 0x87, 0xB1, 0x00, 0xA1, 0x82, 0x1A, 0x03, 0x1B, 0xB1, 0xA1, 0x91,
  0x82, 0xB1, 0x82, 0xB0, 0x17, 0x10, 0xB0, 0x6B, 0xB6, 0xB0, 0xB6, 0xB6, 0x6B, 0xB0, 0xB0, 0xB6,
  0x6B, 0xB6, 0x6B, 0x10, 0xA1, 0x1B, 0xB6, 0xA1, 0x6B, 0x16, 0x91, 0x61, 0x1A, 0x82, 0xA1, 0x81,
  0x91, 0x04, 0xB6, 0x6B, 0x6B, 0xB0, 0xB0, 0x84, 0xB6, 0x08, 0x91, 0xA1, 0x1A, 0xA1, 0x1B, 0xB1,
  0xB0, 0xB6, 0x6B, 0x82, 0xB6, 0x0E, 0x6B, 0xB6, 0x6B, 0x10, 0xA1, 0xA1, 0x91, 0xA1, 0x1A, 0xA1,
  0x61, 0x19, 0x91, 0x6B, 0xB1, 0x83, 0x6B, 0x81, 0xB6, 0x07, 0xB0, 0xB6, 0xB6, 0xA1, 0x61, 0x19,
  0x61, 0x16, 0x82, 0x61, 0x03, 0x16, 0x61, 0x16, 0x91, 0x84, 0xA1, 0x00, 0xB6, 0x83, 0xB1, 0x01,
  0xB6, 0xB0, 0x82, 0xB6, 0x03, 0x10, 0x6B, 0x19, 0xA1, 0x83, 0xB1, 0x81, 0x1B, 0x00, 0x91, 0x82,
  0xA1, 0x81, 0x91, 0x14, 0x19, 0x16, 0x19, 0x16, 0x6B, 0xB6, 0xB1, 0xA1, 0xB0, 0xB1, 0x6B, 0x6B,
  0xB1, 0x1A, 0x6B, 0x1A, 0xA1, 0xB1, 0x91, 0x19, 0x1A, 0x83, 0xA1, 0x05, 0xB1, 0xB0, 0xB6, 0xB6,
  0xB0, 0xB6, 0x82, 0xB0, 0x00, 0x10, 0x83, 0xB1, 0x00, 0xA1, 0x86, 0xB0, 0x08, 0x1B, 0xB1, 0xA1,
  0x1A, 0xA1, 0xB1, 0xA1, 0xA1, 0x1A, 0x83, 0xA1, 0x0B, 0xB6, 0xB1, 0xB6, 0xB0, 0xB1, 0x91, 0x1A,
  0x91, 0x91, 0xA1, 0xB1, 0xB0, 0x87, 0x00, 0xFE, 0x41, 0x90, 0x41, 0x02, 0x1F, 0xF1, 0x91, 0x88,
  0xF6, 0x03, 0x91, 0xF1, 0x5F, 0x50, 0xAF, 0x41, 0x09, 0xF1, 0x1F, 0x91, 0xE1, 0xE1, 0x6F, 0x6F,
  0x91, 0x6F, 0x6F, 0x82, 0x91, 0x02, 0x1F, 0xF1, 0x50, 0xC7, 0x41, 0x81, 0x19, 0x00, 0x1E, 0x82,
  0x19, 0x00, 0x1E, 0x84, 0x19, 0x0A, 0x1E, 0x19, 0x1E, 0x19, 0x1E, 0x19, 0x1E, 0x19, 0x1E, 0x19,
  0x1E, 0x83, 0x19, 0x82, 0x10, 0x00, 0x1E, 0x83, 0x19, 0x0C, 0x1E, 0x91, 0x19, 0x91, 0x19, 0x91,
  0x19, 0x91, 0x19, 0x91, 0x19, 0x1E, 0x18, 0x88, 0x10, 0x02, 0xE0, 0x80, 0x10, 0x88, 0x18, 0x06,
  0x10, 0xE0, 0x80, 0x10, 0xE0, 0x80, 0x10, 0x88, 0x80, 0x02, 0x10, 0xE0, 0x80, 0x82, 0x19, 0x82,
  0x10, 0x05, 0x1E, 0x19, 0x19, 0x91, 0x81, 0x1E, 0x89, 0x19, 0x04, 0xE1, 0x81, 0x19, 0x19, 0x1E,
  0x82, 0x19, 0x00, 0x1E, 0x84, 0x19, 0x0B, 0x81, 0x19, 0x81, 0x19, 0x91, 0x19, 0x81, 0x19, 0x81,
  0x19, 0x1E, 0x18, 0x9F, 0x00, 0x8A, 0x64, 0x84, 0xF4, 0x81, 0x4F, 0x83, 0x46, 0x81, 0xF6, 0x07,
  0x65, 0x15, 0x95, 0x15, 0x15, 0xF5, 0xF5, 0x1F, 0x82, 0x91, 0x82, 0x95, 0x01, 0x15, 0x95, 0x97,
  0x00, 0x81, 0x46, 0x81, 0xA6, 0x83, 0x16, 0x81, 0x18, 0x00, 0x81, 0x84, 0x1F, 0x81, 0xF1, 0x81,
  0x6F, 0x08, 0x6A, 0xFA, 0x4F, 0x4F, 0x61, 0x91, 0xF9, 0x19, 0x19, 0x82, 0xF9, 0x00, 0x9F, 0x84,
  0x91, 0x01, 0x15, 0x65, 0x97, 0x00, 0x87, 0x64, 0x81, 0x46, 0x07, 0x61, 0xF1, 0x6F, 0xF1, 0x6F,
  0xF1, 0x4F, 0x4F, 0x82, 0x46, 0x82, 0x6F, 0x83, 0x15, 0x83, 0x19, 0x85, 0x91, 0x01, 0x15, 0x95,
  0x97, 0x00, 0x01, 0xA4, 0xA2, 0x86, 0xA4, 0x03, 0xA2, 0xA3, 0xA3, 0xA2, 0x83, 0xA4, 0x00, 0xA2,
  0x85, 0xA4, 0x87, 0x15, 0x87, 0xF5, 0x87, 0xF7, 0x8F, 0x00, 0x81, 0x40, 0x00, 0x47, 0x82, 0xF7,
  0x81, 0x07, 0x00, 0x47, 0x82, 0xF7, 0x83, 0x07, 0x87, 0x04, 0x87, 0x45, 0x87, 0x05, 0x87, 0x07,
  0x87, 0x47, 0x87, 0x55, 0xFF};
