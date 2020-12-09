//Only for testing functions

#include "Matrix.h"
#include "Network.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;


#include <set>
int main()
{
  Network net;
  net.AddResistor("R5", 0, 2, 20);
  net.AddResistor("R1", 2, 3, 10);
  net.AddResistor("R2", 3, 5, 15);
  net.AddVoltageSource("V7", 2, 0, 5);
  net.AddVoltageSource("V1", 5, 2, 10);

  vector<string> netList = net.GetNewestNetlist();
  cout << "NetList:" << endl;
  for(unsigned int i = 0; i < netList.size(); ++i)
    cout << netList[i] << endl;

  vector<MeasureVal> measVals;
  net.GetNewestSolution(measVals);
  cout << "MeassureVals:" << endl;
  for(MeasureVal val : measVals){
    cout << val.name << ": " << val.value << val.unit << endl;
  }

  return 0;
}



