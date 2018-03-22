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
 * the Bell Curve calculation class
 *
*/
#include <cmath>
#include "matrix.h"
#include "myArray.h"

template <typename T>
class Gauss
{
	public:

		void operator()(const matrix<T> mat, const myArray<T> vec) const;
};


#include "Gauss.hpp"
#endif