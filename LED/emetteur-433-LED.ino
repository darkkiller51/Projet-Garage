#include <VirtualWire.h>

char *controller;

void setup() {
  pinMode(13,OUTPUT);
  
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(12); //emetteur pin 12
  vw_setup(100);// vitesse en bit/s
}

void loop(){
controller="1" ;
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(13,1);

controller="0" ;
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(13,0);
  
}
