#include <iostream>
#include <math.h>

using namespace std;

struct Point {
    double x = 0, y = 0;
};

double manhattanDistance(const Point& p1, const Point& p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

double degToRad(const double& deg) {
    return deg / 180.0 * M_PI;
}

void rotatePoint(Point& point, double angle) {
    angle = degToRad(angle);
    double s = sin(angle), c = cos(angle);

    double px = point.x * c - point.y * s;
    point.y = point.x * s + point.y * c;
    point.x = px;
}

void moveShip(Point& ship, Point& wpoint, int amount) {
    ship.x += wpoint.x * amount;
    ship.y += wpoint.y * amount;
}

int main() {
    Point ship, waypoint;

    waypoint.x = 10;
    waypoint.y = 1;

    for (int i = 0; i < 769; i++) {
        char direction;
        cin >> direction;

        int amount;
        cin >> amount;

        switch (direction) {
        case 'N':
            waypoint.y += amount;
            break;
        case 'S':
            waypoint.y -= amount;
            break;
        case 'E':
            waypoint.x += amount;
            break;
        case 'W':
            waypoint.x -= amount;
            break;
        case 'L':
            rotatePoint(waypoint, amount);
            break;
        case 'R':
            rotatePoint(waypoint, -amount);
            break;
        case 'F':
            moveShip(ship, waypoint, amount);
            break;
        }
    }

    cout << manhattanDistance(ship, Point()) << endl;

    return 0;
}
