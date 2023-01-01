//
// Created by eliza on 29.10.2022.
//

#include "Matrix.h"
#define MatrixVector std::vector<float>

void Matrix::MakeEMatrix(const unsigned int countString, const unsigned int countColumn){
    matrix.clear();
   for(int stringIndex = 0; stringIndex < countString; stringIndex++) {
       MatrixVector MatrixString;
       for(int columnIndex = 0; columnIndex < countColumn; columnIndex++) {
           (columnIndex==stringIndex)? MatrixString.push_back(1.0):MatrixString.push_back(0.0);
       }
       matrix.push_back(MatrixString);
   }
}
void Matrix::MakeRMatrix(const unsigned int countString, const unsigned int countColumn){
    matrix.clear();
    for(int stringIndex = 0; stringIndex < countString; stringIndex++) {
        MatrixVector MatrixString;
        for(int columnIndex = 0; columnIndex < countColumn; columnIndex++) {
             MatrixString.push_back(std::rand());
        }
        matrix.push_back(MatrixString);
    }
}
void Matrix::MakeOMatrix(const unsigned int countString, const unsigned int countColumn){
    matrix.clear();
    for(int stringIndex = 0; stringIndex < countString; stringIndex++) {
        MatrixVector MatrixString;
        for(int columnIndex = 0; columnIndex < countColumn; columnIndex++) {
            MatrixString.push_back(0.0);
        }
        matrix.push_back(MatrixString);
    }
}
bool Matrix::merge(const Matrix& margeMatrix){
    if(matrix.size()!=margeMatrix.matrix.size()) {
        return false;
    }
    this->additionalColumn.push_back(matrix.size());
    for(int stringIndex=0; stringIndex<matrix.size(); stringIndex++) {
        for(int columnIndex=0; columnIndex<(margeMatrix.matrix[stringIndex].size()); columnIndex++){
            matrix[stringIndex].push_back(margeMatrix.matrix[stringIndex][columnIndex]);
        }
    }
    return true;
}
bool Matrix::sum(const Matrix & sumMatrix){
   if(getStringCount()!=sumMatrix.getStringCount()||getColumnCount()!=sumMatrix.getColumnCount()){
       return false;
   }
    for(int stringIndex = 0; stringIndex < getStringCount(); stringIndex++) {
        for(int columnIndex = 0; columnIndex < getColumnCount(); columnIndex++) {
            matrix[stringIndex][columnIndex]+=sumMatrix.matrix[stringIndex][columnIndex];
        }
    }
    return true;
}
bool Matrix::def(const Matrix & defMatrix){
    if(getStringCount()!=defMatrix.getStringCount()||getColumnCount()!=defMatrix.getColumnCount()){
        return false;
    }
    for(int stringIndex = 0; stringIndex < getStringCount(); stringIndex++) {
        for(int columnIndex = 0; columnIndex < getColumnCount(); columnIndex++) {
            matrix[stringIndex][columnIndex]-=defMatrix.matrix[stringIndex][columnIndex];
        }
    }
    return true;
}
bool Matrix::multiply(const Matrix & A, const Matrix & B){
    if(A.getColumnCount()!=B.getStringCount()){
        return false;
    }
    matrix.clear();
    for(int stringIndex = 0; stringIndex < A.getStringCount(); stringIndex++) {
        MatrixVector matrixString;
        matrix.push_back(matrixString);
        for(int columnIndex = 0; columnIndex < B.getColumnCount(); columnIndex++) {
             matrix[stringIndex].push_back(0.0);
             for(int itemIndex = 0; itemIndex < A.getColumnCount(); itemIndex++){
                 matrix[stringIndex][columnIndex]+=(A.matrix[stringIndex][itemIndex]*B.matrix[itemIndex][columnIndex]);
             }
        }
    }
    return true;
}
void Matrix::changeString(const unsigned int String1, const unsigned int String2){
    MatrixVector matrixString=matrix[String1];
    matrix[String1]=matrix[String2];
    matrix[String2]=matrixString;
}
void Matrix::changeColumn(const unsigned int Column1, const unsigned int Column2){
    for(int stringIndex=0; stringIndex<matrix.size(); stringIndex++){
        float columnItem=matrix[stringIndex][Column1];
        matrix[stringIndex][Column1]=matrix[stringIndex][Column2];
        matrix[stringIndex][Column2]=columnItem;
    }
}
float Matrix::det(const std::vector<MatrixVector> &matrix) const {
    if(matrix.size()==1){
        return matrix[0][0];
    }
    float detResult =0;   // 1 толбец
    unsigned int column=1;
    for(int stringIndex=0;stringIndex<matrix.size();stringIndex++){
        detResult += \
        matrix[stringIndex][column-1]*powf(-1, (stringIndex+1+column))*\
                      det(getMinor(stringIndex+1,column,matrix));
    }
    return detResult;
}
void Matrix::copy(const Matrix& other){
    this->matrix = other.matrix;
    this->additionalColumn=other.additionalColumn;
}
std::vector<MatrixVector> Matrix::getMinor(const unsigned int String, const unsigned int column, \
                                                 const std::vector<MatrixVector>&matrix) const{
    std::vector<MatrixVector> Minor;
    for(int stringIndex = 0; stringIndex < getStringCount(); stringIndex++) {
        if(stringIndex == String-1)continue;
        MatrixVector MatrixString;
        Minor.push_back(MatrixString);
        for(int columnIndex = 0; columnIndex < getColumnCount(); columnIndex++) {
            if(columnIndex == column-1)continue;
            MatrixString.push_back(matrix[stringIndex][columnIndex]);
        }
        Minor.push_back(MatrixString);
    }
    return Minor;
}


