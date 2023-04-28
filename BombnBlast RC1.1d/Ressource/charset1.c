/********************************************/
/*                                          */
/*   GRAPHICS TABLES  -  WIN ICVGM v3.00    */
/*                                          */
/*        WARNING : RLE COMPRESSION         */
/*                                          */
/********************************************/

#include <coleco.h>

byte NAMERLE[] = {
  0x84, 0x20, 0x82, 0x00, 0x02, 0xC9, 0xCC, 0xC9, 0x89, 0x20, 0x02, 0xD7, 0xD4, 0xD7, 0x8C,
  0x20, 0x82, 0x00, 0x02, 0xC9, 0xCC, 0xC9, 0x89, 0x20, 0x05, 0xD7, 0xD4, 0xD7, 0x20, 0x20, 0x0C,
  0x82, 0x20, 0x02, 0x06, 0x20, 0x0C, 0x83, 0x20, 0x82, 0x00, 0x02, 0xC9, 0xCC, 0xC9, 0x89, 0x20,
  0x04, 0xD7, 0xD4, 0xD7, 0x00, 0x72, 0x84, 0x64, 0x02, 0x73, 0x20, 0x20, 0x83, 0x00, 0x04, 0x04,
  0x00, 0xC9, 0xCC, 0xC9, 0x89, 0x20, 0x04, 0xD7, 0xD4, 0xD7, 0x00, 0x64, 0x84, 0x00, 0x01, 0x64,
  0x20, 0x82, 0x00, 0x00, 0x12, 0x82, 0x00, 0x02, 0xC9, 0xCC, 0xC9, 0x89, 0x20, 0x05, 0xD7, 0xD4,
  0xD7, 0x00, 0x64, 0x00, 0x82, 0x20, 0x06, 0x00, 0x64, 0x20, 0x00, 0x20, 0x20, 0x12, 0x82, 0x00,
  0x02, 0xC9, 0xCC, 0xC9, 0x89, 0x20, 0x0F, 0xD7, 0xD4, 0xD7, 0x00, 0x64, 0x00, 0x20, 0x20, 0x00,
  0x00, 0x64, 0x20, 0x00, 0x7B, 0x8D, 0x9E, 0x82, 0x00, 0x02, 0xC9, 0xCC, 0xC9, 0x89, 0x20, 0x06,
  0xD7, 0xD4, 0xD7, 0x00, 0x64, 0x00, 0x20, 0x82, 0x00, 0x05, 0x64, 0x20, 0x00, 0x7C, 0x8E, 0x9F,
  0x82, 0x00, 0x02, 0xC9, 0xCC, 0xC9, 0x89, 0x20, 0x0E, 0xD7, 0xD4, 0xD7, 0x00, 0x64, 0x00, 0x20,
  0x20, 0x00, 0x00, 0x64, 0x20, 0x00, 0x00, 0x8F, 0x83, 0x00, 0x02, 0xC9, 0xCC, 0xC9, 0x82, 0x20,
  0x81, 0x00, 0x84, 0x20, 0x04, 0xD7, 0xD4, 0xD7, 0x00, 0x75, 0x84, 0x64, 0x05, 0x74, 0x20, 0x06,
  0x20, 0x00, 0x20, 0x82, 0x00, 0x02, 0xC9, 0xCC, 0xC9, 0x83, 0x20, 0x00, 0x00, 0x82, 0x20, 0x04,
  0x00, 0x20, 0xD7, 0xD4, 0xD7, 0x87, 0x00, 0x82, 0x20, 0x07, 0x00, 0x20, 0x00, 0x0C, 0x00, 0xC9,
  0xCC, 0xC9, 0x83, 0x20, 0x00, 0x00, 0x82, 0x20, 0x81, 0x00, 0x03, 0xD7, 0xD4, 0xD7, 0x00, 0x89,
  0x20, 0x01, 0x00, 0x20, 0x82, 0x00, 0x02, 0xC9, 0xCC, 0xC9, 0x83, 0x20, 0x00, 0x00, 0x83, 0x20,
  0x16, 0x00, 0xD7, 0xD4, 0xD7, 0x00, 0x20, 0x20, 0x00, 0x00, 0x20, 0x04, 0x20, 0x7E, 0x90, 0xA0,
  0xAB, 0xB6, 0xB8, 0xBC, 0xBF, 0xC9, 0xCC, 0xC9, 0x83, 0x20, 0x00, 0x00, 0x82, 0x20, 0x81, 0x00,
  0x04, 0xD7, 0xD4, 0xD7, 0x00, 0x20, 0x84, 0x00, 0x10, 0x20, 0x7F, 0x91, 0xA1, 0xAC, 0xB7, 0xB9,
  0xBD, 0xC0, 0xC9, 0xCC, 0xC9, 0x00, 0x20, 0x20, 0x00, 0x00, 0x82, 0x20, 0x81, 0x00, 0x19, 0xD7,
  0xD4, 0xD7, 0x00, 0x20, 0x78, 0x8A, 0x9B, 0x00, 0x00, 0x20, 0x80, 0x92, 0xA2, 0xAD, 0xAD, 0xBA,
  0xBE, 0xC1, 0xC9, 0xCC, 0xC9, 0x00, 0x20, 0x20, 0x00, 0x83, 0x20, 0x81, 0x00, 0x2A, 0xD7, 0xD4,
  0xD7, 0x00, 0x20, 0x79, 0x8B, 0x9C, 0x00, 0x20, 0x20, 0x81, 0x93, 0xA3, 0xAE, 0xAE, 0xBB, 0x93,
  0xC2, 0xC9, 0xCC, 0xC9, 0x00, 0x20, 0x20, 0x00, 0x20, 0x20, 0x00, 0x20, 0x00, 0x20, 0xD7, 0xD4,
  0xD7, 0x00, 0x20, 0x7A, 0x8C, 0x9D, 0x00, 0x20, 0x20, 0x83, 0x00, 0x00, 0x20, 0x82, 0x00, 0x02,
  0xC9, 0xCC, 0xC9, 0x86, 0x00, 0x82, 0x20, 0x03, 0xD7, 0xD4, 0xD7, 0x00, 0x82, 0x20, 0x82, 0x00,
  0x0B, 0x20, 0x82, 0x94, 0xA4, 0xAF, 0x82, 0x94, 0xA4, 0xAF, 0xC9, 0xCC, 0xC9, 0x86, 0x00, 0x07,
  0x20, 0x00, 0x20, 0xD7, 0xD4, 0xD7, 0x82, 0x94, 0x85, 0x00, 0x0A, 0x83, 0x95, 0xA5, 0xB0, 0x83,
  0x95, 0xA5, 0xB0, 0xC9, 0xCC, 0xC9, 0x85, 0x00, 0x81, 0x20, 0x81, 0x00, 0x06, 0xD7, 0xD4, 0xD7,
  0x83, 0x95, 0x20, 0x0C, 0x83, 0x00, 0x0B, 0x84, 0x96, 0xA6, 0xB1, 0x84, 0x96, 0xA6, 0xB1, 0xC9,
  0xCC, 0xC9, 0x20, 0x84, 0x00, 0x82, 0x20, 0x19, 0x00, 0xD7, 0xD4, 0xD7, 0x84, 0x96, 0x20, 0x02,
  0x20, 0x0C, 0x02, 0x00, 0x85, 0x97, 0xA7, 0xB2, 0x85, 0x97, 0xA7, 0xB2, 0xC9, 0xCC, 0xC9, 0x20,
  0x00, 0x00, 0x85, 0x20, 0x16, 0x00, 0xD7, 0xD4, 0xD7, 0x85, 0x97, 0x20, 0x20, 0x0E, 0x16, 0x20,
  0x20, 0x86, 0x98, 0xA8, 0xB3, 0x86, 0x98, 0xA8, 0xB3, 0xC9, 0xCC, 0xC9, 0x87, 0x20, 0x81, 0x00,
  0x15, 0xD7, 0xD4, 0xD7, 0x86, 0x98, 0x20, 0x20, 0x0F, 0x17, 0x20, 0x20, 0x87, 0x99, 0xA9, 0xB4,
  0x87, 0x99, 0xA9, 0xB4, 0xCA, 0xCD, 0xD0, 0x8A, 0xD2, 0x14, 0xD5, 0xD8, 0xAA, 0xB5, 0x88, 0x9A,
  0xAA, 0xB5, 0x88, 0x9A, 0x88, 0x9A, 0xAA, 0xB5, 0x88, 0x9A, 0xAA, 0xB5, 0xCB, 0xCE, 0xD1, 0x8A,
  0xD3, 0x09, 0xD6, 0xD9, 0x88, 0x9A, 0xAA, 0xB5, 0x88, 0x9A, 0xAA, 0xB5, 0xFF};

byte PATTERNRLE[] = {
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
  0x00, 0x81, 0xC6, 0x02, 0x7E, 0x06, 0xFC, 0x82, 0x00, 0x08, 0xFC, 0x18, 0x30, 0x60, 0xFC, 0x00,
  0xFF, 0x80, 0x80, 0x91, 0x9F, 0x81, 0x80, 0x00, 0xFF, 0x90, 0x00, 0x81, 0x7F, 0x81, 0x60, 0x81,
  0x7F, 0x01, 0x00, 0xFE, 0x84, 0x82, 0x03, 0xFE, 0xFF, 0x83, 0x82, 0x82, 0xBA, 0x05, 0x82, 0x83,
  0xFF, 0xFF, 0x00, 0x00, 0x84, 0xFF, 0x07, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0x84,
  0xFF, 0x81, 0x00, 0x00, 0xFF, 0x90, 0x00, 0x81, 0xFF, 0x81, 0x00, 0x81, 0xFF, 0x90, 0x00, 0x02,
  0xFF, 0x01, 0x01, 0x91, 0xF9, 0x81, 0x01, 0x04, 0xFF, 0x80, 0xB0, 0xCF, 0xC0, 0x86, 0x80, 0x0B,
  0xC0, 0xCF, 0xB0, 0x80, 0xFF, 0x00, 0xFE, 0xFE, 0x06, 0x06, 0xFE, 0xFE, 0x88, 0x00, 0x2E, 0xFA,
  0xD5, 0xAA, 0xD5, 0xAA, 0x55, 0xAA, 0x55, 0x5F, 0xAB, 0x55, 0xAB, 0x55, 0xAA, 0x55, 0xAA, 0xAA,
  0x55, 0xAA, 0x55, 0xAB, 0x55, 0xAB, 0x5F, 0x55, 0xAA, 0x55, 0xAA, 0xD5, 0xAA, 0xD5, 0xFA, 0xFC,
  0xE5, 0xE6, 0xF6, 0xFA, 0x9D, 0x9D, 0xFA, 0x9D, 0x9D, 0xFA, 0xF6, 0xE6, 0xE5, 0xFC, 0x83, 0xFF,
  0x04, 0xFC, 0xF8, 0xF0, 0xE0, 0xE0, 0x82, 0xC0, 0x84, 0x80, 0x82, 0xC0, 0x03, 0xE8, 0xF5, 0xFA,
  0xFD, 0x82, 0xFF, 0x01, 0xFC, 0xFE, 0x83, 0xFF, 0x81, 0xFC, 0x04, 0xFF, 0xFC, 0xFF, 0xFD, 0xFB,
  0x8F, 0xFF, 0x02, 0xFC, 0xE0, 0xF4, 0x82, 0xAA, 0x08, 0xD5, 0xEA, 0xFD, 0xFE, 0xFF, 0xFF, 0x80,
  0xAF, 0xA8, 0x82, 0xAA, 0x01, 0xFA, 0xFD, 0x8A, 0xFF, 0x31, 0xE0, 0x87, 0x90, 0xCC, 0xC8, 0x8A,
  0xBB, 0xC2, 0xFE, 0xFB, 0xF7, 0xFF, 0xFF, 0xFE, 0xF9, 0xF6, 0x89, 0x8C, 0x85, 0xFC, 0x90, 0xC5,
  0x9B, 0xE1, 0x81, 0xC0, 0xCF, 0x8A, 0xBA, 0x82, 0xDE, 0xF0, 0xFF, 0x81, 0xCF, 0xF7, 0xC0, 0xFB,
  0xFF, 0x90, 0x88, 0xBA, 0x89, 0xBF, 0xFF, 0xC3, 0xB1, 0xF0, 0xE0, 0xC7, 0x88, 0xFF, 0x81, 0xE0,
  0x09, 0x95, 0xB5, 0x90, 0xBF, 0xA0, 0xB5, 0xFF, 0x80, 0xBF, 0x80, 0x82, 0xFF, 0x0C, 0xBF, 0xA8,
  0xFF, 0xFF, 0xEA, 0xAA, 0xAA, 0xAF, 0xFF, 0xFF, 0x81, 0xFF, 0xE7, 0x84, 0xDB, 0x05, 0xFF, 0x81,
  0xFF, 0xDB, 0x81, 0xFF, 0x82, 0x81, 0x82, 0xC3, 0x81, 0xE7, 0x84, 0xFF, 0x06, 0xFE, 0xC0, 0xEA,
  0xAA, 0xFE, 0xFF, 0xBF, 0x84, 0xAA, 0x00, 0xF5, 0x83, 0xFF, 0x84, 0xAA, 0x87, 0xFF, 0x0A, 0xEF,
  0xDF, 0x90, 0xDF, 0xFF, 0xFF, 0x80, 0xC0, 0xAE, 0xDF, 0xEF, 0x83, 0xFF, 0x3B, 0x97, 0x81, 0xFB,
  0xFF, 0x80, 0xFF, 0xEF, 0xEF, 0x97, 0xD0, 0xE8, 0xF4, 0xF3, 0xF8, 0xFF, 0xF9, 0xF9, 0xFF, 0xFB,
  0x83, 0x80, 0xD5, 0xEA, 0xFD, 0xFF, 0xFF, 0xD5, 0xEA, 0xF7, 0xBC, 0xE0, 0xF2, 0xCF, 0xDF, 0xFC,
  0x93, 0x80, 0xC1, 0xFF, 0xFF, 0xE0, 0xF8, 0xFC, 0xF4, 0xEA, 0xF4, 0xFA, 0xF4, 0xF8, 0xF4, 0xEA,
  0xD4, 0xEA, 0xD4, 0xE8, 0xD0, 0xA8, 0xAF, 0xA0, 0xBF, 0x83, 0xFF, 0x01, 0xC0, 0x80, 0x83, 0xFF,
  0x81, 0xC0, 0x04, 0xFF, 0xC0, 0xFF, 0xBF, 0xDF, 0x84, 0xFF, 0x01, 0xF8, 0xFD, 0x82, 0xAA, 0x02,
  0xAF, 0xFF, 0xFE, 0x84, 0xAA, 0x04, 0xA0, 0xFF, 0xFF, 0xFE, 0xF5, 0x83, 0xAA, 0x01, 0xA0, 0xBF,
  0x87, 0xFF, 0x09, 0xFE, 0xFB, 0xFF, 0xFF, 0xF1, 0xCB, 0xE4, 0xF5, 0xFD, 0xCC, 0x86, 0xFF, 0x04,
  0xBC, 0xFB, 0xFD, 0xFE, 0xFE, 0x82, 0xFF, 0x1A, 0x9C, 0x84, 0xF7, 0xEA, 0xAA, 0xFF, 0xFD, 0xC0,
  0x90, 0x9B, 0xC8, 0xDD, 0xAA, 0x9D, 0xEA, 0x80, 0xFC, 0x80, 0xCD, 0xCC, 0xEF, 0x80, 0xF1, 0xC0,
  0x94, 0x89, 0xEF, 0x82, 0xFF, 0x07, 0xF0, 0xFA, 0xAA, 0xAA, 0xFF, 0xFF, 0xEA, 0xD5, 0x84, 0xAA,
  0x83, 0xFF, 0x84, 0xAA, 0x88, 0xFF, 0x0E, 0xDF, 0xBF, 0xDF, 0xBF, 0xFF, 0xFC, 0xCF, 0x82, 0xED,
  0x81, 0xBE, 0xFE, 0xFD, 0xF1, 0xEF, 0x82, 0xFF, 0x23, 0xF8, 0xFD, 0xF7, 0xFF, 0xC0, 0xE0, 0xA8,
  0xEA, 0xFC, 0xF9, 0xF1, 0xFF, 0xFD, 0xA6, 0xA3, 0xDF, 0xEE, 0xF5, 0xFE, 0xFF, 0xAF, 0xA8, 0xBF,
  0x98, 0xCE, 0xF9, 0xFF, 0xFF, 0xE6, 0xED, 0xEF, 0x80, 0xE0, 0xF0, 0xE3, 0x83, 0x82, 0xFF, 0x05,
  0xF0, 0xAF, 0xAA, 0xAA, 0xFF, 0xFF, 0x86, 0xAA, 0x83, 0xFF, 0x00, 0xE0, 0x82, 0xAA, 0x02, 0xF5,
  0xFF, 0xA0, 0x85, 0xAA, 0x00, 0xF5, 0x82, 0xFF, 0x00, 0xA0, 0x83, 0xAA, 0x00, 0xF5, 0x89, 0xFF,
  0x05, 0x80, 0xFC, 0xAF, 0xAA, 0xFF, 0xFF, 0x85, 0xAA, 0x00, 0xA8, 0x83, 0xFF, 0x81, 0xAA, 0x86,
  0xFF, 0x03, 0xC0, 0xF8, 0xE8, 0xD5, 0x82, 0xAA, 0x07, 0xAB, 0xA0, 0xBF, 0xFF, 0xFF, 0xFD, 0xEA,
  0xD5, 0x82, 0xAA, 0x01, 0xAF, 0xA0, 0x86, 0xFF, 0x0D, 0xE0, 0xF8, 0xFE, 0xFD, 0xFA, 0xFD, 0xFA,
  0xF5, 0xEA, 0xAA, 0xAA, 0xAF, 0xA0, 0xBF, 0x84, 0xFF, 0x05, 0x80, 0xFF, 0xBF, 0xA0, 0xFF, 0x80,
  0x84, 0xFF, 0x87, 0x00, 0x87, 0xFF, 0x01, 0x81, 0x99, 0x82, 0x81, 0x00, 0x99, 0x84, 0x81, 0x0C,
  0x9F, 0xF8, 0x92, 0xF8, 0x97, 0xF8, 0x97, 0xF8, 0x92, 0xF8, 0x9F, 0x8A, 0x8A, 0x82, 0xC0, 0x82,
  0xFF, 0x84, 0xC0, 0x0C, 0xFC, 0xF3, 0xA4, 0xF3, 0xF4, 0xF3, 0xF4, 0xF3, 0xA4, 0xF3, 0xFC, 0xA8,
  0xA8, 0x8B, 0xFF, 0x88, 0x80, 0x92, 0xFF, 0x82, 0x81, 0x82, 0xFF, 0x82, 0x81, 0x81, 0xFE, 0x0E,
  0x9F, 0x98, 0x92, 0x98, 0x97, 0x98, 0x97, 0x98, 0x92, 0x98, 0x9F, 0xF5, 0xF5, 0xC0, 0xCC, 0x82,
  0xC0, 0x00, 0xCC, 0x84, 0xC0, 0x0C, 0xFC, 0xF0, 0xA4, 0xF0, 0xF4, 0xF0, 0xF4, 0xF0, 0xA4, 0xF0,
  0xFC, 0xA8, 0xA8, 0xFE, 0x00, 0xFE, 0x00, 0xB1, 0x00, 0xFF};

byte COLORRLE[] = {
  0x87, 0x41, 0x81, 0xF1, 0x83, 0xF4, 0x09, 0xF1, 0x10, 0x1F, 0xF1, 0xE1, 0x91, 0x91, 0xF1,
  0x1F, 0x10, 0x87, 0xA6, 0x87, 0xA1, 0x87, 0xA6, 0x87, 0xF1, 0x8F, 0x41, 0x87, 0xA6, 0x87, 0x66,
  0x86, 0xA1, 0x00, 0xA6, 0x87, 0xB1, 0x86, 0xA1, 0x03, 0xA6, 0x1F, 0xF1, 0x91, 0x88, 0xF6, 0x03,
  0x91, 0xF1, 0x1F, 0x10, 0x87, 0x41, 0x87, 0xA6, 0x87, 0x41, 0x87, 0x01, 0x87, 0x41, 0x87, 0x01,
  0x09, 0xF1, 0x1F, 0x91, 0xE1, 0xE1, 0x6F, 0x6F, 0x91, 0x6F, 0x6F, 0x82, 0x91, 0x02, 0x1F, 0xF1,
  0x10, 0xFE, 0x41, 0xFE, 0x41, 0xFE, 0x41, 0xFE, 0x41, 0x9B, 0x41, 0x97, 0xA1, 0x8F, 0x41, 0x87,
  0x1A, 0x81, 0xF1, 0x0D, 0xF4, 0xFF, 0xF4, 0xF4, 0xF1, 0x10, 0x1F, 0xF1, 0xE1, 0xFF, 0x91, 0xF1,
  0x1F, 0x10, 0x87, 0xA1, 0x87, 0x1A, 0x87, 0xA1, 0x8F, 0x41, 0x87, 0x1A, 0x8F, 0x41, 0x97, 0xA1,
  0x03, 0x1F, 0xF1, 0x91, 0xFF, 0x86, 0xF6, 0x04, 0xFF, 0x91, 0xF1, 0x1F, 0x10, 0x87, 0x1A, 0x87,
  0x41, 0x9F, 0x1A, 0x0E, 0xF1, 0x1F, 0x91, 0xFF, 0xE1, 0x6F, 0x6F, 0x91, 0x6F, 0x6F, 0x91, 0xFF,
  0x91, 0x1F, 0xF1, 0x83, 0x10, 0x87, 0x1F, 0x85, 0x1B, 0x85, 0x1A, 0x82, 0x10, 0x01, 0x1F, 0x1E,
  0x83, 0x10, 0x06, 0x1F, 0x1E, 0x10, 0x1E, 0x10, 0x1E, 0x1F, 0x8F, 0x10, 0x04, 0x19, 0x16, 0x6A,
  0x6A, 0xA6, 0x84, 0x6A, 0x81, 0x60, 0x07, 0x16, 0x61, 0x16, 0x61, 0x16, 0x61, 0x16, 0x16, 0x8A,
  0x10, 0x00, 0x61, 0x82, 0x16, 0x81, 0x61, 0x01, 0x16, 0x61, 0x82, 0x16, 0x81, 0x10, 0x83, 0x16,
  0x01, 0x61, 0x16, 0x82, 0x61, 0x81, 0x16, 0x81, 0x61, 0x17, 0x16, 0x61, 0x16, 0x61, 0x16, 0x61,
  0x10, 0x61, 0x16, 0x16, 0x61, 0x16, 0x10, 0x61, 0x61, 0x16, 0x16, 0x61, 0x60, 0x61, 0x61, 0xA6,
  0x61, 0x91, 0x87, 0xF0, 0x0C, 0x10, 0x1B, 0xFA, 0xFA, 0xAF, 0xFA, 0xAF, 0xFA, 0xAF, 0xA0, 0xFA,
  0xAF, 0xFA, 0x82, 0xA0, 0x0C, 0xAF, 0xFA, 0xA0, 0xA0, 0xA1, 0x1A, 0xA1, 0x1A, 0x10, 0x10, 0xE1,
  0x10, 0x1F, 0x84, 0xE1, 0x07, 0x10, 0x1F, 0x10, 0x1E, 0x1E, 0x10, 0x1F, 0x1F, 0x83, 0x1B, 0x81,
  0x1F, 0x84, 0x10, 0x0C, 0x1F, 0x1B, 0xAF, 0xFA, 0xAF, 0xA0, 0xA6, 0x6A, 0xA6, 0x6A, 0xA6, 0x6A,
  0x6A, 0x83, 0x60, 0x04, 0x61, 0x16, 0x61, 0x16, 0x61, 0x87, 0x10, 0x81, 0x16, 0x05, 0x61, 0x16,
  0x10, 0x10, 0x61, 0x61, 0x82, 0x16, 0x83, 0x10, 0x05, 0x16, 0x61, 0x16, 0x10, 0x61, 0x10, 0x82,
  0x16, 0x81, 0x61, 0x81, 0x16, 0x06, 0x61, 0x10, 0x16, 0x61, 0x10, 0x16, 0x61, 0x83, 0x16, 0x81,
  0x10, 0x84, 0x16, 0x08, 0x61, 0x91, 0x6A, 0x61, 0x91, 0x16, 0x16, 0x10, 0x10, 0x90, 0xA1, 0x02,
  0x1A, 0xA1, 0x1A, 0x83, 0x10, 0x81, 0xE1, 0x83, 0x10, 0x06, 0xF1, 0xE1, 0x10, 0xE1, 0x10, 0x1E,
  0x1F, 0x84, 0x10, 0x0F, 0x1F, 0xFA, 0xFA, 0xAF, 0xFA, 0xAF, 0xA0, 0xA6, 0x6A, 0xA6, 0x6A, 0xA6,
  0x6A, 0xA6, 0x60, 0x60, 0x82, 0x61, 0x04, 0x16, 0x61, 0x16, 0x61, 0x16, 0x87, 0x10, 0x81, 0x16,
  0x81, 0x10, 0x81, 0x16, 0x00, 0x61, 0x82, 0x16, 0x86, 0x10, 0x84, 0x16, 0x82, 0x10, 0x09, 0x16,
  0x61, 0x16, 0x16, 0x61, 0x10, 0x16, 0x61, 0x61, 0x16, 0x85, 0x61, 0x0A, 0x16, 0x61, 0x16, 0x16,
  0x61, 0x61, 0x19, 0xA1, 0x91, 0x1A, 0x91, 0x82, 0x10, 0x05, 0x1F, 0xFA, 0xAF, 0xFA, 0xA0, 0xA0,
  0x82, 0xA6, 0x03, 0x6A, 0xA6, 0x6A, 0xA6, 0x83, 0x60, 0x04, 0x61, 0x16, 0x61, 0x16, 0x61, 0x88,
  0x10, 0x83, 0x16, 0x05, 0x10, 0x16, 0x16, 0x61, 0x16, 0x61, 0x84, 0x16, 0x82, 0x10, 0x03, 0x61,
  0x16, 0x16, 0x10, 0x82, 0x61, 0x82, 0x16, 0x03, 0x61, 0x10, 0x16, 0x61, 0x84, 0x16, 0x10, 0x10,
  0x16, 0x61, 0x16, 0x61, 0x16, 0x16, 0x10, 0x10, 0x16, 0x61, 0x6A, 0x16, 0x19, 0x16, 0x61, 0x16,
  0x82, 0x10, 0x0C, 0xF1, 0xFA, 0xAF, 0xFA, 0xA0, 0xA0, 0xA6, 0x6A, 0xA6, 0x6A, 0xA6, 0x6A, 0xA6,
  0x83, 0x10, 0x0D, 0xF1, 0xAF, 0xFA, 0xAF, 0xAF, 0xA0, 0x6A, 0xA6, 0x6A, 0xA6, 0x6A, 0xA6, 0x6A,
  0x6A, 0x82, 0x60, 0x05, 0x16, 0x61, 0x16, 0x61, 0x16, 0x16, 0x89, 0x10, 0x0C, 0xA1, 0xB1, 0xAF,
  0xFA, 0xA0, 0xA0, 0xA6, 0x6A, 0xA6, 0x6A, 0xA6, 0x6A, 0xA6, 0x83, 0x60, 0x01, 0x61, 0x16, 0x86,
  0x10, 0x81, 0x91, 0x82, 0xA6, 0x06, 0x6A, 0xA6, 0x6A, 0xA6, 0x6A, 0x60, 0x60, 0x83, 0x61, 0x03,
  0x16, 0x61, 0x16, 0x61, 0x86, 0x10, 0x88, 0x61, 0x04, 0x16, 0x61, 0x16, 0x61, 0x16, 0x84, 0x10,
  0x05, 0x61, 0x10, 0x16, 0x61, 0x10, 0x61, 0x84, 0x10, 0x87, 0x00, 0x87, 0xF0, 0x81, 0x19, 0x00,
  0x1E, 0x82, 0x19, 0x00, 0x1E, 0x84, 0x19, 0x0A, 0x1E, 0x19, 0x1E, 0x19, 0x1E, 0x19, 0x1E, 0x19,
  0x1E, 0x19, 0x1E, 0x83, 0x19, 0x82, 0x10, 0x00, 0x1E, 0x83, 0x19, 0x0C, 0x1E, 0x91, 0x19, 0x91,
  0x19, 0x91, 0x19, 0x91, 0x19, 0x91, 0x19, 0x1E, 0x18, 0x88, 0x10, 0x02, 0xE0, 0x80, 0x10, 0x88,
  0x18, 0x06, 0x10, 0xE0, 0x80, 0x10, 0xE0, 0x80, 0x10, 0x88, 0x80, 0x02, 0x10, 0xE0, 0x80, 0x82,
  0x19, 0x82, 0x10, 0x05, 0x1E, 0x19, 0x19, 0x91, 0x81, 0x1E, 0x89, 0x19, 0x04, 0xE1, 0x81, 0x19,
  0x19, 0x1E, 0x82, 0x19, 0x00, 0x1E, 0x84, 0x19, 0x0B, 0x81, 0x19, 0x81, 0x19, 0x91, 0x19, 0x81,
  0x19, 0x81, 0x19, 0x1E, 0x18, 0xFE, 0x00, 0xFE, 0x00, 0xB1, 0x00, 0xFF};