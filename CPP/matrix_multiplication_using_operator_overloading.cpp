#include<iostream>

using namespace std;
class Matrix
{
    int rows, columns, matrix[100][100];
    public:
        Matrix(int r, int c)
        {
            rows = r;
            columns = c;
        }
        void readMatrix()
        {
            cout<<"Enter matrix elements: ";
            for (int i = 0; i < rows ; ++i)
            {
                for(int j = 0; j < columns; ++j)
                {
                    cin>>matrix[i][j];
                }
            }
        }
        void display()
        {
            for(int i = 0; i < rows; ++i)
            {
                for(int j = 0; j < columns ; ++j)
                {
                    cout<<matrix[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        Matrix operator +( Matrix other)
        {
            if(rows!=other.rows || columns != other.columns)
            {
                cout<<"Invalid";
            }
            else
            {
                Matrix result(rows, columns);
                for(int i = 0; i < rows; ++i)
                {
                    for(int j = 0; j < columns; ++j)
                    {
                        result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
                    }
                }
                return result;
            }
        }
};

int main()
{
    int rows1, columns1;
    cout<<"Enter number of rows: ";
    cin>>rows1;
    cout<<"Enter number of columns: ";
    cin>>columns1;

    Matrix mat1(rows1, columns1);
    mat1.readMatrix();
    int rows2, columns2;
    cout<<"Enter number of rows: ";
    cin>>rows2;
    cout<<"Enter number of columns: ";
    cin>>columns2;
    Matrix mat2(rows2, columns2);


    mat2.readMatrix();

    Matrix result = mat1 + mat2;

    result.display();
    return 0;
}
