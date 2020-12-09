/*
 * Matrix_test.cpp
 *
 *  Created on: Nov 4, 2020
 *      Author: user
 */
 
#include <gtest/gtest.h>
#include "Matrix.h"


bool eqMatrix (Matrix lhs, Matrix rhs){
  for(int i = 0; i <= lhs.getRows(); ++i){
    for(int j = 0; j <= rhs.getColumns(); ++j){
      EXPECT_DOUBLE_EQ(lhs.getValue(i,j), rhs.getValue(i,j));
      if(lhs.getValue(i,j) != rhs.getValue(i,j))
        return false;
    }
  }
  return true;
}

TEST(MatrixTest, InverseTest) {
  Matrix m1= Matrix(4, 4, {1, 2, 2, 0,
                           2, 5, 4, 1,
                           2, 4, 3, 1,
                           0, 1, -1, 1});

  Matrix m1inverse =Matrix(4, 4,{1, -2,  2,  0,
                                 2,  0, -1,  1,
                                -2,  1,  0, -1,
                                -4,  1,  1, -1});
  EXPECT_TRUE( eqMatrix(m1.getInverse(), m1inverse) );
}






