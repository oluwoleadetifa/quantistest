#include "/home/wole/Documents/pcie-chip-20.2.4/pcie-chip-20.2.4-linux/Libs-Apps/Quantis/Quantis.h"
#include <float.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(QuantisDeviceType deviceType){
  int deviceNumber = 0;
  float driverVersion = 0.0000;
  int devicesCount = 0;

  printf("The number is %d", ReadInt());

}

static int ReadInt(){
  int deviceNumber = 0;
  QuantisDeviceType deviceType; 
  QuantisReadInt(deviceType, deviceNumber, 0);
}