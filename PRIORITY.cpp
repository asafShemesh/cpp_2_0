// asaf0604@gmail.com 325362457
struct Pair
{
    int vertex;
    int priority;
};

class PriorityQueue
{
private:
    Pair *arr;
    int capacity;
    int size;

public:
    PriorityQueue(int cap)
    {
        capacity = cap;
        arr = new Pair[capacity];
        size = 0;
    }

    ~PriorityQueue()
    {
        delete[] arr;
    }

    void enqueue(Pair value)
    {
        if (size == capacity)
        {
            return;
        }

        int i = size - 1;
        while (i >= 0 && arr[i].priority > value.priority)
        {
            arr[i + 1] = arr[i];
            i--;
        }

        arr[i + 1] = value;
        size++;
    }

    Pair dequeue()
    {
        if (isEmpty())
        {
            return {-1, -1}; 
        }

        Pair value = arr[0];
        for (int i = 1; i < size; i++)
        {
            arr[i - 1] = arr[i];
        }

        size--;
        return value;
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    int getSize() const
    {
        return size;
    }
};
