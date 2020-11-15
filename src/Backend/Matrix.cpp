/*
 * Matrix.cpp
 *
 *  Created on: Nov 4, 2020
 *      Author: Marius Baumann
 */

#include "Matrix.h"

using namespace std;

// Backend main/*
int main(){
  vector<double> v = {1.0,2.0,3.0, 3.0, 5.0, 6.0, 7.0, 8.0, 4.0};
  Matrix m1 = Matrix(2,2,v);
  m1.MatrixShow();
  Matrix m2 = Matrix(3,3,v);

  m2.MatrixShow();
  Matrix m3 = m2.getInverse();

  m2.MatrixShow();
  m3.MatrixShow();

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
      unsigned int index = row * columns + column;
      if(index >= values.size())
        this->values[row].push_back(0.0);
      else
        this->values[row].push_back(values[index]);
    }
  }
}


Matrix Matrix::getInverse() const
{
	double pivot[values.size()] = {};

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

	//TODO delet after tested
	cout<< "Einheitsvektor"<<endl;
	bigmatrix.MatrixShow();

	for(int row = 0; row < rows; row++) {
		if( bigmatrix.values[row][row] != 0){

			pivot[row]=bigmatrix.values[row][row];
		
			for(int colum = 0; colum < 2*colums; colum++){
				bigmatrix.values[row][colum] = bigmatrix.values[row][colum]/pivot[row];  // pivot should not be zero
			}

			//TODO delet after tested
			cout<< "Pivot Teilung"<<endl;
			bigmatrix.MatrixShow();

			for(rreduce = 0; rreduce < rows; rreduce++) {
			  if(rreduce != row){

			    double ratio = bigmatrix.values[rreduce][row] / bigmatrix.values[row][row];

          for(int colum = 0; colum < 2*colums; colum++){
            bigmatrix.values[rreduce][colum] -=  (bigmatrix.values[row][colum] * ratio);
          }
			  }
			}

			//TODO delet after tested
			cout<< "Reihen reduzierung"<<endl;
			bigmatrix.MatrixShow();

		}
		else{		// shit pivot was 0 ???

		  cout << "fuck pivot was zero" <<endl;
		  return result;
		}
	}

	for (int i=0; i< rows; i++){
	  for(int j=0; j<colums; j++){
	    result.values[i][j]=bigmatrix.values[i][j+colums];
	  }

	}
	return result;
}

