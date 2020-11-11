/*
 * Resistor.cpp
 *
 *  Created on: Nov 11, 2020
 *      Author: user
 */

#include <vector>

#include "Resistor.h"

using namespace std;

void Resistor::AddtoMatrix(Matrix& netMatrix, Matrix& netVector) const {

}

std::vector<double> Resistor::GetValues() const
{
  vector<double> values;
  values.push_back(resistance);
  return values;
}
