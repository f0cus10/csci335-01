//
//  matrixSolution.cpp
//  csci-335-01
//
//  Created by Iftikhar Khan on 2/11/18.
//  Copyright © 2018 Iftikhar Khan. All rights reserved.
//
#ifndef MATRIXSOLUTION_CPP
#define MATRIXSOLUTION_CPP
#include "matrixSolution.hpp"
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::ostream;

namespace matrixSolution {
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
    //TODO (Bug 1): Does not copy the array properly
    for (unsigned int i = 0; i < num_rows_; ++i){
      array_ = new T* {*rhs.array_[i]};
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
    delete array_;
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
  const std::vector<T> & Matrix<T>::operator[](int row) const{
    vector<T> result;
    for (unsigned int i = 0; i < num_columns_; ++i) {
      result.push_back(array_[row][i]);
    }
    return result;
  }
  
  template<typename T>
  std::vector<T> & Matrix<T>::operator[](int row){
    vector<T> result;
    for (unsigned int i = 0; i < num_columns_; ++i) {
      result.push_back(array_[row][i]);
    }
    return result;
  }
  
  template<typename T>
  Matrix<T> Matrix<T>::operator+(const Matrix<T> & b_matrix){
    //TODO (Bug 3): Figure out how to change the values of a Matrix object
  }
  
  template<typename T>
  Matrix<T> Matrix<T>::operator+(const T & an_object){
    //TODO (Bug 4): Should follow the same path as the matrix operator
  }
  
  template<typename T>
  size_t Matrix<T>::NumRows() const{
    return num_rows_;
  }
  template<typename T>
  size_t Matrix<T>::NumCols() const {
    return num_columns_;
  }
  
  template<typename T>
  ostream & operator<<(ostream & out, const Matrix<T> & a_matrix){
    out << "[";
    for(auto &row: a_matrix.array_){
      for(auto &column: row){
        out << column << "\t";
      }
      out << "\n";
    }
    out << "]\n";
    return out;
  }
}
#endif
