



#include <iostream>
#include <ctime>

using namespace std;

template <typename T>
T** init_array(size_t rows, size_t cols)
{
    T** arr = new T*[rows];
    for (size_t i = 0; i < rows; i++)
    {
        arr[i] = new T[cols];
        for (size_t j = 0; j < cols; j++)
        {
            arr[i][j] = -10 + T(rand() % 50);
        }
    }
    return arr;
}


template <typename T>
void print_array(T** arr, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}


template<typename T>
bool removearr(T** &arr, size_t &rows, size_t &cols, size_t num_rows, size_t num_cols ,size_t index){
    if (index < 0 || index >= cols) {
        return false;
    }
    int end_index = index + num_cols;
    if (end_index > cols) {
        num_cols = cols - index;
        end_index = cols;
    }
    size_t old_cols = cols;
    cols -= num_cols;
    rows = num_rows;
    T** buffer = new T*[rows];

    for (size_t i = 0; i < rows; i++) {
        buffer[i] = new T[cols];
    }

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < index; j++) {
            buffer[i][j] = arr[i][j];
        }
        for (size_t j = index + num_cols; j < old_cols; j++) {
            buffer[i][j - num_cols] = arr[i][j];
        }
    }

    for (size_t i = 0; i < rows; i++) {
        delete[] arr[i];
    }

    delete[] arr;
    arr = buffer;
    return true;
}

int main()
{
    srand(time(0));

    cout << "Enter number of rows for the array: ";
    size_t rows;
    cin >> rows;
    cout << "Enter number of columns for the array: ";
    size_t cols;
    cin >> cols;
    int** arr_i = init_array<int>(rows, cols);
    cout << "==================================" << endl;
    cout << "Array: " << endl;
    print_array<int>(arr_i, rows, cols);
    cout << "==================================" << endl;
    cout << "Enter size of rows for the remove numbers: ";
    size_t new_rows;
    cin >> new_rows;
    int index;
    cout << "Enter the index to insert items: ";
    cin >> index;
    cout << "==================================" << endl;
    cout << "Result: "<<endl;
    removearr(arr_i, rows, cols, new_rows,cols, index);

    print_array(arr_i,rows,cols);

    delete[] arr_i;

    return 0;
}