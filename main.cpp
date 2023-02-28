
#include <iostream>
using namespace std;
void shift_right(int** arr, int m, int n, int k) {
    k = k % n;
    for (int i = 0; i < m; i++) {
        for (int j = n - 1; j >= k; j--) {
            swap(arr[i][j], arr[i][j - k]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void shift_left(int** arr, int m, int n, int k) {
    k = k % n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - k; j++) {
            swap(arr[i][j], arr[i][j + k]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void shift_down(int** arr, int m, int n, int k) {
    k = k % m;
    for (int j = 0; j < n; j++) {
        for (int i = m - 1; i >= k; i--) {
            swap(arr[i][j], arr[i - k][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void shift_up(int** arr, int m, int n, int k) {
    k = k % m;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m - k; i++) {
            swap(arr[i][j], arr[i + k][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}
int main() {
    int rows,col,k;
    cout << "Enter rows: ";
    cin>> rows;
    cout << "Enter columns: ";
    cin>> col;
    cout << "Enter the shift amount: ";
    cin>> k;
    void (*func[4])(int**, int, int, int)={shift_right, shift_left, shift_down, shift_up};
    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[col];
        for (int j = 0; j < col; j++) {
            arr[i][j] = i * col + j + 1;
        }
    }
    cout << "Initial matrix:" <<endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    string side;
    cout <<"Enter side to shift(right/left/up/down): ";
    cin >> side;
    if(side == "right"){
        func[0](arr,rows,col,k);
    }
    else if(side == "left"){
        func[1](arr,rows,col,k);
    }
    else if(side == "down"){
        func[2](arr,rows,col,k);
    }
    else if(side == "up"){
        func[3](arr,rows,col,k);
    }
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}