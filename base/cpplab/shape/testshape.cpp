#include "shape.hpp"
#include <gtest/gtest.h>
#include <iostream>

namespace shape {

TEST(testshape, constructor) {
  std::cout << "running something else";
  EXPECT_EQ(1, 1);
}

class TestFixture : public ::testing::Test {
protected:
  void SetUp() override { std::cout << "SetUp"; }

  void TearDown() override { std::cout << "teardown"; }

  shape shape1;
  shape shape2;
  shape shape3;
};

TEST_F(TestFixture, constructor) { std::cout << "TEST_F"; }

} // namespace shape
