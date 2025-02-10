LiquidCrystal_I2C lcd(0x27, 16, 2);

unsigned long lcd_update = 0, LCD_INTERVAL = 500;

//initializarea modulului lcd
void init_lcd() {
  lcd.init();
  lcd.backlight();
}

// functie pentru actualizarea informatiilor pe lcd
void update_lcd(String payload) {
  if ((millis() - lcd_update > LCD_INTERVAL)) {
    lcd.clear();

    if (get_value(payload, ',', 4) == String("1")) {
      lcd.setCursor(0, 0);
      lcd.print("Alarma !!! ");
      lcd.print(get_hours_and_minutes(hours, minutes));
    } else {
      lcd.setCursor(0, 0);
      lcd.print("           ");
      lcd.print(get_hours_and_minutes(hours, minutes));
    }

    lcd.setCursor(0, 1);
    lcd.print(get_value(payload, ',', 10).toInt());  // t
    lcd.print(" ");
        lcd.print(get_value(payload, ',', 11).toInt());  // h
    lcd.print(" ");
    lcd.print(get_value(payload, ',', 6).toInt());  // co
    lcd.print(" ");
    lcd.print(WiFi.RSSI());  // rssi

    lcd_update = millis();
  }
}