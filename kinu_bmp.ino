#include <SFE_BMP180.h>
#include <Wire.h>

SFE_BMP180 pressure;

#define ALTITUDE 1655.0
void setup()
{
  Serial.begin(9600);
  Serial.println("REBOOT");
  if (pressure.begin())
    Serial.println("BMP180 init fail\n\n");
    while(1);
}

void loop() {
  double T, P;
  if (pressure.startTemperature() != 0 && pressure.getTemperature(T) != 0){
    Serial.print("temperature:");
    Serial.print(T, 2);
    Serial.print("deg C,");
    Serial.print((9.0/5.0) * T + 32.0, 2);
    Serial.println("deg F");
  
  if (pressure.startPressure(3) != 0 && pressure.getPressure(P, T) != 0){
    Serial.print("pressure:");
    Serial.print(P, 2);
    Serial.println("mb");
  
  }else{Serial.println("error retrieving pressure measurement");}
  }
else{Serial.println("error retrieving temperature measurement");}
delay(5000);  // Pause for 5 seconds.

}
