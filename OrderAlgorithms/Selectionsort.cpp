#include <iostream>
#include <array>
#include <chrono>
#include <fstream>
#include <vector>
#include "./vectora.cpp"
using namespace std;

const std::size_t N = arr.size();

// Selection sort
void selection_sort(vector<int>& a) {
    for (int i = 0; i < N; i++) {
        int min_index = i;
        for (int j = i + 1; j < N; j++) {
            if (a[j] < a[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(a[min_index], a[i]);
        }
    }
}

int main() {
    ofstream myfile;
    myfile.open("data.txt", std::ios::out | std::ios::app);
    vector<int> a = arr;
    auto start = std::chrono::high_resolution_clock::now();
    selection_sort(a);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "selection" << duration.count() << std::endl;
    myfile << "\n" << duration.count();
    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << ", ";
    }
    std::cout << std::endl;
}