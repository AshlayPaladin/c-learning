#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
    char c;
};

struct point *create_point(int x, int y, char c)
{
    struct point *p = malloc(sizeof *p);
    if(p == NULL)
    {
        return NULL;
    }

    p->x = x;
    p->y = y;
    p->c = c;

    return p;
}

void destroy_point(struct point *p)
{
    free(p);
}

void set_point_position(struct point *p, int newX, int newY)
{
    if (p == NULL) return;
    p->x = newX;
    p->y = newY;
}

void rename_point(struct point *p, char newC)
{
    if (p == NULL) return;
    p->c = newC;
}

void print_point(const struct point *p)
{
    if (p == NULL) {
        printf("(null point)\n");
        return;
    }
    printf("Point %c: (%d, %d)\n", p->c, p->x, p->y);
}

int main(void)
{
    struct point *p = create_point(10, 20, 'A');
    if(p == NULL)
    {
        return 1;
    }

    print_point(p);

    set_point_position(p, 50, 100);
    print_point(p);

    rename_point(p, 'H');
    print_point(p);

    destroy_point(p);
    p = NULL;
    print_point(p);

    return 0;
}
