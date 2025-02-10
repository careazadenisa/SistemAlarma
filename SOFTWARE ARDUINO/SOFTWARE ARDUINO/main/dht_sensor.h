#define DHTPIN A3
#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE);

float h = 0;
float t = 0;

// functie pentru initializarea senzorului dht
void init_dht() {
  dht.begin();
}

// functie pentru verificarea senzorului dht
void check_dht() {
  h = dht.readHumidity();
  t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    h = 0;
    t = 0;
  }
}
