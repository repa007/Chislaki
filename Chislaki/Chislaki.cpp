
#include "conio.h"
#include "math.h"
#include "iostream"
using namespace std;

int n, matrix_size;
double znamenatel;
double A[100][100]; //matrica koefficientov
double B[100]; //matrica svobodnih chlenov
double U[100];
double X[100]; //na vivod
double V[100];

int main()
{
    matrix_size = 100; //razmernost matrici

    //vvod znacheniy...
    //zapolnim nolikami
    for (int i = 0; i < matrix_size; i++)
        for (int j = 0; j < matrix_size; j++)
            A[i][j] = 0;

    //rasstavim b
    int k = 0;
    for (int i = 0; i < matrix_size; i++)
    {
        A[i][k] = 2;
        k++;
    }

    //rasstavim c
    k = 1;
    for (int i = 0; i < matrix_size - 1; i++)
    {
        A[i][k] = 1;
        k++;
    }

    //rasstavim a
    k = 0;
    for (int i = 1; i < matrix_size; i++)
    {
        A[i][k] = 1;
        k++;
    }

    //rasstavim d
    for (int i = 0; i < matrix_size; i++)
        B[i] = 90;  //variant 9



    cout << "Matrix A:" << endl;
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
            cout << A[i][j] << "\t ";
        cout << endl;
    }



    cout << "Matrix B:" << endl;
    for (int i = 0; i < matrix_size; i++)
        cout << B[i] << endl;




    n = matrix_size - 1;  //eto ne ta "n" iz formuli
    U[0] = -A[0][1] / A[0][0];
    V[0] = B[0] / A[0][0];

    for (int i = 1; i < n; i++)
    {
        znamenatel = A[i][i] + A[i][i - 1] * U[i - 1];
        U[i] = -A[i][i + 1] / znamenatel;
        V[i] = (B[i] - A[i][i - 1] * V[i - 1]) / znamenatel;
    }

    X[n] = (B[n] - A[n][n - 1] * V[n - 1]) / (A[n][n] + A[n][n - 1] * U[n - 1]);

    for (int i = n - 1; i >= 0; i--)
        X[i] = U[i] * X[i + 1] + V[i];

    cout << "Matrix X:" << endl;
    for (int i = 0; i < matrix_size; i++)
        cout << X[i] << endl;

    return 0;
}
