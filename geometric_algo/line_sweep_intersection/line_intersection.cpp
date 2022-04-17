//
// Created by neha2 on 15-03-2022.
//

#include <bits/stdc++.h>
#include "../convex_hull/Point.h"

using namespace std;

class Solution {

    enum class event_type {
        start, end, cross
    };
//    typedef pair<Point<int>, Point<int> > segment; //<X,Y>
    struct segment {
        Point<int> left;
        Point<int> right;
        int m = 0;
        int c = 0;
        int idx;
    };
//    typedef pair<event_type, segment> event;
    struct event {
        event_type etype;
        int time;
        int idx;
        int idx2;
    };
    vector<segment> &line_segments;

    struct cmp_eq {
        bool operator()(event a, event b) {
            return (a.time < b.time);
        }
    };

    struct cmp_sl {
        bool operator()(segment a, segment b) {
            pair<int, int> mc1 = make_pair(a.m, a.c);
            pair<int, int> mc2 = make_pair(b.m, b.c);
            return (mc1 < mc2); //sort by their y co-ordinates or by (mi, ci)
        }
    };

public:
    void initialise(priority_queue<event, vector<event>, cmp_eq> &EQ,
                    vector<segment> &segments) {
        int N = segments.size();
        for (int i = 0; i < N; i++) {
            segment seg = segments[i]; //assuming seg is sorted in its point left and point right;
            event start;
            start.etype = event_type::start;
            start.time = seg.left.getX(); //seg has both <x,y>
            start.idx = i;
            event end;
            end.etype = event_type::end;
            end.time = seg.right.getX();
            end.idx = i;
            EQ.push(start);
            EQ.push(end);
        }

    }

    int orientation(Point<int> line_start, Point<int> line_end, Point<int> point) {
        return (point - line_start) * (line_end - line_start);
    }

    bool on_line_segement(Point<int> line_start, Point<int> line_end, Point<int> point) {
        int xi = line_start.getX(), yi = line_start.getY();
        int xj = line_end.getX(), yj = line_end.getY();
        if ((min(xi, xj) <= point.getX() <= max(xi, xj)) and
            (min(yi, yj) <= point.getY() <= max(yi, yj)))
            return true;
        else
            return false;
    }

    bool intersect(segment s1, segment s2) {
        Point<int> p1 = s1.left;
        Point<int> p2 = s2.right;
        Point<int> p3 = s2.left;
        Point<int> p4 = s2.right;
        //p1 point ka oreintation wrt to liine p3 p4
        //p2 ka orientation wrt yo line p3 p4..
        int d1 = orientation(p3, p4, p1);
        int d2 = orientation(p3, p4, p2);
        int d3 = orientation(p1, p2, p3);
        int d4 = orientation(p1, p2, p4);
        //good case when line segments intersect normally
        if (((d1 > 0 and d2 < 0) or (d1 < 0 and d2 > 0)) and ((d3 > 0 and d4 < 0) or (d3 < 0 and d4 > 0)))
            return true;
        //degenerative cases when one point lies on the line
        if (d1 == 0 and on_line_segement(p3, p4, p1))
            return true;
        if (d2 == 0 and on_line_segement(p3, p4, p2))
            return true;
        if (d3 == 0 and on_line_segement(p1, p2, p3))
            return true;
        if (d4 == 0 and on_line_segement(p1, p2, p4))
            return true;
        return false;
    }

    int get_time_intersection(const segment &segment1, const segment &segment2) {
        int slope1 = segment1.m;
        int c1 = segment1.c;
        int slope2 = segment2.m;
        int c2 = segment2.c;
        /**
         * y=m1*x+c1
         * y=m2*x+c2
         * at intersection m1*x+c1=m2*x+c2=> x(m1-m2)=c2-c1
         * x=(c2-c1)/(m1-m2);
         */
        int intersection_x = (c2 - c1) / (slope1 - slope2);
        int intersection_y = slope1 * intersection_x + c1;
        return intersection_x;
    }

    void check_for_intersection(priority_queue<event, vector<event>, cmp_eq> &EQ,
                                const segment &a, const segment &b) {
        if (intersect(a, b)) {
            event c;
            c.etype = event_type::cross;
            c.time = get_time_intersection(a, b);// future only right? what to put here?
            c.idx = a.idx;
            c.idx2 = b.idx;
            EQ.push(c);
        }

    }

    const event &new_neighbor(segment segment1) {
        event e;
        return e;
    }

    segment get_segment(event e) {
        int idx = e.idx;
        segment seg = line_segments[idx];
        //fill slope and c here

        if (seg.left.getX() < seg.right.getX()) {
            swap(seg.left, seg.right);
        }
        int x1 = seg.left.getX(), y1 = seg.left.getY();
        int x2 = seg.right.getY(), y2 = seg.right.getY();
        int slope = (y2 - y1) / (x2 - x1);
        /**
         * y=mx+c
         * c=y-mx;
         */
        int bias = y1 - slope * x1;
        seg.m = slope;
        seg.c = bias;
        line_segments[idx] = seg;
        return seg;
    }

    int get_intersection() {
        priority_queue<event, vector<event>, cmp_eq> EQ;
        initialise(EQ, line_segments);
        set<segment, cmp_sl> SL;
        vector<set<segment, cmp_sl>::iterator> connection;
        int no_int = 0;
        while (!EQ.empty()) {
            event e = EQ.top();
            EQ.pop();
            event_type etype = e.etype;
            if (etype == event_type::start) {
                segment se = get_segment(e);
                auto p = SL.insert(se);
                auto q = p;
                auto pred = p.first--;
                if (pred != SL.end())
                    check_for_intersection(EQ, get_segment(e), *pred);
                auto suc = q.first++;
                if (suc != SL.end())
                    check_for_intersection(EQ, get_segment(e), *suc);

            } else if (etype == event_type::end) {
                auto p = SL.find(get_segment(e));
                auto q = p;
                auto pred = p--;
                auto suc = q++;
                check_for_intersection(EQ, *pred, *suc);
                SL.erase(get_segment(e)); //find and erase it

            } else if (etype == event_type::cross) {
                segment s1 = line_segments[e.idx];
                segment s2 = line_segments[e.idx2];
                cout << " segment intersection. s1= < " << s1.left << "," << s1.right << "> " << "s2= <"
                     << s2.left << "," << s2.right << "> " << endl;
                no_int += 1;
                SL.erase(s1);
                SL.erase(s2);
                //how do i change their order here?
                segment new_s1;
                segment new_s2;

                SL.insert(s2);
                SL.insert(s1);
                check_for_intersection(EQ, s1, new_neighbor(s1));
                check_for_intersection(EQ, s2, new_neighbor(s2));

            }
        }
        return no_int;
    }
};

void create_segments(vector<pair<Point<int>, Point<int>>> &line_segments);

int main() {
    vector<pair<Point<int>, Point<int>>> line_segemnts;
    create_segments(line_segemnts);
}

void create_segments(vector<pair<Point<int>, Point<int>>> &line_segments) {
    Point<int> p(0, 0);
    Point<int> q(1, 1);
    Point<int> r(2, 2);
    line_segments.push_back(make_pair(p, q));
    line_segments.push_back(make_pair(q, r));
    line_segments.push_back(make_pair(p, r));

}
