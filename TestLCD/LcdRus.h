// LcdRus.h - руски текст на СТАНДАРТЕН HD44780 дисплей (16x2) без кирилица в ROM.
//
// Как работи:
//  * Буквите, които изглеждат като латински (А В Е К М Н О Р С Т Х, а е о р с у х ...),
//    се печатат със съответния латински код от ROM.
//  * Останалите (Б Г Д Ж З И Й Л П ... ) се чертаят в CGRAM (8 свободни символа).
//  * ОГРАНИЧЕНИЕ: на един екран (двата реда заедно) може да има най-много 8
//    РАЗЛИЧНИ "рисувани" букви. Излишните се заменят с '?', а show() връща броя им.
//
// Текстът се подава като UTF-8 (така го записва Arduino IDE в низовете).

#pragma once
#include <Arduino.h>
#include <LiquidCrystal.h>
#include <avr/pgmspace.h>

struct LcdRusGlyph {
  uint16_t cp;       // Unicode код
  uint8_t  rows[8];  // 5x8 растер
};

static const LcdRusGlyph LCDRUS_GLYPHS[] PROGMEM = {
  // ---------- ГЛАВНИ ----------
  {0x0401, {0b01010,0b11111,0b10000,0b11110,0b10000,0b10000,0b11111,0b00000}}, // Ё
  {0x0411, {0b11111,0b10000,0b10000,0b11110,0b10001,0b10001,0b11110,0b00000}}, // Б
  {0x0413, {0b11111,0b10000,0b10000,0b10000,0b10000,0b10000,0b10000,0b00000}}, // Г
  {0x0414, {0b00111,0b01001,0b01001,0b01001,0b01001,0b11111,0b10001,0b00000}}, // Д
  {0x0416, {0b10101,0b10101,0b10101,0b01110,0b10101,0b10101,0b10101,0b00000}}, // Ж
  {0x0417, {0b01110,0b10001,0b00001,0b00110,0b00001,0b10001,0b01110,0b00000}}, // З
  {0x0418, {0b10001,0b10001,0b10011,0b10101,0b11001,0b10001,0b10001,0b00000}}, // И
  {0x0419, {0b01010,0b10001,0b10001,0b10011,0b10101,0b11001,0b10001,0b00000}}, // Й
  {0x041B, {0b00111,0b01001,0b01001,0b01001,0b01001,0b01001,0b10001,0b00000}}, // Л
  {0x041F, {0b11111,0b10001,0b10001,0b10001,0b10001,0b10001,0b10001,0b00000}}, // П
  {0x0423, {0b10001,0b10001,0b10001,0b01111,0b00001,0b10001,0b01110,0b00000}}, // У
  {0x0424, {0b00100,0b01110,0b10101,0b10101,0b10101,0b01110,0b00100,0b00000}}, // Ф
  {0x0426, {0b10010,0b10010,0b10010,0b10010,0b10010,0b11111,0b00001,0b00000}}, // Ц
  {0x0427, {0b10001,0b10001,0b10001,0b01111,0b00001,0b00001,0b00001,0b00000}}, // Ч
  {0x0428, {0b10101,0b10101,0b10101,0b10101,0b10101,0b10101,0b11111,0b00000}}, // Ш
  {0x0429, {0b10101,0b10101,0b10101,0b10101,0b10101,0b11111,0b00001,0b00000}}, // Щ
  {0x042A, {0b11000,0b01000,0b01000,0b01110,0b01001,0b01001,0b01110,0b00000}}, // Ъ
  {0x042B, {0b10001,0b10001,0b10001,0b11001,0b10101,0b10101,0b11001,0b00000}}, // Ы
  {0x042C, {0b10000,0b10000,0b10000,0b11110,0b10001,0b10001,0b11110,0b00000}}, // Ь
  {0x042D, {0b01110,0b10001,0b00001,0b00111,0b00001,0b10001,0b01110,0b00000}}, // Э
  {0x042E, {0b10010,0b10101,0b10101,0b11101,0b10101,0b10101,0b10010,0b00000}}, // Ю
  {0x042F, {0b01111,0b10001,0b10001,0b01111,0b00101,0b01001,0b10001,0b00000}}, // Я
  // ---------- МАЛКИ ----------
  {0x0431, {0b00110,0b01000,0b10000,0b11110,0b10001,0b10001,0b01110,0b00000}}, // б
  {0x0433, {0b00000,0b00000,0b11110,0b10000,0b10000,0b10000,0b10000,0b00000}}, // г
  {0x0434, {0b00000,0b00000,0b00111,0b01001,0b01001,0b11111,0b10001,0b00000}}, // д
  {0x0436, {0b00000,0b00000,0b10101,0b10101,0b01110,0b10101,0b10101,0b00000}}, // ж
  {0x0437, {0b00000,0b00000,0b01110,0b00001,0b00110,0b00001,0b01110,0b00000}}, // з
  {0x0438, {0b00000,0b00000,0b10001,0b10011,0b10101,0b11001,0b10001,0b00000}}, // и
  {0x0439, {0b01010,0b00100,0b10001,0b10011,0b10101,0b11001,0b10001,0b00000}}, // й
  {0x043B, {0b00000,0b00000,0b00111,0b01001,0b01001,0b01001,0b10001,0b00000}}, // л
  {0x043F, {0b00000,0b00000,0b11111,0b10001,0b10001,0b10001,0b10001,0b00000}}, // п
  {0x0444, {0b00100,0b00100,0b01110,0b10101,0b10101,0b01110,0b00100,0b00100}}, // ф
  {0x0446, {0b00000,0b00000,0b10010,0b10010,0b10010,0b11111,0b00001,0b00000}}, // ц
  {0x0447, {0b00000,0b00000,0b10001,0b10001,0b01111,0b00001,0b00001,0b00000}}, // ч
  {0x0448, {0b00000,0b00000,0b10101,0b10101,0b10101,0b10101,0b11111,0b00000}}, // ш
  {0x0449, {0b00000,0b00000,0b10101,0b10101,0b10101,0b11111,0b00001,0b00000}}, // щ
  {0x044A, {0b00000,0b00000,0b11000,0b01000,0b01110,0b01001,0b01110,0b00000}}, // ъ
  {0x044B, {0b00000,0b00000,0b10001,0b10001,0b11001,0b10101,0b11001,0b00000}}, // ы
  {0x044C, {0b00000,0b00000,0b10000,0b10000,0b11110,0b10001,0b11110,0b00000}}, // ь
  {0x044D, {0b00000,0b00000,0b01110,0b00001,0b00111,0b00001,0b01110,0b00000}}, // э
  {0x044E, {0b00000,0b00000,0b10010,0b10101,0b11101,0b10101,0b10010,0b00000}}, // ю
  {0x044F, {0b00000,0b00000,0b01111,0b10001,0b01111,0b00101,0b01001,0b00000}}, // я
  {0x0451, {0b01010,0b00000,0b01110,0b10001,0b11111,0b10000,0b01110,0b00000}}, // ё
};
static const uint8_t LCDRUS_GLYPH_COUNT = sizeof(LCDRUS_GLYPHS) / sizeof(LCDRUS_GLYPHS[0]);

class LcdRus {
public:
  // 4-битов режим, RW -> GND
  LcdRus(uint8_t rs, uint8_t en, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
    : _lcd(rs, en, d4, d5, d6, d7) {}

  void begin(uint8_t cols = 16, uint8_t rows = 2) {
    _cols = (cols > 20) ? 20 : cols;
    _rows = (rows > 2) ? 2 : rows;
    _lcd.begin(_cols, _rows);
    _lcd.clear();
  }

  // Показва два реда (UTF-8). Връща броя символи, заменени с '?'.
  uint8_t show(const char* line1, const char* line2 = "") {
    uint8_t out[2][20];
    uint8_t glyphIdx[8];
    uint16_t glyphCp[8];
    uint8_t nGlyph = 0, bad = 0;
    const char* lines[2] = { line1, line2 };

    for (uint8_t r = 0; r < _rows; r++) {
      const char* p = lines[r];
      uint8_t col = 0;
      while (*p && col < _cols) {
        uint16_t cp = nextCodepoint(p);
        uint8_t code;
        if (cp < 0x80) {
          code = (uint8_t)cp;
        } else {
          char la = lookalike(cp);
          if (la) {
            code = (uint8_t)la;
          } else {
            int16_t gi = findGlyph(cp);
            if (gi < 0) {
              code = '?'; bad++;
            } else {
              int8_t slot = -1;
              for (uint8_t i = 0; i < nGlyph; i++) if (glyphCp[i] == cp) { slot = i; break; }
              if (slot < 0 && nGlyph < 8) {
                glyphCp[nGlyph] = cp;
                glyphIdx[nGlyph] = (uint8_t)gi;
                slot = nGlyph++;
              }
              if (slot < 0) { code = '?'; bad++; }
              else code = (uint8_t)slot;
            }
          }
        }
        out[r][col++] = code;
      }
      while (col < _cols) out[r][col++] = ' ';
    }

    // 1) зареждаме рисуваните букви в CGRAM
    for (uint8_t i = 0; i < nGlyph; i++) {
      uint8_t bmp[8];
      memcpy_P(bmp, &LCDRUS_GLYPHS[glyphIdx[i]].rows[0], 8);
      _lcd.createChar(i, bmp);
    }
    // 2) печатаме (setCursor връща адреса към DDRAM)
    for (uint8_t r = 0; r < _rows; r++) {
      _lcd.setCursor(0, r);
      for (uint8_t c = 0; c < _cols; c++) _lcd.write(out[r][c]);
    }
    return bad;
  }

  void clear() { _lcd.clear(); }
  LiquidCrystal& raw() { return _lcd; }

private:
  LiquidCrystal _lcd;
  uint8_t _cols = 16, _rows = 2;

  // UTF-8 -> Unicode (само 1- и 2-байтови последователности)
  static uint16_t nextCodepoint(const char*& p) {
    uint8_t b = (uint8_t)*p++;
    if (b < 0x80) return b;
    if ((b & 0xE0) == 0xC0 && *p) {
      uint8_t b2 = (uint8_t)*p++;
      return ((uint16_t)(b & 0x1F) << 6) | (b2 & 0x3F);
    }
    while (*p && (((uint8_t)*p) & 0xC0) == 0x80) p++;  // пропускаме 3/4-байтови
    return '?';
  }

  static char lookalike(uint16_t cp) {
    switch (cp) {
      case 0x0410: return 'A'; case 0x0412: return 'B'; case 0x0415: return 'E';
      case 0x041A: return 'K'; case 0x041C: return 'M'; case 0x041D: return 'H';
      case 0x041E: return 'O'; case 0x0420: return 'P'; case 0x0421: return 'C';
      case 0x0422: return 'T'; case 0x0425: return 'X';
      case 0x0430: return 'a'; case 0x0432: return 'B'; case 0x0435: return 'e';
      case 0x043A: return 'K'; case 0x043C: return 'M'; case 0x043D: return 'H';
      case 0x043E: return 'o'; case 0x0440: return 'p'; case 0x0441: return 'c';
      case 0x0442: return 'T'; case 0x0443: return 'y'; case 0x0445: return 'x';
    }
    return 0;
  }

  static int16_t findGlyph(uint16_t cp) {
    for (uint8_t i = 0; i < LCDRUS_GLYPH_COUNT; i++)
      if (pgm_read_word(&LCDRUS_GLYPHS[i].cp) == cp) return i;
    return -1;
  }
};
