/*
 * Network.cpp
 *
 *  Created on: Nov 11, 2020
 *      Author: user
 */
#include "Network.h"
#include "Resistor.h"
#include "VoltageSource.h"
#include "Component.h"


#include <string>
#include <vector>
#include <set>
#include <stdexcept>

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
  newDimensions += VoltageSource::getSourceCount();

  //TODO Count sources with currents that have to be added to netMatrix

  netMatrix = Matrix(newDimensions  , newDimensions);
  netVector = Matrix(newDimensions  ,             1);

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
  components.push_back(std::make_unique<VoltageSource>(name, node1, node2, voltage));
}

std::vector<std::string> Network::GetNewestNetlist()
{
  GenerateNetList();
  return netList;
}

void Network::GetNewestSolution(std::vector<MeasureVal>& storeVals)
{
  GenerateMatrixAndVector();
  Matrix solutionVector = Matrix(0,0);
  try {
     solutionVector = netMatrix.getInverse() * netVector;
  }
  catch(range_error& r){return;}


  int i = 1;
  for(set<int>::iterator it=nodes.begin(); it!=nodes.end(); ++it)
  {
    if(*it != 0)
      storeVals.push_back(MeasureVal("U" + to_string(*it), solutionVector.getValue(i++, 1), "V"));
  }
}
