//
// Created by eliza on 29.10.2022.
//

#ifndef NUMERICALMETHODS_MATRIX_H
#define NUMERICALMETHODS_MATRIX_H
#include <cmath>
#include <vector>
#include <string>
#define MatrixVector std::vector<float>

class Matrix {
public:
   enum Key{O=0,E=1,R=2};
private:
    void changeString(const unsigned int String1, const unsigned int String2);
    void changeColumn(const unsigned int Column1, const unsigned int Column2);
    void copy(const Matrix& other);
    std::vector<MatrixVector> getMinor(const unsigned int String, \
    const unsigned int column,const std::vector<MatrixVector>&matrix) const;
    void MakeEMatrix(const unsigned int countString=1, const unsigned int countColumn=1);
    void MakeRMatrix(const unsigned int countString=1, const unsigned int countColumn=1);
    void MakeOMatrix(const unsigned int countString=1,const  unsigned int countColumn=1);
    bool merge(const Matrix & mergeMatrix);
    bool sum(const Matrix & sumMatrix);
    bool def(const Matrix & defMatrix);
    bool multiply(const Matrix & A, const Matrix & B);
    float det(const std::vector<MatrixVector> &matrix)const ;
public:
      int getColumnCount() const;
      int getStringCount() const;
      Matrix getMinor(const unsigned int string, const unsigned int column) const;
      float det()const;
      Matrix& Transpose();
      void operator+=(const Matrix& other);
      void operator-=(const Matrix& other);
      void operator*=(const Matrix& other);
      void operator|=(const Matrix& other);
      MatrixVector& operator[](const unsigned int string);
public:
      void operator=(const Matrix& other);
      Matrix(const Matrix& other);
      Matrix( const std::vector<MatrixVector> &matrix);
      Matrix(const unsigned int countString=1, const unsigned int countColumn=1, const  Key key=R);
      Matrix(const unsigned int countElements, const  Key key=R);
public:
      friend float det(const Matrix& other);
      friend Matrix Transpose(const Matrix& other);
      friend Matrix operator+(const Matrix& A, const Matrix& B);
      friend Matrix operator-(const Matrix& A, const Matrix& B);
      friend Matrix operator*(const Matrix& A, const Matrix& B);
      friend Matrix operator|(const Matrix& A, const Matrix& B);
public:
    friend std::istream& operator>> (std::istream &in, Matrix &other);
    friend std::ostream& operator<< (std::ostream &out, const Matrix&other);
private:
    std::vector<MatrixVector> matrix;
    std::vector<int> additionalColumn={-1};
};


#endif //NUMERICALMETHODS_MATRIX_H
