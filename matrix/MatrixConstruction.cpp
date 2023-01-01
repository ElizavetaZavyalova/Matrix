//
// Created by eliza on 05.11.2022.
//
#include "Matrix.h"
#define MatrixVector std::vector<float>



Matrix::Matrix(const std::vector<MatrixVector> &matrix){
    this->matrix = matrix;
}
Matrix::Matrix(const unsigned int countString, const  unsigned int countColumn, const Key key){
    switch(key){
        case O:
            MakeOMatrix(countString, countColumn);
            break;
        case E:
            MakeEMatrix(countString, countColumn);
            break;
        case R:
            MakeRMatrix(countString, countColumn);
            break;
    }

}
Matrix::Matrix(const unsigned int countElements, const Key key):\
Matrix(countElements, countElements, key) {

}
void Matrix::operator=(const Matrix& other){
    this->copy(other);
}
Matrix::Matrix(const Matrix& other){
    this->copy(other);
}