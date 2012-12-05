#ifndef MANAGEDPTRLSIT_H
#define MANAGEDPTRLSIT_H

#include <list>

using namespace std;

template <typename T>
class ManagedPtrList : public list<T*>
{
public:
	~ManagedPtrList();
};

template <typename T>
ManagedPtrList<T>::~ManagedPtrList()
{
	for (iterator i = begin(); i != end(); ++i)
	{
		delete *i;
	}
}

#endif