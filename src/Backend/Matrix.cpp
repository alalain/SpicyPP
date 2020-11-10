/*
 * Matrix.cpp
 *
 *  Created on: Nov 4, 2020
 *      Author: Marius Baumann
 */

#include "Matrix.h"

Matrix::Matrix(int rows, int columns, double* values) :
  rows(rows), columns(columns)
{
  if(rows <= 0 || columns <= 0){
    matrix = nullptr;
    return;
  }

  matrix = new double*[rows];
  for(int row = 0; row < rows; row++) {
    matrix[row] = new double[columns];
    for(int column = 0; column < columns; column++){
      if(values == nullptr)
        matrix[row][column] = 0.0;
      else
        matrix[row][column] = values[row*columns+column];
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

