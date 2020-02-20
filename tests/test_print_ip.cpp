#include "to_string.h"

#include <vector>
#include <list>
#include <climits>

#include <gtest/gtest.h>

TEST(INEGRALS, CHAR)
{
    char ch1 = CHAR_MIN;
    char ch2 = 0;
    char ch3 = 5;
    char ch4 = CHAR_MAX;

    ASSERT_EQ(to_string(ch1), std::string("128"));
    ASSERT_EQ(to_string(ch2), std::string("0"));
    ASSERT_EQ(to_string(ch3), std::string("5"));
    ASSERT_EQ(to_string(ch4), std::string("127"));
}

TEST(INEGRALS, SHORT)
{
    short sh1 = SHRT_MIN;
    short sh2 = 0;
    short sh3 = 5;
    short sh4 = SHRT_MAX;

    ASSERT_EQ(to_string(sh1), std::string("128.0"));
    ASSERT_EQ(to_string(sh2), std::string("0.0"));
    ASSERT_EQ(to_string(sh3), std::string("0.5"));
    ASSERT_EQ(to_string(sh4), std::string("127.255"));
}

TEST(INEGRALS, INT)
{
    int i1 = INT_MIN;
    int i2 = 0;
    int i3 = 5;
    int i4 = INT_MAX;

    ASSERT_EQ(to_string(i1), std::string("128.0.0.0"));
    ASSERT_EQ(to_string(i2), std::string("0.0.0.0"));
    ASSERT_EQ(to_string(i3), std::string("0.0.0.5"));
    ASSERT_EQ(to_string(i4), std::string("127.255.255.255"));
}

TEST(INEGRALS, LONG_LONG)
{
    long long ll1 = LLONG_MIN;
    long long ll2 = 0;
    long long ll3 = 5;
    long long ll4 = LLONG_MAX;

    ASSERT_EQ(to_string(ll1), std::string("128.0.0.0.0.0.0.0"));
    ASSERT_EQ(to_string(ll2), std::string("0.0.0.0.0.0.0.0"));
    ASSERT_EQ(to_string(ll3), std::string("0.0.0.0.0.0.0.5"));
    ASSERT_EQ(to_string(ll4), std::string("127.255.255.255.255.255.255.255"));
}

TEST(CONTAINERS, VECTOR)
{
    std::vector<int> vi1;
    std::vector<int> vi2{1};
    std::vector<int> vi3{1,2,3,4};

    std::vector<std::string> vs1;
    std::vector<std::string> vs2{"1"};
    std::vector<std::string> vs3{"1","2","3","4"};

    ASSERT_EQ(to_string(vi1), std::string());
    ASSERT_EQ(to_string(vi2), std::string("1"));
    ASSERT_EQ(to_string(vi3), std::string("1.2.3.4"));

    ASSERT_EQ(to_string(vs1), std::string());
    ASSERT_EQ(to_string(vs2), std::string("1"));
    ASSERT_EQ(to_string(vs3), std::string("1.2.3.4"));
}

TEST(CONTAINERS, LIST)
{
    std::list<int> li1;
    std::list<int> li2{1};
    std::list<int> li3{1,2,3,4};

    std::list<std::string> ls1;
    std::list<std::string> ls2{"1"};
    std::list<std::string> ls3{"1","2","3","4"};

    ASSERT_EQ(to_string(li1), std::string());
    ASSERT_EQ(to_string(li2), std::string("1"));
    ASSERT_EQ(to_string(li3), std::string("1.2.3.4"));

    ASSERT_EQ(to_string(ls1), std::string());
    ASSERT_EQ(to_string(ls2), std::string("1"));
    ASSERT_EQ(to_string(ls3), std::string("1.2.3.4"));
}

TEST(STRING, STRING)
{
    std::string s1;
    std::string s2("1.2.3.4");

    ASSERT_EQ(to_string(s1), std::string());
    ASSERT_EQ(to_string(s2), std::string("1.2.3.4"));
}
