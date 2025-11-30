#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX 1024

typedef struct {
    char **lines;
    size_t count;
    size_t capacity;
} LineBuffer;

void initBuffer(LineBuffer *b) {
    b->count = 0;
    b->capacity = 4;
    b->lines = (char **) malloc(b->capacity * sizeof(char *));
    if (b->lines == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
}

void freeAll(LineBuffer *b) {
    size_t i;
    if (b->lines == NULL) return;
    for (i = 0; i < b->count; ++i) free(b->lines[i]);
    free(b->lines);
    b->lines = NULL;
    b->count = b->capacity = 0;
}

void ensureCapacity(LineBuffer *b, size_t min) {
    char **tmp;
    size_t nc;
    if (b->capacity >= min) return;
    nc = b->capacity * 2;
    while (nc < min) nc *= 2;
    tmp = (char **) realloc(b->lines, nc * sizeof(char *));
    if (tmp == NULL) {
        perror("realloc");
        freeAll(b);
        exit(EXIT_FAILURE);
    }
    b->lines = tmp;
    b->capacity = nc;
}

void insertLine(LineBuffer *b, size_t index, const char *text) {
    char *s;
    size_t len;
    if (index > b->count) {
        fprintf(stderr, "insert: bad index\n");
        return;
    }
    ensureCapacity(b, b->count + 1);
    if (index < b->count) {
        memmove(&b->lines[index + 1], &b->lines[index],
                (b->count - index) * sizeof(char *));
    }
    len = strlen(text);
    s = (char *) malloc(len + 1);
    if (s == NULL) {
        perror("malloc");
        freeAll(b);
        exit(EXIT_FAILURE);
    }
    strcpy(s, text);
    b->lines[index] = s;
    b->count++;
}

void deleteLine(LineBuffer *b, size_t index) {
    if (index >= b->count) {
        fprintf(stderr, "delete: bad index\n");
        return;
    }
    free(b->lines[index]);
    if (index + 1 < b->count) {
        memmove(&b->lines[index], &b->lines[index + 1],
                (b->count - index - 1) * sizeof(char *));
    }
    b->count--;
}

void printAllLines(const LineBuffer *b) {
    size_t i;
    for (i = 0; i < b->count; ++i) {
        printf("%4u: %s\n", (unsigned)(i + 1), b->lines[i]);
    }
}

void shrinkToFit(LineBuffer *b) {
    char **tmp;
    if (b->count == 0) {
        if (b->lines) free(b->lines);
        b->lines = NULL;
        b->capacity = 0;
        return;
    }
    tmp = (char **) realloc(b->lines, b->count * sizeof(char *));
    if (tmp != NULL) {
        b->lines = tmp;
        b->capacity = b->count;
    } /* if realloc fails, keep old allocation */
}

int saveToFile(const LineBuffer *b, const char *fname) {
    FILE *f;
    size_t i;
    f = fopen(fname, "w");
    if (f == NULL) {
        perror("fopen");
        return -1;
    }
    for (i = 0; i < b->count; ++i) {
        if (fprintf(f, "%s\n", b->lines[i]) < 0) {
            perror("fprintf");
            fclose(f);
            return -1;
        }
    }
    if (fclose(f) != 0) {
        perror("fclose");
        return -1;
    }
    return 0;
}

int loadFromFile(LineBuffer *b, const char *fname) {
    FILE *f;
    char buf[LINE_MAX];
    size_t oldcount;
    f = fopen(fname, "r");
    if (f == NULL) return -1;
    /* free existing lines */
    oldcount = b->count;
    while (b->count > 0) deleteLine(b, 0);
    while (fgets(buf, LINE_MAX, f) != NULL) {
        buf[strcspn(buf, "\n")] = '\0';
        insertLine(b, b->count, buf);
    }
    fclose(f);
    return 0;
}

void readLineSimple(char *buf, size_t n) {
    if (fgets(buf, n, stdin) == NULL) {
        buf[0] = '\0';
        return;
    }
    buf[strcspn(buf, "\n")] = '\0';
}

int main(void) {
    LineBuffer buf;
    char cmd;
    char line[LINE_MAX];
    size_t idx;
    initBuffer(&buf);
    printf("Simple editor (C89). File: buffer.txt\n");
    for (;;) {
        printf("\nCommands: a=append i=insert d=delete p=print s=save l=load r=shrink q=quit\nChoice: ");
        if (scanf(" %c", &cmd) != 1) break;
        while (getchar() != '\n'); /* clear rest */
        if (cmd == 'a') {
            printf("Enter line: ");
            readLineSimple(line, LINE_MAX);
            if (line[0] != '\0') insertLine(&buf, buf.count, line);
        } else if (cmd == 'i') {
            printf("Index (1-based): ");
            if (scanf("%u", (unsigned *)&idx) != 1) { while(getchar()!='\n'); continue; }
            while (getchar() != '\n');
            if (idx < 1 || idx > buf.count + 1) { printf("Range 1..%u\n", (unsigned)(buf.count + 1)); continue; }
            printf("Enter line: ");
            readLineSimple(line, LINE_MAX);
            insertLine(&buf, idx - 1, line);
        } else if (cmd == 'd') {
            printf("Index (1-based): ");
            if (scanf("%u", (unsigned *)&idx) != 1) { while(getchar()!='\n'); continue; }
            while (getchar() != '\n');
            if (idx < 1 || idx > buf.count) { printf("Range 1..%u\n", (unsigned)buf.count); continue; }
            deleteLine(&buf, idx - 1);
        } else if (cmd == 'p') {
            printAllLines(&buf);
        } else if (cmd == 's') {
            if (saveToFile(&buf, "buffer.txt") == 0) printf("Saved to buffer.txt\n");
            else printf("Save failed\n");
        } else if (cmd == 'l') {
            if (loadFromFile(&buf, "buffer.txt") == 0) printf("Loaded from buffer.txt\n");
            else printf("Load failed or file not found\n");
        } else if (cmd == 'r') {
            shrinkToFit(&buf);
            printf("Shrunk: count=%u cap=%u\n", (unsigned)buf.count, (unsigned)buf.capacity);
        } else if (cmd == 'q') {
            freeAll(&buf);
            break;
        } else {
            printf("Unknown command\n");
        }
    }
    return 0;
}

