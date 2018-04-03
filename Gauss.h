/*! \file
 *
 * the Gauss class
 */
/*
header function for Gauss class
By: Ari Sherman
Class: CS5201 HW #5
Date: 4.4.18
*/

#ifndef GAUSS_H
#define GAUSS_H
/*!
 * the Gauss solver calculation class
 *
*/
#include <cmath>
#include "matrix.h"
#include "myArray.h"

template <typename T>
class Gauss
{
	public:

	/*! Operator () calculator!
	* \ Calcultes the Gauss algorthem for the Ax=b eqation.
	* A is the mat Matrix. b Is the vec MyArray.
  * \pre "-" binary operator defiend for T
  * pre "*" binary operator defiend for T
  * \post A new MyArray is born
  *	\return a new Array with the calculated results.
  */
		MyArray<T> operator()(const Matrix<T> & mat, const MyArray<T> & vec) const;
	
	private:

	/*! functoin helper
	* internal use only!
	*/

		void GaussHelper(const int col, const int starterRow,
		 Matrix<T> & mat,  MyArray<T> & vec) const;

};


#include "Gauss.hpp"
#endif