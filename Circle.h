#ifndef CIRCLE_H
#define CIRCLE_H
#include <string>
struct Circle {
    double x;
    double y;
    double radius;
    Circle* next;
};

void addCircleAtTheEnd(Circle** head, double x, double y, double radius);
void printList(Circle* adress);
void addCircleAtTheFront(Circle** head, double x, double y, double radius);
void deleteList(Circle* head);
void clearList(Circle *&head);
void sortByOrigin(Circle* head);

//void searchBelowOrigin(Circle* head, double distance);
//void deleteCircleBelowOrigin(Circle*& head, double distance);


#endif // CIRCLE_H
