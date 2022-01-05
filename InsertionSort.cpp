//
// Created by neha2 on 30-12-2021.
//
#include <iostream>
#include<vector>
#include <algorithm>
#include <ctime>
#include <iterator>

using namespace std;

void InsertionSort(vector<int> v, vector<int>::iterator iterator, vector<int>::iterator iterator1, int h);


void insert(vector<int>::iterator key, vector<int>::iterator begin,
            int h);

unsigned long long int insertion_swap_count = 0;

int main() {
    vector<int> v(10000);
    srand(time(0));
    generate(v.begin(), v.end(), [] { return 1 + rand() % 100000000; });
    auto v_copy = v; //TODO: what constructor is working here?
//    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
//    cout << endl;
    int h = 1;
    while (h < v.size() / 3)h = 3 * h + 1;
    cout << "Initial h is: " << h << endl;
    while (h >= 1) {
        cout << "h (" << h << ") swap count :: ";
        InsertionSort(v, v.begin(), v.end(), h);
        h = h / 3;
    }
//    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
//    cout << endl;
    insertion_swap_count = 0;
    InsertionSort(v_copy, v_copy.begin(), v_copy.end(), h = 0);
//    copy(v_copy.begin(), v_copy.end(), ostream_iterator<int>(cout, " "));
//    cout << endl;
}

void InsertionSort(vector<int> v, vector<int>::iterator b, vector<int>::iterator e, int h) {
    if (b >= e) return;
    auto keyI = b + h;
    while (keyI < e) {
        insert(keyI, b, h);
        keyI++;
    }
    cout << "insertion sort swap count is " << insertion_swap_count << endl;

}

void insert(vector<int>::iterator key, vector<int>::iterator begin, int h) {
    auto leftKey = key - ((h == 0) ? 1 : h);
    while (leftKey >= begin) {
        if (*key < *leftKey) {
            iter_swap(key, leftKey);
            key = key - ((h == 0) ? 1 : h);
            insertion_swap_count++;
        }
        leftKey = leftKey - ((h == 0) ? 1 : h);
    }
}

