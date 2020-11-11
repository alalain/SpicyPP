/*
 * Matrix.cpp
 *
 *  Created on: Nov 4, 2020
 *      Author: Marius Baumann
 */

#include "Matrix.h"

using namespace std;

// Backend main
int main(){
  vector<double> v = {1.0,2.0,3.0, 4.0, 5.0};
  Matrix m1 = Matrix(2,2,v);
  m1.MatrixShow();
  Matrix m2 = Matrix(2,3);
  m2.setValue(2.0, -1,2);
  m2.MatrixShow();
  return 0;
}

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
}


void Matrix::setValue(double value, int row, int column)
{
  if(row <= 0 || row > values.size() || column <= 0 || column > values[0].size())
    return;
  values[row-1][column-1] = value;
}


/*friend Matrix operator*(Matrix& left, Matrix& right)
{

} */
