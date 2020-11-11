/*
 * Matrix.h
 *
 *  Created on: Nov 4, 2020
 *      Author: Marius Baumann
 */

#ifndef BACKEND_MATRIX_H_
#define BACKEND_MATRIX_H_

#include <iostream> //TODO wont be needed in final version
#include <vector>

class Matrix
{
  private:
    std::vector<std::vector<double>> values;

  public:
    Matrix(int rows, int columns, std::vector<double> values = std::vector<double>());       //instantiate Matrix

    double getValue(int row, int column) const;
    int getRows() const;
    int getColumns() const;
    bool hasError() const; //if rows or columns <= 0;

    void setValue(double value, int row = 0, int column = 0);
    void setValues(std::vector<double> values, int rowStart = 0, int columnStart = 0);
    void setValueColumn(std::vector<double> values, int column);
    void setValueRow(std::vector<double> values, int row);

    Matrix getInverse() const;
    friend Matrix operator*(Matrix& left, Matrix& right);
    friend bool operator==(Matrix& left, Matrix& right);

    //TODO Only for test
    void MatrixShow()
    {
      using namespace std;
      cout << "Matrix:" << endl;
      for(int i = 0; i < values.size(); i++)
      {
        for(int j = 0; j < values[i].size(); j++){
          cout << values[i][j] << " ";
        }
        cout << endl;
      }
    }
};

#endif /* BACKEND_MATRIX_H_ */
