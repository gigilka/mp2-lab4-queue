#pragma once
#include <string>
#include <iostream>
using namespace std;

template <class T>
class TQueue
{
	T* a;
	int msize;
	int first, last,count;
public:
	TQueue(int _msize = 10);
	TQueue(const TQueue<T>& smt);
	~TQueue();
	TQueue<T>& operator=(const TQueue<T>& smt);
	bool operator==(const TQueue<T>& smt) const;
	bool operator!=(const TQueue<T>& smt) const;
	bool IsEmpty();
	bool IsFull();
	void Push(T smt);
	T Pop();

	void Clear();

	friend std::ostream& operator<<(std::ostream& out, const TQueue& q)
	{
		for (int t = q.count, i = q.first; t > 0; t--)
		{
			out << q.a[i] << ' ';
			i = (++i) % q.msize;
		}
		return out;
	}
};
template <class T>
TQueue<T>::TQueue(int _msize) {
	if (_msize < 2) {
		trhow "Incorrect msize";
	}
	msize = _msize;
	a = new T[msize];
	count = 0;
	first = 0;
	last = -1;

}
template <class T>
TQueue<T>::TQueue(const TQueue<T>& smt) {
	msize = smt.msize;
	a = new t[msize];
	count = smt.count;
	first = smt.first;
	last = smt.last;
	for (int t = count, i = first; t > 0; t--)
	{
		a[i] = smt.a[i];
		i = (++i) % msize;
	}
}
template <class T>
TQueue<T>::~TQueue() {
	delete[] a;
}
template <class T>
TQueue<T>& TQueue<T>::operator=(const TQueue<T>& smt) {

}
