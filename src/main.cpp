#include <Arduino.h>
#include <IRremote.h>

const int LED = 13; // set pin 13 as LED
int RECV_PIN = 7;   // set pin 7 as IR

IRrecv irrecv(RECV_PIN);
decode_results results;

int inputIR = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // init Serial monitor

  irrecv.enableIRIn(); // enable IR module

  pinMode(LED, OUTPUT);     // set LED as OUTPUT
  pinMode(RECV_PIN, INPUT); // set IR as INPUT
}

void translateIR() // takes action based on IR code received
{
  switch (results.value) {
  case 0xFFA25D:
    Serial.println(" CH-            ");
    break;
  case 0xFF629D:
    Serial.println(" CH             ");
    break;
  case 0xFFE21D:
    Serial.println(" CH+            ");
    break;
  case 0xFF22DD:
    Serial.println(" PREV           ");
    break;
  case 0xFF02FD:
    Serial.println(" NEXT           ");
    break;
  case 0xFFC23D:
    Serial.println(" PLAY/PAUSE     ");
    break;
  case 0xFFE01F:
    Serial.println(" VOL-           ");
    break;
  case 0xFFA857:
    Serial.println(" VOL+           ");
    break;
  case 0xFF906F:
    Serial.println(" EQ             ");
    break;
  case 0xFF6897:
    Serial.println(" 0              ");
    break;
  case 0xFF9867:
    Serial.println(" 100+           ");
    break;
  case 0xFFB04F:
    Serial.println(" 200+           ");
    break;
  case 0xFF30CF:
    Serial.println(" 1              ");
    break;
  case 0xFF18E7:
    Serial.println(" 2              ");
    break;
  case C0302AC2:
    Serial.println(" 3              ");
    break;
  case 0xFF10EF:
    Serial.println(" 4              ");
    break;
  case 0xFF38C7:
    Serial.println(" 5              ");
    break;
  case 0xFF5AA5:
    Serial.println(" 6              ");
    break;
  case 0xFF42BD:
    Serial.println(" 7              ");
    break;
  case 0xFF4AB5:
    Serial.println(" 8              ");
    break;
  case 0xFF52AD:
    Serial.println(" 9              ");
    break;
  default:
    Serial.println(" other button   ");
  }
  delay(500);
} // END translateIR

void loop() {
  // put your main code here, to run repeatedly:
  // digitalWrite(LED, HIGH); // test LED

  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    //    Serial.println(results.value, HEX);  UN Comment to see raw values
    translateIR();
    irrecv.resume(); // receive the next value
  }
  Serial.println(results.value, HEX);

  delay(1000);
}
