#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Matrix {
    int** M;
    int rows;
    int cols;
    int sum;
public:
    Matrix() {
        rows = 0;
        cols = 0;
        M = nullptr;
        sum = 0;
    }

    Matrix(int n) {
        rows = n;
        cols = n;
        sum = 0;
        M = new int*[rows];
        for (int i = 0; i < rows; i++) {
            M[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                if (i == j) M[i][j] = 1;
                else M[i][j] = 0;
            }
        }
    }

    Matrix(int r, int c) {
        rows = r;
        cols = c;
        sum = 0;
        M = new int*[rows];
        for (int i = 0; i < rows; i++) {
            M[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                M[i][j] = 0;
            }
        }
    }

    void Input() {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> M[i][j];
    }

    void RandomFill() {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                M[i][j] = rand() % 10;
    }

    void FillByFormula() {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                M[i][j] = i * j;
    }

    void Print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << M[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }

    void CalculateSum() {
        sum = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                sum += M[i][j];
        cout << sum << endl;
    }

    ~Matrix() {
        if (M != nullptr) {
            for (int i = 0; i < rows; i++)
                delete[] M[i];
            delete[] M;
        }
    }
};

int main() {
    srand(time(0));

    Matrix M1;
    Matrix M2(3);
    Matrix M3(3,4);
    Matrix M4(2,3);

    M2.Print();
    M3.Print();
    M4.Print();

    M2.FillByFormula();
    M2.Print();

    M3.RandomFill();
    M3.Print();

    M4.Input();
    M4.Print();

    M3.CalculateSum();

    return 0;
}