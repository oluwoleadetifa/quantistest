#include "/home/wole/Documents/pcie-chip-20.2.4/pcie-chip-20.2.4-linux/Libs-Apps/Quantis/Quantis.h"
#include <stdio.h>

// Function prototype
static int ReadInt();

int main(QuantisDeviceType deviceType){
  int deviceNumber = 0;
  float driverVersion = 0.0000;
  int devicesCount = 0;

  printf("The number is %d", ReadInt());

}

static int ReadInt(){
  int deviceNumber = 0;
  QuantisDeviceType deviceType; 
  int result = QuantisReadInt(deviceType, deviceNumber, 0);
  return result;
  }