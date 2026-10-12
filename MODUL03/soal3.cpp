#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarIsiArray(int arr1[3][3], int arr2[3][3], int row, int col){
    int temp = arr1[row][col];
    arr1[row][col] = arr2[row][col];
    arr2[row][col] = temp;
}

void tukarPointer(int *ptr1, int *ptr2){
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main(){
    int array1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int array2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    int var1 = 15, var2 = 50;
    int *p1 = &var1;
    int *p2 = &var2;

    cout << "=== SEBELUM DITUKAR ===" << endl;
    cout << "Array 1:" << endl;
    tampilArray(array1);
    cout << "Array 2:" << endl;
    tampilArray(array2);
    tukarIsiArray(array1, array2, 1, 1);

    cout << "\n=== SESUDAH ARRAY DITUKAR (Posisi [1][1]) ===" << endl;
    cout << "Array 1:" << endl;
    tampilArray(array1);
    cout << "Array 2:" << endl;
    tampilArray(array2);

    cout << "\n-----------------------------------" << endl;

    cout << "=== SEBELUM POINTER DITUKAR ===" << endl;
    cout << "Isi P1 = " << *p1 << ", Isi P2 = " << *p2 << endl;
    
    tukarPointer(p1, p2);

    cout << "\n=== SESUDAH POINTER DITUKAR ===" << endl;
    cout << "Isi P1 = " << *p1 << ", Isi P2 = " << *p2 << endl;

    return 0;
}