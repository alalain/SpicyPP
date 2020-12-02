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
    VoltageSource(std::string name, int node1, int node2, double voltage):
      Component(name, node1, node2), voltage(voltage) {sourceId = sourceCount++;}
    static int getSourceCount() {return sourceCount;}
    void AddFootprinttoMatrix(Network& network) const override;
    std::vector<double> GetValues() const override;
};

#endif /* BACKEND_VOLTAGESOURCE_H_ */
