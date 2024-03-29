#ifndef matrixSolution_hpp
#define matrixSolution_hpp

#include <iostream>
#include <vector>
using namespace std;

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
    
//    // @row: an index to a row of the matrix.
//    // @returns the row as a vector of items. No error checking.
//    // const version.
//    const std::vector<T> & operator[](int row) const;
    
    // @row: an index to a row of the matrix.
    // @returns the row as a vector of items. No error checking.
    // non-cost version.
    std::vector<T> operator[](int row) const;
    
    Matrix operator+(const Matrix &b_matrix);
    Matrix operator+(const T &an_object);
    
    // @returns number of rows.
    size_t NumRows() const;
    // @returns number of columns.
    size_t NumCols() const;
    
    // Overloading the << operator.
    friend std::ostream &operator<<(std::ostream &out, const Matrix<T> &a_matrix){
      out << "[";
      for (size_t i = 0; i < a_matrix.num_rows_; ++i){
        for(size_t j = 0; j < a_matrix.num_columns_; ++j){
          out << a_matrix.array_[i][j] << " ";
        }
        out << "\n";
      }
      out << "]\n";
      return out;
    }
    
  private:
    size_t num_columns_;
    size_t num_rows_;
    T** array_;
  };
  
  //Default Constructor
  template<typename T>
  Matrix<T>::Matrix(){
    num_columns_ = 0;
    num_rows_ = 0;
    array_ = nullptr;
  }
  
  //Copy Constructor
  template<typename T>
  Matrix<T>::Matrix(const Matrix<T> & rhs){
    num_rows_ = rhs.num_rows_;
    num_columns_ = rhs.num_columns_;
    //Allocate the memory for the array
    array_ = new T* [static_cast<int>(num_rows_)];
    for(unsigned int i = 0; i < num_rows_; ++i){
      array_[i] = new T [static_cast<int>(num_columns_)];
    }
    //Do a deep copy of the elements
    for (size_t i = 0; i < num_rows_; ++i){
      for(size_t j = 0; j < num_columns_; ++j){
        this->array_[i][j] = rhs.array_[i][j];
      }
    }
  }
  
  //Copy Assignment operator
  template<typename T>
  Matrix<T> & Matrix<T>::operator=(const Matrix<T> & rhs){
    Matrix<T> copy = rhs;
    std::swap(*this, copy);
    return *this;
  }
  
  //Move Constructor
  template<typename T>
  Matrix<T>::Matrix(Matrix<T> && rhs): num_columns_{rhs.num_columns_}, num_rows_{rhs.num_rows_}, array_{rhs.array_}{
    //TODO(Bug #1): This may not actually copy the data over
    rhs.num_columns_ = 0;
    rhs.num_rows_ = 0;
    rhs.array_ = nullptr;
  }
  
  template<typename T>
  Matrix<T> & Matrix<T>::operator=(Matrix<T> && rhs){
    std::swap(num_columns_, rhs.num_columns_);
    std::swap(num_rows_, rhs.num_rows_);
    std::swap(array_, rhs.array_);
    return *this;
  }
  
  template<typename T>
  Matrix<T>::~Matrix<T>(){
    for(size_t i = 0; i < num_rows_; ++i){
      delete[] array_[i];
    }
    delete[] array_;
    array_ = nullptr;
  }
  
  template<typename T>
  void Matrix<T>::ReadMatrix(){
    //First read the columns and rows
    cout << "Please enter your matrix configuration: ";
    cin >> num_rows_;
    //Ignore the space
    cin.ignore();
    cin >> num_columns_;
    cin.ignore();
    
    cout << "\nConstructing dynamically allocated array with parameters\n";
    //Then, allocate space for array_;
    array_ = new T*[num_rows_];
    for(unsigned int i = 0; i < num_rows_; ++i){
      array_[i] = new T[num_columns_];
    }
    cout << "Array completed" << endl;
    cout << "Reading data..." << endl;
    for(unsigned int i = 0; i < num_rows_; ++i){
      for(unsigned int j = 0; j < num_columns_; ++j){
        T tmp;
        cin >> tmp;
        array_[i][j] = tmp;
      }
    }
  }
  
  template<typename T>
  std::vector<T> Matrix<T>::operator[](int row) const {
    vector<T> result;
    for (unsigned int i = 0; i < num_columns_; ++i) {
      result.push_back(array_[row][i]);
    }
    return result;
  }
  
  template<typename T>
  Matrix<T> Matrix<T>::operator+(const Matrix<T> & b_matrix){
    //First, check if the matrices can be added at all
    if(num_rows_ != b_matrix.num_rows_ || num_columns_ != b_matrix.num_columns_){
      //Can't be done,
      abort();
    }
    //Else, we proceed as usual
    //First, we make a copy
    Matrix c{*this};
    //We take each element and add them together
    for(size_t i = 0; i < num_rows_; ++i){
      for(size_t j = 0; j < num_columns_; ++j){
        c.array_[i][j] = array_[i][j] + b_matrix.array_[i][j];
      }
    }
    return c;
  }
  
  template<typename T>
  Matrix<T> Matrix<T>::operator+(const T & an_object){
    Matrix c{*this};
    for (size_t i = 0; i < num_rows_; ++i){
      for(size_t j = 0; j < num_columns_; ++j){
        c.array_[i][j] = array_[i][j] + an_object;
      }
    }
    return c;
  }
  
  template<typename T>
  size_t Matrix<T>::NumRows() const{
    return num_rows_;
  }
  template<typename T>
  size_t Matrix<T>::NumCols() const {
    return num_columns_;
  }
}
#endif /* matrixSolution_hpp */
