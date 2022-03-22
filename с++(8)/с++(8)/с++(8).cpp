#include <iostream>


int view(int arr[], int n, int max) {

    int finish = 7;

    if (n == finish - 1) {
        return 0;
    }

    else
    {

        if (max < arr[n + 1]) {
            max = arr[n + 1];
            return 1 + view(arr, n + 1, max);
            std::cout << "+ " << n << "\n";
        }
        else {
            return 0 + view(arr, n + 1, max);
            std::cout << "- " << n << "\n";
        }
    }

}


int main()
{
    int arr[7] = {5, 12, 20, 39, 45, 89 };
    std::cout << view(arr, 0, arr[0]);
}