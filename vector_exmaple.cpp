//
// Created by neha2 on 28-12-2021.
//
#include<iostream>
#include <vector>

using namespace std;

vector<int> v_ex() {
    vector<int> a(2, 1);
    vector<int> b(a);
    vector<int> c(10);
    vector<int> d;
    for (auto x: a) {
        cout << x << ", ";
    }
    cout << endl;
    vector<int>::iterator it = a.begin();
    auto it2 = b.begin();
    auto low = a.begin();
    auto high = a.end();
    auto mid = low + (high - low) / 2;
    //Note: you cant print low directly, there is no concept of printing iterator dorectly.
    cout << "low is " << low - a.begin()
         << " high is " << high - a.begin() << "mid is " << mid - a.begin() << endl;
    //    auto mid=a.begin()+(a.begin()+a.end())/2;
    //Note , the addition of vector is not supported here. Iterator arithmatic is a whole different topic.
//    cout<<low;
    return a;


}

