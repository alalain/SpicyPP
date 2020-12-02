/*
 * Matrix_test.cpp
 *
 *  Created on: Nov 4, 2020
 *      Author: user
 */
 
#include <gtest/gtest.h>
#include "Matrix.h"

enum
{
  Msize = 2
};

TEST(MatrixTest, MatrixGetValues){
<<<<<<< HEAD
 int i = 1;
 EXPECT_EQ(1, i);

}
//
//TEST(MatrixTest, MatrixRowsAndColumnCount){
//  Matrix m1 = Matrix(3, 5);
//  EXPECT_EQ(3,    m1.getRows());
//  EXPECT_EQ(5,    m1.getColumns());
//  Matrix m2 = Matrix(-2, -1); //Is correct, but hasError should be true
//  EXPECT_EQ(-2,   m2.getValue(0,1));
//  EXPECT_EQ(1,    m2.getValue(0,1));
//}
//
//TEST(MatrixTest, MatrixSetValue){
//  Matrix m = Matrix(Msize, Msize);
//  m.setValue(1.0, 0, 1);
//  m.setValue(-2.0, 1, 0);
//
//  EXPECT_DOUBLE_EQ(0.0,   m.getValue(0,0));
//  EXPECT_DOUBLE_EQ(1.0,   m.getValue(0,1));
//  EXPECT_DOUBLE_EQ(-2.0,  m.getValue(1,0));
//  EXPECT_DOUBLE_EQ(0.0,   m.getValue(1,1));
//}
//
//TEST(MatrixTest, MatrixSetValues){
//  double values[2] = {1.0,-2.0};
//  Matrix m = Matrix(Msize, Msize);
//  m.setValues(values, 2, 0, 1);
//
//  EXPECT_DOUBLE_EQ(0.0,   m.getValue(0,0));
//  EXPECT_DOUBLE_EQ(1.0,   m.getValue(0,1));
//  EXPECT_DOUBLE_EQ(-2.0,  m.getValue(1,0));
//  EXPECT_DOUBLE_EQ(0.0,   m.getValue(1,1));
//}
//
//TEST(MatrixTest, MatrixSetRow){
//  double values[2] = {1.0,-2.0};
//  Matrix m = Matrix(Msize, Msize);
//  m.setValueRow(values, 1);
//
//  EXPECT_DOUBLE_EQ(0.0,   m.getValue(0,0));
//  EXPECT_DOUBLE_EQ(0.0,   m.getValue(0,1));
//  EXPECT_DOUBLE_EQ(1.0,   m.getValue(1,0));
//  EXPECT_DOUBLE_EQ(-2.0,  m.getValue(1,1));
//}
//
//TEST(MatrixTest, MatrixSetColumn){
//  double values[2] = {1.0,-2.0};
//  Matrix m = Matrix(Msize, Msize);
//  m.setValueColumn(values, 1);
//
//  EXPECT_DOUBLE_EQ(0.0,   m.getValue(0,0));
//  EXPECT_DOUBLE_EQ(1.0,   m.getValue(0,1));
//  EXPECT_DOUBLE_EQ(0.0,   m.getValue(1,0));
//  EXPECT_DOUBLE_EQ(-2.0,  m.getValue(1,1));
//}
//
//
=======
  double values[Msize*Msize] = { 1.0,0.0,4.0,-2.0 };
  Matrix m = Matrix(Msize, Msize, values);
  for(int r = 0; r < Msize; ++r){
    for(int c = 0; c < Msize; ++c)
      EXPECT_DOUBLE_EQ(values[r*Msize+c], m.getValue(r,c));
  }
}

TEST(MatrixTest, MatrixRowsAndColumnCount){
  Matrix m1 = Matrix(3, 5);
  EXPECT_EQ(3,    m1.getRows());
  EXPECT_EQ(5,    m1.getColumns());
  Matrix m2 = Matrix(-2, -1); //Is correct, but hasError should be true
  EXPECT_EQ(-2,   m2.getValue(0,1));
  EXPECT_EQ(1,    m2.getValue(0,1));
}

TEST(MatrixTest, MatrixSetValue){
  Matrix m = Matrix(Msize, Msize);
  m.setValue(1.0, 0, 1);
  m.setValue(-2.0, 1, 0);

  EXPECT_DOUBLE_EQ(0.0,   m.getValue(0,0));
  EXPECT_DOUBLE_EQ(1.0,   m.getValue(0,1));
  EXPECT_DOUBLE_EQ(-2.0,  m.getValue(1,0));
  EXPECT_DOUBLE_EQ(0.0,   m.getValue(1,1));
}

TEST(MatrixTest, MatrixSetValues){
  double values[2] = {1.0,-2.0};
  Matrix m = Matrix(Msize, Msize);
  m.setValues(values, 2, 0, 1);

  EXPECT_DOUBLE_EQ(0.0,   m.getValue(0,0));
  EXPECT_DOUBLE_EQ(1.0,   m.getValue(0,1));
  EXPECT_DOUBLE_EQ(-2.0,  m.getValue(1,0));
  EXPECT_DOUBLE_EQ(0.0,   m.getValue(1,1));
}

TEST(MatrixTest, MatrixSetRow){
  double values[2] = {1.0,-2.0};
  Matrix m = Matrix(Msize, Msize);
  m.setValueRow(values, 1);

  EXPECT_DOUBLE_EQ(0.0,   m.getValue(0,0));
  EXPECT_DOUBLE_EQ(0.0,   m.getValue(0,1));
  EXPECT_DOUBLE_EQ(1.0,   m.getValue(1,0));
  EXPECT_DOUBLE_EQ(-2.0,  m.getValue(1,1));
}

TEST(MatrixTest, MatrixSetColumn){
  double values[2] = {1.0,-2.0};
  Matrix m = Matrix(Msize, Msize);
  m.setValueColumn(values, 1);

  EXPECT_DOUBLE_EQ(0.0,   m.getValue(0,0));
  EXPECT_DOUBLE_EQ(1.0,   m.getValue(0,1));
  EXPECT_DOUBLE_EQ(0.0,   m.getValue(1,0));
  EXPECT_DOUBLE_EQ(-2.0,  m.getValue(1,1));
}


>>>>>>> parent of a3c161d... Bois take it
