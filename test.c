#include "/home/wole/Documents/pcie-chip-20.2.4/pcie-chip-20.2.4-linux/Libs-Apps/Quantis/Quantis.h"
#include <stdio.h>
#include "test.h"

//Global variable
QuantisDevicetype deviceType;
int deviceNumber = 0;

// Function prototype
static int ReadInt();
unsigned char *Read();

int main()
{
  int deviceNumber = 0;
  float driverVersion = 0.0000;
  int devicesCount = 0;

  printf("The number is %d", ReadInt());
}

static int ReadInt(){ 
  int result = QuantisReadInt(deviceType, deviceNumber, 0);
  return result;
  }

unsigned char *Read(int size)
{
  // Assuming deviceType and deviceNumber are globally accessible or defined somewhere
  return QuantisRead(deviceType, deviceNumber, size);
}