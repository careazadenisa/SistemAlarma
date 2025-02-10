// includerea librariilor
#include "libs.h"

// functia de initializare program
void setup() {
  // initializare afisare seriala
  Serial.begin(9600);

  // initializare pachet de timp, comunicare thingspeak, lcd si comunicare seriala
  init_time();
  init_tks();
  init_lcd();
  init_communication();
}

// functie bucla
void loop() {
  // apelam functia pentru citirea datelor venite serial
  receive_data();
}
