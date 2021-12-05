
typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point a;
    Point b;
} Metrix;

void swap(int* x, int* y)
{
    if (*x > *y) {
        int tmp = *x;
        *x = *y;
        *y = tmp;
    }
}

int main(int argc, char **argv)
{
    Metrix metrix[10];
    int x1 = metrix[0].a.x;
    int x2 = metrix[0].b.x;
    swap(&x1, &x2);
    
    for (int i = 1; i < 10; i++) {
        int *pointx1 = &metrix[i].a.x;
        int *pointx2 = &metrix[i].b.x;
        swap(&pointx1, &pointx2);
        if (x2 < *pointx1 || *pointx2 < x1) {
            printf("there is no common point\n");
            break;
        } else if (x1 < *pointx1) {
            x1 = *pointx1;
        } else if (x1 > *pointx2) {
            x2 = *pointx2;
        }
    }
    if (x1 = x2) {
        printf("交线是x = %d\n", x1);
    } else {
        printf("交线区域是 [%d, %d]\n", x1, x2);
    }
    return 0;
}