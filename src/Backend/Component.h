#ifndef BACKEND_COMPONENT_H_
#define BACKEND_COMPONENT_H_

#include <string>
#include "Matrix.h"

class Component
{
  private:
    std::string name;
    int node1;
    int node2;

  public:
    Component(std::string name, int node1, int node2):
      name(name), node1(node1), node2(node2){}
    std::string GetName() {return name;}
    int GetNode1() {return node1;}
    int GetNode2() {return node1;}
    virtual~ Component(){}
    virtual void AddtoMatrix(Matrix& netMatrix, Matrix& netVector) const = 0;
    virtual std::vector<double> GetValues() const = 0;
};

#endif /* BACKEND_COMPONENT_H_ */
