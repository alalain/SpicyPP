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
    return Matrix(0,0);

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

  rrefMatrix.MatrixShow();
  rref(rrefMatrix);
  rrefMatrix.MatrixShow();

  //Read inverse out of rrefMatrix
  Matrix inverse = Matrix(getRows(), getColumns());
  for(int i = 1; i <= getRows(); i++) {
    vector<double> row;
    for(int j = 1; j <= getColumns(); j++){
      row.push_back(rrefMatrix.getValue(i, j + getColumns()));
    }
    inverse.setValueRow(row, i);
  }
  inverse.MatrixShow();

  return inverse;
}


void divideLine(Matrix& rrefMatrix, int line, double divider)
{
  int nDim = rrefMatrix.getRows();
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
  int nDim = rrefMatrix.getRows();
  int mDim = rrefMatrix.getColumns();
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
  int nDim = rrefMatrix.getRows();
  double base = rrefMatrix.getValue(line,col);
  for(int i = line; i > 0; i--)
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
  int nDim = rrefMatrix.getRows();
  int mDim = rrefMatrix.getColumns();
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
    for(int i = mDim; i > 0; i--)
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
}

/*
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
*/

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


