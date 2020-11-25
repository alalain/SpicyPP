#ifndef BACKEND_COMPONENT_H_
#define BACKEND_COMPONENT_H_

#include "Matrix.h"

#include <string>

class Component
{
  private:
    std::string name;
    int node1;
    int node2;

  public:
    Component(std::string name, int node1, int node2):
      name(name), node1(node1), node2(node2){}
    virtual ~Component() = default;
    std::string GetName() const {return name;}
    int GetNode1() const {return node1;}
    int GetNode2() const {return node2;}
    virtual void AddFootprinttoMatrix(class Network& network) const = 0;
    virtual std::vector<double> GetValues() const = 0;
};

#endif /* BACKEND_COMPONENT_H_ */
