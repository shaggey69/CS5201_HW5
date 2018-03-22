#include <iostream>
#include "matrix.h"
#include "myArray.h"

using namespace std;

int main()
{

	Matrix<int> my_matrix(5);
	for (int i = 0 ; i < 5 ; i++)
		for (int j = 0 ; j < 5 ; j++)
			my_matrix[i][j]=i*5+j+1;

	Matrix<int> my_matrix2(3);
	for (int i = 0 ; i < 3 ; i++)
		for (int j = 0 ; j < 3 ; j++)
			my_matrix2[i][j]= (i*3+j+1);

	cout << my_matrix2 << endl << endl;

	my_matrix2.sortRows(1);
	//my_matrix.sortRows(1);

	cout << my_matrix2 << endl ;
	//cout << my_matrix << endl ;

	return 0;
}