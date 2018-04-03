#include <iostream>
#include <fstream>
#include "matrix.h"
#include "myArray.h"
#include "Gauss.h"


using namespace std;

int main(int argc, char *argv[])
{
	int dimNum = 0;
	Matrix< double> my_matrix;
	MyArray< double> my_arary, answears_array;
	Gauss< double> my_gauss;
	double temp = 0;
	ifstream in;

	if (argc < 2)
    cout << endl << "not enough inputs :(" << endl ;
  else  if (argc > 2)    
    cout << endl << "too many inputs :(" << endl ;
  else
  {
  	in.open(argv[1]);
		argc = 0;
		if (!in) 
    	cout << endl << "invailed file :("  << endl;
		else
		{
			in >> dimNum;
			my_matrix.setSize(dimNum);
			for (int i = 0 ; i < dimNum ; i++)
				for (int j = 0 ; j < dimNum ; j++)
				{
					in >> temp;
					my_matrix[j][i] = temp;
				}
			my_matrix.transpose();

			my_arary.setSize(dimNum);
			for (int i = 0 ; i < dimNum ; i++)
			{
				in >> temp;
				my_arary[i] = temp;
			}
	
			answears_array.setSize(dimNum);
			answears_array = my_gauss(my_matrix,my_arary);
			cout << setprecision(8);
			cout << answears_array;
		}
	}
	return 0;
}