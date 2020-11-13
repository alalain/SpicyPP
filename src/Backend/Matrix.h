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
    void setValues(std::vector<double> inputValues, int rowStart = 0, int columnStart = 0);
    void setValueColumn(std::vector<double> inputValues, int column, double fillValue);
    void setValueColumn(std::vector<double> inputValues, int column);
    void setValueRow(std::vector<double> inputValues, int row, double fillValue);
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
    friend bool operator==(Matrix& left, Matrix& right);

    //TODO Only for test
    void MatrixShow()
    {
      using namespace std;
      cout << "Matrix:" << endl;
      for(unsigned int i = 0; i < values.size(); i++)
      {
        for(unsigned int j = 0; j < values[i].size(); j++){
          cout << values[i][j] << " ";
        }
        cout << endl;
      }
    }
};

#endif /* BACKEND_MATRIX_H_ */
