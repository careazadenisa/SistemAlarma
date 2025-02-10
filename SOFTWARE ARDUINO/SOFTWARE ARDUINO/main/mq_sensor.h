int mq2_pin = A1;
float lpg, co, smoke;

MQ2 mq2(mq2_pin);

// functie ptr initializarea senzorului mq
void init_mq_sensor() {
  mq2.begin();
}

// functie pentru citirea datelor de la senzorul mq
void check_mq_sensor() {
  float* values = mq2.read(false);

  lpg = mq2.readLPG();
  if (lpg > 1000)
    lpg = 1000;

  co = mq2.readCO();
  if (co > 1000)
    co = 1000;
    
  smoke = mq2.readSmoke();
  if (smoke > 1000)
    smoke = 1000;
}
