/*
 * Network.h
 *
 *  Created on: Nov 11, 2020
 *      Author: user
 */

#ifndef BACKEND_NETWORK_H_
#define BACKEND_NETWORK_H_

#include "Matrix.h"
#include "Component.h"

#include <map>
#include <vector>
#include <memory>
#include <string>


struct MeasureVal {
    std::string name;
    double value;
    std::string unit;

    MeasureVal(std::string name, double value, std::string unit):
      name(name), value(value), unit(unit){}
};

class Network
{
  private:
    std::vector<std::unique_ptr<Component>> components;

    Matrix netMatrix = Matrix(0,0);
    Matrix netVector = Matrix(0,0);

    std::vector<std::string> netList;

    void GenerateMatrixAndVector();
    void GenerateNetList();

  public:
    void AddResistor(std::string name, int node1, int node2, double resistance);
    void AddVoltageSource(std::string name, int node1, int node2, double voltage);

    std::vector<std::string> GetNetlist();
    std::vector<MeasureVal>GetSolution();
};

#endif /* BACKEND_NETWORK_H_ */
