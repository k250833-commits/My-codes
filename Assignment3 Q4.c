#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef long long ll;

typedef struct {
    int id;          
    int pop;         
    ll  lastAccess;  
    int used;        
} Book;
int i, qi;
int findIndexById(Book shelf[], int cap, int id) {
    for (i = 0; i < cap; ++i) {
        if (shelf[i].used && shelf[i].id == id) return i;
    }
    return -1;
}
int findLeastRecent(Book shelf[], int cap) {
    int idx = -1;
    ll minTime = LLONG_MAX;
    for (i = 0; i < cap; ++i) {
        if (shelf[i].used) {
            if (shelf[i].lastAccess < minTime) {
                minTime = shelf[i].lastAccess;
                idx = i;
            }
        }
    }
    return idx;
}
int currentCount(Book shelf[], int cap) {
    int c = 0;
    for (i = 0; i < cap; ++i) if (shelf[i].used) ++c;
    return c;
}

int main(void) {
    int capacity, Q;
    if (scanf("%d %d", &capacity, &Q) != 2) {
        return 0;
    }

    Book *shelf = malloc(sizeof(Book) * capacity);
    if (!shelf) return 0;

    for (i = 0; i < capacity; ++i) {
        shelf[i].used = 0;
        shelf[i].id = 0;
        shelf[i].pop = 0;
        shelf[i].lastAccess = 0;
    }

    ll timeCounter = 1;  

    char op[16];
    for (qi = 0; qi < Q; ++qi) {
        if (scanf("%s", op) != 1) break;

        if (strcmp(op, "ADD") == 0) {
            int x, y;
            scanf("%d %d", &x, &y); 

            int idx = findIndexById(shelf, capacity, x);
            if (idx != -1) {
                shelf[idx].pop = y;
                shelf[idx].lastAccess = timeCounter++;
            } else {
                int count = currentCount(shelf, capacity);
                if (count < capacity) {
                    for (i = 0; i < capacity; ++i) {
                        if (!shelf[i].used) {
                            shelf[i].used = 1;
                            shelf[i].id = x;
                            shelf[i].pop = y;
                            shelf[i].lastAccess = timeCounter++;
                            break;
                        }
                    }
                } else {
                    int evict = findLeastRecent(shelf, capacity);
                    shelf[evict].id = x;
                    shelf[evict].pop = y;
                    shelf[evict].lastAccess = timeCounter++;
                    shelf[evict].used = 1;
                }
            }
        }
        else if (strcmp(op, "ACCESS") == 0) {
            int x; scanf("%d", &x);
            int idx = findIndexById(shelf, capacity, x);
            if (idx == -1) {
                printf("-1\n");
            } else {
                printf("%d\n", shelf[idx].pop);
                shelf[idx].lastAccess = timeCounter++;
            }
        }
        else {
            char line[256];
            fgets(line, sizeof(line), stdin);
        }
    }

    free(shelf);
    return 0;
}

