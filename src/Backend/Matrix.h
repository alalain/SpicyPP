/*
 * Matrix.h
 *
 *  Created on: Nov 4, 2020
 *      Author: Marius Baumann
 */

#ifndef BACKEND_MATRIX_H_
#define BACKEND_MATRIX_H_

#include <iostream> //TODO wont be needed in final version

class Matrix
{
  private:
    double** matrix;
    int rows;
    int columns;

  public:
    Matrix(int rows, int columns, double* values = nullptr);   //instantiate Matrix in heap (values has to be length of rows*columns)
    ~Matrix();                                                //delete data on heap
    Matrix(const Matrix &other);                              //no shallow Copy
    Matrix& operator=(const Matrix &other);                   //no shallow Copy

    double getValue(int row, int column) const;
    int getRows() const;
    int getColumns() const;
    bool hasError() const; //if rows or columns <= 0;

    void setValue(double value, int row = 0, int column = 0);
    void setValues(double* values, int count, int rowStart = 0, int columnStart = 0);
    void setValueColumn(double* values, int column);
    void setValueRow(double* values, int row);

    Matrix getInverse() const;
    friend Matrix operator*(Matrix& left, Matrix& right);
    friend bool operator==(Matrix& left, Matrix& right);

    //TODO Only for test
    void MatrixShow()
    {
      using namespace std;
      cout << "Matrix:" << endl;
      for(int i = 0; i < rows; i++)
      {
        for(int j = 0; j < columns; j++){
          cout << matrix[i][j] << " ";
        }
        cout << endl;
      }
    }
};

#endif /* BACKEND_MATRIX_H_ */
