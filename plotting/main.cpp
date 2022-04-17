//
// Created by neha2 on 16-03-2022.
//
#include <bits/stdc++.h>
#include "../geometric_algo/convex_hull/convexhull_helper.h"

using namespace std;

ScatterPlotSeries *get_new_series(vector<double> *x, vector<double> *y) {
    ScatterPlotSeries *series = GetDefaultScatterPlotSeriesSettings();
    series->xs = x;
    series->ys = y;
    series->linearInterpolation = true;
    series->lineType = toVector(L"solid");
    series->lineThickness = 2;
    series->color = CreateRGBColor(0, 0, 1);
    return series;
}

ScatterPlotSettings *get_settings() {
    ScatterPlotSettings *settings = GetDefaultScatterPlotSettings();
    settings->width = 1500;
    settings->height = 1500;
    settings->autoBoundaries = false;
    settings->autoPadding = true;
    settings->xMax = 20;
    settings->yMax = 20;
    settings->xMin = -20;
    settings->yMin = -20;
    return settings;
}

int main() {
    RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();
    ScatterPlotSettings *settings = get_settings();
    ScatterPlotSeries *series = get_new_series(new vector<double>({1, 10}),
                                               new vector<double>({10, 5}));
    settings->scatterPlotSeries->push_back(series);
    ScatterPlotSeries *series2 = get_new_series(new vector<double>({2, 8}),
                                                new vector<double>({6, 8}));
    settings->scatterPlotSeries->push_back(series2);
    ScatterPlotSeries *series4 = get_new_series(new vector<double>({2, 7}),
                                                new vector<double>({4, 9}));
    settings->scatterPlotSeries->push_back(series4);
    ScatterPlotSeries *series3 = get_new_series(new vector<double>({8, 10}),
                                                new vector<double>({3, 6}));
    settings->scatterPlotSeries->push_back(series3);

    StringReference *errorMessage = new StringReference();
    bool success = DrawScatterPlotFromSettings(imageRef, settings, errorMessage);
    if (success) {
        vector<double> *pngData = ConvertToPNG(imageRef->image);
        WriteToFile(pngData, "test_plot.png");
        DeleteImage(imageRef->image);
    } else {
        cerr << "Error: ";
        for (wchar_t c: *errorMessage->string) {
            cerr << c;
        }
        cerr << endl;
    }

}
