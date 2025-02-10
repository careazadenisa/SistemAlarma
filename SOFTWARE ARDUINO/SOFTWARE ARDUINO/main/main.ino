#include "libraries.h"

unsigned long last_sent = 0, INTERVAL = 100;
unsigned long last_sent_2 = 0, INTERVAL_2 = 2000;

// functie pentru initializarea programului
void setup() {
  // initializare afisare seriala
  Serial.begin(9600);

  // initializare module create
  init_communication();
  init_relays();
  init_mq_sensor();
  init_acs_sensor();
  init_pir();
  init_buzzer();
  init_led();
  init_btns();
}

// functie care se executa in bucla
void loop() {
  // verificam daca butoanele sunt apasate
  check_btns();
  // verificam daca pir-ul a detectat miscare
  check_pir();

  // verificam daca putem citi datele de la dht, mq si acs la un anumit interval predefinit
  if ((millis() - last_sent_2 > INTERVAL_2)) {
    check_dht();
    check_mq_sensor();
    check_acs_sensor();
    last_sent_2 = millis();
  }

  // analizam informatiile de la butoane si verificam daca alarma este activata
  int alarm = 0;
  if (_button1 == 1 || _button2 == 1 || _button3 == 1 || _button4 == 1 || pir == 1) {
    alarm = 1;
    buzzer_on();
    led_on();
  } else {
    led_off();
  }

  // daca pir-ul este activat, activam si releul 1
  if (pir) {
    relay_one_on();
  } else {
    relay_one_off();
  }

  // daca temperatura este mai mare decat 25 activam releu 2
  if (t > 25) {
    relay_two_on();
  } else {
    relay_two_off();
  }

  // trimitem datele prin comunicare seriala la un anumit interval
  if ((millis() - last_sent > INTERVAL)) {
    String payload = String(_button1);
    payload += ",";
    payload += String(_button2);
    payload += ",";
    payload += String(_button3);
    payload += ",";
    payload += String(_button4);
    payload += ",";
    payload += String(alarm);
    payload += ",";
    payload += String(lpg);
    payload += ",";
    payload += String(co);
    payload += ",";
    payload += String(smoke);
    payload += ",";
    payload += String(I);
    payload += ",";
    payload += String(pir);
    payload += ",";
    payload += String(t);
    payload += ",";
    payload += String(h);
    payload += "_";

    send_data(payload);

    Serial.println(payload);

    last_sent = millis();
  }
}
