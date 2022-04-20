#include <SoftwareSerial.h>
// RS485 setup with ESp32
#define RE 32  // Connect RE terminal with 32 of ESP
#define DE 33    // Connect DE terminal with 33 of ESP            
const byte BufferKelembaban[] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x84, 0x0A};
const byte BufferSuhu[] = {0x01, 0x03, 0x00, 0x01, 0x00, 0x01, 0xD5, 0xCA};
const byte BufferKonduktifitas[] = {0x01, 0x03, 0x00, 0x02, 0x00, 0x01, 0x25, 0xCA};
const byte BufferPH[] = {0x01, 0x03, 0x00, 0x03, 0x00, 0x01, 0x74, 0x0A};
const byte BufferNitrogen[] = {0x01, 0x03, 0x00, 0x04, 0x00, 0x01, 0xC5, 0xCB};
const byte BufferPhospor[] = {0x01, 0x03, 0x00, 0x05, 0x00, 0x01, 0x94, 0x0B};
const byte BufferKalium[] = {0x01, 0x03, 0x00, 0x06, 0x00, 0x01, 0x64, 0x0B};
const byte BufferSalinitas[] = {0x01, 0x03, 0x00, 0x07, 0x00, 0x01, 0x35, 0xCB};
const byte BufferTDS[] = {0x01, 0x03, 0x00, 0x08, 0x00, 0x01, 0x05, 0xC8};

byte BufferValue[8];
SoftwareSerial mod(26, 27); // RX=26 , TX =27

byte values[11];
float Kelembaban = 0;
float Suhu = 0;
float Konduktifitas = 0;
float PH = 0;
float Nitrogen = 0;
float Phospor = 0;
float Kalium = 0;
float Salinitas = 0;
float TDS = 0;

void setup() {
  Serial.begin(115200);
  mod.begin(4800);// modbus configuration
  pinMode(RE, OUTPUT);
  pinMode(DE, OUTPUT);
}


void loop() {
  DataKelembaban();
  DataSuhu();
  DataKonduktifitas();
  DataPH();
  DataNitrogen();
  DataPhospor();
  DataKalium();
  DataSalinitas();
  DataTDS();
  Serial.print("Hum:");
  Serial.print(Kelembaban);
  Serial.print(" ");
  Serial.print("Temp:");
  Serial.print(Suhu);
  Serial.print(" ");
  Serial.print("Cond:");
  Serial.print(Konduktifitas);
  Serial.print(" ");
  Serial.print("PH:");
  Serial.print(PH);
  Serial.print(" ");
  Serial.print("N:");
  Serial.print(Nitrogen);
  Serial.print(" ");
  Serial.print("P:");
  Serial.print(Phospor);
  Serial.print(" ");
  Serial.print("K:");
  Serial.print(Kalium);
  Serial.print(" ");
  Serial.print("Sal:");
  Serial.print(Salinitas);
  Serial.print(" ");
  Serial.print("TDS:");
  Serial.print(TDS);
  Serial.print(" ");

  Serial.println();
  delay(3000);
}
void DataKelembaban(){
//  byte i;
  digitalWrite(DE,HIGH);
  digitalWrite(RE,HIGH);
  delay(10);
  for (uint8_t i = 0; i < sizeof(BufferKelembaban); i++ ) mod.write( BufferKelembaban[i] );
  mod.flush();
  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);
// delay to allow response bytes to be received!
  delay(200);
  for (byte i = 0; i < 7; i++) {
    values[i] = mod.read();
//    Serial.print(values[i],HEX);
//    Serial.print(' ');
  }
  int num1,num2,num3;
  num1=values[3];
  num2=values[4];
  num3=(num1<<8)|(num2);
  int TotalHextoDec = ("%x %d",num3,num3);
  Kelembaban = (float)TotalHextoDec/10;
}

void DataSuhu(){
//  byte i;
  digitalWrite(DE,HIGH);
  digitalWrite(RE,HIGH);
  delay(10);
  for (uint8_t i = 0; i < sizeof(BufferSuhu); i++ ) mod.write( BufferSuhu[i] );
  mod.flush();
  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);
// delay to allow response bytes to be received!
  delay(200);
  for (byte i = 0; i < 7; i++) {
    values[i] = mod.read();
//    Serial.print(values[i],HEX);
//    Serial.print(' ');
  }
  int num1,num2,num3;
  num1=values[3];
  num2=values[4];
  num3=(num1<<8)|(num2);
  int TotalHextoDec = ("%x %d",num3,num3);
  Suhu = (float)TotalHextoDec/10;
}

void DataKonduktifitas(){
//  byte i;
  digitalWrite(DE,HIGH);
  digitalWrite(RE,HIGH);
  delay(10);
  for (uint8_t i = 0; i < sizeof(BufferKonduktifitas); i++ ) mod.write( BufferKonduktifitas[i] );
  mod.flush();
  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);
// delay to allow response bytes to be received!
  delay(200);
  for (byte i = 0; i < 7; i++) {
    values[i] = mod.read();
//    Serial.print(values[i],HEX);
//    Serial.print(' ');
  }
  int num1,num2,num3;
  num1=values[3];
  num2=values[4];
  num3=(num1<<8)|(num2);
  int TotalHextoDec = ("%x %d",num3,num3);
  Konduktifitas = (float)TotalHextoDec/10;
}

void DataPH(){
//  byte i;
  digitalWrite(DE,HIGH);
  digitalWrite(RE,HIGH);
  delay(10);
  for (uint8_t i = 0; i < sizeof(BufferPH); i++ ) mod.write( BufferPH[i] );
  mod.flush();
  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);
// delay to allow response bytes to be received!
  delay(200);
  for (byte i = 0; i < 7; i++) {
    values[i] = mod.read();
//    Serial.print(values[i],HEX);
//    Serial.print(' ');
  }
  int num1,num2,num3;
  num1=values[3];
  num2=values[4];
  num3=(num1<<8)|(num2);
  int TotalHextoDec = ("%x %d",num3,num3);
  PH = (float)TotalHextoDec/10;
}

void DataNitrogen(){
//  byte i;
  digitalWrite(DE,HIGH);
  digitalWrite(RE,HIGH);
  delay(10);
  for (uint8_t i = 0; i < sizeof(BufferNitrogen); i++ ) mod.write( BufferNitrogen[i] );
  mod.flush();
  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);
// delay to allow response bytes to be received!
  delay(200);
  for (byte i = 0; i < 7; i++) {
    values[i] = mod.read();
//    Serial.print(values[i],HEX);
//    Serial.print(' ');
  }
  int num1,num2,num3;
  num1=values[3];
  num2=values[4];
  num3=(num1<<8)|(num2);
  int TotalHextoDec = ("%x %d",num3,num3);
  Nitrogen = (float)TotalHextoDec/10;
}

void DataPhospor(){
//  byte i;
  digitalWrite(DE,HIGH);
  digitalWrite(RE,HIGH);
  delay(10);
  for (uint8_t i = 0; i < sizeof(BufferPhospor); i++ ) mod.write( BufferPhospor[i] );
  mod.flush();
  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);
// delay to allow response bytes to be received!
  delay(200);
  for (byte i = 0; i < 7; i++) {
    values[i] = mod.read();
//    Serial.print(values[i],HEX);
//    Serial.print(' ');
  }
  int num1,num2,num3;
  num1=values[3];
  num2=values[4];
  num3=(num1<<8)|(num2);
  int TotalHextoDec = ("%x %d",num3,num3);
  Phospor = (float)TotalHextoDec/10;
}

void DataKalium(){
//  byte i;
  digitalWrite(DE,HIGH);
  digitalWrite(RE,HIGH);
  delay(10);
  for (uint8_t i = 0; i < sizeof(BufferKalium); i++ ) mod.write( BufferKalium[i] );
  mod.flush();
  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);
// delay to allow response bytes to be received!
  delay(200);
  for (byte i = 0; i < 7; i++) {
    values[i] = mod.read();
//    Serial.print(values[i],HEX);
//    Serial.print(' ');
  }
  int num1,num2,num3;
  num1=values[3];
  num2=values[4];
  num3=(num1<<8)|(num2);
  int TotalHextoDec = ("%x %d",num3,num3);
  Kalium = (float)TotalHextoDec/10;
}

void DataSalinitas(){
//  byte i;
  digitalWrite(DE,HIGH);
  digitalWrite(RE,HIGH);
  delay(10);
  for (uint8_t i = 0; i < sizeof(BufferSalinitas); i++ ) mod.write( BufferSalinitas[i] );
  mod.flush();
  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);
// delay to allow response bytes to be received!
  delay(200);
  for (byte i = 0; i < 7; i++) {
    values[i] = mod.read();
//    Serial.print(values[i],HEX);
//    Serial.print(' ');
  }
  int num1,num2,num3;
  num1=values[3];
  num2=values[4];
  num3=(num1<<8)|(num2);
  int TotalHextoDec = ("%x %d",num3,num3);
  Salinitas = (float)TotalHextoDec/10;
}

void DataTDS(){
//  byte i;
  digitalWrite(DE,HIGH);
  digitalWrite(RE,HIGH);
  delay(10);
  for (uint8_t i = 0; i < sizeof(BufferTDS); i++ ) mod.write( BufferTDS[i] );
  mod.flush();
  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);
// delay to allow response bytes to be received!
  delay(200);
  for (byte i = 0; i < 7; i++) {
    values[i] = mod.read();
//    Serial.print(values[i],HEX);
//    Serial.print(' ');
  }
  int num1,num2,num3;
  num1=values[3];
  num2=values[4];
  num3=(num1<<8)|(num2);
  int TotalHextoDec = ("%x %d",num3,num3);
  TDS = (float)TotalHextoDec/10;
}
