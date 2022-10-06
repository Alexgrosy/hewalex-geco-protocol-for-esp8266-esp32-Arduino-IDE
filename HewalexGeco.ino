#include <SoftwareSerial.h>

SoftwareSerial RS485Serial;

float Temp[8];

void setup() {
  pinMode(D0, OUTPUT);
  Serial.begin(115200);
  RS485Serial.begin(38400, SWSERIAL_8N1, D1, D2, false);
}

void loop() {
  char messageread[1000];
  int pos = 0;
  byte message[] = { 0x69, 0x02, 0x01, 0x84, 0x00, 0x00, 0x0C, 0xF6, 0x02, 0x00, 0x01, 0x00, 0x40, 0x80, 0x00, 0x32, 0x64, 0x00, 0xBD, 0xB2 };

  digitalWrite(D0, HIGH);
  RS485Serial.write(message, 20);

  digitalWrite(D0, LOW);
  while(RS485Serial.available() > 0){
    messageread[pos] = RS485Serial.read();
    pos++;
  }

  if (messageread[0] == 0x69) {
    int fncID = messageread[12];
   if(fncID == 0x50){
     int startReg = messageread[16];
     for(int i = 0;i < messageread[15];i++)
        if(i %2 == 0){
         int iReg = i + startReg;
          if(iReg == 128){
            byte hexstr[] = {messageread[19+i], messageread[18+i]};
            int w = hexstr[0] << 8 | hexstr[1];
            if(w & 0x8000) {
              w = w - 0x10000;
            }
            Temp[0] = w / 10.0;
          }
          if(iReg == 130){
            byte hexstr[] = {messageread[19+i], messageread[18+i]};
            int w = hexstr[0] << 8 | hexstr[1];
            if(w & 0x8000) {
              w = w - 0x10000;
            }
            Temp[1] = w / 10.0;
         }
         if(iReg == 132){
            byte hexstr[] = {messageread[19+i], messageread[18+i]};
           int w = hexstr[0] << 8 | hexstr[1];
           if(w & 0x8000) {
              w = w - 0x10000;
            }
           Temp[2] = w / 10.0;
         }
         if(iReg == 138){
           byte hexstr[] = {messageread[19+i], messageread[18+i]};
           int w = hexstr[0] << 8 | hexstr[1];
           if(w & 0x8000) {
             w = w - 0x10000;
           }
           Temp[3] = w / 10.0;
         }
         if(iReg == 140){
           byte hexstr[] = {messageread[19+i], messageread[18+i]};
           int w = hexstr[0] << 8 | hexstr[1];
           if(w & 0x8000) {
             w = w - 0x10000;
           }
           Temp[4] = w / 10.0;
         }
         if(iReg == 142){
           byte hexstr[] = {messageread[19+i], messageread[18+i]};
           int w = hexstr[0] << 8 | hexstr[1];
           if(w & 0x8000) {
             w = w - 0x10000;
           }
           Temp[5] = w / 10.0;
         }        

          if(iReg == 144){
           byte hexstr[] = {messageread[19+i], messageread[18+i]};
           int w = hexstr[0] << 8 | hexstr[1];
           if(w & 0x8000) {
             w = w - 0x10000;
           }
           Temp[6] = w / 10.0;
         }
         if(iReg == 146){
           byte hexstr[] = {messageread[19+i], messageread[18+i]};
           int w = hexstr[0] << 8 | hexstr[1];
           if(w & 0x8000) {
             w = w - 0x10000;
           }
            Temp[7] = w / 10.0;
         }
        }
     }
    }

  for(int i=0; i<8); i++){
   Serial.print("Temperature");
   Serial.print(i);
   Serial.print("= ");
   Serial.print(Temp[i]);
   Serial.println();
  }       
  delay(2000);
}
