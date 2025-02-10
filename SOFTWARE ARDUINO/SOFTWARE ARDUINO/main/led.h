const int led_pin = 8;

// led on
void led_on() {
  digitalWrite(led_pin, HIGH);
}

// led off
void led_off() {
  digitalWrite(led_pin, LOW);
}

// functie pentru initializarea ledului
void init_led() {
  pinMode(led_pin, OUTPUT);

  led_off();
}
