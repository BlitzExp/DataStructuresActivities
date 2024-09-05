#include <iostream>
#include <array>
#include <chrono>
#include <fstream>
#include <vector>
#include "./vectora.cpp"
using namespace std;

const std::size_t N = arr.size();

// Exchange sort
void exchange_sort(vector<int>& a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            if (a[i] < a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

int main() {
    ofstream myfile;
    myfile.open("data.txt", std::ios::out | std::ios::app);

    vector<int> a = arr;

    auto start = std::chrono::high_resolution_clock::now();
    exchange_sort(a);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "exchange" << duration.count() << std::endl;
    myfile << "\n" << duration.count();

    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << ", ";
    }
    std::cout << std::endl;
}