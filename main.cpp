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

	

	my_matrix.switchRows(1,3);

	cout << my_matrix << endl ;

	return 0;
}