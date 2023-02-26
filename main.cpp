
#include <iostream>
#include <ctime>

using namespace std;

template <typename T>
T* init_array(size_t size)
{
    T* arr = new T[size];
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = T(rand() % 150);
    }
    return arr;
}

template <typename T>
void avg_array(T* arr, T* arr2, int size = -1, int size2 = -1)
{
    int sum = 0;
    if (size == -1)
    {
        size = _msize(arr) / sizeof * arr;
    }
    if (size2 == -1)
    {
        size2 = _msize(arr2) / sizeof * arr2;
    }
    for (size_t i = 0; i < size; i++)
    {
        sum += *(arr+i);
    }
    for (size_t i = 0; i < size2; i++)
    {
        sum += *(arr2+i);
    }
    double avg = static_cast<double>(sum) / (size + size2);
    cout << "AVG: "<< avg << endl;
}

template <typename T>
void max_array(T* arr, T* arr2, int size = -1, int size2 = -1)
{
    int max = *arr;
    if (size == -1)
    {
        size = _msize(arr) / sizeof * arr;
    }
    if (size2 == -1)
    {
        size2 = _msize(arr2) / sizeof * arr2;
    }
    for (size_t i = 0; i < size; i++)
    {
        if(*(arr+i) > max)
        {
            max = *(arr+i);
        }
    }
    for (size_t i = 0; i < size2; i++)
    {
        if(*(arr2+i) > max)
        {
            max = *(arr2+i);
        }
    }
    cout << "Max: "<< max << endl;
}

template <typename T>
T* min_array(T* arr,T* arr2,int size =-1, int size2 =-1)
{
    int* min = new int(150);
    if (size == -1)
    {
        size = _msize(arr) / sizeof * arr;
    }
    if (size2 == -1)
    {
        size2 = _msize(arr2) / sizeof * arr2;

    }
    for (size_t i = 0; i < size; i++)
    {
        if(*(arr+i) < *min)
        {
            *min = *(arr+i);
        }
    }
    for (size_t i = 0; i < size2; i++)
    {
        if(*(arr2+i) < *min)
        {
            *min = *(arr2+i);
        }
    }
    cout << "Min: "<< *min;
}
template <typename T>
T* Action(T* arr,T* arr2,int size =-1, int size2 =-1){
    if (size == -1)
    {
        size = _msize(arr) / sizeof * arr;
    }
    cout << "A: ";
    for (size_t i = 0; i < size; i++)
    {
        cout << *(arr + i) << "  ";
    }

    if (size2 == -1)
    {
        size2 = _msize(arr2) / sizeof * arr2;

    }
    cout << endl<<"B: ";
    for (size_t i = 0; i < size2; i++)
    {
        cout << *(arr2 + i) << "  ";
    }
    cout << endl;
}

int main()
{
    srand(time(0));

    cout << "Enter size for A: ";
    int size;
    cin >> size;
    int* arr_i = init_array<int>(size);

    cout << "Enter size for B: ";
    int size2;
    cin >> size2;
    int* arr_i2 = init_array<int>(size2);

    cout << "==================================" << endl;
    Action(arr_i,arr_i2);
    cout << "==================================" << endl;
    cout <<endl<<"===============MENU==============="<<endl;

    string action;
    char answer;
    do{
        cout <<"Select an action(max,min,avg): ";
        cin>> action;
        if(action != "max" ^ action != "min" ^ action != "avg"){
            cout <<"Error! Write max or min or avg."<<endl;
        }
        if(action == "max"){
            max_array(arr_i,arr_i2);
        }
        else if(action =="min"){
            min_array(arr_i,arr_i2);
        }
        else if(action =="avg"){
            avg_array(arr_i,arr_i2);
        }
        cout <<endl <<"Do u want try again?(y/n): ";

        cin>> answer;
        if(answer == 'y'){
            continue;
        }
        else if(answer == 'n'){
            break;
        }
    } while (action != "max" ^ action != "min" ^ action != "avg" || answer != 'n' ^ answer != 'y');

    delete[] arr_i;
    delete[] arr_i2;
    return 0;
}