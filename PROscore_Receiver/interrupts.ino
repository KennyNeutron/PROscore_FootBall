void PSABTinterrupt_setup() {
  cli();  // disable interrupts

  // set timer2 interrupt at 8kHz
  TCCR2A = 0;
  TCCR2B = 0;
  TCNT2 = 0;
  OCR2A = 249;
  TCCR2A |= (1 << WGM21);
  TCCR2B |= (1 << CS21);
  TIMSK2 |= (1 << OCIE2A);

  sei();  // enable interrupts
}

// Interrput for Time
ISR(TIMER2_COMPA_vect) {
  // timer2 interrupt 8kHz

  cli();  //disable all interrupts
  isr_tmr_counter++;
  if (isr_tmr_counter >= 400) {
    isr_tmr_counter = 0;
    display_updated = false;
  }

  if (SetupMode) {
    blinker_millis++;
    if (blinker_millis >= 400) {
      blinker_millis = 0;
      blink = !blink;
    }
  }

  sei();  //enable all interrupts
}