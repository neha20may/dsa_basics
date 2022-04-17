//
// Created by neha2 on 29-12-2021.
//
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

#ifndef COURSERA_PART1_QUICKSORTING_H
#define COURSERA_PART1_QUICKSORTING_H

template<class T, class It>
pair<T, It> getPivot(vector<T> v, It low, It high) {
    srand(time(0));
    It p = low + rand() % (high - low);
    return make_pair(*p, p);
};
/**
 * Normal partition ,check the boundary condition.
 * @tparam It
 * @tparam T
 * @param low
 * @param high
 * @return
 */
template<class It, class T>
It Partition(It low, It high) {
    It i = low + 1, j = high - 1;
    T p = *low;
    while (true) {
        while (*i < p & i < high)i++;
        while (*j >= p & j > low)j--;
        if (i >= j) break;
        else {
//            cout << "I is bigger while j is lesser" << endl;
//            cout << "before i and j swap" << endl;
//            copy(low, high, ostream_iterator<T>(cout, " "));
//            cout << endl;
            iter_swap(i, j);
//            cout << "after  i and j swap" << endl;
//            copy(low, high, ostream_iterator<T>(cout, " "));
//            cout << endl;
        }
    }
    iter_swap(low, j);
//    cout << "Vector after partitioning is " << endl;
//    copy(low, high, ostream_iterator<T>(cout, " "));
//    cout << endl;
    return j;
};

/*
 * The equal keys is very different from the normal partion and corner cases took significant time.
 * */
template<class It, class T>
pair<It, It> PartitionEqualKeys(It low, It high) {
    It i = low, j = high - 1, lt = low;//note low , not low+1
    T p = *low;
    while (i <= j) {
        while (*i < p & i < high) {
            iter_swap(i, lt);
            i++;
            lt++;
        }
        while (*i == p & i < high)i++;
        while (*i > p & i <= j) {
            iter_swap(i, j);
            j--;
        }
    }
    return make_pair(lt, j);
};

template<class T, class It>
void QuickSortEqualKeys(vector<T> v, It low, It high) {
    if (high <= low)return;
    pair<T, It> answer = getPivot(v, low, high);//or TODO: shuffle the array, check time complexity!
    It pivot_position = answer.second;
    iter_swap(low, pivot_position);
    pair<It, It> two_pivots = PartitionEqualKeys<It, T>(low, high);
    It lt = two_pivots.first, gt = two_pivots.second;
    QuickSortEqualKeys(v, low, lt);
    QuickSortEqualKeys(v, gt + 1, high);
};
/**
 * The old quick sort.
 * @tparam T
 * @tparam It
 * @param v
 * @param low
 * @param high
 */
template<class T, class It>
void QuickSort(vector<T> v, It low, It high) {
    if (low + 1 >= high)return;
    //Pick pivot randomly
    pair<T, It> answer = getPivot(v, low, high);//or TODO: shuffle the array, check time complexity!
    It pivot_position = answer.second;
//    cout << "pivot is " << answer.first << " its position is " << pivot_position - low << endl;
    iter_swap(low, pivot_position);
//    cout << "vector after pivot swapping is " << endl;
//    copy(low, high, ostream_iterator<T>(cout, " "));
//    cout << endl;
    //partition based on pivot
    It p = Partition<It, T>(low, high);
    //recursively call left and right of pivot
//    cout << " Next two recursive calls are " << endl;
//    copy(low, p, ostream_iterator<T>(cout, " "));
//    cout << endl;
//    copy(p + 1, high, ostream_iterator<T>(cout, " "));
//    cout << endl;
    QuickSort(v, low, p);
    QuickSort(v, p + 1, high);
};

#endif //COURSERA_PART1_QUICKSORTING_H
