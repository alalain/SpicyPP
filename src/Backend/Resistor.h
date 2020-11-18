/*
 * Resistor.h
 *
 *  Created on: Nov 11, 2020
 *      Author: user
 */

#ifndef BACKEND_RESISTOR_H_
#define BACKEND_RESISTOR_H_

#include "Matrix.h"
#include "Network.h"
#include "Component.h"

#include <string>

class Resistor: public Component
{
  private:
    double resistance;

  public:
    Resistor(std::string name, int node1, int node2, double resistance):
      Component(name, node1, node2), resistance(resistance){}
    void AddFootprinttoMatrix(Network& network) const override;
    std::vector<double> GetValues() const override;
};

#endif /* BACKEND_RESISTOR_H_ */
