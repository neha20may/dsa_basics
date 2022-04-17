//
// Created by neha2 on 28-12-2021.
//
#include<iostream>
#include <iterator>

using namespace std;
#ifndef COURSERA_PART1_SORTING_H
#define COURSERA_PART1_SORTING_H

std::vector<int> v_ex();
//Use of different namespace to distinguish it from stl
namespace xyz {
    template<typename RI, typename T>
    void merge(RI low, RI mid, RI high) {
        cout << "In merge subroutine" << endl;
        cout << "first: ";
        copy(low, mid, ostream_iterator<T>(cout, " "));
        cout << endl << "second: ";
        cout << "The second part of the vector is " << endl;
        copy(mid, high, ostream_iterator<T>(cout, " "));
        cout << endl;
        //Example to use is_sorted
//        if (is_sorted(low, mid)) {
//            cout << "first half is sorted between" << endl;
//        }
//        if (is_sorted(mid, high)) {
//            cout << "second half sorted between mid+1 " << endl;
//        }
        auto i = low, j = mid, l = high;
        vector<T> o(high - low); //Extra space.
        auto ot = o.begin();
        while (i < mid && j < high) {
            if (*i <= *j)
                *ot++ = *i++;
            else
                *ot++ = *j++;
        };
        if (i == mid) {
            while (j < high)
                *ot++ = *j++;
        } else {
            while (i < mid)
                *ot++ = *i++;
        }
//        Note: in each recursive call, these low high change! thats why copy is needed. The auxiliary space is local to the merge function call.
//        auto t = o.begin();
//        auto it = low;
//        while (it < high) {
//            *it++ = *t++;
//        }
        copy(o.begin(), o.end(),low);
        cout << "partially sorted vector is " << endl;
        copy(low, high, ostream_iterator<T>(cout, " "));
        cout << endl;
    };
};

//Note: The templatized code is written in header file itself, the cpp source file gave linker error.
template<typename RandomAccessIterator, typename T>
void mergeSort(std::vector<T> &a,
               RandomAccessIterator low, RandomAccessIterator high) {
    if (low == high) {
        return;
    } else if (low + 1 == high) {
        return;
    } else {
        auto mid = low + (high - low) / 2;
        mergeSort(a, low, mid);//mid is just like high ,
        // that is the +1 to the last element (high is 1 past the last element), thats why the next call is mid (not mid+1).
        mergeSort(a, mid, high);
        cout << "calling merge routine" << endl;
        copy(low, mid, ostream_iterator<T>(cout, " "));
        cout << endl;
        copy(mid, high, ostream_iterator<T>(cout, " "));
        cout << endl;
        xyz::merge<RandomAccessIterator, T>(low, mid, high);
    }
};


#endif //COURSERA_PART1_SORTING_H
