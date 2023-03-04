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

TEST(arithmeticOperatorsSub, Default){
	phy::Qty<phy::Metre> m(2);
	phy::Qty<phy::Metre, std::milli> mm(1000);

	auto sub = m - mm;

	ASSERT_EQ(sub.value, 1000);
	ASSERT_TRUE((std::is_same_v<decltype(sub)::Ratio, std::milli>));
}

TEST(arithmeticOperatorsProduct, Default){
	phy::Qty<phy::Metre> m(2);
	phy::Qty<phy::Metre, std::milli> mm(2000);

	auto product = mm * m;

	ASSERT_EQ(product.value, 4000000);
	ASSERT_TRUE((std::is_same_v<decltype(product)::Ratio, std::milli>));
	ASSERT_TRUE((std::is_same_v<decltype(product)::Unit , phy::Unit<2, 0, 0, 0, 0, 0, 0>>));
}

TEST(arithmeticOperatorsQuotient, Default){
	phy::Qty<phy::Metre> m(4);
	phy::Qty<phy::Metre, std::milli> mm(2000);

	auto quotient = m / mm;

	
	ASSERT_EQ(quotient.value, 2);
	ASSERT_TRUE((std::is_same_v<decltype(quotient)::Ratio, std::milli>));
	ASSERT_TRUE((std::is_same_v<decltype(quotient)::Unit , phy::Radian>));
}

TEST(castQuantity, Default){
	using Kilometre = phy::Qty<phy::Metre, std::kilo>;
	phy::Qty<Kilometre> km(4);

	phy::Qty<phy::Metre> m = phy::qtyCast<phy::Qty<phy::Metre>>(km);

	
	ASSERT_EQ(m.value, 4000);
	ASSERT_TRUE((std::is_same_v<decltype(m)::Ratio, std::ratio<1>>));
	ASSERT_TRUE((std::is_same_v<decltype(m)::Unit , phy::Metre>));
}

TEST(literals, Default) {
    using namespace phy::literals;

    auto len1 = 2_metres;
    auto len2 = 5_metres;

    ASSERT_EQ(len1.value, 2);
    ASSERT_EQ(len2.value, 5);
    ASSERT_TRUE((std::is_same_v<decltype(len1)::Ratio, std::ratio<1>>));
    ASSERT_TRUE((std::is_same_v<decltype(len1)::Unit, phy::Metre>));
}



int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
