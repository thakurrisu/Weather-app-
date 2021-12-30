#include<iostream>
using namespace std;

void add_mat()
{
	int row, col, i, j;
	int m1[10][10], m2[10][10], sum[10][10];
	cout << "Enter number of  rows and column for matrix:";
	cin >> row >> col;
	cout << "Enter the " << row * col << "element of first matrix:";
	 for(i=0;i<row;i++)
	   {
		 for (j = 0; j < col; j++)
		  {
			 cin >> m1[i][j];
		  }
	   }
    cout << "Enter the " << row * col << "element of second matrix:";
	 for (i = 0; i < row; i++)
	 {
		 for (j = 0; j < col; j++)
		 {
			 cin >> m2[i][j];
		 }
	 }
	 for (i = 0; i < row; i++)
	 {
		 for (j = 0; j < col; j++)
		 {
			 sum[i][j] = m1[i][j] + m2[i][j];
		 }
	 }

	 cout << "\n The sum of matrix is :\n";
	 for (i = 0; i < row; i++)
	 {
		 for (j = 0; j < col; j++)
		 {
			 cout << sum[i][j]<<" ";

		 }
		 cout << endl;
	 }

}

void mul_mat()
{
	int row1, col1, row2, col2, i, j, k;
	int m1[10][10], m2[10][10], mul[10][10];
	cout << "Enter then  rows and column for first matrix:";
	cin >> row1 >> col1;
	cout << "Enter the rows and column for second matrix:";
	cin >> row2 >> col2;

	if (col1 == row2)
	{
		cout << "Enter the " << row1 * col1 << "element for first matrix:";
		for (i = 0; i < row1; i++)
		{
			for (j = 0; j < col1; j++)
			{
				cin >> m1[i][j];
			}
		}
		cout << "Enter the " << row2 * col2 << "element for second matrix:";
		for (i = 0; i < row2; i++)
		{
			for (j = 0; j < col2; j++)
			{
				cin >> m2[i][j];
			}
		}

		cout << "Entered Matrix are:\n";
		cout << "first matrix:";
		for (i = 0; i < row1; i++)
		{
			for (j = 0; j < col1; j++)
			{
				cout << m1[i][j] << " ";
			}
			cout << endl;
        }
		cout << "Second matrix:";
		for (i = 0; i < row2; i++)
		{
			for (j = 0; j < col2; j++)
			{
				cout << m2[i][j] << " ";
			}
			cout << endl;
		}
		for (i = 0; i < row1; i++)
		{
			for (j = 0; j < col2; j++)
			{
				mul[i][j] = 0;
				for (k = 0; k < col1; k++)
				{
					mul[i][j] = mul[i][j] + (m1[i][k] * m2[k][j]);
				 }
			}
		}
		cout << "product matrix is :\n";
		for (i = 0; i < row1; i++)
		{
			for (j = 0; j < col2; j++)
			{
				cout << mul[i][j] << " ";
			}
			cout << endl;
		}
	}
	 else
	   {
		cout << "Multiplication can not be proceed";
	   }
}

void trans_mat()
{
	int i, j;
	int m[10][10], trans[10][10], row, col;
	cout << "Enter the number of rows and column:";
	cin >> row >> col;
	cout << "Enter " << row * col << "Matrix element :\n";
	for (i = 0; i < row ; i++)
	{
		for (j = 0; j < col; j++)
		{
			cin >> m[i][j];

		}
	 }
	cout << "Entered Matrix is :\n";
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			cout << m[i][j]<<" ";
		}
		cout << endl;
	}
	
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < row; j++)
		{
			trans[j][i] = m[i][j];

		}
	}
	cout << "Matrix after transpose:\n";
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			cout << trans[i][j] << " ";
		}
		cout << endl;
    }
}

int main()
{
	int choice;
	cout << "\n What do you want to do:\n";
	cout << "1.Addition" << endl;
	cout << "2.Multiplication" << endl;
	cout << "3.Transpose" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1: add_mat();
		    break;
	case 2: mul_mat();
		    break;
	case 3: trans_mat();
		    break;
	default:cout << "invalid choice!";
		break;
	}
return 0;
}


