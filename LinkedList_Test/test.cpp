// @author Kondakov N

#include "pch.h"
#include "../LinkedList.h"


                                                       //////// тестирование оператора begin
TEST(TestBegin, Test1) {

    // создаем лист ( 6 1 9 5 11 )
    LinkedList<int> list;

    list.AddInHead(1);
    list.AddInTail(9);
    list.AddInTail(5);
    list.AddInTail(11);
    list.AddInHead(6);

    // итератор указывающий на начало списка
    auto it1 = list.begin();

    // значение, на которое указывает итератор, равно 6
	EXPECT_EQ(*it1, 6);
}


TEST(TestBegin, Test2) {

    // создаем лист ( 11 64 55 53 42 )
    LinkedList<int> list;

    list.AddInHead(64);
    list.AddInTail(55);
    list.AddInTail(53);
    list.AddInTail(42);
    list.AddInHead(11);

    // итератор указывающий на начало списка
    auto it1 = list.begin();

    // значение, на которое указывает итератор, равно 6
    EXPECT_EQ(*it1, 11);
}





                                                     ///////// тест оператора end 
TEST(TestEnd, Test1) {

    // создаем лист ( 6 1 9 5 11 )
    LinkedList<int> list;

    list.AddInHead(1);
    list.AddInTail(9);
    list.AddInTail(5);
    list.AddInTail(11);
    list.AddInHead(6);

    // итератор указывающий на конец списка
    auto it1 = list.end();

    // проверяем значение текущего узла через оператор разыменования
    EXPECT_EQ(*it1, 11);
}


TEST(TestEnd, Test2) {

    // создаем лист ( 11 64 55 53 42 )
    LinkedList<int> list;

    list.AddInHead(64);
    list.AddInTail(55);
    list.AddInTail(53);
    list.AddInTail(42);
    list.AddInHead(11);

    // итератор указывающий на конец списка
    auto it1 = list.end();

    // проверяем значение текущего узла через оператор разыменования
    EXPECT_EQ(*it1, 42);
}






                                                /////// тест инкремента
TEST(TestIncr, Test1) {

    // создаем лист ( 11 64 55 53 42 )
    LinkedList<int> list;

    list.AddInHead(64);
    list.AddInTail(55);
    list.AddInTail(53);
    list.AddInTail(42);
    list.AddInHead(11);

    // итератор указывающий на начало списка
    auto it1 = list.begin();

    // проверяем значение текущего узла через оператор разыменования
    EXPECT_EQ(*it1, 11);

    ++it1;
    EXPECT_EQ(*it1, 64);

    ++it1;
    ++it1;
    EXPECT_EQ(*it1, 53);
}


TEST(TestIncr, Test2) {

    // создаем лист ( 6 1 9 5 11 )
    LinkedList<int> list;

    list.AddInHead(1);
    list.AddInTail(9);
    list.AddInTail(5);
    list.AddInTail(11);
    list.AddInHead(6);

    // итератор указывающий на начало списка
    auto it1 = list.begin();

    // проверяем значение текущего узла через оператор разыменования
    EXPECT_EQ(*it1, 6);

    ++it1;
    ++it1;
    ++it1;
    EXPECT_EQ(*it1, 5);
}






                                                       /////// тест оператора равенства
TEST(TestEqual, Test1) {

    // создаем лист ( 11 64 55 53 42 )
    LinkedList<int> list;

    list.AddInHead(64);
    list.AddInTail(55);
    list.AddInTail(53);
    list.AddInTail(42);
    list.AddInHead(11);

    // итераторы указывающие на начало списка
    auto it1 = list.begin();
    auto it2 = list.begin();

    // проверяем, что итераторы равны 
    EXPECT_EQ(it1,it2);
}

TEST(TestEqual, Test2) {

    // создаем лист ( 6 1 9 5 11 )
    LinkedList<int> list;

    list.AddInHead(1);
    list.AddInTail(9);
    list.AddInTail(5);
    list.AddInTail(11);
    list.AddInHead(6);

    // итераторы указывающие на начало списка
    auto it1 = list.begin();
    auto it2 = list.begin();

    // проверяем, что итераторы равны 
    EXPECT_EQ(it1, it2);
}



                                                //////// тест оперратора неравенства
TEST(TestNotEqual, Test1) {

    // создаем лист ( 11 64 55 53 42 )
    LinkedList<int> list;

    list.AddInHead(64);
    list.AddInTail(55);
    list.AddInTail(53);
    list.AddInTail(42);
    list.AddInHead(11);

    // итераторы указывающие на начало списка
    auto it1 = list.begin();
    auto it2 = list.begin();
    ++it2;

    // проверяем, что итераторы не равны 
    EXPECT_NE(it1,it2);
}

TEST(TestNotEqual, Test2) {

    // создаем лист ( 6 1 9 5 11 )
    LinkedList<int> list;

    list.AddInHead(1);
    list.AddInTail(9);
    list.AddInTail(5);
    list.AddInTail(11);
    list.AddInHead(6);

    // итераторы указывающие на начало списка
    auto it1 = list.begin();
    auto it2 = list.begin();
    ++it2;

    // проверяем, что итераторы не равны 
    EXPECT_NE(it1, it2);
}