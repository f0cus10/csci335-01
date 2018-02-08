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
  template<typename Object>
  class Matrix{
  public:
    /* The Big Five */
    Matrix();
    Matrix(const Matrix & rhs);
    Matrix & operator=(const Matrix & rhs);
    Matrix(const Matrix && rhs);
    Matrix & operator=(const Matrix && rhs);
    
    void ReadMatrix();
    const std::vector<Object> & operator[](int row) const;
    std::vector<Object> & operator[](int row);
    
    Matrix operator+(const Matrix & b_matrix);
    Matrix operator+(const Object & an_object);
    
    size_t NumRows() const;
    size_t NumColumns() const;
    
    friend std::ostream & operator<<(std::ostream & out, const Matrix & a_matrix);
  };
}
