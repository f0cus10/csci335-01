// Iftikhar Khan
// Test file for assignment 1.

#include <iostream>
#include <string>

#include "matrixSolution.hpp"

// It is fine to use namespaces in .cc files.
using namespace std;
using namespace matrixSolution;

namespace {

template <typename Object>
void PrintVec(const vector<Object> &a_vector) {
  // Provide code for this function.
}

void TestPart1() {
  Matrix<int> a, b;
  cout << a.NumRows() << " " << a.NumCols() << endl;

  a.ReadMatrix();

  cout << a << endl;
  b.ReadMatrix();
  cout << b << endl;

  a = b;
  cout << a << endl;

  Matrix<int> c = b;
  cout << c << endl;

  Matrix<int> d = std::move(c);
  cout << d << endl;

  a = std::move(d);
  cout << a << endl;

}

void TestPart2() {
  Matrix<string> a, b;
  a.ReadMatrix();
  cout << a << endl;
  b.ReadMatrix();
  cout << b << endl;
  cout << a + b << endl; // Matrices should have same size.
                         // The default + operator for strings
                         // will be used.

  Matrix<string> d = a + b;
  cout << d <<endl;

  const string a_string{"hi_there"};
  cout << d + a_string << endl;

  PrintVec(a[0]);  // Should print the first row of a.
  PrintVec(b[1]);  // Should be print the second row of b.
                   // Note, that the [] operator should return
                   // a vector object.
                   // PrintVec() is a templated function that
                   // couts the elements of a vector.
}

}  // namespace

int main() {
  TestPart1();
  TestPart2();
  return 0;
}



