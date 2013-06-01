#include <cppunit/config/SourcePrefix.h>
#include "ManagedPtrListTestCase.h"
#include "ManagedPtrList.h"
#include "AutoPtr.h"

CPPUNIT_TEST_SUITE_REGISTRATION(ManagedPtrListTestCase);

class Node
{
public:
	int i_;

	Node(int i):i_(i)
	{
	}

	~Node()
	{
		cout << "Inside ~Node() of: " << i_ << endl;
	}
};

void ManagedPtrListTestCase::setUp()
{
}

void ManagedPtrListTestCase::testList()
{
	ManagedPtrList<Node> ml;

	ml.push_back(new Node(5));
	ml.push_back(new Node(6));
	ml.push_back(new Node(7));

	for (ManagedPtrList<Node>::iterator i = ml.begin(); 
		 i != ml.end(); ++i)
	{
		cout << "Accessing " << (*i)->i_ << endl;
	}
}

void ManagedPtrListTestCase::testAutoPtr()
{
	{
		AutoPtr<Node> a(new Node(10));

		cout << "Testing * and -> " << (*a).i_ << " "
			 << a->i_ << endl;
	}

	Node *n;

	{
		AutoPtr<Node> b(new Node(5));
		n = b.release();
	}

	cout << "Node of 5 will be destroyed after this." << endl;

	delete n;

	cout << endl;
}