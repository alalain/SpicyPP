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
#include <set>

using namespace std;

void Network::GenerateMatrixAndVector()
{
  //Resize Matrix
  int newDimensions = 0;
  nodes.clear();
  nodes.insert(0); //Zero has to be in Set (for distancecalculations)
  //Count nodes => how many Voltage dimensions added
  for(const std::unique_ptr<Component>& component : components){
    nodes.insert(component->GetNode1());
    nodes.insert(component->GetNode2());
  }
  newDimensions += nodes.size() - 1; //size without zero node

  //TODO Count sources with currents that have to be added to netMatrix

  netMatrix = Matrix(newDimensions  , newDimensions);
  netVector = Matrix(            1  , newDimensions);

  for(const std::unique_ptr<Component>& component : components){
    component->AddFootprinttoMatrix(*this);
  }
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

std::vector<std::string> Network::GetNewestNetlist()
{
  GenerateNetList();
  return netList;
}

std::vector<MeasureVal> Network::GetNewestSolution()
{
  GenerateMatrixAndVector();
  //Matrix solutionVector = netMatrix.getInverse() * netVector;
  //TODO which values which?

  return vector<MeasureVal>();
}
