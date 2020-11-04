/*
 * Matrix.h
 *
 *  Created on: Nov 4, 2020
 *      Author: Marius Baumann
 */

#ifndef BACKEND_MATRIX_H_
#define BACKEND_MATRIX_H_

#include <iostream> //TODO maybe remove

class Matrix
{
  private:
    double** matrix;
    int rows;
    int colums;

  public:
    Matrix(int rows, int colums);             //instantiate Matrix in heap
    ~Matrix();                                //delete data on heap
    Matrix(const Matrix &other);              //no shallow Copy
    Matrix& operator=(const Matrix &other);   //no shallow Copy

    double getValue(int row, int colum);
    Matrix getInverse();
    friend Matrix operator*(Matrix& left, Matrix& right);
    bool hasError(); //if rows or colums <= 0;

    //TODO Only for test
    void MatrixShow()
    {
      using namespace std;
      cout << "Matrix:" << endl;
      for(int i = 0; i < rows; i++)
      {
        for(int j = 0; j < colums; j++){
          cout << matrix[i][j] << " ";
        }
        cout << endl;
      }
    }
};

#endif /* BACKEND_MATRIX_H_ */
