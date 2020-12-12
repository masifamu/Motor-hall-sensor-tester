uint8_t a=0;
uint16_t count=0;
void pciSetup(byte pin)
{
    *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // enable pin
    PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
    PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}

ISR (PCINT0_vect) // handle pin change interrupt for D8 to D13 here
 {    
    a=PINB & 0b00000111;
    count++;
    // put your main code here, to run repeatedly:
  Serial.print(a);Serial.print(" :");
  Serial.println(count);
 }
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pciSetup(8);
  pciSetup(9);
  pciSetup(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.print(a);Serial.print(" :");
  //Serial.println(count);
}
