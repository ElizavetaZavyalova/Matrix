//
// Created by eliza on 05.11.2022.
//
#include "Matrix.h"
#define MatrixVector std::vector<float>

Matrix Matrix::getMinor(const unsigned int string, const unsigned int column) const {
    return Matrix(getMinor(string, column,matrix));
}
int Matrix::getColumnCount() const{
    if(matrix.size()==0){
        return 0;
    }
    return matrix[0].size();
}
int Matrix::getStringCount() const{
    return matrix.size();
}
Matrix& Matrix::Transpose(){
    std::vector<MatrixVector> LastMatrix=matrix;
    for(int stringIndex = 0; stringIndex < getStringCount(); stringIndex++) {
        for(int columnIndex = 0; columnIndex < getColumnCount(); columnIndex++) {
            matrix[stringIndex][columnIndex]=LastMatrix[columnIndex][stringIndex];
        }
    }
    return *this;
}
float Matrix::det() const {
    return det(matrix);
}
void Matrix::operator+=(const Matrix& other){
    if(!this->sum(other)){
        //throw
    }
}
void Matrix::operator-=(const Matrix& other){
    if(!this->def(other)){
        //throw
    }
}
void Matrix::operator*=(const Matrix& other){
    Matrix A=*this;
    if(!this->multiply(A,other)){
        //throw
    }
}
void Matrix::operator|=(const Matrix& other){
    if(!this->merge(other)){
        //throw
    }
}
MatrixVector& Matrix::operator[](const unsigned int string){
    if(string>=getStringCount()){
        //throw
    }
    return matrix[string];
}