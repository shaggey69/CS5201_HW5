/*
header function for Gauss class
By: Ari Sherman
Class: CS5201 HW #5
Date: 4.4.18
*/
// operator ()
template <typename T>
void Gauss::operator()(const matrix<T> mat, const myArray<T> vec) const;
{
	matrix<T> temp(mat.getSize);
	temp = mat;
	for (int i = 0 ; i < mat.getSize(); i++)
	{
		temp.sortRows(i);
		for (int j = i+1)
	}
}