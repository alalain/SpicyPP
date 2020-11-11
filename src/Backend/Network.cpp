/*
 * Network.cpp
 *
 *  Created on: Nov 11, 2020
 *      Author: user
 */
#include <string>
#include <vector>

#include "Network.h"
#include "Resistor.h"
#include "Component.h"

using namespace std;

Network::~Network(){
  for(unsigned int i = 0; i < components.size(); ++i)
    delete components[i];
}

void Network::GenerateMatrixAndVector()
{
}

void Network::GenerateNetList()
{
  netList.clear();
  for(unsigned int i = 0; i < components.size(); ++i){
    string netRow = components[i]->GetName() + " " +
                    to_string(components[i]->GetNode1()) + " " +
                    to_string(components[i]->GetNode2());
    vector<double> values = components[i]->GetValues();
    for(unsigned int j = 0; j < values.size(); ++j)
      netRow += " " + to_string(values[j]);
    netList.push_back(netRow);
  }
}


void Network::AddResistor(std::string name,
                          int node1,
                          int node2,
                          double resistance)
{
  components.push_back(new Resistor(name, node1, node2, resistance));
}

void Network::AddVoltageSource(std::string name,
                               int node1,
                               int node2,
                               double voltage)
{
}

std::vector<std::string> Network::GetNetlist()
{
  GenerateNetList();
  return netList;
}

std::vector<MeasureVal> Network::GetSolution()
{
  GenerateMatrixAndVector();
  //Matrix solutionVector = netMatrix.getInverse() * netVector;
  //TODO which values which?

  return vector<MeasureVal>();
}
