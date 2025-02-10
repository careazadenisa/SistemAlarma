// functie pentru extragerea unui index din string
String get_value(String data, char separator, int index) {
  int found = 0;
  int str_index[] = { 0, -1 };
  int max_index = data.length() - 1;

  for (int i = 0; i <= max_index && found <= index; i++) {
    if (data.charAt(i) == separator || i == max_index) {
      found++;
      str_index[0] = str_index[1] + 1;
      str_index[1] = (i == max_index) ? i + 1 : i;
    }
  }
  return found > index ? data.substring(str_index[0], str_index[1]) : "";
}

// functie pentru formatarea timpului
String get_hours_and_minutes(int h, int m) {
  String _h, _m;
  if (h == 0)
    _h = "00";
  else if (h < 10)
    _h = "0" + String(h);
  else
    _h = String(h);
    
  if (m == 0)
    _m = "00";
  else if (m < 10)
    _m = "0" + String(m);
  else
    _m = String(m);
    
  return _h + ":" + _m;
}
