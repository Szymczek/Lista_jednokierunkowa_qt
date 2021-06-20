#include <iostream>
#include"Circle.h"
#include <cmath>
#include <sstream>
using namespace std;

void addCircleAtTheEnd(Circle** head, double x, double y, double radius){

    Circle* newCircle = new Circle();
    newCircle->x = x;
    newCircle->y = y;
    newCircle->radius = radius;
    newCircle->next = NULL;

    if (radius < 0) {
        delete newCircle;
        return;
    }
    if (*head == NULL) {
        *head = newCircle;
        return;
    }
    Circle* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newCircle;

}

void printList(Circle* adress){
    while (adress != NULL)
    {
        cout << "(" << adress->x << "," << adress->y << "," << adress->radius << ")" ;
        adress = adress->next;
    }
}

void addCircleAtTheFront(Circle** head, double x, double y, double radius){
    Circle* newCircle = new Circle();
    newCircle->x = x;
    newCircle->y = y;
    if (radius < 0) {
        delete newCircle;
        return;
    }
    newCircle->radius = radius;
    newCircle->next = *head;
    *head = newCircle;
}

void deleteList(Circle* head){
    Circle* previous;
    while (head != NULL)
    {
        previous = head;
        head = head->next;
        delete previous;
    }
}

void clearList(Circle *&head){
    if(head==0) return;
    clearList(head->next);
    delete head->next;
}
void sortByOrigin(Circle* head) {
    Circle* i, * j;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            double currentDistance = sqrt(pow(i->x, 2) + pow(i->y, 2));
            double nextDistance = sqrt(pow(j->x, 2) + pow(j->y, 2));
            if (nextDistance < currentDistance) {
                swap(i->x, j->x);
                swap(i->y, j->y);
            }
        }
    }
}

