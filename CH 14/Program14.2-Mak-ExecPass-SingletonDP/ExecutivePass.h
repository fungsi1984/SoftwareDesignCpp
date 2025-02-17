#ifndef EXECUTIVEPASS_H_
#define EXECUTIVEPASS_H_

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class ExecutivePass
{
public:
    ~ExecutivePass();

    ExecutivePass(ExecutivePass& other) = delete;
    ExecutivePass& operator =(ExecutivePass& other) = delete;

    int get_key() const { return key; }

    static ExecutivePass *obtain(const string holder);

    void print()
    {
        cout << "Executive pass now held by " << holder
             << ", key = " << key << endl;
    }

private:
    ExecutivePass() : key(generate_key()) {}

    static ExecutivePass *single_instance;

    int key;
    string holder;

    int generate_key() const { return rand()%10000 + 1000; }
};

#endif /* EXECUTIVEPASS_H_ */
