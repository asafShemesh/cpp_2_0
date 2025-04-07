// asaf0604@gmail.com 325362457

class Queue
{
private:
    int *arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    Queue(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue()
    {
        delete[] arr;
    }

    void enqueue(int value)
    {
        if (size == capacity)
        {
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    bool isEmpty() const
    {
        return size == 0;
    }
};
