//
// Created by neha2 on 01-01-2022.
//
/**
 * Jarvis march convex hull
 */
#include <iostream>
#include <vector>
#include <iterator>
#include "convexhull_helper.h"


using namespace std;


template<class T, class It>
It nextCandidate(It current, T &points, T &convex_hull);

template<class It>
bool colinear_distance(It current, It min, It i);

int main() {
    typedef Point<double> point_type;
    typedef vector<point_type> setType;
    typedef setType::iterator it;
//    string file = "C:\\Users\\neha2\\CLionProjects\\Coursera_Part1\\wrong_ex.txt";
//    auto points = read_points_from_file<point_type>(file.c_str());
    auto points = generate_points<setType, double>(10);
    cout << "points given are" << endl;
    copy(points.begin(), points.end(), ostream_iterator<Point<double>>(cout, " "));
    cout << endl;
    vector<double> x, y;
    getXY<double>(points, x, y);
    plotPoints(x, y, string("points.png").c_str());
    auto p_0 = find_y_min<setType, it>(points);
    cout << "initial point " << *p_0;
    auto start = p_0;
    setType convex_hull;
    convex_hull.push_back(*start);
    auto nextCan = nextCandidate<setType, it>(start, points, convex_hull);
    while (!(*nextCan == *start)) {
        nextCan = nextCandidate<setType, it>(nextCan, points, convex_hull);
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
//    cout << "current reference is " << *current;
    auto min = current;
    vector<Point<double>> colinear;
    for (auto i = points.begin(); i != points.end(); i++) {
        if (*current == *i)
            continue;
        double cross_product = (*i - *current) * (*min - *current);
        if (cross_product > 0.0) {
            min = i;
            colinear.clear();
        } else if (cross_product == 0) {
            ///colinear points should be sorted according to their distance from the current point.
            //while going up, you take the nearest point as the next point, while going down, you take the
            if (colinear_distance(*current, *min, *i)) {
                //min is closure to current so shift min to far but add that before to colinear.
                if (!(*min == *current))
                    colinear.push_back(*min);
                min = i;
            } else {
                //min is already far
                colinear.push_back(*i);
            }
        }
    }
//    cout << "Co-linear points are" << endl;
    unique(colinear.begin(), colinear.end());
//    for (auto i: colinear)
//        cout << i;
    copy(colinear.begin(), colinear.end(), back_inserter(convex_hull));
    convex_hull.push_back(*min);
    return min;
}





