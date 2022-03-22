#include <iostream>
using namespace std;

class Queue
{
public:
    int front, rear, size;
    unsigned capacity;
    int *array;
};

Queue *createQueue(unsigned _capacity)
{
    Queue *q = new Queue();
    q->capacity = _capacity;
    q->front = 0;
    q->size = 0;
    q->rear = _capacity - 1;
    q->array = new int[q->capacity];
    return q;
}

bool isFull(Queue *q)
{
    if (q->size == q->capacity)
        return true;
    return false;
}

bool isEmpty(Queue *q)
{
    if (q->size == 0)
        return true;
    return false;
}

void endQueue(Queue *q, int i)
{
    // check if the queue is full.
    if (isFull(q))
        return;
    // update rear
    q->rear = (q->rear + 1) % q->capacity;
    q->array[q->rear] = i;
    q->size += 1;
    cout << i << " enqueued to queue\n";
}

int dequeue(Queue *q)
{
    if (isEmpty(q)) return INT_MIN;
    int i = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size -= 1;
    return i;
}

int front(Queue *q)
{
    if (isEmpty(q))
        return INT_MIN;
    return q->array[q->front];
}

int rear(Queue *q)
{
    if (isEmpty(q))
        return INT_MIN;
    return q->array[q->rear];
}

int main()
{
    Queue *queue = createQueue(1000);

    endQueue(queue, 10);
    endQueue(queue, 20);
    endQueue(queue, 30);
    endQueue(queue, 40);

    cout << dequeue(queue)
         << " dequeued from queue\n";
    cout << "Front item is "
         << front(queue) << endl;
    cout << "Rear item is "
         << rear(queue) << endl;
 
    return 0;
}