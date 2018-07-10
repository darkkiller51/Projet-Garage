#include <VirtualWire.h>

int LED = 2;

void setup(){
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_set_rx_pin(5);
  vw_setup(100); // Bits per sec
  pinMode(LED, OUTPUT);
  
  vw_rx_start(); // Start the receiver PLL running
}
void loop(){
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  
  if (vw_get_message(buf, &buflen)) { // Non-blocking
    if(buf[0]=='1'){
      digitalWrite(LED,1);
    }
    if(buf[0]=='0'){
      digitalWrite(LED,0);
    }
  }
}
