#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "DefaultTest.h"

using ::testing::Eq;

TEST_F(DefaultTest, DefaultConstructor)
{
	EXPECT_THAT(0, Eq(0));
}