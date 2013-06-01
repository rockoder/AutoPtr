#ifndef ManagedPtrListTestCase_H
#define ManagedPtrListTestCase_H

#include <cppunit/extensions/HelperMacros.h>

class ManagedPtrListTestCase : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(ManagedPtrListTestCase);
	CPPUNIT_TEST(testList);
	CPPUNIT_TEST(testAutoPtr);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();

protected:
	void testList();
	void testAutoPtr();
};

#endif