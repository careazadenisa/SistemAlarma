// definire comunicare seriala
SoftwareSerial comm(D6, D5);

String payload = "";

// functie pentru citirea datelor venite serial
void receive_data() {
  while (comm.available() > 0) {

    char inChar = comm.read();
    payload.concat(inChar);

    if (payload.endsWith("_")) {
      payload.replace("_", "");

      Serial.println(payload);
      
      update_time();
      update_lcd(payload);
      update_tks(payload);
      payload = "";
    }
  }
}

// functie pentru initializarea comunicarii seriala
void init_communication() {
  comm.begin(1200);
}
