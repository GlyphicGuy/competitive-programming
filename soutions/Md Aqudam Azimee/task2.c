#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *items;
    int front;
    int rear;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->items = (int*)malloc(sizeof(int) * capacity);
    q->front = 0;
    q->rear = 0;
    q->capacity = capacity;
    return q;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void push(Queue* q, int value) {
    q->items[q->rear % q->capacity] = value;
    q->rear++;
}

int pop(Queue* q) {
    int item = q->items[q->front % q->capacity];
    q->front++;
    return item;
}

void freeQueue(Queue* q) {
    free(q->items);
    free(q);
}

char* predictPartyVictory(char* senate) {
    int n = strlen(senate);
    Queue* qr = createQueue(n);
    Queue* qd = createQueue(n);

    for (int i = 0; i < n; i++) {
        if (senate[i] == 'R') {
            push(qr, i);
        } else {
            push(qd, i);
        }
    }

    while (!isEmpty(qr) && !isEmpty(qd)) {
        int r = pop(qr);
        int d = pop(qd);

        if (r < d) {
            push(qr, r + n);
        } else {
            push(qd, d + n);
        }
    }

    char* result;
    if (!isEmpty(qr)) {
        result = "Radiant";
    } else {
        result = "Dire";
    }

    freeQueue(qr);
    freeQueue(qd);

    return result;
}

int main() {
    char senate[10000];

    printf("Enter the senate string (R/D): ");
    if (scanf("%s", senate) != 1) {
        return 0;
    }

    char* result = predictPartyVictory(senate);
    printf("%s\n", result);

    return 0;
}