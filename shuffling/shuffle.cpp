//
// Created by neha2 on 31-12-2021.
//
#include <bits/stdc++.h>

using namespace std;

void shuffle(vector<int> v, vector<int>::iterator b, vector<int>::iterator e);

void
shuffle(vector<int> v, vector<int>::iterator bv, vector<int>::iterator ev) {
    auto b = bv, e = ev - 1; //first and last element
    typedef std::uniform_int_distribution<int> ugen;
    std::mt19937 rng(time(0));
    while (e >= b) {
        int min = b - b, max = e - b;//0 index and last element index
        ugen u(min, max);
        int r = u(rng);
        auto bb = b + r;
        iter_swap(e, bb);
        e--;
    }
}

int main() {
    std::mt19937 rng(time(0));
    int min = 0, max = 100000;
    std::uniform_int_distribution<int> ug(min, max); // uniform, unbiased
    vector<int> v(100);
    generate(v.begin(), v.end(), [&ug, &rng] { return ug(rng); });//Note:the use of lambda to pass the ug functor
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    shuffle(v, v.begin(), v.end());
    cout << "after shuffle" << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

}
