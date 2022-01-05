#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <sstream>
#include "mergeSorting.h"

using namespace std;

/**
 * Example to try vector and then use merge sort to sort the vector.
 * String read for input
 * @return
?/.,./.,m,.,mnbvnmnbvbnbvcxcvcxzxcxzZZZ  */
int main() {
    std::cout << "Hello, World!" << std::endl;
    //Example 0.0 for vector creation and iterator implementaions.
//    vector<int> r = v_ex();
//Example 0.1 for string and split
    string v = "91 63 7 37 35 32 67 53 98 2";
    int w;
    istringstream sin(v);
    while (sin >> w)
        cout << w << ", ";
    cout << endl;
//Example 1: creation of vectpr using generate, and them ,merge sort to sort the routine!
    vector<int> a(5);
    srand(time(0));
    //Note: the lambda function
    generate(a.begin(), a.end(), [] { return 1 + rand() % 1000; });
    cout << "initial vector is  " << endl;
    for (auto x:a) { cout << " " << x; }
    cout << endl;
    mergeSort(a, a.begin(), a.end());
    cout << "sorted array is " << endl;
    for (auto x:a) {
        cout << " " << x;
    }
    cout << endl;
//Example 2 to use the template design!
    string str = "my name is neha, can you sort it?";
    vector<char> e(str.begin(), str.end()); //Transfer constructor? or converson constructor
    copy(e.begin(), e.end(), ostream_iterator<char>(cout, " "));
    cout << endl;
    mergeSort(e, e.begin(), e.end());
    copy(e.begin(), e.end(), ostream_iterator<char>(cout, " "));
    cout << endl;
    string o(e.begin(), e.end());
    cout << "s string: " << str << endl << "f string: " << o << endl;
    return 0;
}
