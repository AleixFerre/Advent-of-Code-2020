#include <iostream>
#include <math.h>

using namespace std;

double manhattanDistance(const double& x, const double& y) {
    return abs(x) + abs(y);
}

double degToRad(const double& deg) {
    return deg / 180.0 * M_PI;
}

void moveShip(double& x, double& y, int angle, int amount) {
    x += cos(degToRad(angle)) * amount;
    y += sin(degToRad(angle)) * amount;
}

int main() {
    int facing = 0; // In degrees
    double x = 0, y = 0;

    for (int i = 0; i < 769; i++) {
        char direction;
        cin >> direction;

        int amount;
        cin >> amount;

        switch (direction) {
        case 'N':
            y += amount;
            break;
        case 'S':
            y -= amount;
            break;
        case 'E':
            x += amount;
            break;
        case 'W':
            x -= amount;
            break;
        case 'L':
            facing += amount;
            break;
        case 'R':
            facing -= amount;
            break;
        case 'F':
            moveShip(x, y, facing, amount);
            break;
        }
    }

    cout << manhattanDistance(x, y) << endl;


    return 0;
}
