//============================================================================
// Name        : Matrix.h
// Author      : Bharadwaj Krishnan
// Version     : -
// Copyright   : Your copyright notice
// Description : Template class for a Matrix
//============================================================================

#ifndef HELPER_MATRIX_H_
#define HELPER_MATRIX_H_

#include <iostream>
#include <cmath>

#include <vector>
using namespace std;

template<class T, int ROWS, int COLUMNS>
class Matrix
{
private:
	vector<vector<T> > m_data;

public:
	Matrix()
	{
		vector<T> column;
		for(int i = 0; i < COLUMNS; i++)
		{
			column.push_back(0);
		}

		for(int i=0; i < ROWS; i++)
		{
			m_data.push_back(column);
		}
	}

	void change_data(T data, int row, int col)
	{
		this->m_data[row][col] = data;
	}

	void set_Identity()
	{
		for(int row = 0; row < this->get_number_of_rows(); row++)
		{
			for(int col = 0; col < this->get_number_of_columns(); col++)
			{
				if(row == col)
					this->m_data[row][col] = 1;
				else
					this->m_data[row][col] = 0;
			}
		}
	}

	T get_data(int row, int col)
	{
		return m_data[row][col];
	}

	void set_data(T data, int row, int col)
	{
		m_data[row][col] = data;
	}

	// Get number of rows
	int get_number_of_rows()
	{
		return ROWS;
	}

	// Get number of columns
	int get_number_of_columns()
	{
		return COLUMNS;
	}

	void transpose()
	{
		vector<vector<T> > copy_data;
		copy_data.assign(m_data.begin(), m_data.end());

		m_data.clear();

		vector<T> transpose_data;

		for(int j = 0; j < this->get_number_of_columns(); j++)
		{
			for(int i = 0; i < this->get_number_of_rows(); i++)
			{
				transpose_data.push_back(copy_data[i][j]);
			}

			m_data.push_back(transpose_data);

			transpose_data.clear();
		}
	}

	// Print the vector data
	void print()
	{
		typename vector<T>::iterator itr;

		for(int i = 0; i < ROWS; i++)
		{
			cout<< "[";
			for(itr = this->m_data[i].begin(); itr != this->m_data[i].end(); itr++)
			{
				cout << *itr <<" ";
			}

			cout<< "]" <<endl;
		}
	}

	vector<vector<T> > operator*(Matrix<float, 4, 1> matrix)
	{
		vector<vector<T> > prod;
		vector<T> row;
		if(this->get_number_of_columns() == matrix.get_number_of_rows())
		{
			typename vector<T>::iterator itr;

			for(int j = 0; j < this->get_number_of_rows(); j++)
			{
				for(itr = this->m_data[j].begin(); itr != this->m_data[j].end(); itr++)
				{
					float sum = 0;
					for(int i = 0; i < this->get_number_of_rows(); i++)
					{
						sum += itr[i] * matrix.get_data(i, 0);
					}
					row.push_back(sum);
				}
				prod.push_back(row);
				row.clear();
			}
		}
		else
		{
			// Do nothing
		}

		return prod;
	}

	vector<vector<T> > operator*(Matrix<float, 4, 4> matrix)
	{
		vector<vector<T> > prod;

		vector<T> row;
		if(this->get_number_of_columns() == matrix.get_number_of_rows())
		{
			for(int i = 0; i < this->get_number_of_rows(); i++)
			{
				for(int j = 0; j < matrix.get_number_of_columns(); j++)
				{
					float sum = this->get_data(i, 0) * matrix.get_data(0, j) + this->get_data(i, 1) * matrix.get_data(1, j)
							+ this->get_data(i, 2) * matrix.get_data(2, j) + this->get_data(i, 3) * matrix.get_data(3, j);

					row.push_back(sum);
				}
				prod.push_back(row);
				row.clear();
			}

		}
		else
		{
			// Do nothing
		}
		return prod;
	}

	vector<vector<T> > operator+(Matrix<float, 4, 4> matrix)
	{
		vector<vector<T> > sum;

		vector<T> row;
		if((this->get_number_of_rows() == matrix.get_number_of_rows()) && (this->get_number_of_columns() == matrix.get_number_of_columns()))
		{
			for(int i = 0; i < this->get_number_of_rows(); i++)
			{
				for(int j = 0; j < this->get_number_of_columns(); j++)
				{
					row.push_back(this->get_data(i, j) + matrix.get_data(i, j));
				}
				sum.push_back(row);
				row.clear();
			}
		}
		else
		{
			// Do nothing
		}

		return sum;

	}

	vector<vector<T> > operator+(Matrix<float, 4, 1> matrix)
	{
		vector<vector<T> > sum;

		vector<T> row;
		if((this->get_number_of_rows() == matrix.get_number_of_rows()) && (this->get_number_of_columns() == matrix.get_number_of_columns()))
		{
			for(int i = 0; i < this->get_number_of_rows(); i++)
			{
				for(int j = 0; j < this->get_number_of_columns(); j++)
				{
					row.push_back(this->get_data(i, j) + matrix.get_data(i, j));
				}
				sum.push_back(row);
				row.clear();
			}
		}
		else
		{
			// Do nothing
		}

		return sum;

	}

	template<typename X>
	vector<vector<T> > operator-(X matrix)
	{
		vector<vector<T> > difference;

		vector<T> row;
		if((this->get_number_of_rows() == matrix.get_number_of_rows()) && (this->get_number_of_columns() == matrix.get_number_of_columns()))
		{
			for(int i = 0; i < this->get_number_of_rows(); i++)
			{
				for(int j = 0; j < this->get_number_of_columns(); j++)
				{
					row.push_back(this->get_data(i, j) - matrix.get_data(i, j));
				}
				difference.push_back(row);
				row.clear();
			}
		}
		else
		{
			// Do nothing
		}

		return difference;

	}

	template<typename U>
	void operator=(U matrix)
	{
		for(int row = 0; row < this->get_number_of_rows(); row++)
		{
			for(int col = 0; col < this->get_number_of_columns(); col++)
			{
				this->m_data[row][col] = matrix[row][col];
			}
		}
	}

	vector<vector<T> > inverse()
	{
		float det_1 = (m_data[1][1] * m_data[2][2] * m_data[3][3]) + (m_data[1][2] * m_data[2][3] * m_data[3][1]) + (m_data[1][3] * m_data[2][1] * m_data[3][2])
				- (m_data[1][3] * m_data[2][2] * m_data[3][1]) - (m_data[1][2] * m_data[2][1] * m_data[3][3]) - (m_data[1][1] * m_data[2][3] * m_data[3][2]);

		float det_2 = (m_data[0][1] * m_data[2][2] * m_data[3][3]) + (m_data[0][2] * m_data[2][3] * m_data[3][2]) + (m_data[0][3] * m_data[2][1] * m_data[3][2])
				- (m_data[0][3] * m_data[2][2] * m_data[3][1]) - (m_data[0][2] * m_data[2][1] * m_data[3][3]) - (m_data[0][1] * m_data[2][3] * m_data[3][2]);

		float det_3 = (m_data[0][1] * m_data[1][2] * m_data[3][3]) + (m_data[0][2] * m_data[1][3] * m_data[3][1]) + (m_data[0][3] * m_data[1][1] * m_data[3][2])
				- (m_data[0][3] * m_data[1][2] * m_data[3][1]) - (m_data[0][2] * m_data[1][1] * m_data[3][3]) - (m_data[0][1] * m_data[1][3] * m_data[3][2]);

		float det_4 = (m_data[0][1] * m_data[1][2] * m_data[2][3]) + (m_data[0][2] * m_data[1][3] * m_data[2][1]) + (m_data[0][3] * m_data[1][1] * m_data[2][2])
				- (m_data[0][3] * m_data[1][2] * m_data[2][1]) - (m_data[0][2] * m_data[1][1] * m_data[2][3]) - (m_data[0][1] * m_data[1][3] * m_data[2][2]);

		float determinant = (m_data[0][0] * det_1) - (m_data[1][0] * det_2) + (m_data[2][0] * det_3) - (m_data[3][0] * det_4);

		vector<vector<T> > matrix;
		vector<T> row;
		float a_11 = (m_data[1][1] * m_data[2][2] * m_data[3][3]) + (m_data[1][2] * m_data[2][3] * m_data[3][1]) + (m_data[1][3] * m_data[2][1] * m_data[3][2])
				- (m_data[1][3] * m_data[2][2] * m_data[3][1]) - (m_data[1][2] * m_data[2][1] * m_data[3][3]) - (m_data[1][1] * m_data[2][3] * m_data[3][2]);
		float a_12 = -(m_data[0][1] * m_data[2][2] * m_data[3][3]) - (m_data[0][2] * m_data[2][3] * m_data[3][1]) - (m_data[0][3] * m_data[2][1] * m_data[3][2])
				+ (m_data[0][3] * m_data[2][2] * m_data[3][1]) + (m_data[0][2] * m_data[2][1] * m_data[3][3]) + (m_data[0][1] * m_data[2][3] * m_data[3][2]);
		float a_13 = (m_data[0][1] * m_data[1][2] * m_data[3][3]) + (m_data[0][2] * m_data[1][3] * m_data[3][1]) + (m_data[0][3] * m_data[1][1] * m_data[3][2])
				- (m_data[0][3] * m_data[1][2] * m_data[3][1]) - (m_data[0][2] * m_data[1][1] * m_data[3][3]) - (m_data[0][1] * m_data[1][3] * m_data[3][2]);
		float a_14 = -(m_data[0][1] * m_data[1][2] * m_data[2][3]) - (m_data[0][2] * m_data[1][3] * m_data[2][1]) - (m_data[0][3] * m_data[1][1] * m_data[2][2])
				+ (m_data[0][1] * m_data[1][2] * m_data[2][1]) + (m_data[0][2] * m_data[1][1] * m_data[2][3]) + (m_data[0][1] * m_data[1][3] * m_data[2][2]);
		row.push_back(abs(a_11/determinant) < 0.0005 ? 0.000: a_11/determinant);
		row.push_back(abs(a_12/determinant) < 0.0005 ? 0.000: a_12/determinant);
		row.push_back(abs(a_13/determinant) < 0.0005 ? 0.000: a_13/determinant);
		row.push_back(abs(a_14/determinant) < 0.0005 ? 0.000: a_14/determinant);
		matrix.push_back(row);
		row.clear();

		float a_21 = -(m_data[1][0] * m_data[2][2] * m_data[3][3]) - (m_data[1][2] * m_data[2][3] * m_data[3][0]) - (m_data[1][3] * m_data[2][0] * m_data[3][2])
				+ (m_data[1][3] * m_data[2][2] * m_data[3][0]) + (m_data[1][2] * m_data[2][0] * m_data[3][3]) + (m_data[1][0] * m_data[2][3] * m_data[3][2]);
		float a_22 = (m_data[0][0] * m_data[2][2] * m_data[3][3]) + (m_data[0][2] * m_data[2][3] * m_data[3][0]) + (m_data[0][3] * m_data[2][0] * m_data[3][2])
				- (m_data[0][3] * m_data[2][2] * m_data[3][0]) - (m_data[0][2] * m_data[2][0] * m_data[3][3]) - (m_data[0][0] * m_data[2][3] * m_data[3][2]);
		float a_23 = -(m_data[0][0] * m_data[1][2] * m_data[3][3]) - (m_data[0][2] * m_data[1][3] * m_data[3][0]) - (m_data[0][3] * m_data[1][0] * m_data[3][2])
				+ (m_data[0][3] * m_data[1][2] * m_data[3][0]) + (m_data[0][2] * m_data[1][0] * m_data[3][3]) + (m_data[0][0] * m_data[1][3] * m_data[3][2]);
		float a_24 = (m_data[0][0] * m_data[1][2] * m_data[2][3]) + (m_data[0][2] * m_data[1][3] * m_data[2][0]) + (m_data[0][3] * m_data[1][0] * m_data[2][2])
				- (m_data[0][3] * m_data[1][2] * m_data[2][0]) - (m_data[0][2] * m_data[1][0] * m_data[2][3]) - (m_data[0][0] * m_data[1][3] * m_data[2][2]);
		row.push_back(abs(a_21/determinant) < 0.0005 ? 0.000: a_21/determinant);
		row.push_back(abs(a_22/determinant) < 0.0005 ? 0.000: a_22/determinant);
		row.push_back(abs(a_23/determinant) < 0.0005 ? 0.000: a_23/determinant);
		row.push_back(abs(a_24/determinant) < 0.0005 ? 0.000: a_24/determinant);
		matrix.push_back(row);
		row.clear();

		float a_31 = (m_data[1][0] * m_data[2][1] * m_data[3][3]) + (m_data[1][1] * m_data[2][3] * m_data[3][0]) + (m_data[1][3] * m_data[2][0] * m_data[3][1])
				- (m_data[1][3] * m_data[2][1] * m_data[3][0]) - (m_data[1][1] * m_data[2][0] * m_data[3][3]) - (m_data[1][0] * m_data[2][3] * m_data[3][1]);
		float a_32 = -(m_data[0][0] * m_data[2][1] * m_data[3][3]) - (m_data[0][1] * m_data[2][3] * m_data[3][0]) - (m_data[0][3] * m_data[2][0] * m_data[3][1])
				+ (m_data[0][3] * m_data[2][1] * m_data[3][0]) + (m_data[0][1] * m_data[2][0] * m_data[3][3]) + (m_data[0][0] * m_data[2][3] * m_data[3][1]);
		float a_33 = (m_data[0][0] * m_data[1][1] * m_data[3][3]) + (m_data[0][1] * m_data[1][3] * m_data[3][0]) + (m_data[0][3] * m_data[1][0] * m_data[3][1])
				- (m_data[0][3] * m_data[1][1] * m_data[3][0]) - (m_data[0][1] * m_data[1][0] * m_data[3][3]) - (m_data[0][0] * m_data[1][3] * m_data[3][1]);
		float a_34 = -(m_data[0][0] * m_data[1][1] * m_data[2][3]) - (m_data[0][1] * m_data[1][3] * m_data[2][0]) - (m_data[0][3] * m_data[1][0] * m_data[2][1])
				+ (m_data[0][3] * m_data[1][1] * m_data[2][0]) + (m_data[0][1] * m_data[1][0] * m_data[2][3]) + (m_data[0][0] * m_data[1][3] * m_data[2][1]);
		row.push_back(abs(a_31/determinant) < 0.0005 ? 0.000: a_31/determinant);
		row.push_back(abs(a_32/determinant) < 0.0005 ? 0.000: a_32/determinant);
		row.push_back(abs(a_33/determinant) < 0.0005 ? 0.000: a_33/determinant);
		row.push_back(abs(a_34/determinant) < 0.0005 ? 0.000: a_34/determinant);
		matrix.push_back(row);
		row.clear();

		float a_41 = -(m_data[1][0] * m_data[2][1] * m_data[3][2]) - (m_data[1][1] * m_data[2][2] * m_data[3][0]) - (m_data[1][2] * m_data[2][0] * m_data[3][1])
				+ (m_data[1][2] * m_data[2][1] * m_data[3][0]) + (m_data[1][1] * m_data[2][0] * m_data[3][2]) + (m_data[1][0] * m_data[2][2] * m_data[3][1]);
		float a_42 = (m_data[0][0] * m_data[2][1] * m_data[3][2]) + (m_data[0][1] * m_data[2][2] * m_data[3][0]) + (m_data[0][2] * m_data[2][0] * m_data[3][1])
				- (m_data[0][2] * m_data[2][1] * m_data[3][0]) - (m_data[0][1] * m_data[2][0] * m_data[3][2]) - (m_data[0][0] * m_data[2][2] * m_data[3][1]);
		float a_43 = -(m_data[0][0] * m_data[1][1] * m_data[3][2]) - (m_data[0][1] * m_data[1][2] * m_data[3][0]) - (m_data[0][2] * m_data[1][0] * m_data[3][1])
				+ (m_data[0][2] * m_data[1][1] * m_data[3][0]) + (m_data[0][1] * m_data[1][0] * m_data[3][2]) + (m_data[0][0] * m_data[1][2] * m_data[3][1]);
		float a_44 = (m_data[0][0] * m_data[1][1] * m_data[2][2]) + (m_data[0][1] * m_data[1][2] * m_data[2][0]) + (m_data[0][2] * m_data[1][0] * m_data[2][1])
				- (m_data[0][2] * m_data[1][1] * m_data[2][0]) - (m_data[0][1] * m_data[1][0] * m_data[2][2]) - (m_data[0][0] * m_data[1][2] * m_data[2][1]);
		row.push_back(abs(a_41/determinant) < 0.0005 ? 0.000: a_41/determinant);
		row.push_back(abs(a_42/determinant) < 0.0005 ? 0.000: a_42/determinant);
		row.push_back(abs(a_43/determinant) < 0.0005 ? 0.000: a_43/determinant);
		row.push_back(abs(a_44/determinant) < 0.0005 ? 0.000: a_44/determinant);
		matrix.push_back(row);
		row.clear();

		return matrix;
	}

};



#endif /* HELPER_MATRIX_H_ */
