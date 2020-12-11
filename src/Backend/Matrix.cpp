/*
 * Matrix.cpp
 *
 *  Created on: Nov 4, 2020
 *      Author: Marius Baumann
 */

#include "Matrix.h"
#include <stdexcept>

using namespace std;

void rref(Matrix& rrefMatrix);

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

double Matrix::getValue(int row, int column) const {
  if(row <= 0 || row > values.size() || column <= 0 || column > values[0].size())
      return 0.0;
  return values[row-1][column-1];
}

Matrix Matrix::getInverse() const {
  //return if no SqaureMatrix
  if(getRows() != getColumns())
    throw range_error("not NxN -> not invertable");

  Matrix rrefMatrix = Matrix(getRows(), 2*getColumns());
  //Fill rows of Matrix for RREF with additional IdentityMatrix
  for(int i = 1; i <= getRows(); i++){
    vector<double> row;
    for(int j = 1; j <= getColumns(); j++)
      row.push_back(getValue(i,j));
    for(int j = 1; j <= getColumns(); j++){
      if(i==j)
        row.push_back(1.0);
      else
        row.push_back(0.0);
    }
    rrefMatrix.setValueRow(row,i);
  }

  rref(rrefMatrix);

  //Read inverse out of rrefMatrix
  Matrix inverse = Matrix(getRows(), getColumns());
  for(int i = 1; i <= getRows(); i++) {
    vector<double> row;
    for(int j = 1; j <= getColumns(); j++){
      row.push_back(rrefMatrix.getValue(i, j + getColumns()));
    }
    inverse.setValueRow(row, i);
  }

  return inverse;
}


void divideLine(Matrix& rrefMatrix, int line, double divider)
{
  int nDim = rrefMatrix.getColumns();
  if(divider != 0)
  {
    for(int i = 1; i <= nDim; i++)
    {
      rrefMatrix.setValue(rrefMatrix.getValue(line,i) / divider, line, i);
    }
  }
}


void reduceForward(Matrix& rrefMatrix, int line, int col)
{
  int nDim = rrefMatrix.getColumns();
  int mDim = rrefMatrix.getRows();
  double base = rrefMatrix.getValue(line,col);
  for(int i = line+1; i <= mDim; i++)
  {
    if(rrefMatrix.getValue(i,col) != 0)
    {
      double factor = rrefMatrix.getValue(i,col) / base;
      for(int j = 1; j <= nDim; j++)
      {
        rrefMatrix.setValue((rrefMatrix.getValue(i,j) - rrefMatrix.getValue(line,j) * factor),i,j);
      }
    }
  }
}

void reduceBackward(Matrix& rrefMatrix, int line, int col)
{
  int nDim = rrefMatrix.getColumns();
  double base = rrefMatrix.getValue(line,col);
  for(int i = line-1; i > 0; i--)
  {
    if(rrefMatrix.getValue(i,col) != 0)
    {
      double factor = rrefMatrix.getValue(i,col) / base;
      for(int j = 1; j <= nDim; j++)
      {
        rrefMatrix.setValue((rrefMatrix.getValue(i,j) - rrefMatrix.getValue(line,j) * factor),i,j);
      }
    }
  }
}

void rref(Matrix& rrefMatrix) {
  int nDim = rrefMatrix.getColumns();
  int mDim = rrefMatrix.getRows();
  for(int i = 1; i <= mDim; i++)
    {
      int j = 1;
      bool found = false;
      while(j <= nDim && !found)
      {
        if(rrefMatrix.getValue(i,j) != 0)
        {
          found = true;
          divideLine(rrefMatrix, i, rrefMatrix.getValue(i,j));
          reduceForward(rrefMatrix, i,j);
        }
        ++j;
      }
    }
    for(int i = mDim+1; i > 0; i--)
    {
      int j = 1;
      bool found = false;
      while(j <= nDim && !found)
      {
        if(rrefMatrix.getValue(i,j) == 1)
        {
          found = true;
          reduceBackward(rrefMatrix, i,j);
        }
        ++j;
      }
    }

    Matrix switcheroo = Matrix(mDim, nDim);
    for(int i = 1; i <= mDim; i++)
    {
      bool oneFound = false;
      for(int j = 1; j <= mDim; j++){
        if(rrefMatrix.getValue(j,i) == 1.0){
          vector<double> row;
          oneFound = true;
          for(int k = 1; k <= nDim; k++)
            row.push_back(rrefMatrix.getValue(j,k));
          switcheroo.setValueRow(row,i);
        }
      }
      if(!oneFound)
        throw range_error("Inverse doesn't exist because the Matrix is singular");
    }
    rrefMatrix = switcheroo;
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
  int sizeOfValues = getColumns();

  for(int i = 1; i <= sizeOfValues; ++i)
  {
    if(i <= sizeOfInputValues)
    {
      setValue(inputValues[i-1], row, i);
    }
  }
}

void Matrix::setValueRow(std::vector<double> inputValues, int row, double fillValue)
{
  int sizeOfInputValues = inputValues.size();
  int sizeOfValues = getColumns();

  for(int i = 1; i <= sizeOfValues; ++i)
  {
    if(i <= sizeOfInputValues)
    {
      setValue(inputValues[i-1], row, i);
    }
    else
    {
      setValue(fillValue ,row, i);
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


