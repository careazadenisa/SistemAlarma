// definire obiect comunicare wifi
ESP8266WiFiMulti WiFiMulti;

String url_ts = "http://api.thingspeak.com/update?api_key=IN3N4D7MRHSSJIQL";

unsigned long last_ts_sent = 0, TS_INTERVAL = 15000;

// initializare modul tks
void init_tks() {
  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("iPhone", "12345678");
}

// functie ptr trimiterea datelor catre tks
void update_tks(String payload) {
  if ((millis() - last_ts_sent > TS_INTERVAL)) {
    
    if (WiFiMulti.run() == WL_CONNECTED) {

      WiFiClient client;
      HTTPClient http;
      
       String _url = url_ts;
      _url += "&field1=";
      _url += get_value(payload, ',', 4); // alarma
      _url += "&field2=";
      _url += get_value(payload, ',', 5); // lpg
      _url += "&field3=";
      _url += get_value(payload, ',', 6); // co
      _url += "&field4=";
      _url += get_value(payload, ',', 7); // smoke
      _url += "&field5=";
      _url += get_value(payload, ',', 8);  // I
      _url += "&field6=";
      _url += get_value(payload, ',', 9);  // pir
      _url += "&field7=";
      _url += get_value(payload, ',', 10); // t
      _url += "&field8=";
      _url += get_value(payload, ',', 11); // h
      
      if (http.begin(client, _url)) {
        int httpCode = http.GET();
        if (httpCode > 0) {
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
            String payload = http.getString();
          }
        }
        http.end();
      }
    }
    last_ts_sent = millis();
  }
}
