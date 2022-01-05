//
// Created by neha2 on 01-01-2022.
//
/**
 * Jarvis march convex hull
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <set>
#include "pbPlots.hpp"
#include "supportLib.hpp"
#include "convexhull_helper.h"

using namespace std;

template<class T, class I>
I find_y_min(T &v);

template<class T, class It>
It nextCandidate(It current, T &points, T &convex_hull);

int main() {
    typedef Point<double> point_type;
    typedef vector<point_type> vecType;
    typedef vecType::iterator it;
//    string file = "C:\\Users\\neha2\\CLionProjects\\Coursera_Part1\\wrong_ex.txt";
//    auto points = read_points_from_file<point_type>(file.c_str());
    auto points = generate_points<double>(10);
    cout << "points given are" << endl;
    copy(points.begin(), points.end(), ostream_iterator<Point<double>>(cout, " "));
    cout << endl;
    vector<double> x;
    vector<double> y;
    for (auto p: points) {
        x.push_back(p.getX());
        y.push_back(p.getY());
    }
    plotPoints(x, y, string("points.png").c_str());
    auto p_0 = find_y_min<vecType, it>(points);
    cout << "initial point " << *p_0;
    auto start = p_0;
    vecType convex_hull;
    convex_hull.push_back(*start);
    auto nextCan = nextCandidate<vecType, it>(start, points, convex_hull);
    while (!(*nextCan == *start)) {
        nextCan = nextCandidate<vecType, it>(nextCan, points, convex_hull);
    }
//    convex_hull.pop_back();
    cout << "convex hull is " << endl;
    copy(convex_hull.begin(), convex_hull.end(), ostream_iterator<Point<double>>(cout, " "));
    cout << endl;
    //Plot convex_hull
    vector<double> x2, y2;
    for (auto p: convex_hull) {
        x2.push_back(p.getX());
        y2.push_back(p.getY());
    }
    plotLine(x, y, x2, y2, string("convex_hull.png").c_str());
}

template<class T, class It>
It nextCandidate(It current, T &points, T &convex_hull) {
    cout << "current reference is " << *current;
    auto min = current;
    set<Point<double>> colinear;
    for (auto i = points.begin(); i < points.end(); i++) {
        if (*current == *i)
            continue;
        double cross_product = (*i - *current) * (*min - *current);
        if (cross_product > 0.0)
            min = i;
        else if (cross_product == 0) {
            if (!(*min == *current)) {
                colinear.insert(*i);
            }
            auto d_min = distance(*min, *current);
            auto d_i = distance(*i, *current);
            min = (d_min < d_i) ? i : min;
        }
    }
    cout << "Co-linear points are" <<
         endl;
    for (auto i: colinear)
        cout << i;
    cout << endl;
//    auto cit=colinear.rbegin();
//    colinear.erase(*min);
//if(colinear.size()>1)
//    copy(colinear.rbegin(), colinear.rend(), back_inserter(convex_hull));
//else
    convex_hull.push_back(*min);
    return min;
}

template<class T, class I>
I find_y_min(T &v) {
    auto min = v.begin();
    for (auto j = v.begin(); j < v.end(); j++) {
        if (j->getY() < min->getY()) {
            min = j;
        } else if (j->getY() == min->getY()) {
            min = (j->getX() > min->getX()) ? j : min;
        }
    }
    return min;
}

