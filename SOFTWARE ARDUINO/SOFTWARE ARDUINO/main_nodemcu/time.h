const long utcOffsetInSeconds = 3600 * 2;

int hours = 0;
int minutes = 0;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

// functie pentru citirea datelor ntp
void init_time() {
  timeClient.begin();
}

// functie pentru actualizarea timpului
void update_time() {
  timeClient.update();

  hours = timeClient.getHours();
  minutes = timeClient.getMinutes();
}
