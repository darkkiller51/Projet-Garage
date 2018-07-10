#include <VirtualWire.h>

char *controller;
int bouton = 2; //bouton pin 2
int etatBouton = 0; //variable état du bouton
int dernierEtatBouton = 0; //variable état du bouton

void setup() {
  pinMode(13,OUTPUT);
  pinMode(bouton, INPUT);
  
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(5); //emetteur pin 5
  vw_setup(100);// vitesse en bit/s

  controller="1" ;
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx(); // Wait until the whole message is gone

}

void loop(){
etatBouton = digitalRead(bouton);

  if (etatBouton != dernierEtatBouton) {
    // if the state has changed, increment the counter
    if (etatBouton == HIGH) {
  
    controller="0" ;
    vw_send((uint8_t *)controller, strlen(controller));
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13,1);
  
    } else {
  
    controller="1" ;
    vw_send((uint8_t *)controller, strlen(controller));
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13,0);
    
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  dernierEtatBouton = etatBouton;

}
