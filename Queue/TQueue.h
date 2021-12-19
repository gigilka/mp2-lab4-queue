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

	friend std::ostream& operator<<(std::ostream& out, const TQueue& q){
		for (int t = q.count, i = q.first; t > 0; t--){
			out << q.a[i] << ' ';
			i = (++i) % q.msize;
		}
		return out;
	}
};
template <class T>
TQueue<T>::TQueue(int _msize) {
	if (_msize < 2) {
		throw "Incorrect size";
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
	a = new T[msize];
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
	if(this == &smt)
		return *this;

	if (msize != smt.msize) {
		msize = smt.msize;
		delete[] a;
		a = new T[msize];
	}
	count = smt.count;
	first = smt.first;
	last = smt.last;
	for (int t = count, i = first; t > 0; t--)
	{
		a[i] = smt.a[i];
		i = (++i) % msize;
	}
	return *this;
}
template <class T>
bool TQueue<T>::operator==(const TQueue<T>& smt) const
{
	if (msize != smt.msize) {
		return false;
	}
	if (count != smt.count) {
		return false;
	}
	if (first != smt.first){
		return false;
	}
	if (last != smt.last) {
		return false;
	}
	for (int t = count, i = first; t > 0; t--)
	{
		if (a[i] != smt.a[i]) {
			return false;
		}
		i = (++i) % msize;
	}
	return true;
}
template <class T>
bool TQueue<T>::operator!=(const TQueue<T>& smt) const{
	return !operator==(smt);
}
template <class T>
bool TQueue<T>::IsEmpty(){
	return count == 0;
}
template <class T>
bool TQueue<T>::IsFull(){
	return count == msize;
}
template <class T>
void TQueue<T>::Push(T smt){
	if (IsFull())
		throw "Full queue";
	last = (++last) % msize;
	a[last] = smt;
	count++;
}
template <class T>
T TQueue<T>::Pop(){
	if (IsEmpty())
		throw "Empty queue";
	T smt = a[first];
	first = (++first) % msize;
	count--;
	return smt;
}
template <class T>
void TQueue<T>::Clear(){
	count = 0;
	last = -1, first = 0;
}