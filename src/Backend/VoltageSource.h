/*
 * VoltageSource.h
 *
 *  Created on: Nov 18, 2020
 *      Author: user
 */

#ifndef BACKEND_VOLTAGESOURCE_H_
#define BACKEND_VOLTAGESOURCE_H_

#include "Matrix.h"
#include "Component.h"

class VoltageSource: public Component
{
  private:
    static int sourceCount;
    int sourceId; //Starts at 0
    double voltage;
  public:
    /**
          * Add a new voltage source to the network
          * @param name: Name of the component
          * @param node1: First connection of the voltage source
          * @param node2: Second connection of the voltage source
          * @param voltage: Value of the voltage source
          */
    VoltageSource(std::string name, int node1, int node2, double voltage):
      Component(name, node1, node2), voltage(voltage) {sourceId = sourceCount++;}
    /**
              * Getter for the source count
              * @return Returns the source count
              */
    static int getSourceCount() {return sourceCount;}
    /**
              * Adds a new footprint to the matrix
              * @param network: Reference to the network
              */
    void AddFootprinttoMatrix(Network& network) const override;
    /**
              * Returns all values of the voltage source
              * @return Values of voltage source
              */
    std::vector<double> GetValues() const override;
};

#endif /* BACKEND_VOLTAGESOURCE_H_ */
