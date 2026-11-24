#include "LcdRus.h"
LcdRus lcd(8, 9, 10, 11, 12, 13);   // RS, E, D4, D5, D6, D7

void setup() { lcd.begin(16, 2); }
void loop()  { lcd.show("Привет, мир!", "Arduino Mega"); }
