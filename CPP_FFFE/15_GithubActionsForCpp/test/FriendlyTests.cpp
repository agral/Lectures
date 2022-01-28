#include <gtest/gtest.h>
#include <string>

TEST(FriendlyTests, std_string_equality_test)
{
  std::string strAlice {"Alice"};
  std::string strBob {"Bob"};
  std::string strAlice2 {"Alice"};

  EXPECT_TRUE(strAlice == strAlice2);
  EXPECT_FALSE(strAlice == strBob);
}
