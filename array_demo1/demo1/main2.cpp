#include<iostream>

int sum(int arr[], int len);

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::cout << "sizeof: " << sizeof arr << std::endl;
    int arr_size = sizeof arr/ sizeof(int);
    sum(arr, arr_size);
    return 0;
}

int sum(int arr[], int len) {
    int total = 0;
    std::cout << "sizeof: " << sizeof arr << std::endl;
    for (int i = 0; i < len; i++)
        total += arr[i];
    return total;
}