// A simple basic implementation of a Matrix class

#ifndef TEACH_CSCI335_MATRIX_H_
#define TEACH_CSCI335_MATRIX_H_

#include <iostream>


// Make it a habit to use namespaces for your code.
namespace linear_algebra_project {

// Templated implementation of Matrix
// Sample usage:
//   Matrix<int> a;
//   a.ReadMatrix();
//   cout << a_matrix.NumRows() << endl;
//   cout << a_matrix.NumCols() << endl;
//   cout << a;
//   Matrix<int> b;
//   b.ReadMatrix();
//   cout << a + b;
template <typename Object>
class Matrix {
 public:
  Matrix() {
    num_columns_ =
  };
  Matrix(const Matrix &rhs) {};
  Matrix& operator=(const Matrix &rhs) {};
  Matrix(Matrix &&rhs) {};
  Matrix& operator=(Matrix &&rhs) {};
  
   
  void ReadMatrix() { }
  // @row: an index to a row of the matrix.
  // @returns the row as a vector of items. No error checking.
  // const version.
  const std::vector<Object> & operator[](int row) const
  {  }

 // @row: an index to a row of the matrix.
 // @returns the row as a vector of items. No error checking.
 // non-cost version. 
  std::vector<Object> & operator[](int row)
   {  }
  
  Matrix operator+(const Matrix &b_matrix) { }
  Matrix operator+(const Object &an_object) { }

 // @returns number of rows.
  size_t NumRows() const { }
  // @returns number of columns.
  size_t NumCols() const {  }

 // Overloading the << operator.
 friend std::ostream &operator<<(std::ostream &out, const Matrix &a_matrix) {
   
   return out;
 }

 private:
 size_t num_columns_;
 size_t num_rows_;
 Object **array_;
};

}  // namespace linear_algebra_project

#endif  // TEACH_CSCI335_MATRIX_H


