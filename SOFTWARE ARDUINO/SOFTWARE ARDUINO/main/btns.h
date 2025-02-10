ezButton button1(2);
ezButton button2(3);
ezButton button3(4);
ezButton button4(5);

int _button1 = 0;
int _button2 = 0;
int _button3 = 0;
int _button4 = 0;

// initializare butoane
void init_btns() {
  button1.setDebounceTime(50);
  button2.setDebounceTime(50);
  button3.setDebounceTime(50);
  button4.setDebounceTime(50);
}

// verificare butoane
void check_btns() {
  button1.loop(); 
  button2.loop(); 
  button3.loop(); 
  button4.loop(); 

  int btn1State = button1.getState();
  int btn2State = button2.getState();
  int btn3State = button3.getState();
  int btn4State = button4.getState();

  if (button1.isPressed())
    _button1 = 1;

  if (button1.isReleased())
    _button1 = 0;

  if (button2.isPressed())
    _button2 = 1;

  if (button2.isReleased())
    _button2 = 0;

  if (button3.isPressed())
     _button3 = 1;

  if (button3.isReleased())
    _button3 = 0;

  if (button4.isPressed())
    _button4 = 1;

  if (button4.isReleased())
    _button4 = 0;
}