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
Matrix getInverse(Matrix& A)
{
	double pivot[A.rows] = 0;
	int row = 0;
	int colum = 0;
	Matrix invmatrix(A.rows,2*A.colums);
	
	// Eigenmatrize added
	for(int row = A.rows; row < A.rows*2; row++) {
	    for(int colum = A.colums; colum < 2*A.colums; colum++){
		  if(row== colum)
			 inmvmatrix[row][colum] = 1.0;
		  else
			 inmvmatrix[row][colum] = 0.0;
        }
    }
	
	pivot[row]=A.matrix[0][0];
	/*
	  for(int row = 0; row < 2*A.rows; row++) {
		for(int colum = 0; colum < 2*A.colums; colum++){
			invmatrix[row][colum] = A.matrix[row][colum]/pivot[row];
		}
		for(int colum = 0; colum < 2*A.colums; colum++){
			invmatrix[row][colum] = A.matrix[row][colum]/pivot[row];
		}

		
	}
	*/
	return invmatrix
}
Matrix& Matrix::operator=(const Matrix &other)
{
  // TODO Auto-generated method stub

}

