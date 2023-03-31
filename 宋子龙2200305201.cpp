#include <iostream>
#include <ctime>
#include "Vector.h"
#include "Complex.h"

using namespace std;

int main() {
    srand(time(NULL));

    Vector<Complex> v(4);
    v[0] = Complex(1, 2);
    v[1] = Complex(3, 4);
    v[2] = Complex(5, 6);
    v[3] = Complex(1, 2);

    cout << v << endl; // (1, 2) (3, 4) (5, 6) (1, 2)

    v.shuffle();
    cout << v << endl; // (1, 2) (3, 4) (1, 2) (5, 6)

    int index = v.find(Complex(1, 2));
    cout << "Index of (1, 2): " << index << endl; // Index of (1, 2): 0

    v.insert(2, Complex(3, 4));
    cout << v << endl; // (1, 2) (3, 4) (3, 4) (1, 2) (5, 6)

    v.remove(2);
    cout << v << endl; // (1, 2) (3, 4) (1, 2) (5, 6)

    int n = v.deduplicate();
    cout << "Deduplicated " << n << " elements." << endl; // Deduplicated 1 elements.

    v.sort(); // 默认排序（升序）
    cout << v << endl; // (1, 2) (1, 2) (3, 4) (5, 6)

    v.shuffle();
    cout << v << endl; // (5, 6) (1, 2) (1, 2) (3, 4)

    v.sort(Vector<Complex>::MERGE_SORT); // 归并排序（升序）
    cout << v << endl; // (1, 2) (1, 2) (3, 4) (5, 6)

    v.shuffle();
    cout << v << endl; // (3, 4) (1, 2) (1, 2) (5, 6)

    v.sort(Vector<Complex>::BUBBLE_SORT); // 起泡排序（升序）
    cout << v << endl; // (1, 2) (1, 2) (3, 4) (5, 6)

    v.shuffle();
    cout << v << endl; // (3, 4) (1, 2) (5, 6) (1, 2)

    clock_t t1 = clock();
    v.sort();
    clock_t t2 = clock();
    cout << "Default sort: " << t2 - t1 << " ticks." << endl; // Default sort: 147 ticks.

    v.shuffle();
    t1 = clock();
    v.sort(Vector<Complex>::MERGE_SORT);
    t2 = clock();
    cout << "Merge sort: " << t2 - t1 << " ticks." << endl; // Merge sort: 2 ticks.

    v.shuffle();
    t1 = clock();
    v.sort(Vector<Complex>::BUBBLE_SORT);
    t2 = clock();
    cout << "Bubble sort: " << t2 - t1 << " ticks." << endl; // Bubble sort: 202 ticks.

    Vector<Complex> sub_v = v.search(2, 5); // 查找模在[2, 5)之间的元素
    cout << sub_v << endl; // (3, 4) (5, 6)

    return 0;
}

