#include <iostream>
#include <array>
#include <chrono>
#include <fstream>
using namespace std;

// Binary Search code, entering an int x, an array a of size n, low as the beginning and high as the end.
int binary_search(int x, std::array<int, 10> a, int low, int high) {
    if (a.size() == 1) {
        if (a[0] == x) {
            return 0;
        } else {
            return -1;
        }
    } else {
        int m = low + (high - low) / 2;
        if (a[m] == x) {
            return m;
        } else if (x < a[m]) {
            return binary_search(x, a, low, m - 1);
        } else {
            return binary_search(x, a, m + 1, high);
        }
    }
}

int ternary_search(int x, std::array<int, 10> a, int low, int high) {
    if (a.size() == 1) {
        if (a[0] == x) {
            return 0;
        } else {
            return -1;
        }
    } else {
        int m1 = low + (high - low) / 3;
        int m2 = high - (high - low) / 3;
        if (a[m1] == x) {
            return m1;
        } else if ((a[m2] == x)) {
        } else if (x < a[m1]) {
            return binary_search(x, a, low, m1 - 1);
        } else if (x < a[m2]) {
            return binary_search(x, a, m1 + 1, m2 - 1);
        } else {
            return binary_search(x, a, m2 + 1, high);
        }
    }
    return -1;
}

int main() {
    ofstream myfile;
    myfile.open("data.txt", std::ios::out | std::ios::app);
    std::array<int, 10> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    time_t current_time = time(NULL);
    srand((unsigned)time(NULL));
    int x = rand() % 10;

    auto start = std::chrono::high_resolution_clock::now();
    std::cout << binary_search(x, a, 0, a.size()) << std::endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "binary: " << duration.count() << std::endl;
    myfile << "\n" << duration.count();

    // auto start1 = std::chrono::high_resolution_clock::now();
    // std::cout << ternary_search(x, a, 0, a.size()) << std::endl;
    // auto stop1 = std::chrono::high_resolution_clock::now();
    // auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stop1 - start1);
    // std::cout << "ternary: " << duration1.count() << std::endl;
    // myfile << "\n" << duration1.count();

    myfile.close();
    return 0;
}