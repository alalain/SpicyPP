#ifndef BACKEND_COMPONENT_H_
#define BACKEND_COMPONENT_H_

#include "Matrix.h"
#include "Network.h"

#include <string>

class Component
{
 private:
  std::string name;
  int node1;
  int node2;

 public:
  /**
   * Constructor for Component
   * @param Name of the component
   * @param First node, the component is connected to
   * @param Second node, the component is connected to
   */
  Component(std::string name, int node1, int node2)
      : name(name), node1(node1), node2(node2)
  {
  }
  virtual ~Component() = default;
  /**
   * Getter for name
   * @return Name of component
   */
  std::string GetName() const
  {
    return name;
  }
  /**
   * Getter for Node 1
   * @return Value of Node1
   */
  int GetNode1() const
  {
    return node1;
  }
  /**
   * Getter for Node 2
   * @return Value of Node2
   */
  int GetNode2() const
  {
    return node2;
  }

  /**
   * Adds footprint of the component to the Network Matrix
   * @param Network where the footprint should be added to
   */
  virtual void AddFootprinttoMatrix(class Network& network) const = 0;
  /**
   * Getter for all values of a component
   * @return Vector of values
   */
  virtual std::vector<double> GetValues() const = 0;
};

#endif /* BACKEND_COMPONENT_H_ */
