#include "Units.h"

#include <iostream>
#include <type_traits>

#include <gtest/gtest.h>

/*
 * exemples units
 */
TEST(differentsUnits, Default)
{
	using squareMeter = phy::Unit<2, 0, 0, 0, 0, 0, 0>;
	using speed = phy::Unit<1, 0, -1, 0, 0, 0, 0>;
}


/**
 * Comparison operators tests
*/
TEST(QtySum, Default){
	phy::Qty<phy::Metre> m(2);
	phy::Qty<phy::Metre, std::milli> mm(1000);
	m += mm;
	ASSERT_EQ(m.value, 3);
}

TEST(QtySub, Default){
	phy::Qty<phy::Metre> m(2);
	phy::Qty<phy::Metre, std::milli> mm(1000);
	m -= mm;
	ASSERT_EQ(m.value, 1);
}
//tests miles / foot ....

/**
 * 
*/
TEST(comparisonOperatorsEq, Default){
	phy::Qty<phy::Metre> m(2);
	phy::Qty<phy::Metre, std::milli> mm(2000);
	ASSERT_TRUE(m == mm);
}

TEST(comparisonOperatorsNotEq, Default){
	phy::Qty<phy::Metre> m(2);
	phy::Qty<phy::Metre, std::milli> mm(3000);
	ASSERT_TRUE(m != mm);
}

TEST(comparisonOperatorsLt, Default){
	phy::Qty<phy::Metre> m(2);
	phy::Qty<phy::Metre, std::centi> cm(2);
	ASSERT_TRUE(cm < m);
}

TEST(comparisonOperatorsLe, Default){
	phy::Qty<phy::Metre> m(2);
	phy::Qty<phy::Metre, std::milli> mm(3000);
	ASSERT_TRUE(m <= mm);
}

TEST(comparisonOperatorsGt, Default){
	phy::Qty<phy::Metre> m(2);
	phy::Qty<phy::Metre, std::milli> mm(300);
	ASSERT_TRUE(m > mm);
}

TEST(comparisonOperatorsGe, Default){
	phy::Qty<phy::Metre> m(2);
	phy::Qty<phy::Metre, std::milli> mm(2000);
	ASSERT_TRUE(m >= mm);
}

TEST(arithmeticOperatorsAdd, Default){
	phy::Qty<phy::Metre> m(2);
	phy::Qty<phy::Metre, std::milli> mm(2000);

	auto sum = m + mm;


	ASSERT_EQ(sum.value, 4000);
	ASSERT_TRUE((std::is_same_v<decltype(sum)::Ratio, std::milli>));
}



int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
