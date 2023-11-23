// @author Kondakov N

#include "pch.h"
#include "../LinkedList.h"


                                                       //////// ������������ ��������� begin
TEST(TestBegin, Test1) {

    // ������� ���� ( 6 1 9 5 11 )
    LinkedList<int> list;

    list.AddInHead(1);
    list.AddInTail(9);
    list.AddInTail(5);
    list.AddInTail(11);
    list.AddInHead(6);

    // �������� ����������� �� ������ ������
    auto it1 = list.begin();

    // ��������, �� ������� ��������� ��������, ����� 6
	EXPECT_EQ(*it1, 6);
}


TEST(TestBegin, Test2) {

    // ������� ���� ( 11 64 55 53 42 )
    LinkedList<int> list;

    list.AddInHead(64);
    list.AddInTail(55);
    list.AddInTail(53);
    list.AddInTail(42);
    list.AddInHead(11);

    // �������� ����������� �� ������ ������
    auto it1 = list.begin();

    // ��������, �� ������� ��������� ��������, ����� 6
    EXPECT_EQ(*it1, 11);
}





                                                     ///////// ���� ��������� end 
TEST(TestEnd, Test1) {

    // ������� ���� ( 6 1 9 5 11 )
    LinkedList<int> list;

    list.AddInHead(1);
    list.AddInTail(9);
    list.AddInTail(5);
    list.AddInTail(11);
    list.AddInHead(6);

    // �������� ����������� �� ����� ������
    auto it1 = list.end();

    // ��������� �������� �������� ���� ����� �������� �������������
    EXPECT_EQ(*it1, 11);
}


TEST(TestEnd, Test2) {

    // ������� ���� ( 11 64 55 53 42 )
    LinkedList<int> list;

    list.AddInHead(64);
    list.AddInTail(55);
    list.AddInTail(53);
    list.AddInTail(42);
    list.AddInHead(11);

    // �������� ����������� �� ����� ������
    auto it1 = list.end();

    // ��������� �������� �������� ���� ����� �������� �������������
    EXPECT_EQ(*it1, 42);
}






                                                /////// ���� ����������
TEST(TestIncr, Test1) {

    // ������� ���� ( 11 64 55 53 42 )
    LinkedList<int> list;

    list.AddInHead(64);
    list.AddInTail(55);
    list.AddInTail(53);
    list.AddInTail(42);
    list.AddInHead(11);

    // �������� ����������� �� ������ ������
    auto it1 = list.begin();

    // ��������� �������� �������� ���� ����� �������� �������������
    EXPECT_EQ(*it1, 11);

    ++it1;
    EXPECT_EQ(*it1, 64);

    ++it1;
    ++it1;
    EXPECT_EQ(*it1, 53);
}


TEST(TestIncr, Test2) {

    // ������� ���� ( 6 1 9 5 11 )
    LinkedList<int> list;

    list.AddInHead(1);
    list.AddInTail(9);
    list.AddInTail(5);
    list.AddInTail(11);
    list.AddInHead(6);

    // �������� ����������� �� ������ ������
    auto it1 = list.begin();

    // ��������� �������� �������� ���� ����� �������� �������������
    EXPECT_EQ(*it1, 6);

    ++it1;
    ++it1;
    ++it1;
    EXPECT_EQ(*it1, 5);
}






                                                       /////// ���� ��������� ���������
TEST(TestEqual, Test1) {

    // ������� ���� ( 11 64 55 53 42 )
    LinkedList<int> list;

    list.AddInHead(64);
    list.AddInTail(55);
    list.AddInTail(53);
    list.AddInTail(42);
    list.AddInHead(11);

    // ��������� ����������� �� ������ ������
    auto it1 = list.begin();
    auto it2 = list.begin();

    // ���������, ��� ��������� ����� 
    EXPECT_EQ(it1,it2);
}

TEST(TestEqual, Test2) {

    // ������� ���� ( 6 1 9 5 11 )
    LinkedList<int> list;

    list.AddInHead(1);
    list.AddInTail(9);
    list.AddInTail(5);
    list.AddInTail(11);
    list.AddInHead(6);

    // ��������� ����������� �� ������ ������
    auto it1 = list.begin();
    auto it2 = list.begin();

    // ���������, ��� ��������� ����� 
    EXPECT_EQ(it1, it2);
}



                                                //////// ���� ���������� �����������
TEST(TestNotEqual, Test1) {

    // ������� ���� ( 11 64 55 53 42 )
    LinkedList<int> list;

    list.AddInHead(64);
    list.AddInTail(55);
    list.AddInTail(53);
    list.AddInTail(42);
    list.AddInHead(11);

    // ��������� ����������� �� ������ ������
    auto it1 = list.begin();
    auto it2 = list.begin();
    ++it2;

    // ���������, ��� ��������� �� ����� 
    EXPECT_NE(it1,it2);
}

TEST(TestNotEqual, Test2) {

    // ������� ���� ( 6 1 9 5 11 )
    LinkedList<int> list;

    list.AddInHead(1);
    list.AddInTail(9);
    list.AddInTail(5);
    list.AddInTail(11);
    list.AddInHead(6);

    // ��������� ����������� �� ������ ������
    auto it1 = list.begin();
    auto it2 = list.begin();
    ++it2;

    // ���������, ��� ��������� �� ����� 
    EXPECT_NE(it1, it2);
}