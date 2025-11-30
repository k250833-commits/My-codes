

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h> 
#include <errno.h>

#define DBFILE "members.dat"
#define NAME_MAX 100

typedef struct {
    int id;
    char name[NAME_MAX];
    char batch[32];
    char membership[8];
    char regDate[11];
    char dob[11];
    char interest[8];
} Student;

typedef struct {
    Student *arr;
    size_t count;
    size_t cap;
} DB;

DB db;

/* ensure capacity */
void ensureCap(size_t need) {
    Student *t;
    size_t n;
    if (db.cap >= need) return;
    n = db.cap ? db.cap * 2 : 8;
    while (n < need) n *= 2;
    t = (Student *) realloc(db.arr, n * sizeof(Student));
    if (t == NULL) {
        perror("realloc");
        free(db.arr);
        exit(EXIT_FAILURE);
    }
    db.arr = t;
    db.cap = n;
}

/* load/save database (binary) */
int loadDatabase(const char *fname) {
    FILE *f;
    long sz;
    size_t cnt;
    f = fopen(fname, "rb");
    if (f == NULL) return 0; /* start empty if file missing */
    if (fseek(f, 0, SEEK_END) != 0) { perror("fseek"); fclose(f); return -1; }
    sz = ftell(f);
    if (sz < 0) { perror("ftell"); fclose(f); return -1; }
    rewind(f);
    cnt = (size_t)(sz / sizeof(Student));
    db.arr = (Student *) malloc(cnt * sizeof(Student));
    if (db.arr == NULL && cnt > 0) { perror("malloc"); fclose(f); exit(EXIT_FAILURE); }
    if (cnt > 0) {
        if (fread(db.arr, sizeof(Student), cnt, f) != cnt) { perror("fread"); fclose(f); return -1; }
    }
    db.count = cnt;
    db.cap = cnt;
    fclose(f);
    return 0;
}

int saveDatabase(const char *fname) {
    FILE *f;
    f = fopen(fname, "wb");
    if (f == NULL) { perror("fopen"); return -1; }
    if (db.count > 0) {
        if (fwrite(db.arr, sizeof(Student), db.count, f) != db.count) {
            perror("fwrite");
            fclose(f);
            return -1;
        }
    }
    if (fclose(f) != 0) { perror("fclose"); return -1; }
    return 0;
}

/* find by id */
int findIndex(int id) {
    size_t i;
    for (i = 0; i < db.count; ++i) {
        if (db.arr[i].id == id) return (int)i;
    }
    return -1;
}

/* add/update/delete */
int addStudent(const Student *s) {
    if (findIndex(s->id) != -1) {
        printf("Duplicate ID\n");
        return -1;
    }
    ensureCap(db.count + 1);
    db.arr[db.count++] = *s;
    return saveDatabase(DBFILE);
}

int updateStudent(int id) {
    int idx;
    char tmp[128];
    idx = findIndex(id);
    if (idx < 0) { printf("Not found\n"); return -1; }
    printf("Current batch: %s\nNew batch (blank keep): ", db.arr[idx].batch);
    if (fgets(tmp, sizeof(tmp), stdin) != NULL) {
        tmp[strcspn(tmp, "\n")] = '\0';
        if (tmp[0]) {
            strncpy(db.arr[idx].batch, tmp, sizeof(db.arr[idx].batch) - 1);
            db.arr[idx].batch[sizeof(db.arr[idx].batch) - 1] = '\0';
        }
    }
    printf("Current membership: %s\nNew membership (blank keep): ", db.arr[idx].membership);
    if (fgets(tmp, sizeof(tmp), stdin) != NULL) {
        tmp[strcspn(tmp, "\n")] = '\0';
        if (tmp[0]) {
            strncpy(db.arr[idx].membership, tmp, sizeof(db.arr[idx].membership) - 1);
            db.arr[idx].membership[sizeof(db.arr[idx].membership) - 1] = '\0';
        }
    }
    return saveDatabase(DBFILE);
}

int deleteStudent(int id) {
    int idx;
    idx = findIndex(id);
    if (idx < 0) { printf("Not found\n"); return -1; }
    if ((size_t)idx + 1 < db.count) {
        memmove(&db.arr[idx], &db.arr[idx + 1], (db.count - idx - 1) * sizeof(Student));
    }
    db.count--;
    return saveDatabase(DBFILE);
}

void printAll(void) {
    size_t i;
    if (db.count == 0) { puts("No records."); return; }
    for (i = 0; i < db.count; ++i) {
        printf("%d | %s | %s | %s | %s | %s | %s\n",
               db.arr[i].id, db.arr[i].name, db.arr[i].batch,
               db.arr[i].membership, db.arr[i].regDate, db.arr[i].dob, db.arr[i].interest);
    }
}

void batchReport(const char *batch, const char *member) {
    size_t i;
    for (i = 0; i < db.count; ++i) {
        if (strcasecmp(db.arr[i].batch, batch) == 0) {
            if (member == NULL || member[0] == '\0' ||
                strcasecmp(db.arr[i].membership, member) == 0 ||
                (strcasecmp(member, "Both") == 0 && strcasecmp(db.arr[i].interest, "Both") == 0)) {
                printf("%d | %s | %s\n", db.arr[i].id, db.arr[i].name, db.arr[i].membership);
            }
        }
    }
}

/* safe readLine helper */
void readLine(char *buf, size_t n) {
    if (fgets(buf, n, stdin) == NULL) { buf[0] = '\0'; return; }
    buf[strcspn(buf, "\n")] = '\0';
}

int main(void) {
    char line[256];
    int choice;
    Student s;
    int id;
    db.arr = NULL;
    db.count = db.cap = 0;

    if (loadDatabase(DBFILE) == 0) printf("Loaded %u records\n", (unsigned)db.count);

    for (;;) {
        printf("\n1:Add 2:Update 3:Delete 4:List 5:Report 6:Exit\nChoice: ");
        readLine(line, sizeof(line));
        if (line[0] == '\0') continue;
        if (sscanf(line, "%d", &choice) != 1) { printf("Invalid choice\n"); continue; }

        if (choice == 1) {
            /* Read ID using readLine + sscanf */
            printf("ID: ");
            readLine(line, sizeof(line));
            if (sscanf(line, "%d", &s.id) != 1) { printf("Invalid ID\n"); continue; }
            if (findIndex(s.id) >= 0) { printf("Duplicate\n"); continue; }

            printf("Name: "); readLine(s.name, sizeof(s.name));
            printf("Batch: "); readLine(s.batch, sizeof(s.batch));
            printf("Membership: "); readLine(s.membership, sizeof(s.membership));
            printf("RegDate: "); readLine(s.regDate, sizeof(s.regDate));
            printf("DOB: "); readLine(s.dob, sizeof(s.dob));
            printf("Interest: "); readLine(s.interest, sizeof(s.interest));

            if (addStudent(&s) == 0) printf("Added and saved\n"); else printf("Save failed\n");

        } else if (choice == 2) {
            printf("ID: "); readLine(line, sizeof(line));
            if (sscanf(line, "%d", &id) != 1) { printf("Invalid ID\n"); continue; }
            updateStudent(id);

        } else if (choice == 3) {
            printf("ID: "); readLine(line, sizeof(line));
            if (sscanf(line, "%d", &id) != 1) { printf("Invalid ID\n"); continue; }
            deleteStudent(id);

        } else if (choice == 4) {
            printAll();

        } else if (choice == 5) {
            char batch[64], member[16];
            printf("Batch: "); readLine(batch, sizeof(batch));
            printf("Membership filter (blank for any): "); readLine(member, sizeof(member));
            batchReport(batch, member);

        } else if (choice == 6) {
            saveDatabase(DBFILE);
            if (db.arr) free(db.arr);
            break;

        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}

