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
    num_columns_ = rhs.num_columns_;
    num_rows_ = rhs.num_rows_;
    //First, we must copy over all the columns
    for(unsigned int i: num_columns_){
      //Take the value of each of the columns, and copy them over
      //TODO: Verify if the arrays, are copied over as well
      array_ = new T*{*rhs.array_[i]};
    }
  }
  
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
    for (size_t i: num_columns_){
      for(size_t j: num_rows_){
        delete array_[i][j];
      }
      delete array_[i];
    }
    //TODO (Bug 3): Not really sure about whether this part is necessary
    delete array_;
    array_ = nullptr;
  }
  
  void ReadMatrix(){
    
  }
}
#endif
