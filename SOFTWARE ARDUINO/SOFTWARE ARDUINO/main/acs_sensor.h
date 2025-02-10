ACS712 sensor(ACS712_30A, A2);

float I = 0;

// initializare senzor acs
void init_acs_sensor() {
  int zero = sensor.calibrate();
}

// citire data senzor acs
void check_acs_sensor() {
  I = sensor.getCurrentDC();
}
