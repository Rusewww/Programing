#include <gtest/gtest.h>
#include "../src/list.hpp"

TEST(Test, getLinkTest) {
    bool result = true;

    list<int> listTest;

    int one = 7;
    int two = 9;
    int tree = 3;

    listTest.addLink(&one);
    listTest.addLink(&two);
    listTest.addLink(&tree);

    int actual = listTest.getLink(1);

    ASSERT_EQ(actual, two);
}

TEST(Test, sortTest) {
    bool result = true;

    list<int> listTest;

    int one = 7;
    int two = 9;
    int tree = 3;

    listTest.addLink(&one);
    listTest.addLink(&two);
    listTest.addLink(&tree);

    listTest.sortList();

    ASSERT_EQ(listTest.getLink(2),9);
    ASSERT_EQ(listTest.getLink(1), 7);
    ASSERT_EQ(listTest.getLink(0), 3);
}

TEST(Test, deleteTest) {
    bool result = true;

    list<int> listTest;

    int one = 7;
    int two = 9;
    int tree = 3;

    listTest.addLink(&one);
    listTest.addLink(&two);
    listTest.addLink(&tree);

    listTest.deleteLink(1);

    ASSERT_EQ(listTest.getLink(0),7);
    ASSERT_EQ(listTest.getLink(1), 3);
}

TEST(Test, minTest) {
    bool result = true;

    list<int> listTest;

    int one = 7;
    int two = 9;
    int tree = 3;

    listTest.addLink(&one);
    listTest.addLink(&two);
    listTest.addLink(&tree);

    int actual = listTest.findMinLink();

    ASSERT_EQ(actual,3);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


