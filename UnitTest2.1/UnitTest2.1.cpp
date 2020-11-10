#include "CppUnitTest.h"
#include "../Program_2.1/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest21
{
	TEST_CLASS(UnitTest21)
	{

	public:
		LinkedList* lst1, *lst2;
		// before each test
		TEST_METHOD_INITIALIZE(setUp)
		{
			lst1 = new LinkedList();
			lst2 = new LinkedList();
		}
		// after each test
		TEST_METHOD_CLEANUP(cleanUp)
		{
			delete lst1;
			delete lst2;
		}

		TEST_METHOD(at_correct_index)
		{
			lst1->push_back(1);
			lst1->push_back(2);
			lst1->push_back(3);
			Assert::AreEqual(lst1->at(1), 2);
		}
		TEST_METHOD(at_incorrect_index)
		{
			try {
				lst1->at(-1);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Index is greater than list size", e.what());
			}

		}
		TEST_METHOD(get_size_empty)
		{
			Assert::AreEqual(lst1->get_size(), size_t(0));

		}
		TEST_METHOD(get_size_full)
		{
			lst1->push_back(1);
			lst1->push_back(2);
			Assert::AreEqual(lst1->get_size(), size_t(2));

		}
		TEST_METHOD(push_front_full)
		{
			lst1->push_back(2);
			lst1->push_back(3);
			lst1->push_front(1);
			Assert::AreEqual(lst1->at(0), 1);

		}
		TEST_METHOD(push_front_connection_with_next_elem)
		{
			lst1->push_back(2);
			lst1->push_back(3);
			lst1->push_front(1);
			Assert::AreEqual(lst1->at(1), 2);
		}
		TEST_METHOD(push_front_size)
		{
			lst1->push_front(1);
			Assert::AreEqual(lst1->get_size(), size_t(1));
		}
		TEST_METHOD(push_back_empty)
		{
			lst1->push_back(1);
			Assert::AreEqual(lst1->at(0), 1);
		}
		TEST_METHOD(push_back_full)
		{
			lst1->push_front(1);
			lst1->push_back(2);
			Assert::AreEqual(lst1->at(1), 2);
		}
		TEST_METHOD(push_back_size)
		{
			lst1->push_back(1);
			Assert::AreEqual(lst1->get_size(), size_t(1));
		}
		TEST_METHOD(pop_back_empty)
		{

			try {
				lst1->pop_back();
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Last elem not found", e.what());
			}
		}
		TEST_METHOD(pop_back_full_size)
		{
			lst1->push_back(1);
			lst1->push_back(2);
			lst1->pop_back();
			Assert::AreEqual(lst1->get_size(), size_t(1));
		}
		TEST_METHOD(pop_back_full_last_elem)
		{
			lst1->push_back(1);
			lst1->push_back(2);
			lst1->push_back(3);
			lst1->pop_back();
			Assert::AreEqual(lst1->at(lst1->get_size() - 1), 2);
		}
		TEST_METHOD(pop_front_empty)
		{

			try {
				lst1->pop_front();
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("First elem not found", e.what());
			}
		}
		TEST_METHOD(pop_front_full_size)
		{
			lst1->push_back(1);
			lst1->push_back(2);
			lst1->pop_front();
			Assert::AreEqual(lst1->get_size(), size_t(1));
		}
		TEST_METHOD(pop_front_full_last_elem)
		{
			lst1->push_back(1);
			lst1->push_back(2);
			lst1->push_back(3);
			lst1->pop_front();
			Assert::AreEqual(lst1->at(0), 2);
		}
		TEST_METHOD(insert_index_out_of_range)
		{

			try {
				lst1->push_back(1);
				lst1->insert(1, 2);
			}
			catch(std::out_of_range e) {
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}

		TEST_METHOD(insert_index_0)
		{
			lst1->push_back(2);
			lst1->push_back(3);
			lst1->insert(1, 0);
			
			Assert::AreEqual(lst1->at(0), 1);
		}
		TEST_METHOD(insert_full)
		{
			lst1->push_back(1);
			lst1->push_back(2);
			lst1->push_back(4);
			lst1->insert(3, 2);
			Assert::AreEqual(lst1->at(2), 3);
		}
		TEST_METHOD(insert_full_connection_with_next_elem)
		{
			lst1->push_back(1);
			lst1->push_back(2);
			lst1->push_back(4);
			lst1->insert(3, 2);
			Assert::AreEqual(lst1->at(3), 4);
		}
	
		TEST_METHOD(remove_index_out_of_range)
		{
			try {
				lst1->push_back(1);
				lst1->remove(12);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Index is greater than list size", e.what());
			}

		}
		TEST_METHOD(remove)
		{
			lst1->push_back(1);
			lst1->push_back(2);
			lst1->push_back(3);
			lst1->remove(1);
			Assert::AreEqual(lst1->at(1), 3);
		}
		TEST_METHOD(clear)
		{
			/*lst1->push_back(1);
			lst1->push_back(2);
			lst1->push_back(3);*/
			lst1->clear();
			Assert::IsTrue(lst1->isEmpty());
		}
		TEST_METHOD(set_index_out_of_range)
		{

			try {
				lst1->push_back(1);
				lst1->set(1, 2);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}
		TEST_METHOD(set)
		{
			lst1->push_back(1);
			lst1->push_back(6);
			lst1->push_back(3);
			lst1->set(1, 2);
			Assert::AreEqual(lst1->at(1), 2);
		}
		TEST_METHOD(isEmpty_full)
		{
			lst1->push_back(1);
			Assert::IsFalse(lst1->isEmpty());
		}
		TEST_METHOD(isEmpty_empty)
		{
			Assert::IsTrue(lst1->isEmpty());
		}
		TEST_METHOD(contains_yes)
		{
			lst1->push_back(1);
			lst1->push_back(2);
			lst1->push_back(3);
			lst2->push_back(2);
			lst2->push_back(3);
			Assert::IsTrue(lst1->contains(lst2));
		}
		TEST_METHOD(contains_no)
		{
			lst1->push_back(1);
			lst1->push_back(2);
			lst2->push_back(3);
			Assert::IsFalse(lst1->contains(lst2));
		}
		TEST_METHOD(contains_error_in_first_sequence_of_concurrence)
		{
			lst1->push_back(1);
			lst1->push_back(2);
			lst1->push_back(1);
			lst1->push_back(2);
			lst1->push_back(3);
			lst2->push_back(1);
			lst2->push_back(2);
			lst2->push_back(3);
			Assert::IsTrue(lst1->contains(lst2));
		}
		TEST_METHOD(contains_full_ingoing)
		{
			lst1->push_back(1);
			lst1->push_back(2);
			lst2->push_back(1);
			lst2->push_back(2);
			Assert::IsTrue(lst1->contains(lst2));
		}
		TEST_METHOD(contains_empty)
		{
			
			try 
			{
				lst1->contains(lst2);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("The list is empty", e.what());
			}
		}
		TEST_METHOD(contains_lst2_greater_then_lst1)
		{
			try
			{
				lst1->push_back(1);
				lst2->push_back(1);
				lst2->push_back(2);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Second list is greater then first list", e.what());
			}
		}
	};
}
