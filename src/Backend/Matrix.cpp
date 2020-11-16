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


Matrix getInverse(Matrix& A)
{

	double pivot = 0;
	/*
	Matrix bigmatrix(A.rows,2*A.colums);
	Matrix result(A.rows,A.colums);
	
	// Eigenmatrize added
	for(int row = A.rows; row < A.rows; row++) {
	    for(int colum = A.colums; colum < 2*A.colums; colum++){
		  if(row== (colum-A.colums))
			 bigmatrix[row][colum] = 1.0;
		  else
			 bigmatrix[row][colum] = 0.0;
      }
   }
	
	for(int row = 0; row < A.rows; row++) {
		if( A.matrix[row][row] != 0){
			pivot[row]=A.matrix[row][row];
		
			for(int colum = 0; colum < 2*A.colums; colum++){
				bigmatrix[row][colum] = A.matrix[row][colum]/pivot[row];  // pivot shold not be zero
			}
			for(int rreduce = row+1; rreduce < A.rows; rreduce++) {
				for(int colum = 0; colum < 2*A.colums; colum++){
					bigmatrix[rreduce][colum] = bigmatrix[rreduce][colum] - bigmatrix[rreduce][row]*bigmatrix[row][colum]; // seconde row - second row faktor* first row
				}
			}

		}
		else		// shit pivot was 0 ???
	}
	
	
	return invmatrix*/
	return Matrix(0,0);
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


