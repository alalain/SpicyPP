/*
 * Resistor.cpp
 *
 *  Created on: Nov 11, 2020
 *      Author: user
 */

#include "Resistor.h"

#include <vector>

using namespace std;

void Resistor::AddtoMatrix(Network& network) const {

}

std::vector<double> Resistor::GetValues() const
{
  vector<double> values;
  values.push_back(resistance);
  return values;
}
