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
Matrix getInverse(Matrix& A)
{
  /*
	double pivot[A.rows] = 0;

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
}
Matrix& Matrix::operator=(const Matrix &other)
{
  // TODO Auto-generated method stub

}

