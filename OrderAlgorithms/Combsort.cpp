#include <iostream>
#include <array>
#include <chrono>
#include <fstream>
#include <vector>
#include "./vectora.cpp"
using namespace std;

const std::size_t N = arr.size();

// Comb sort
int getNextGap(int gap) {
    gap = (gap * 10) / 13;

    if (gap < 1) return 1;
    return gap;
}

void comb_sort(vector<int>& a) {
    int gap = a.size();

    bool swapped = true;

    while (gap != 1 || swapped == true) {
        gap = getNextGap(gap);
        swapped = false;

        for (int i = 0; i < a.size() - gap; i++) {
            if (a[i] > a[i + gap]) {
                swap(a[i], a[i + gap]);
                swapped = true;
            }
        }
    }
}

// Implementación de sort de la librería estándar (std::sort)

int main() {
    ofstream myfile;
    myfile.open("data.txt", std::ios::out | std::ios::app);
    vector<int> a = arr;
    auto start = std::chrono::high_resolution_clock::now();
    comb_sort(a);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "comb" << duration.count() << std::endl;
    myfile << "\n" << duration.count();
    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << ", ";
    }
    std::cout << std::endl;
}