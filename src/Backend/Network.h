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

#include <vector>
#include <set>
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
    std::set<int> nodes = std::set<int>();
    std::vector<std::string> netList;

    void GenerateMatrixAndVector();
    void GenerateNetList();

  public:
    Matrix& GetCurrentNetMatrix() { return netMatrix; }
    Matrix& GetCurrentNetVector() { return netVector; }
    const std::set<int>& GetCurrentNodeSet(){return nodes; }
    std::vector<std::string> GetNewestNetlist();
    std::vector<MeasureVal> GetNewestSolution();

    void AddResistor(std::string name, int node1, int node2, double resistance);
    void AddVoltageSource(std::string name, int node1, int node2, double voltage);
};

#endif /* BACKEND_NETWORK_H_ */
