#ifndef MATRIX_H
#define MATRIX_H
#include "myArray.h"
#include <vector>
#include <algorithm>


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

		T sumRow(const int row) const;

		T sumCol(const int col) const;

	public:

		Matrix (); 

		Matrix (const int n);

		Matrix (const Matrix<T> & rhs);

		~Matrix();

		Matrix<T>& operator= (const Matrix<T>& rhs);  

		Matrix<T> operator+(const Matrix<T> & rhs) const;

		Matrix<T> operator*(const Matrix<T> & rhs) const;

		MyArray<T> operator*(const MyArray<T> & rhs) const;

		MyArray<T> & operator[](const int i);

		void switchRows (const int i, const int j);

		void sortRows(const int i);

		int getSize(){return m_size;};

		friend ostream& operator<< <T> (ostream& out ,  Matrix<T> & mat);
};


template <typename T>
class Compare
{
	public:
		/*! The () Operator
		*	returns true if lhs is bigger then rhs
		* \pre '<' operator defind for T! 
		* \post none
		*/
		bool operator() (const T lhs, const T rhs) const
		{
			return (lhs) > (rhs);
		}
};

#include "matrix.hpp"

#endif