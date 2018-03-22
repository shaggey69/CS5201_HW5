template <typename T>   
Matrix<T>::Matrix()
{
	m_size = 0;
	m_matrix.setSize(0);
}

template <typename T>   
Matrix<T>::Matrix (const int n)
{
	m_size = n;
	m_matrix.setSize(n);
	for (int i = 0 ; i < m_size ; i++)
	{
		m_matrix[i].setSize(n);
	}
}

template <typename T>   
Matrix<T>::Matrix (const Matrix<T> & rhs)
{
	clear();
	m_size = rhs.m_size;
	m_matrix.setSize(m_size);	

	for (int i = 0 ; i < m_size ; i++)
 		m_matrix[i] = rhs.m_matrix[i];
}

template <typename T>   
Matrix<T>::~Matrix()
{
	clear();
}
 
template <typename T>   
Matrix<T>& Matrix<T>::operator= (const Matrix<T>& rhs)
{
	clear();
	m_size = rhs.m_size;
	m_matrix.setSize(m_size);

	for (int i = 0 ; i < m_size ; i++)
 		m_matrix[i] = rhs.m_matrix[i];

 	return *this;
}

template <typename T>   
void Matrix<T>::clear()
{
	m_size = 0;
}

template <typename T>   
T Matrix<T>::sumRow(const int row) const
{
	T sum = 0;
	for (int i = 0 ; i < m_size ; i++)
		sum += m_matrix[row][i];
	return sum;
}

template <typename T>   
T Matrix<T>::sumCol(const int col) const
{
	T sum = 0;
	for (int i = 0 ; i < m_size ; i++)
		sum += m_matrix[i][col];
	return sum;
}

template <typename T>   
Matrix<T> Matrix<T>::operator+(const Matrix<T> & rhs) const
{
	Matrix<T> retVal(m_size);
	for (int i = 0 ; i < m_size ; i++)
		for (int j = 0 ; j < m_size ; j++)
			retVal[i][j]= m_matrix[i][j]+rhs.m_matrix[i][j];
	return retVal;
}

template <typename T>   
Matrix<T> Matrix<T>::operator*(const Matrix<T> & rhs) const
{
	T sum = 0;
	Matrix<T> retVal(m_size);
	for (int i = 0 ; i < (m_size) ; i++)
		for (int j = 0 ; j < (m_size) ; j++)
		{ 
			for (int k = 0 ; k < (m_size) ; k++)
				sum += m_matrix[k][i]*rhs.m_matrix[j][k];
			retVal[j][i] = sum;
			sum = 0;
		}			
	return retVal;
}

template <typename T>   
MyArray<T>  Matrix<T>::operator*(const MyArray<T> & rhs) const
{
	T sum = 0;
	MyArray<T> retVal(m_size);
	for (int i = 0 ; i < (m_size) ; i++)
		{ 
			for (int k = 0 ; k < (m_size) ; k++)
				sum += m_matrix[i][k]*rhs[k];
			retVal[i] = sum;
			sum = 0;
		}			
	return retVal;
}

template <typename T>   
MyArray<T> & Matrix<T>::operator[](const int i)
{
	return m_matrix[i];
}

template <typename T>   
void Matrix<T>::switchRows(const int i, const int j)
{
	MyArray<T> temp;
	temp = m_matrix[i];
	m_matrix[i] = m_matrix [j];
	m_matrix[j] =temp;

}

template <typename T>   
void Matrix<T>::sortRows(const int i)
{
	/*
	vector<T> temp ;

	for (int k = 0 ; k < m_size ; k++)
		temp.push_back(m_matrix[k][i]);

	sort(temp.begin(),temp.end(),Compare<T>());
	
	for (int j = 0 ; j < m_size ; j++)
		m_matrix[j][i] = temp[j];
	*/

	T max = 0;
	for (int k = 0 ; k < m_size ; k++)
		if (max > m_matrix[k][i])
			max = m_matrix[k][i];
	switchRows(,)
}

template <typename T>   
ostream& operator<<(ostream& out ,  Matrix<T> & mat)
{
	for (int i = 0 ; i < mat.m_size ; i++)
	{
		for (int j = 0 ; j < mat.m_size ; j++)
			out << mat.m_matrix[i][j] << " ";
		out << endl;
	}
	return out;
}

