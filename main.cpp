#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
	Matrix<int> my_matrix(5);
	for (int i = 1 ; i <= 5 ; i++)
		for (int j = 1 ; j <= 5 ; j++)
			my_matrix[i-1][j-1]=(i+j-1)+(i-1)*(5-i);
	cout << my_matrix;	

	return 0;
}