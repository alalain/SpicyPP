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
  net.AddResistor("R2", 0, 2, 15);
  net.AddResistor("R3", 1, 2, 20);
  net.AddVoltageSource("V1", 0, 1, 5);

  vector<string> netList = net.GetNewestNetlist();
  cout << "NetList:" << endl;
  for(unsigned int i = 0; i < netList.size(); ++i)
    cout << netList[i] << endl;

  net.GetNewestSolution();
  Matrix netMatrix = net.GetCurrentNetMatrix();
  netMatrix.MatrixShow();


  vector<double> v;
  for (int i = 1; i <= 8; i++)
          v.push_back(i+1);
  Matrix m1(3,3,v);
  m1 = m1.getInverse();
  m1.MatrixShow();

  return 0;
}



