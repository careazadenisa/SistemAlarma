// variabile pentru comunicarea seriala
SoftwareSerial comm(12, 13); // tx, rx

// functie pentru initializarea comunicarii seriale
void init_communication() {
  comm.begin(1200);
}

// functie pentru trimiterea datelor serial
void send_data(String payload) {
  char* buf = (char*) malloc(sizeof(char) * payload.length() + 1);
  payload.toCharArray(buf, payload.length() + 1);
  comm.write(buf);
  free(buf);
}
