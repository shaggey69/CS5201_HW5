#ifndef MATRIX_H
#define MATRIX_H
#include "myArray.h"


template <typename T>
class Matrix;

template<class T>
ostream& operator<< (ostream& out ,  Matrix<T> & mat);



template <class T>
class Matrix
{
	private:
		
		MyArray <MyArray<T>> m_matrix;

		int m_size;

		void clear();

	public:

		Matrix (); 

		Matrix (const int n);

		Matrix (const Matrix & rhs);

		MyArray<T> & operator[](const int i);

		~Matrix();

		friend ostream& operator<< <T> (ostream& out ,  Matrix<T> & mat);


};

#include "matrix.hpp"

#endif