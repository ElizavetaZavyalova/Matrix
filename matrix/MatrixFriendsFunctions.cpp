//
// Created by eliza on 05.11.2022.
//
#include "Matrix.h"
#define MatrixVector std::vector<float>


Matrix Transpose(const Matrix& other){
    Matrix result=other;
    result.Transpose();
    return result;
}
Matrix operator+(const Matrix& A, const Matrix& B){
    Matrix result=A;
    result+=B;
    return result;
}
Matrix operator-(const Matrix& A, const Matrix& B){
    Matrix result=A;
    result-=B;
    return result;
}
Matrix operator*(const Matrix& A, const Matrix& B){
    Matrix result=A;
    result*=B;
    return result;
}
Matrix operator|(const Matrix& A, const Matrix& B){
    Matrix result=A;
    result|=B;
    return result;
}


float det(const Matrix& other){
    return other.det();
}