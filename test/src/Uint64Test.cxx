#include <gtest/gtest.h>
#include <Uint64_t.hpp>

TEST(Uint64Test, NormalOperationsTest)
{
	constexpr Uint64_t varA = 100u;
	constexpr Uint64_t varB = 101u;

	EXPECT_NE(varA, varB) << "Variables can't compare.";
}
