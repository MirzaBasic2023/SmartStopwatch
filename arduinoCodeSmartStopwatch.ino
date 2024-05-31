/*

Code by Edhem Krivdić, 2024

*/

const int start = 13, stopp = 6;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
#include <LiquidCrystal.h>
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
unsigned long trenutno_vrijeme, sekunde, milisekunde, interval, proslo_vrijeme = 0;
bool istina = true;  //sluzi za provjeru da li se prvi put pokrece funkcija stopperica u rekurziji iste funckije
void stopperica();
void kraj();
void setup() 
{
  pinMode(stopp, INPUT);
  pinMode(start, INPUT);
  lcd.begin(16, 2);
  lcd.print("Rising Edge(TM)");
  delay(3000);
  lcd.clear();
}
void loop() 
{
  lcd.setCursor(0, 0);
  lcd.print("vrijeme:");
  lcd.print("0:");
  lcd.print("0");
  if (digitalRead(start) == HIGH) {
    istina = true;
    stopperica();
  }
}
void stopperica()
 {
  if (istina == true) {
    trenutno_vrijeme = millis();
    proslo_vrijeme = trenutno_vrijeme;
  }
  istina = false;
  lcd.clear();
  trenutno_vrijeme =millis();
  interval = trenutno_vrijeme - proslo_vrijeme;
  sekunde = interval / 1000;
  milisekunde = interval - sekunde * 1000;
  lcd.setCursor(0, 0);
  lcd.print("vrijeme: ");
  lcd.print(sekunde);
  lcd.print(":");
  lcd.print(milisekunde);
  delay(100);
  digitalRead(stopp) == HIGH ? stopperica():kraj() ;  // obrnuti kraj i stoppericu za projekat(signal se ocitava low na finalnoj semi) // prvo stopperica() pa kraj
}
void kraj()
 {
  lcd.clear();
  lcd.setCursor(0, 0);
  interval = trenutno_vrijeme - proslo_vrijeme;
  sekunde = interval / 1000;
  milisekunde = interval - sekunde * 1000;
  lcd.setCursor(0, 0);
  lcd.print("VRIJEME: ");
  lcd.print(sekunde);
  lcd.print(":");
  lcd.print(milisekunde);
  delay(10000);
  lcd.clear();
  interval = 0;
  sekunde = 0;
  milisekunde = 0;
  return;
}
