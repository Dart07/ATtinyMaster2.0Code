/* ATtiny85 as an I2C Master 
* I2C master reading FDC1004 Capacitance Sensor Chip. (display with leds)
 * SETUP:
 * ATtiny Pin 1 = (RESET) N/U                      ATtiny Pin 2 = LED3
 * ATtiny Pin 3 = LED1                             ATtiny Pin 4 = GND
 * ATtiny Pin 5 = SDA on FDC1004                    ATtiny Pin 6 =  LED2
 * ATtiny Pin 7 = SCK on FDC1004                    ATtiny Pin 8 = VCC (2.7-5.5V)
 
 * TinyWireM USAGE & CREDITS: - see TinyWireM.h
 * The FDC1004 will be running in the differential mode.
 */
#include <TinyWireM.h>
#include <USI_TWI_Master.h>

#define FDC1004_ADDR  0x50  //7 bit I2C address for the FDC1004 Capacitance Sensor

#define LED1_PIN   4     //ATtiny Pin 3
#define LED2_PIN   1     //ATtiny Pin 6
#define LED3_PIN   3     //ATtiny Pin 2


void setup() {
  

}

void loop() {
  // put your main code here, to run repeatedly:

}

void Init_FDC(byte led){ //Setup for the FDC1004
  TinyWireM.beginTransmission(FDC1004_ADDR); //calls for the address pointing to the Device ID
  TinyWireM.send(0xFF); //
  TinyWireM.endTransmission();
  int ReadBytes = 1;
  int x = 0;
  byte FDC_Device_ID[2];
  TinyWireM.requestFrom(FDC1004_ADDR,2); //places 
  while(TinyWireM.available()){
     FDC_Device_ID[x] = TinyWireM.read();//reads device ID with bytes
     x++; 
    }
  if (FDC_Device_ID == x1004){ //check to see if device ID is read correctly
    digitalWrite(led,HIGH);
    delay(1000);}
  else{
    digitalWrite(led, LOW);
    delay(1000);}
}

/* to configure the 2 measurements we want
* Pointer  RegisterName  ResetVal 
* 0x08     CONF_MEAS1    0x1C00
* 0x09     CONF_MEAS2    0x1C00
* 0x0A     CONF_MEAS3    0x1C00
* 0x0B     CONF_MEAS4    0x1C00
* The mode we want to configure the FDC1004 is differential. 
*
*/
void Config_Cap(){ //Configuartion of the FDC1004 Capacitors





   
    
  
