#include <iostream>
#include <array>
#include <chrono>
#include <fstream>
#include <vector>
#include "./vectora.cpp"
using namespace std;

const std::size_t N = arr.size();

// Quick sort
int partition(vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quick_sort(vector<int>& a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);

        quick_sort(a, low, pi - 1);
        quick_sort(a, pi + 1, high);
    }
}

int main() {
    ofstream myfile;
    myfile.open("data.txt", std::ios::out | std::ios::app);
    vector<int> a = arr;
    auto start = std::chrono::high_resolution_clock::now();
    quick_sort(a, 0, N - 1);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "quick: ";
    myfile << "\n" << duration.count();
    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << ", ";
    }
    std::cout << std::endl;
}