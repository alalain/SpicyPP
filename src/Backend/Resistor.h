/*
 * Resistor.h
 *
 *  Created on: Nov 11, 2020
 *      Author: user
 */

#ifndef BACKEND_RESISTOR_H_
#define BACKEND_RESISTOR_H_

#include "Matrix.h"
#include "Component.h"

class Resistor: public Component
{
  private:
    double resistance;

  public:
    /**
          * Adds a new resistor to the network
          * @param name: Name of the resistor
          * @param node1: First connection of the resistor
          * @param node2: Second connection of the resistor
          * @param resistance: Value of the resistor
          */
    Resistor(std::string name, int node1, int node2, double resistance):
      Component(name, node1, node2), resistance(resistance){}
    /**
          * Adds a new footprint to the matrix
          * @param network: Reference to the network
          */
    void AddFootprinttoMatrix(Network& network) const override;
    /**
              * Returns all values of the resistor
              * @return Values of resistor
              */
    std::vector<double> GetValues() const override;
};

#endif /* BACKEND_RESISTOR_H_ */
