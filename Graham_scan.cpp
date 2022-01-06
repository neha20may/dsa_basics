//
// Created by neha2 on 05-01-2022.
//

#include "Graham_scan.h"
#include "convexhull_helper.h"
#include <bits/stdc++.h>

namespace cmp {
    template<typename Pnt, typename T>
    struct less : public binary_function<Pnt, Pnt, bool> {
        Point<T> p;

        bool
        operator()(const Pnt &q, const Pnt &r) const {
//        return q < r;
            auto qp = q - p;
            auto rp = r - p;
            auto cross = qp * rp;
            if (cross > 0)
                return true;
            else if (cross < 0)
                return false;
            else {
                auto d_qp = distance(q, p);
                auto d_rp = distance(r, p);
                if (d_qp > d_rp)
                    return true;
                else return false;
            }
        }

        less(Pnt p0) : p(p0) {}
    };
}

bool isLeft(Point<double> nextTop, Point<double> top, Point<double> p) {
    auto qp = top - nextTop;
    auto rq = p - top;
    auto c = qp * rq;
    if (c > 0)
        return true;
    else
        return false;
}

using namespace std;

int main() {
    auto points = generate_points<vector<Point<double>>, double>(1000);
    if (points.size() <= 2) {
        return 0;
    }
//    string file = "C:\\Users\\neha2\\CLionProjects\\Coursera_Part1\\wrong_ex.txt";
//    auto points = read_points_from_file<Point<double>>(file.c_str());
    vector<double> x, y;
    getXY<double>(points, x, y);
    plotPoints(x, y, string("gs_points.png").c_str());
    copy(points.begin(), points.end(), ostream_iterator<Point<double>>(cout, " "));
    cout << endl;
    auto p_0 = find_y_min<vector<Point<double>>, vector<Point<double>>::iterator>(points);
    cout << "initial point " << *p_0;
    auto start = *p_0; //it gets invalidated after sort
    sort(points.begin(), points.end(), cmp::less<Point<double>, double>(*p_0));
    points.erase(points.end() - 1);
    copy(points.begin(), points.end(), ostream_iterator<Point<double>>(cout, " "));
    cout << endl;
    stack<Point<double>> convex_hull;
    convex_hull.push(start);
    convex_hull.push(*points.begin());
    convex_hull.push(*(points.begin() + 1));
    for (auto p = points.begin() + 2; p < points.end(); p++) {
        auto top = convex_hull.top();
        convex_hull.pop();
        auto next_top = convex_hull.top();
        convex_hull.push(top);
        while (true) {
            if (!isLeft(next_top, top, *p)) {
                convex_hull.pop();
                top = convex_hull.top();
                convex_hull.pop();
                next_top = convex_hull.top();
                convex_hull.push(top);
            } else
                break;

        }
        convex_hull.push(*p);
    }
    vector<Point<double>> CH;
    while (!convex_hull.empty()) {
        Point<double> pt = convex_hull.top();
        cout << pt;
        CH.push_back(pt);
        convex_hull.pop();
    }
    reverse(CH.begin(), CH.end());
    vector<double> x2, y2;
    CH.push_back(start);
    getXY<double>(CH, x2, y2);
    plotLine(x, y, x2, y2, string("graham_scan_convex_hull.png").c_str());
    return 0;

}
