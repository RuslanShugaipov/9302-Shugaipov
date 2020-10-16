#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Руслан\source\repos\АлгиСтр(Лаба1)\АлгиСтр(Лаба1)\LinkedList.h"
#include "C:\Users\Руслан\source\repos\АлгиСтр(Лаба1)\АлгиСтр(Лаба1)\LinkedListcpp.cpp"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(LinkedListTests)
	{
	public:

		LinkedList* p,p1,p2;
		TEST_METHOD_INITIALIZE(setUp)
		{
			p = new LinkedList();
		}

		TEST_METHOD_CLEANUP(cleanUp)
		{
			delete p;
		}

		TEST_METHOD(push_back)
		{
			p->push_back(1);
			p->push_back(2);
			p->push_back(3);
			Assert::AreEqual(p->at(0), 1);
			Assert::AreEqual(p->at(1), 2);
			Assert::AreEqual(p->at(2), 3);
		}

		TEST_METHOD(push_front)
		{
			p->push_front(0);
			p->push_front(-1);
			p->push_front(-2);
			Assert::AreEqual(p->at(0), -2);
			Assert::AreEqual(p->at(1), -1);
			Assert::AreEqual(p->at(2), 0);
		}

		TEST_METHOD(pop_back)
		{
			p->push_back(1);
			p->push_back(2);
			p->push_back(3);
			p->pop_back();
			Assert::AreEqual(p->get_size(), size_t(2));
		}

		TEST_METHOD(pop_front)
		{
			p->push_back(1);
			p->push_back(2);
			p->pop_front();
			Assert::AreEqual(p->get_size(), size_t(1));
		}

		TEST_METHOD(insert)
		{
			p->push_back(1);
			p->push_back(3);
			p->insert(2, 1);
			Assert::AreEqual(p->at(0), 1);
			Assert::AreEqual(p->at(1), 2);
			Assert::AreEqual(p->at(2), 3);
		}

		TEST_METHOD(at)
		{
			p->push_back(9);
			p->push_back(10);
			Assert::AreEqual(p->at(1), 10);
		}

		TEST_METHOD(remove)
		{
			p->push_back(1);
			p->push_back(2);
			p->push_back(3);
			p->remove(1);
			Assert::AreEqual(p->at(0), 1);
		}

		TEST_METHOD(remove_front)
		{
			p->push_back(1);
			p->push_back(2);
			p->push_back(3);
			p->remove(0);
			Assert::AreEqual(p->at(0), 2);
		}

		TEST_METHOD(get_size)
		{
			Assert::AreEqual(p->get_size(), size_t(0));
		}

		TEST_METHOD(print_to_console)
		{
			Assert::IsTrue(p->isPrinted());
		}

		TEST_METHOD(clear)
		{
			p->push_back(1);
			p->push_back(2);
			p->push_back(3);
			p->clear();
			Assert::AreEqual(int(p->get_size()), 0);
		}

		TEST_METHOD(set)
		{
			p->push_back(1);
            p->push_back(2);
            p->push_back(3);
			p->set(1, 99);
			Assert::AreEqual(p->at(1), 99);
		}

		TEST_METHOD(isEmpty)
		{
			Assert::AreEqual(p->get_size(), size_t(0));
		}

		TEST_METHOD(find_first)
		{
			p1.push_back(0);
			p1.push_back(1);
			p1.push_back(2);
			p1.push_back(3);
			p2.push_back(1);
			p2.push_back(2);
			p2.push_back(3);
			Assert::AreEqual(p1.find_first(p1, p2), size_t(1));
		}
	};
}