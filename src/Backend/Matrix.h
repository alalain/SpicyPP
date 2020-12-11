#ifndef BACKEND_MATRIX_H_
#define BACKEND_MATRIX_H_

#include <iostream> //TODO wont be needed in final version
#include <iomanip>  //     Same
#include <vector>

class Matrix
{
  private:
    std::vector<std::vector<double>> values;

  public:
    Matrix(int rows, int columns, std::vector<double> values = std::vector<double>());       //instantiate Matrix

    /**
       * Gets the value of a specific spot in matrix
       * @param row: Matrix row
       * @param column: Matrix column
       * @return one value in matrix
    */
    double getValue(int row, int column) const;

    /**
       * Gets actual number of rows in matrix
       * @return number of rows
    */
    int getRows() const {return values.size();}

    /**
       * Gets actual number of columns in matrix
       * @return number of columns
    */
    int getColumns() const{return values[0].size();} // because every Column have the same size

    /**
       * Checks if matrix has rows or columns that are smaller or equal to 0
       * @return true or false value
    */
    bool hasError() const; //if rows or columns <= 0;

    /**
       * Sets a value of a specific spot in matrix
       * @param value: desired value that should be written in matrix
       * @param row: in which row should value be written in
       * @param column: in which column should value be written in
       * @return matrix with value on right spot
    */
    void setValue(double value, int row = 0, int column = 0);

    /**
       * Sets a series of values beginning from a specific spot in matrix
       * @param inputValues: desired values that are being written
       * @param rowStart: in which row should values be written in
       * @param columnStart: in which column should values be written in
       * @return matrix with values beginning from right spot
    */
    void setValues(std::vector<double> inputValues, int rowStart = 0, int columnStart = 0);

    /**
       * Sets a series of values in a specific column of matrix
       * @param inputValues: desired values that should be written in column
       * @param column: in which column should values be written in
       * @param fillValue: if column is longer than amount of values written in, rest of elements are getting filled with another desired value
       * @return matrix with values in desired column
    */
    void setValueColumn(std::vector<double> inputValues, int column, double fillValue);

    /**
       * Sets a series of values in a specific column of matrix
       * @param inputValues: desired values that should be written in column
       * @param column: in which column should values be written in
       * @return matrix with values in desired column
    */
    void setValueColumn(std::vector<double> inputValues, int column);

    /**
       * Sets a series of values in a specific row of matrix
       * @param inputValues: desired values that should be written in row
       * @param row: in which row should values be written in
       * @param fillValue: if row is longer than amount of values written in, rest of elements are getting filled with another desired value
       * @return matrix with values in desired row
    */
    void setValueRow(std::vector<double> inputValues, int row, double fillValue);

    /**
       * Sets a series of values in a specific row of matrix
       * @param inputValues: desired values that should be written in row
       * @param row: in which row should values be written in
       * @return matrix with values in desired row
    */
    void setValueRow(std::vector<double> inputValues, int row);

    /**
       * A pure virtual member.
       * @return inverted Matrix
     */
    Matrix getInverse() const;
    /**
     * Multiplying left with right Matrix. Watch out for Order and dimensions of params.
     * @param left: Matrix with dimensions a*N
     * @param right: Matrix with dimensions N*b
     * @return New Multiplied Matrix
     */
    friend Matrix operator*(const Matrix& left, const Matrix& right);
    //friend bool operator==(Matrix& left, Matrix& right);

    //TODO Only for test
    void MatrixShow()
    {
      using namespace std;
      cout << "Matrix:" << endl;
      for(unsigned int i = 0; i < values.size(); i++)
      {
        for(unsigned int j = 0; j < values[i].size(); j++){
          cout << std::fixed << std::setw(6) << std::setprecision(3) << values[i][j] << ", ";
        }
        cout << endl;
      }
    }
};

#endif /* BACKEND_MATRIX_H_ */
