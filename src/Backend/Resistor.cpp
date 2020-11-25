/*
 * Resistor.cpp
 *
 *  Created on: Nov 11, 2020
 *      Author: user
 */

#include "Resistor.h"
#include "Matrix.h"

#include <vector>

using namespace std;

void Resistor::AddFootprinttoMatrix(Network& network) const {
  Matrix& netMatrix = network.GetCurrentNetMatrix();
  const set<int> nodes = network.GetCurrentNodeSet();
  //node in Matrix is distance in set from first element (0) to the node in the set
  //f.e. set = {0, 2, 5, 10} distance for node 5 is 2 -> second column in matrix
  int n1 = distance(nodes.begin(), nodes.find(GetNode1()));
  int n2 = distance(nodes.begin(), nodes.find(GetNode2()));
  //if node is zero setValue wont do anything
  netMatrix.setValue(netMatrix.getValue(n1, n1) +  1/resistance, n1, n1);
  netMatrix.setValue(netMatrix.getValue(n1, n2) + -1/resistance, n1, n2);
  netMatrix.setValue(netMatrix.getValue(n2, n1) + -1/resistance, n2, n1);
  netMatrix.setValue(netMatrix.getValue(n2, n2) +  1/resistance, n2, n2);
}

std::vector<double> Resistor::GetValues() const
{
  vector<double> values;
  values.push_back(resistance);
  return values;
}
