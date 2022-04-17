//
// Created by neha2 on 05-01-2022.
//

#ifndef COURSERA_PART1_CONVEXHULL_HELPER_H
#define COURSERA_PART1_CONVEXHULL_HELPER_H

#include <vector>
#include "Point.h"
#include <fstream>
#include "../../plotting/pbPlots.hpp"
#include "../../plotting/supportLib.hpp"
#include "convexhull_helper.h"

using namespace std;

template<class P>
bool colinear_distance(P current, P min, P i) {
    auto d1 = distance(current, min);
    auto d2 = distance(current, i);
    if (d1 < d2)
        return true;
    else
        return false;
}

template<class T>
void getXY(vector<Point<T>> &points, vector<T> &x, vector<T> &y) {
    for (auto p: points) {
        x.push_back(p.getX());
        y.push_back(p.getY());
    }

}

template<class T, class I>
I find_y_min(T &v) {
    auto min = v.begin();
    for (auto j = v.begin(); j != v.end(); j++) {
        if (j->getY() < min->getY()) {
            min = j;
        } else if (j->getY() == min->getY()) {
            min = (j->getX() > min->getX()) ? j : min;
        }
    }
    return min;
}

template<class T>
std::vector<T> read_points_from_file(const char *file_name) {
    ifstream input(file_name);
    int xx, yy;
    char ch;
//    typedef Point<T> point_type;
    typedef vector<T> vecType;
    vector<T> v;
    if (input.is_open())
        while (input) {
            input >> ch >> ch >> xx >> ch >> yy >> ch;
            if (input.eof()) break;
            //  NOTE: while(input){ then reading input>>x>>y ; reads last line twice bcz it treats EOF as healthy line so the last value of x and y gets carried over!
            cout << "x=" << xx << " y=" << yy << endl;
            Point<double> p(xx, yy);
            //Question why this point being seg1 local variable gets stored in vector? Copy by value, Honey!
            v.push_back(p);
        }
    else
        cout << "file closed" << endl;

    return v;
}

template<class T>
void plotPoints(vector<T> &x, vector<T> &y, const char *file_name) {
    RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();
    ScatterPlotSeries *series = GetDefaultScatterPlotSeriesSettings();
    series->xs = &x;
    series->ys = &y;
    series->linearInterpolation = false;
    series->pointType = toVector(L"circles");
    series->color = CreateRGBColor(1, 0, 0);
    ScatterPlotSettings *settings1 = GetDefaultScatterPlotSettings();
    settings1->width = 600;
    settings1->height = 400;
    settings1->autoBoundaries = false;
    settings1->autoPadding = true;
    settings1->xMax = 700;
    settings1->yMax = 700;
    settings1->xMin = -700;
    settings1->yMin = -700;
    settings1->scatterPlotSeries->push_back(series);
    DrawScatterPlotFromSettings(imageRef, settings1, (StringReference *) "error");
    vector<double> *pngdata1 = ConvertToPNG(imageRef->image);
    WriteToFile(pngdata1, file_name);
    DeleteImage(imageRef->image);
}

template<class T>
void plotLine(vector<T> &ox, vector<T> &oy, vector<T> &x, vector<T> &y, const char *file_name) {
    RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();
    ScatterPlotSeries *series = GetDefaultScatterPlotSeriesSettings();
    series->xs = &ox;
    series->ys = &oy;
    series->linearInterpolation = false;
    series->pointType = toVector(L"circles");
    series->color = CreateRGBColor(1, 0, 0);

    ScatterPlotSeries *series2 = GetDefaultScatterPlotSeriesSettings();
    series2->xs = &x;
    series2->ys = &y;
    series2->linearInterpolation = true;
    series2->lineType = toVector(L"solid");
    series2->lineThickness = 2;
    series2->color = CreateRGBColor(0, 0, 0.2);

    ScatterPlotSeries *series3 = GetDefaultScatterPlotSeriesSettings();
    series3->xs = &x;
    series3->ys = &y;
    series3->linearInterpolation = false;
    series3->pointType = toVector(L"filled triangles");
    series3->color = CreateRGBColor(0, 0, 1);

    ScatterPlotSettings *settings = GetDefaultScatterPlotSettings();
    settings->width = 1000;
    settings->height = 1000;
    settings->autoBoundaries = false;
    settings->autoPadding = true;
    settings->xMax = 20;
    settings->yMax = 20;
    settings->xMin = -20;
    settings->yMin = -20;
    settings->scatterPlotSeries->push_back(series);
    settings->scatterPlotSeries->push_back(series2);
    settings->scatterPlotSeries->push_back(series3);
    StringReference *errorMessage = new StringReference();
    bool success = DrawScatterPlotFromSettings(imageRef, settings, errorMessage);
    if (success) {
        vector<double> *pngData = ConvertToPNG(imageRef->image);
        WriteToFile(pngData, file_name);
        DeleteImage(imageRef->image);
    } else {
        cerr << "Error: ";
        for (wchar_t c: *errorMessage->string) {
            cerr << c;
        }
        cerr << endl;
    }
}

template<class T>
void cross_min(T &nextTarget, T &j, T &current) {
    Point<double> origin = *current;
    Point<double> pj = *j - origin;
    Point<double> nT = *nextTarget - origin;
    double cross = nT * pj;
    if (cross > 0)
        nextTarget = j;
    else if (cross == 0) {
        double d1 = distance(nT, origin);
        double d2 = distance(pj, origin);
        nextTarget = ((d1 > d2) ? nextTarget : j);
    }
}

template<class T>
bool checkPointInSegment(Point<T> c, Point<T> i, Point<T> min) {
    if (i.getX() <= c.getX() <= min.getX() & i.getY() <= c.getY() <= min.getY())
        return true;
    else return false;
}


#endif //COURSERA_PART1_CONVEXHULL_HELPER_H
