#include "LiquidCrystalRus.h"

// Свързване като в основния проект 7e2:
// RS -> D8, E -> D9, D4 -> D10, D5 -> D11, D6 -> D12, D7 -> D13
LiquidCrystalRus lcd(8, 9, 10, 11, 12, 13);

void showPage(const char *title, const char *letters)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(title);
  lcd.setCursor(0, 1);
  lcd.print(letters);
  delay(3500);
}

void setup()
{
  lcd.begin(16, 2);
}

void loop()
{
  showPage("RUSSIAN TEST 1/4", "АБВГДЕЁЖЗИЙКЛМНО");
  showPage("RUSSIAN TEST 2/4", "ПРСТУФХЦЧШЩЪЫЬЭЮ");
  showPage("RUSSIAN TEST 3/4", "Я");
  showPage("RUSSIAN TEST 4/4", "абвгдеёжзийклмно");
}
