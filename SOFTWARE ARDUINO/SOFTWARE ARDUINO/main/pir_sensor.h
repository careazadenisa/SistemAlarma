int pir_one_pin = 10;

int pir = 0;

// functie pentru initializare senzor pir
void init_pir() {
  pinMode(pir_one_pin, INPUT); 
}

// functie pentru verificarea senzorului pirs
bool check_pir(){
  pir = digitalRead(pir_one_pin);
}
