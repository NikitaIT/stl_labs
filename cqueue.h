#ifndef CQUEUE
#define CQUEUE
#include <assert.h>
class CQueue
{
public:
    CQueue(int size);
    ~CQueue(){delete[] _buffer;}
    void Enqueue(int a);
    int Dnqueue();

    bool isEmpty() const { return _head == _tail;}
private:
    int* _buffer;
    int _bufferSize;
    int _head;
    int _tail;
};
CQueue::CQueue(int size):
    _bufferSize(size),
    _head(0),
    _tail(0)
{
    _buffer = new int[_bufferSize];
}

void CQueue::Enqueue(int a)
{
    assert((_tail + 1) % _bufferSize != _head);
    _buffer[_tail]=a;
    _tail = (_tail + 1) % _bufferSize;
}

int CQueue::Dnqueue()
{
    assert(_tail != _head);
    int result = _buffer[_head];
    _head = (_head + 1) % _bufferSize;
    return result;
}



#endif // CQUEUE

