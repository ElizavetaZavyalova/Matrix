//
// Created by eliza on 05.11.2022.
//
#include "Matrix.h"
#include <iostream>
#define MatrixVector std::vector<float>
std::ostream& operator<< (std::ostream &out, const Matrix&other){

    for(int stringIndex = 0; stringIndex < other.getStringCount(); stringIndex++) {
        unsigned int index=0;
        for(int columnIndex = 0; columnIndex < other.getColumnCount(); columnIndex++) {
            if(other.additionalColumn[index]==columnIndex){
                out<<"|"<<"\t";
                index++;
            }
            out<<other.matrix[stringIndex][columnIndex]<<"\t";
        }
        out<<"\n";
    }
    return out;
}
std::istream& operator>> (std::istream &in, Matrix &other){
    std::cout<<"Strings:";
    unsigned int countString=0;
    in>>countString;
    std::cout<<"Columns:";
    unsigned int countColumn=0;
    in>>countColumn;
    if(countColumn==0||countString==0){
        //throw
    }
    other.MakeOMatrix(countString,countColumn);
    other.additionalColumn.clear();
    for(int stringIndex = 0; stringIndex < countString; stringIndex++) {
        for(int columnIndex = 0; columnIndex < countColumn; columnIndex++) {
           in>>other.matrix[stringIndex][columnIndex];
        }
    }
    return in;
}