#include "b.h"

static int sI1 = 1;

void bAdd() {
    sI1 -= 1;
    f1();
}

int bV() {
    return sI1;
}

void f1() {
    sI1 -= 10;
}

void b::f1() {
    sI1 -= 5;
}

void b::test() {

}
