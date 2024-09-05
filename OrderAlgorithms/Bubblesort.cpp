#include <iostream>
#include <array>
#include <chrono>
#include <fstream>
#include <vector>
#include "./vectora.cpp"
using namespace std;

const std::size_t N = arr.size();

// Bubble sort
void bubble_sort(vector<int>& a) {
    for (int i = 1; i < N; i++) {
        bool swapped = false;
        if (swapped == false) {
            for (int j = 0; j < N - i; j++) {
                if (a[j + 1] < a[j]) {
                    swap(a[j], a[j + 1]);
                    swapped = true;
                }
            }
        }
        if (swapped = false) {
            break;
        }
    }
}

int main() {
    ofstream myfile;
    myfile.open("data.txt", std::ios::out | std::ios::app);
    vector<int> a = arr;
    auto start = std::chrono::high_resolution_clock::now();
    bubble_sort(a);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "bubble" << duration.count() << std::endl;
    myfile << "\n" << duration.count();

    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << ", ";
    }
    std::cout << std::endl;
}