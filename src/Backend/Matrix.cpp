/*
 * Matrix.cpp
 *
 *  Created on: Nov 4, 2020
 *      Author: Marius Baumann
 */

#include "Matrix.h"

Matrix::Matrix(int rows, int colums) :
  rows(rows), colums(colums)
{
  if(rows <= 0 || colums <= 0){
    matrix = nullptr;
    return;
  }

  matrix = new double*[rows];
  for(int row = 0; row < rows; row++) {
    matrix[row] = new double[colums];
    for(int colum = 0; colum < colums; colum++){
      matrix[row][colum] = 0.0;
    }
  }
}

Matrix::~Matrix()
{
  for(int row = 0; row < rows; row++){
    delete[] matrix[row];
  }
  delete[] matrix;
}

Matrix::Matrix(const Matrix &other)
{
  // TODO Auto-generated constructor stub

}

Matrix& Matrix::operator=(const Matrix &other)
{
  // TODO Auto-generated method stub

}

