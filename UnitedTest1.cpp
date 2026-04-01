#include "CppUnitTest.h"
#include "../task4/LinkedList.h"
#include <sstream>
#include <stdexcept>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace containers;

namespace Tests
{
    TEST_CLASS(LinkedListTests)
    {
    public:
        // 1. Тест конструктора по умолчанию
        TEST_METHOD(TestDefaultConstructor)
        {
            LinkedList<int> list;
            Assert::AreEqual(size_t(0), list.getSize());
            Assert::IsTrue(list.isEmpty());
        }

        // 2. Тест конструктора со списком инициализации
        TEST_METHOD(TestInitializerListConstructor)
        {
            LinkedList<int> list = { 1, 2, 3, 4, 5 };
            Assert::AreEqual(size_t(5), list.getSize());
            Assert::AreEqual(1, list[0]);
            Assert::AreEqual(3, list[2]);
            Assert::AreEqual(5, list[4]);
        }

        // 3. Тест конструктора копирования
        TEST_METHOD(TestCopyConstructor)
        {
            LinkedList<int> original = { 10, 20, 30 };
            LinkedList<int> copy(original);

            Assert::AreEqual(original.getSize(), copy.getSize());
            Assert::AreEqual(original[0], copy[0]);
            Assert::AreEqual(original[1], copy[1]);
            Assert::AreEqual(original[2], copy[2]);

            copy[0] = 100;
            Assert::AreEqual(10, original[0]);
            Assert::AreEqual(100, copy[0]);
        }

        // 4. Тест оператора присваивания
        TEST_METHOD(TestAssignmentOperator)
        {
            LinkedList<int> original = { 1, 2, 3 };
            LinkedList<int> assigned;
            assigned = original;

            Assert::AreEqual(original.getSize(), assigned.getSize());
            Assert::AreEqual(original[0], assigned[0]);
            Assert::AreEqual(original[1], assigned[1]);
            Assert::AreEqual(original[2], assigned[2]);
        }

        // 5. Тест самоприсваивания
        TEST_METHOD(TestSelfAssignment)
        {
            LinkedList<int> list = { 1, 2, 3 };
            list = list;
            Assert::AreEqual(size_t(3), list.getSize());
            Assert::AreEqual(1, list[0]);
            Assert::AreEqual(2, list[1]);
            Assert::AreEqual(3, list[2]);
        }

        // 6. Тест push_back
        TEST_METHOD(TestPushBack)
        {
            LinkedList<int> list;
            list.push_back(10);
            list.push_back(20);
            list.push_back(30);

            Assert::AreEqual(size_t(3), list.getSize());
            Assert::AreEqual(10, list[0]);
            Assert::AreEqual(20, list[1]);
            Assert::AreEqual(30, list[2]);
        }

        // 7. Тест push_front
        TEST_METHOD(TestPushFront)
        {
            LinkedList<int> list;
            list.push_front(30);
            list.push_front(20);
            list.push_front(10);

            Assert::AreEqual(size_t(3), list.getSize());
            Assert::AreEqual(10, list[0]);
            Assert::AreEqual(20, list[1]);
            Assert::AreEqual(30, list[2]);
        }

        // 8. Тест insert
        TEST_METHOD(TestInsert)
        {
            LinkedList<int> list = { 10, 20, 40, 50 };
            list.insert(2, 30);

            Assert::AreEqual(size_t(5), list.getSize());
            Assert::AreEqual(10, list[0]);
            Assert::AreEqual(20, list[1]);
            Assert::AreEqual(30, list[2]);
            Assert::AreEqual(40, list[3]);
            Assert::AreEqual(50, list[4]);
        }

        // 9. Тест pop_back
        TEST_METHOD(TestPopBack)
        {
            LinkedList<int> list = { 10, 20, 30, 40 };
            list.pop_back();

            Assert::AreEqual(size_t(3), list.getSize());
            Assert::AreEqual(10, list[0]);
            Assert::AreEqual(20, list[1]);
            Assert::AreEqual(30, list[2]);
        }

        // 10. Тест pop_front
        TEST_METHOD(TestPopFront)
        {
            LinkedList<int> list = { 10, 20, 30, 40 };
            list.pop_front();

            Assert::AreEqual(size_t(3), list.getSize());
            Assert::AreEqual(20, list[0]);
            Assert::AreEqual(30, list[1]);
            Assert::AreEqual(40, list[2]);
        }

        // 11. Тест erase
        TEST_METHOD(TestErase)
        {
            LinkedList<int> list = { 10, 20, 30, 40, 50 };
            list.erase(2);

            Assert::AreEqual(size_t(4), list.getSize());
            Assert::AreEqual(10, list[0]);
            Assert::AreEqual(20, list[1]);
            Assert::AreEqual(40, list[2]);
            Assert::AreEqual(50, list[3]);
        }

        // 12. Тест remove
        TEST_METHOD(TestRemove)
        {
            LinkedList<int> list = { 10, 20, 30, 20, 40 };
            bool result = list.remove(20);

            Assert::IsTrue(result);
            Assert::AreEqual(size_t(4), list.getSize());
            Assert::AreEqual(10, list[0]);
            Assert::AreEqual(30, list[1]);
            Assert::AreEqual(20, list[2]);
            Assert::AreEqual(40, list[3]);
        }

        // 13. Тест find
        TEST_METHOD(TestFind)
        {
            LinkedList<int> list = { 10, 20, 30, 40, 50 };
            int index = list.find(30);
            Assert::AreEqual(2, index);
        }

        // 14. Тест modify
        TEST_METHOD(TestModify)
        {
            LinkedList<int> list = { 10, 20, 30 };
            list.modify(1, 99);

            Assert::AreEqual(10, list[0]);
            Assert::AreEqual(99, list[1]);
            Assert::AreEqual(30, list[2]);
        }

        // 15. Тест оператора []
        TEST_METHOD(TestSubscriptOperator)
        {
            LinkedList<int> list = { 10, 20, 30 };
            Assert::AreEqual(10, list[0]);
            Assert::AreEqual(20, list[1]);
            Assert::AreEqual(30, list[2]);

            list[1] = 99;
            Assert::AreEqual(99, list[1]);
        }

        // 16. Тест ToString
        TEST_METHOD(TestToString)
        {
            LinkedList<int> list = { 1, 2, 3, 4 };
            std::string result = list.ToString();

            Assert::IsTrue(result.find("1") != std::string::npos);
            Assert::IsTrue(result.find("2") != std::string::npos);
            Assert::IsTrue(result.find("3") != std::string::npos);
            Assert::IsTrue(result.find("4") != std::string::npos);
        }

        // 17. Тест clear
        TEST_METHOD(TestClear)
        {
            LinkedList<int> list = { 1, 2, 3, 4, 5 };
            list.clear();

            Assert::AreEqual(size_t(0), list.getSize());
            Assert::IsTrue(list.isEmpty());
        }

        // 18. Тест исключения при доступе по индексу
        TEST_METHOD(TestSubscriptOutOfRange)
        {
            LinkedList<int> list = { 1, 2, 3 };

            auto func = [&list]() { list[3]; };
            Assert::ExpectException<std::out_of_range>(func);
        }

        // 19. Тест исключения при erase
        TEST_METHOD(TestEraseOutOfRange)
        {
            LinkedList<int> list = { 1, 2, 3 };

            auto func = [&list]() { list.erase(3); };
            Assert::ExpectException<std::out_of_range>(func);
        }
    };
}
