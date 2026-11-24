// Руски текст на стандартен LCD 1602 (HD44780) с Arduino Mega 2560
//
// Свързване (същото като в примера 7e2):
//   LCD pin 1  VSS -> GND
//   LCD pin 2  VDD -> 5V
//   LCD pin 3  V0  -> среден извод на тример 10k (контраст), краищата към 5V и GND
//   LCD pin 4  RS  -> D8
//   LCD pin 5  RW  -> GND
//   LCD pin 6  E   -> D9
//   LCD pin 11 D4  -> D10
//   LCD pin 12 D5  -> D11
//   LCD pin 13 D6  -> D12
//   LCD pin 14 D7  -> D13
//   LCD pin 15 A   -> 5V (през ~220 Ом, ако модулът няма вграден резистор)
//   LCD pin 16 K   -> GND
//   (D0..D3, pin 7..10, остават свободни)

#include "LcdRus.h"

LcdRus lcd(8, 9, 10, 11, 12, 13);   // RS, E, D4, D5, D6, D7

void page(const char* l1, const char* l2, unsigned ms = 3000) {
  lcd.show(l1, l2);
  delay(ms);
}

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  page("Привет, мир!",  "Arduino Mega");
  page("Температура",   "23.5 C");
  page("Давление",      "Всё работает!");

  // Тест на всички "рисувани" букви (до 8 различни на екран)
  page("БГДЁЖЗИЙ",      "TEST 1/6");
  page("ЛПУФЦЧШЩ",      "TEST 2/6");
  page("ЪЫЬЭЮЯ",        "TEST 3/6");
  page("бгдёжзий",      "TEST 4/6");
  page("лпфцчшщъ",      "TEST 5/6");
  page("ыьэюя",         "TEST 6/6");
}
