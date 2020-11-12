/*
 * Network.cpp
 *
 *  Created on: Nov 11, 2020
 *      Author: user
 */
#include "Network.h"
#include "Resistor.h"
#include "Component.h"

#include <string>
#include <vector>

using namespace std;

void Network::GenerateMatrixAndVector()
{
}

void Network::GenerateNetList()
{
  netList.clear();
  for (const std::unique_ptr<Component>& component : components){
    string netRow = component->GetName() + " " +
                    to_string(component->GetNode1()) + " " +
                    to_string(component->GetNode2());
    vector<double> values = component->GetValues();
    for(double value : values)
      netRow += " " + to_string(value);
    netList.push_back(netRow);
  }
}


void Network::AddResistor(std::string name,
                          int node1,
                          int node2,
                          double resistance)
{
  components.push_back(std::make_unique<Resistor>(name, node1, node2, resistance));
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
