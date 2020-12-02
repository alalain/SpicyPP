/*
 * VoltageSource.cpp
 *
 *  Created on: Nov 18, 2020
 *      Author: user
 */

#include "VoltageSource.h"
#include "Matrix.h"

#include <vector>

using namespace std;

int VoltageSource::sourceCount = 0;

void VoltageSource::AddFootprinttoMatrix(Network &network) const
{
  Matrix& netMatrix = network.GetCurrentNetMatrix();
  Matrix& netVector = network.GetCurrentNetVector();
  const set<int> nodes = network.GetCurrentNodeSet();
  //node in Matrix is distance in set from first element (0) to the node in the set
  //f.e. set = {0, 2, 5, 10} distance for node 5 is 2 -> second column in matrix
  int n1 = distance(nodes.begin(), nodes.find(GetNode1()));
  int n2 = distance(nodes.begin(), nodes.find(GetNode2()));
  int currentPosOffset = nodes.size() + sourceId;
  cout << n1;
  //Set 1nes for Currents throught sources
  netMatrix.setValue(netMatrix.getValue(n1, currentPosOffset) + 1, n1, currentPosOffset);
  netMatrix.setValue(netMatrix.getValue(n2, currentPosOffset) - 1, n2, currentPosOffset);
  netMatrix.setValue(netMatrix.getValue(currentPosOffset, n1) + 1, currentPosOffset, n1);
  netMatrix.setValue(netMatrix.getValue(currentPosOffset, n2) - 1, currentPosOffset, n2);
  //Set volatgevalue in netVector
  netVector.setValue(netVector.getValue(currentPosOffset,  1) + voltage, currentPosOffset, 1);
}

std::vector<double> VoltageSource::GetValues() const
{
  vector<double> values;
  values.push_back(voltage);
  values.push_back(sourceId);
  return values;
}
