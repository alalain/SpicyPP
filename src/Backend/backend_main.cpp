//Only for testing functions

#include <iostream>
#include <string>
#include <vector>

#include "Matrix.h"
#include "Network.h"

using namespace std;

int main()
{
  Network net;
  net.AddResistor("R1", 0, 1, 10);
  net.AddResistor("R2", 0, 2, 15);
  net.AddResistor("R3", 1, 2, 20);
  net.AddVoltageSource("V1", 0, 1, 5);

  vector<string> netList = net.GetNetlist();
  cout << "NetList:" << endl;
  for(unsigned int i = 0; i < netList.size(); ++i)
    cout << netList[i] << endl;
  return 0;
}



