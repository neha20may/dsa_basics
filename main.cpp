#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "sorting/quickSorting.h"
#include <iterator>
//#include "matplotlibcpp.h"

//namespace plt = matplotlibcpp;
using namespace std;
int main() {
    vector<int> v(100000);
    srand(time(0));
    generate(v.begin(), v.end(), [] { return (1 + rand() % 100); });
    cout<<"Initial vector is"<<endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
//    plt::plot(v);
    QuickSortEqualKeys(v, v.begin(), v.end());
    cout<<"sorted vector is "<<endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " ")); cout<<endl;
//    plt::plot(v);
}