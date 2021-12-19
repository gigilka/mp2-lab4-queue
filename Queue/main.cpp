#include <iostream>
#include "TQueue.h"

using namespace std;

int main()
{
    TQueue<int> q;
    for (int i = 0; i < 10; i++){
        q.Push(i);
        cout << q<<endl;
    }
    for (int i = 0; i < 10; i++){
        q.Pop();
        cout << q << endl;
    }
    q.Push(123456789);
    cout << "Poping and pushin to copied queue"<<endl;
    TQueue<int> other(q);
    cout << other << endl;
    other.Pop();
    cout << other << endl;

    cout << "Second pop"<<endl;
    try{
        other.Pop();
    }
    catch (...){
        cout  << "Error catched" <<endl;
    }
    cout << "Trying to create queue with incorrect size(< 2)"<<endl;
    try{
        TQueue<char> q2(-2);
    }
    catch (...) {
        cout << "Error catched" << endl;
    }
    return 0;
}