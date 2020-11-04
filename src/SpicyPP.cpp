//============================================================================
// Name        : SpicyPP.cpp
// Author      : Marius Baumann
// Version     :
// Copyright   : (c) by Marius Baumann
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Backend/Matrix.h"

using namespace std;

int main() {
  {
    Matrix m = Matrix(5,6);
    m.MatrixShow();
  }
	return 0;
}
