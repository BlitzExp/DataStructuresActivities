#include <iostream>
#include <array>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <vector>
#include "./vectora.cpp"
using namespace std;

const std::size_t N = arr.size();

// Implementación de sort de la librería estándar (std::sort)

int main() {
    ofstream myfile;
    myfile.open("data.txt", std::ios::out | std::ios::app);
    vector<int> a = arr;
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(a.begin(), a.end());
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "sort" << duration.count() << std::endl;
    myfile << "\n" << duration.count();

    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << ", ";
    }
    std::cout << std::endl;
}