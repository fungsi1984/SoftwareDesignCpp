#ifndef CIRCULARBUFFER_H_
#define CIRCULARBUFFER_H_

#include <vector>

using namespace std;

class CircularBuffer
{
public:
    CircularBuffer(const int cap);

    void add(const int value);
    int remove();

    friend ostream& operator <<(ostream& ostr,
                                CircularBuffer& buffer);

private:
    int capacity;
    int head, tail;
    int count;

    vector<int> buffer;
};

#endif /* CIRCULARBUFFER_H_ */