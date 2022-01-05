//
// Created by neha2 on 04-01-2022.
//
#include <iterator>
#include <iostream>
#include <ctime>
#include <algorithm>

template<class TC>
class Point  {
private:
    TC x, y;
public:
    Point() {
        this->x = 0.0;
        this->y = 0.0;
    };

    Point(TC x, TC y) : x(x), y(y) {}

    TC getX() const {
        return x;
    }

    TC getY() const {
        return y;
    }

    template<class T>
    friend T operator*(Point<T> p1, Point<T> p2);


    template<class T>
    friend std::ostream &operator<<(std::ostream &o, Point<T> p);

    template<class T>
    friend Point<T> operator-(Point<T> p1, Point<T> p2);

    template<class T>
    friend T distance(Point<T> p1, Point<T> p2);

//    bool operator==(const Point<TC> &p) const {
//        return (this->getX() == p.getX() && this->getY() == p.getY()) ? true : false;
//    }

    template<class T>
    friend bool operator<(Point<T> p1, Point<T> p2) {
        if (abs(p1.getY()) < abs(p2.getY()))
            return true;
        else if (p1.getY() == p2.getY() & p1.getX() < p2.getX())
            return true;
        else
            return false;
    };

    template<class T>
    friend bool operator==(Point<T> p1, Point<T> p2) {
        return (p1.x == p2.x && p1.y == p2.y) ? true : false;
    };

    template<class T>
    friend std::vector<Point<T>> generate_points(int N);

};
namespace xyz {
    template<class T>
    struct createPoint {
        Point<T> operator()() {
            T x = -10 + rand() % 20;
            T y = -10 + rand() % 20;
            Point<T> p(x, y);
            return p;
        };
    };
}

template<class T>
std::vector<Point<T>> generate_points(int N) {
    std::vector<Point<T>> v(N);
    srand(time(0));
    xyz::createPoint<T> t;
    std::generate(v.begin(), v.end(), t);
//    std::cout << "vector created with size " << v.size() << std::endl;
    return v;
};


namespace std {
    template<class T>
    struct hash<Point<T>> {
        size_t operator()(Point<T> const &x) const noexcept {
            return (
                    (51 + std::hash<int>()(x.getX())) * 51
                    + std::hash<int>()(x.getY())
            );
        }
    };
}

template<class T>
T distance(Point<T> p1, Point<T> p2) {
    return (sqrt(pow(p1.y - p2.y, 2) + pow(p1.x - p2.x, 2)));
}


template<class T>
T operator*(Point<T> p1, Point<T> p2) {
    return (p1.x * p2.y - p1.y * p2.x);
}

template<class T>
std::ostream &operator<<(std::ostream &o, const Point<T> p) {
    std::cout << "(" << "x " << p.x << " y " << p.y << ")" << std::endl;
    return o;
}

template<class T>
Point<T> operator-(Point<T> p1, Point<T> p2) {
    T x = p1.x - p2.x;
    T y = p1.y - p2.y;
    return Point<T>(x, y);
}