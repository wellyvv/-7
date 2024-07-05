#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int intersection_points(int x1, int y1, int r1, int x2, int y2, int r2) {
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    int sum_radii = r1 + r2;
    int diff_radii = abs(r1 - r2);

    if (distance == 0) {
        if (r1 == r2) {
            return -1;  
        }
        else {
            return 0;  
        }
    }
    else if (distance > sum_radii || distance < diff_radii) {
        return 0;       
    }
    else if (distance == sum_radii || distance == diff_radii) {
        return 1;      
    }
    else {
        return 2;       
    }
}

int main() {
    setlocale(LC_ALL, "Ukr");
    int x1, y1, r1, x2, y2, r2;
    printf("Введiть координати та радiуси двох колiв через пробiл (x1 y1 r1 x2 y2 r2): ");
    scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

    int points = intersection_points(x1, y1, r1, x2, y2, r2);

    if (points == -1) {
        printf("Кола збiгаються, безкiнечно багато точок перетину\n");
    }
    else {
        printf("Кiлькiсть точок перетину: %d\n", points);
    }

    return 0;
}
