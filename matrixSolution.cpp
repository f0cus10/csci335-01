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
    array_ = new T*[1];
    *array_ = new T[1];
  }
}
