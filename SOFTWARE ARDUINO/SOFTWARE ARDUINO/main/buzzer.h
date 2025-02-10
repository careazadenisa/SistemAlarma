const int buzzer = 9;

// initializare modul buzzer
void init_buzzer(){
  pinMode(buzzer, OUTPUT);
}

// activare buzzer
void buzzer_on(){
  tone(buzzer, 1000); 
  delay(200);     
  noTone(buzzer);  
  delay(200);    
}

// verificare buzzer - functie de test
void check_buzzer(){
  tone(buzzer, 1000); 
  delay(1000);     
  noTone(buzzer);  
  delay(1000);      
}
