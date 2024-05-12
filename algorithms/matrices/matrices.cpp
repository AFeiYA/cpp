#include <iostream>
// Diagonal Matrix
// What is a diagonal matrix?
// A diagonal matrix is a square matrix in which the entries outside the main diagonal are all zero
// A diagonal matrix can be represented using a one-dimensional array
// For example, the following diagonal matrix
// 1 0 0 0
// 0 2 0 0
// 0 0 3 0
// 0 0 0 4
// can be represented using the following array
// 1 2 3 4
// The number of non-zero elements in a diagonal matrix is equal to the number of rows or columns
class Diagonal
{
    private:
		int *A;
		int n;
    public:
		Diagonal()
		{
			n = 2;
			A = new int[2];
		}
        Diagonal(int n)
        {
			this->n = n;
			A = new int[n];
		}
		~Diagonal()
		{
			delete[] A;
		}
		void Set(int i, int j, int x);
		int Get(int i, int j);
		void Display();
};
void Diagonal::Set(int i, int j, int x)
{
	if (i == j)
	{
		A[i - 1] = x;
	}
}
int Diagonal::Get(int i, int j)
{
	if (i == j)
	{
		return A[i - 1];
	}
	return 0;
}
void Diagonal::Display()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				std::cout << A[i] << " ";
			}
			else
			{
				std::cout << "0 ";
			}
			std::cout << "\t";
		}
		std::cout << std::endl;
	}
}
// Lower Triangular Matrix
// What is a lower triangular matrix?
// A lower triangular matrix is a square matrix in which all the entries above the main diagonal are zero
// A lower triangular matrix can be represented using a one-dimensional array
// For example, the following lower triangular matrix
// 1 0 0 0
// 2 3 0 0
// 4 5 6 0
// 7 8 9 10
// can be represented using the following array
// 1 2 3 4 5 6 7 8 9 10
// The number of non-zero elements in a lower triangular matrix is equal to n(n+1)/2
// where n is the number of rows or columns
// The index of an element A[i][j] in a lower triangular matrix is given by the formula
// index = i(i-1)/2 + j - 1
class LowerTriangular
{
	private:
		int *A;
		int n;
	public:
		LowerTriangular()
		{
			n = 2;
			A = new int[2];
		}
		LowerTriangular(int n)
		{
			this->n = n;
			A = new int[n * (n + 1) / 2];
		}
		~LowerTriangular()
		{
			delete[] A;
		}
		void Set(int i, int j, int x);
		int Get(int i, int j);
		void Display();
};
void LowerTriangular::Set(int i, int j, int x)
{
	if (i >= j)
	{
		A[i * (i - 1) / 2 + j - 1] = x;
	}
}
int LowerTriangular::Get(int i, int j)
{
	if (i >= j)
	{
		return A[i * (i - 1) / 2 + j - 1];
	}
	return 0;
}
void LowerTriangular::Display()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i >= j)
			{
				std::cout << A[i * (i - 1) / 2 + j - 1] << " ";
			}
			else
			{
				std::cout << "0 ";
			}
			std::cout << "\t";
		}
		std::cout << std::endl;
	}
}
// Upper Triangular Matrix
// What is an upper triangular matrix?
// An upper triangular matrix is a square matrix in which all the entries below the main diagonal are zero
// A upper triangular matrix can be represented using a one-dimensional array
// For example, the following upper triangular matrix
// 1 2 3 4
// 0 5 6 7
// 0 0 8 9
// 0 0 0 10
// can be represented using the following array
// 1 2 3 4 5 6 7 8 9 10
// The number of non-zero elements in a upper triangular matrix is equal to n(n+1)/2
// where n is the number of rows or columns
// The index of an element A[i][j] in a upper triangular matrix is given by the formula
// index = j(j-1)/2 + i - 1
class UpperTriangular
{
	private:
		int *A;
		int n;
	public:
		UpperTriangular()
		{
			n = 2;
			A = new int[2];
		}
		UpperTriangular(int n)
		{
			this->n = n;
			A = new int[n * (n + 1) / 2];
		}
		~UpperTriangular()
		{
			delete[] A;
		}
		void Set(int i, int j, int x);
		int Get(int i, int j);
		void Display();
};
void UpperTriangular::Set(int i, int j, int x)
{
	if (i <= j)
	{
		A[j * (j - 1) / 2 + i - 1] = x;
	}
}
int UpperTriangular::Get(int i, int j)
{
	if (i <= j)
	{
		return A[j * (j - 1) / 2 + i - 1];
	}
	return 0;
}
void UpperTriangular::Display()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i <= j)
			{
				std::cout << A[j * (j - 1) / 2 + i - 1] << " ";
			}
			else
			{
				std::cout << "0 ";
			}
			std::cout << "\t";
		}
		std::cout << std::endl;
	}
}
// Symmetric Matrix
// What is a symmetric matrix?
// A symmetric matrix is a square matrix that is equal to its transpose
// A symmetric matrix can be represented using a one-dimensional array
// For example, the following symmetric matrix
// 1 2 3
// 2 4 5
// 3 5 6
// can be represented using the following array
// 1 2 4 3 5 6
// The number of non-zero elements in a symmetric matrix is equal to n(n+1)/2
// where n is the number of rows or columns
// The index of an element A[i][j] in a symmetric matrix is given by the formula
// index = i(i-1)/2 + j - 1
class Symmetric
{
	private:
		int *A;
		int n;
	public:
		Symmetric()
		{
			n = 2;
			A = new int[2];
		}
		Symmetric(int n)
		{
			this->n = n;
			A = new int[n * (n + 1) / 2];
		}
		~Symmetric()
		{
			delete[] A;
		}
		void Set(int i, int j, int x);
		int Get(int i, int j);
		void Display();
};
void Symmetric::Set(int i, int j, int x)
{
	if (i >= j)
	{
		A[i * (i - 1) / 2 + j - 1] = x;
	}
	else
	{
		A[j * (j - 1) / 2 + i - 1] = x;
	}
}
int Symmetric::Get(int i, int j)
{
	if (i >= j)
	{
		return A[i * (i - 1) / 2 + j - 1];
	}
	return A[j * (j - 1) / 2 + i - 1];
}
void Symmetric::Display()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i >= j)
			{
				std::cout << A[i * (i - 1) / 2 + j - 1] << " ";
			}
			else
			{
				std::cout << A[j * (j - 1) / 2 + i - 1] << " ";
			}
			std::cout << "\t";
		}
		std::cout << std::endl;
	}
}

// Tri-Diagonal and Tri-Band Matrix
// A tri-diagonal matrix is a special form of a band matrix where the non-zero elements are only present in the main diagonal and the diagonals immediately above and below the main diagonal
// A tri-diagonal matrix can be represented using a one-dimensional array
// For example, the following tri-diagonal matrix
// 1 2 0 0
// 3 4 5 0
// 0 6 7 8
// 0 0 9 10
// can be represented using the following array
// 2 5 8 1 4 7 10 3 6 9
// The number of non-zero elements in a tri-diagonal matrix is equal to 3n-2
// where n is the number of rows or columns
// The index of an element A[i][j] in a tri-diagonal matrix is given by the formula
// index = |i-j|
class TriDiagonal
{
	private:
		int *A;
		int n;
	public:
		TriDiagonal()
		{
			n = 2;
			A = new int[2];
		}
		TriDiagonal(int n)
		{
			this->n = n;
			A = new int[3 * n - 2];
		}
		~TriDiagonal()
		{
			delete[] A;
		}
		void Set(int i, int j, int x);
		int Get(int i, int j);
		void Display();
};
void TriDiagonal::Set(int i, int j, int x)
{
	if (i - j == 1)
	{
		A[i - 2] = x;
	}
	else if (i - j == 0)
	{
		A[n - 1 + i - 1] = x;
	}
	else if (i - j == -1)
	{
		A[2 * n - 1 + i - 1] = x;
	}
}
int TriDiagonal::Get(int i, int j)
{
	if (i - j == 1)
	{
		return A[i - 2];
	}
	else if (i - j == 0)
	{
		return A[n - 1 + i - 1];
	}
	else if (i - j == -1)
	{
		return A[2 * n - 1 + i - 1];
	}
	return 0;
}
void TriDiagonal::Display()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i - j == 1)
			{
				std::cout << A[i - 2] << " ";
			}
			else if (i - j == 0)
			{
				std::cout << A[n - 1 + i - 1] << " ";
			}
			else if (i - j == -1)
			{
				std::cout << A[2 * n - 1 + i - 1] << " ";
			}
			else
			{
				std::cout << "0 ";
			}
			std::cout << "\t";
		}
		std::cout << std::endl;
	}
}


int main()
{
	Diagonal d(4);
	d.Set(1, 1, 1);
	d.Set(2, 2, 2);
	d.Set(3, 3, 3);
	d.Set(4, 4, 4);
	d.Display();
	std::cout << std::endl;
	LowerTriangular lt(4);
	lt.Set(1, 1, 1);	
	lt.Set(2, 1, 2);
	lt.Set(2, 2, 3);
	lt.Set(3, 1, 4);
	lt.Set(3, 2, 5);
	lt.Set(3, 3, 6);
	lt.Set(4, 1, 7);
	lt.Set(4, 2, 8);
	lt.Set(4, 3, 9);
	lt.Set(4, 4, 10);
	lt.Display();
	std::cout << std::endl;
	UpperTriangular ut(4);
	ut.Set(1, 1, 1);
	ut.Set(1, 2, 2);
	ut.Set(1, 3, 3);
	ut.Set(1, 4, 4);
	ut.Set(2, 2, 5);
	ut.Set(2, 3, 6);
	ut.Set(2, 4, 7);
	ut.Set(3, 3, 8);
	ut.Set(3, 4, 9);
	ut.Set(4, 4, 10);
	ut.Display();
	std::cout << std::endl;
	Symmetric s(3);
	s.Set(1, 1, 1);
	s.Set(1, 2, 2);
	s.Set(1, 3, 3);
	s.Set(2, 2, 4);
	s.Set(2, 3, 5);
	s.Set(3, 3, 6);
	s.Display();
	std::cout << std::endl;
	TriDiagonal td(4);
	td.Set(1, 1, 1);
	td.Set(1, 2, 2);
	td.Set(2, 1, 3);
	td.Set(2, 2, 4);
	td.Set(2, 3, 5);
	td.Set(3, 2, 6);
	td.Set(3, 3, 7);
	td.Set(3, 4, 8);
	td.Set(4, 3, 9);
	td.Set(4, 4, 10);
	td.Display();

	return 0;
}
