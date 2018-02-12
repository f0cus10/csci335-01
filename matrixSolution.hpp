#ifndef matrixSolution_hpp
#define matrixSolution_hpp

#include <iostream>

namespace matrixSolution {
  template <typename T>
  class Matrix {
  public:
    Matrix();
    Matrix(const Matrix &rhs);
    Matrix& operator=(const Matrix &rhs);
    Matrix(Matrix &&rhs);
    Matrix& operator=(Matrix &&rhs);
    ~Matrix();
    
    void ReadMatrix();
    
    // @row: an index to a row of the matrix.
    // @returns the row as a vector of items. No error checking.
    // const version.
    const std::vector<T> & operator[](int row) const;
    
    // @row: an index to a row of the matrix.
    // @returns the row as a vector of items. No error checking.
    // non-cost version.
    std::vector<T> & operator[](int row);
    
    Matrix operator+(const Matrix &b_matrix);
    Matrix operator+(const T &an_object);
    
    // @returns number of rows.
    size_t NumRows() const;
    // @returns number of columns.
    size_t NumCols() const;
    
    // Overloading the << operator.
    friend std::ostream &operator<<(std::ostream &out, const Matrix &a_matrix);
    
  private:
    size_t num_columns_;
    size_t num_rows_;
    T** array_;
  };
  
}

#include "matrixSolution.cpp" /* Templated Class */
#endif /* matrixSolution_hpp */
