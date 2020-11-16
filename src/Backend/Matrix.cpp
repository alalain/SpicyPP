/*
 * Matrix.cpp
 *
 *  Created on: Nov 4, 2020
 *      Author: Marius Baumann
 */

#include "Matrix.h"
#include <stdexcept>

using namespace std;

Matrix::Matrix(int rows, int columns, vector<double> values)
{
  this->values = vector<vector<double>>();

  if(rows <= 0 || columns <= 0){
    return;
  }

  for(int row = 0; row < rows; row++) {
    this->values.push_back(vector<double>());
    for(int column = 0; column < columns; column++){
      int index = row * columns + column;
      if(index >= values.size())
        this->values[row].push_back(0.0);
      else
        this->values[row].push_back(values[index]);
    }
  }
}



Matrix Matrix::getInverse() const
{
  double* pivot = new double[values.size()]{0};

  int rows = values.size();
  int colums = values[0].size();  // 1. Row because every Colum have equal size.
  int rreduce = 0;

  Matrix bigmatrix(rows,2*colums);
  Matrix result(rows,colums,{});

  bigmatrix.values= values;     //set equal, copy,

  // Eigenmatrize added
  for(int row = 0; row < rows; row++) {

      bigmatrix.values[row].resize(rows+colums);  //because of the set equal the bigmatrix was shrinked.

      for(int colum = colums; colum < 2*colums; colum++){
      if(row == (colum-colums))
       bigmatrix.values[row][colum] = 1.0;
      else
       bigmatrix.values[row][colum] = 0.0;
      }
  }

////TODO delet after tested
//cout<< "Einheitsvektor"<<endl;
//bigmatrix.MatrixShow();

  for(int row = 0; row < rows; row++) {
    if( bigmatrix.values[row][row] != 0){
      pivot[row]=bigmatrix.values[row][row];

      for(int colum = 0; colum < 2*colums; colum++){
        bigmatrix.values[row][colum] = bigmatrix.values[row][colum]/pivot[row];  // pivot should not be zero
      }

////TODO delet after tested
//cout<< "Pivot Teilung"<<endl;
//bigmatrix.MatrixShow();

      for(rreduce = 0; rreduce < rows; rreduce++) {
        if(rreduce != row){

          double ratio = bigmatrix.values[rreduce][row] / bigmatrix.values[row][row];
          for(int colum = 0; colum < 2*colums; colum++){
            bigmatrix.values[rreduce][colum] -=  (bigmatrix.values[row][colum] * ratio);
          }
        }
      }

////TODO delet after tested
//cout<< "Reihen reduzierung"<<endl;
//bigmatrix.MatrixShow();
    }
    else{   // shit pivot was 0 ???
      delete [] pivot;
      throw range_error("Inverse doesn't exist because the Matrix is singular");
    }
  }
  delete [] pivot;
  for (int i=0; i< rows; i++){
    for(int j=0; j<colums; j++){
      result.values[i][j]=bigmatrix.values[i][j+colums];
    }

  }
  return result;
}


void Matrix::setValue(double value, int row, int column)
{
  if(row <= 0 || row > values.size() || column <= 0 || column > values[0].size())
    return;
  values[row-1][column-1] = value;
}

void Matrix::setValueColumn(std::vector<double> inputValues, int column)
{
  int sizeOfInputValues = inputValues.size();
    int sizeOfValues = values.size();

    for(int i = 1; i <= sizeOfValues; ++i)
    {
      if(i <= sizeOfInputValues)
      {
        setValue(inputValues[i-1], i, column);
      }
    }
}

void Matrix::setValueColumn(std::vector<double> inputValues, int column, double fillValue)
{
  int sizeOfInputValues = inputValues.size();
  int sizeOfValues = values.size();

  for(int i = 1; i <= sizeOfValues; ++i)
  {
    if(i <= sizeOfInputValues)
    {
      setValue(inputValues[i-1], i, column);
    }
    else
    {
      setValue(fillValue ,i, column);
    }
  }
}

void Matrix::setValueRow(std::vector<double> inputValues, int row)
{
  int sizeOfInputValues = inputValues.size();
    int sizeOfValues = values.size();

    for(int i = 1; i <= sizeOfValues; ++i)
    {
      if(i <= sizeOfInputValues)
      {
        setValue(inputValues[i-1], i, row);
      }
    }
}

void Matrix::setValueRow(std::vector<double> inputValues, int row, double fillValue)
{
  int sizeOfInputValues = inputValues.size();
  int sizeOfValues = values.size();

  for(int i = 1; i <= sizeOfValues; ++i)
  {
    if(i <= sizeOfInputValues)
    {
      setValue(inputValues[i-1], i, row);
    }
    else
    {
      setValue(fillValue ,i, row);
    }
  }
}

Matrix operator*(const Matrix& left, const Matrix& right)
{
  if(left.values[0].size() == right.values.size())
  {
    Matrix matrixProduct = Matrix(left.values.size(), right.values[0].size());
    for(unsigned int r = 1; r <= matrixProduct.values.size(); ++r)
    {
      for(unsigned int c = 1; c <= matrixProduct.values[0].size(); ++c)
      {
        for(unsigned int elementIndex = 1; elementIndex <= left.values.size(); ++elementIndex)
        {
          matrixProduct.setValue(left.values[r-1][elementIndex-1]*right.values[elementIndex-1][c-1] + matrixProduct.values[r-1][c-1], r, c);
        }
      }
    }
    return matrixProduct;
  }
  else
  {
    throw range_error("Incorrect dimension for matrix multiplication");
  }
}


