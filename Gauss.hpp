/*
header function for Gauss class
By: Ari Sherman
Class: CS5201 HW #5
Date: 4.4.18
*/
// operator ()
template <typename T>
MyArray<T> Gauss<T>::operator()(const Matrix<T> & mat, const MyArray<T> & vec) const
{
	Matrix<T> tempMat (mat);
	MyArray<T> tempArr (vec);
	MyArray<T> answearVec (mat.getSize());

	int theSize = mat.getSize()-1;

	T multiplayer = 0;
	for (int i = 0 ; i < mat.getSize(); i++)
	{
		GaussHelper(i,i,tempMat,tempArr);
		for (int j = i+1 ; j <  mat.getSize() ; j++)
		{
			multiplayer = tempMat[j][i]/tempMat[i][i];
			for (int k = i ; k < mat.getSize() ; k++)	
				tempMat[j][k] = (tempMat[i][k]*multiplayer) - tempMat[j][k];			
			tempArr[j] = (tempArr[i]*multiplayer) - tempArr[j];
		}		
	}


	// back sub
	answearVec[0] = tempArr[theSize]/tempMat[theSize][theSize];
	for (int i = 1 ; i < mat.getSize(); i++)
	{
		T sum = 0;
		for (int j = 0 ; j < i; j++)
			sum+= tempMat[theSize-i][theSize-j]*answearVec[j];
		answearVec[i] = (tempArr[theSize-i] - sum)/tempMat[theSize-i][theSize-i];
	}
	
	//flip Answears Vec
	for (int i = 0 ; i <mat.getSize()/2 ; i++)
	{
		T temp = answearVec[i];
		answearVec[i] =answearVec[theSize-i];
		answearVec[theSize-i] = temp;
	}
	return answearVec;
}

//helper function
template <typename T>
void Gauss<T>::GaussHelper(const int col, const int starterRow,
	 Matrix<T> & mat,  MyArray<T> & arr) const
{
	int size = mat.getSize();

	vector < tuple< T ,int > > tempVec ;
	Matrix<T> tempMat(size);
	MyArray<T> tempArray(size);

	for (int k = 0 ; k < size ; k++)
		tempVec.push_back(make_tuple(fabs(mat[k][col]),k));

	sort(tempVec.begin()+starterRow,tempVec.end(),Compare<T>());
	
	for (int j = 0 ; j < size ; j++)
	{
		tempMat[j] = mat[get<1>(tempVec[j])];
		tempArray[j] = arr[get<1>(tempVec[j])];
	}
	
	mat = tempMat;
	arr = tempArray;
}
