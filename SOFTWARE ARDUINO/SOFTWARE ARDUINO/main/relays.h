// definire pini relee
const int relay_one_pin = 6;
const int relay_two_pin = 7;

// functie ptr deschiderea releului unu
void relay_one_on() {
  digitalWrite(relay_one_pin, LOW);
}

// functie ptr inchiderea releului unu
void relay_one_off() {
  digitalWrite(relay_one_pin, HIGH);
}

// functie ptr deschiderea releului doi
void relay_two_on() {
  digitalWrite(relay_two_pin, LOW);
}

// functie ptr inchiderea releului doi
void relay_two_off() {
  digitalWrite(relay_two_pin, HIGH);
}

// functie pentru initializarea releelor
void init_relays() {
  pinMode(relay_one_pin, OUTPUT);
  pinMode(relay_two_pin, OUTPUT);

  relay_one_off();
  relay_two_off();
}
