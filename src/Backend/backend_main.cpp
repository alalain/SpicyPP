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
  net.AddResistor("R1", 0, 1, 10);
  net.AddResistor("R2", 2, 3, 15);
  net.AddVoltageSource("V1", 0, 1, 5);

  vector<string> netList = net.GetNewestNetlist();
  cout << "NetList:" << endl;
  for(unsigned int i = 0; i < netList.size(); ++i)
    cout << netList[i] << endl;

  net.GetNewestSolution();
  Matrix netMatrix = net.GetCurrentNetMatrix();
  netMatrix.MatrixShow();

  return 0;
}



