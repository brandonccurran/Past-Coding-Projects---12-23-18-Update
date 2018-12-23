#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>

#include "../src/inverter.h"

using namespace std;

const string EXPECTED_STR_1 = "a: 0 1\nalso: 1\nboring: 1\ncool: 0\nis: 0 1\ntest: 0 1\nthis: 0 1\n";

TEST(InverterTest, Test1) {
  string out = build_inverted_index("inputs.txt");
  EXPECT_EQ(out, EXPECTED_STR_1);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
