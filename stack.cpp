#include <iostream>
#define MAXQUEUE 100
using namespace std;

typedef struct {
    int front;
    int rear;
    int count;
    int data[MAXQUEUE];
} Queue;

Queue antrian;

void init(Queue *q) {
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}

void enqueue(int value, Queue *q) {
    if (q->count == MAXQUEUE) {
        cout << "Maaf antrian penuh" << endl;
    } else {
        q->data[q->rear] = value;
        q->rear = (q->rear + 1) % MAXQUEUE;
        ++(q->count);
    }
}

void dequeue(Queue *q, int *datanya) {
    if (q->count == 0) {
        cout << "Maaf masih kosong" << endl;
    } else {
        *datanya = q->data[q->front];
        q->front = (q->front + 1) % MAXQUEUE;
        --(q->count);
    }
}

int main() {
    int a;
    init(&antrian);
    enqueue(10, &antrian);
    enqueue(11, &antrian);
    enqueue(12, &antrian);
    enqueue(13, &antrian);
    
    dequeue(&antrian, &a);
    cout << "Nilai terambil adalah "<<a;
    dequeue(&antrian, &a);
    cout << "\nNilai terambil adalah "<<a;
    dequeue(&antrian, &a);
    cout << "\nNilai terambil adalah "<<a;
    dequeue(&antrian, &a);

    return 0;
}