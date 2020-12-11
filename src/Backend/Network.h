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

class Component;

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
    /**
       * Getter for current net matrix
       * @return Returns current net matrix
       */
    Matrix& GetCurrentNetMatrix() { return netMatrix; }
    /**
       * Getter for the current net vector
       * @return Returns current net vector
       */
    Matrix& GetCurrentNetVector() { return netVector; }
    /**
       * Getter for the current node set
       * @return Returns current node set
       */
    const std::set<int>& GetCurrentNodeSet(){return nodes; }
    /**
       * Getter for the net list
       * @return Returns net list
       */
    std::vector<std::string> GetNewestNetlist();
    /**
       * Calculate the voltages of the network
       * @param storeVals: Empty vector for the storage of the values
       */
    void GetNewestSolution(std::vector<MeasureVal>& storeVals);
    /**
       * Adds a new resistor to the network
       * @param name: Name of the resistor
       * @param node1: First connection of the resistor
       * @param node2: Second connection of the resistor
       * @param resistance: Value of the resistor
       */
    void AddResistor(std::string name, int node1, int node2, double resistance);
    /**
       * Add a new voltage source to the network
       * @param name: Name of the component
       * @param node1: First connection of the voltage source
       * @param node2: Second connection of the voltage source
       * @param voltage: Value of the voltage source
       */
    void AddVoltageSource(std::string name, int node1, int node2, double voltage);
};

#endif /* BACKEND_NETWORK_H_ */
