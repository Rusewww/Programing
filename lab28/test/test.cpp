#include <gtest/gtest.h>
#include "../src/list.h"

TEST(Test, findAverageTest) {
    list test;
    string fileName;
    fileName = "../../lab28/test/assets/testInput.txt";
    test.setFileName(fileName);
    test.readFromFile();
    int *result = test.findAverageValue();
    test.setResult(result);
    int expect[] = {2, 5, 2, 3, 3, 12, 14, 8};
    ASSERT_EQ(*test.getResult(),*expect);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
