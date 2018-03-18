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
Matrix<T>::Matrix (const Matrix & rhs)
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
void Matrix<T>::clear()
{
	/*
	for (int i = 0 ; i < m_size ; i++)
		delete m_matrix[i];
	delete m_matrix;
	*/
	m_size = 0;
}

template <typename T>   
MyArray<T> & Matrix<T>::operator[](const int i)
{
	return m_matrix[i];
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

