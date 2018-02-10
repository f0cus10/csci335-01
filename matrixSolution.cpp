//
//  matrixSolution.cpp
//  csci-335-01
//
//  Created by Iftikhar Khan on 2/7/18.
//  Copyright © 2018 Iftikhar Khan. All rights reserved.
//

#include "matrixSolution.hpp"
#include <iostream>

namespace matrixSolution {
  template<typename T>
  Matrix<T>::Matrix(){
    num_columns_ = 0;
    num_rows_ = 0;
    array_ = nullptr;
  }

  template<typename T>
  Matrix<T>(const Matrix & rhs){
    this->num_columns_{rhs.num_columns};
    this->num_rows_{rhs.num_rows_};
    for(unsigned int i = 0; i < num_columns_; ++i){
      for(unsigned int j = 0; j < num_rows_; ++j){
        this->array_[i][j]{rhs.array_[i][j]};
      }
    }
  }

  Matrix & operator=(const Matrix & rhs){
    std::swap(num_columns_, rhs.num_columns);
    std::swap(num_rows_, rhs.num_rows);
    //Check how to transfer the array_ from rhs to lhs
  }
    
}
