#include "Units.h"

#include <iostream>
#include <type_traits>

#include <gtest/gtest.h>

using namespace phy;

/**
 * Qty constructors tests
*/
TEST(constructorQty, Default){
	Qty<Metre> m;
	ASSERT_TRUE((std::is_same_v<decltype(m)::Unit, Unit<1, 0, 0, 0, 0, 0, 0>>));
	ASSERT_EQ(m.value, 0);
	ASSERT_TRUE((std::is_same_v<decltype(m)::Ratio, std::ratio<1>>));

	Qty<Kilogram> kg;
	ASSERT_TRUE((std::is_same_v<decltype(kg)::Unit, Unit<0, 1, 0, 0, 0, 0, 0>>));
	ASSERT_EQ(kg.value, 0);
	ASSERT_TRUE((std::is_same_v<decltype(kg)::Ratio, std::ratio<1>>));

	Qty<Second> s;
	ASSERT_TRUE((std::is_same_v<decltype(s)::Unit, Unit<0, 0, 1, 0, 0, 0, 0>>));
	ASSERT_EQ(s.value, 0);
	ASSERT_TRUE((std::is_same_v<decltype(s)::Ratio, std::ratio<1>>));

	Qty<Ampere> a;
	ASSERT_TRUE((std::is_same_v<decltype(a)::Unit, Unit<0, 0, 0, 1, 0, 0, 0>>));
	ASSERT_EQ(a.value, 0);
	ASSERT_TRUE((std::is_same_v<decltype(a)::Ratio, std::ratio<1>>));

	Qty<Kelvin> k;
	ASSERT_TRUE((std::is_same_v<decltype(k)::Unit, Unit<0, 0, 0, 0, 1, 0, 0>>));
	ASSERT_EQ(k.value, 0);
	ASSERT_TRUE((std::is_same_v<decltype(k)::Ratio, std::ratio<1>>));

	Qty<Mole> mo;
	ASSERT_TRUE((std::is_same_v<decltype(mo)::Unit, Unit<0, 0, 0, 0, 0, 1, 0>>));
	ASSERT_EQ(mo.value, 0);
	ASSERT_TRUE((std::is_same_v<decltype(mo)::Ratio, std::ratio<1>>));
	
	Qty<Candela> c;
	ASSERT_TRUE((std::is_same_v<decltype(c)::Unit, Unit<0, 0, 0, 0, 0, 0, 1>>));
	ASSERT_EQ(c.value, 0);
	ASSERT_TRUE((std::is_same_v<decltype(c)::Ratio, std::ratio<1>>));

	Qty<Radian> r;
	ASSERT_TRUE((std::is_same_v<decltype(r)::Unit, Unit<0, 0, 0, 0, 0, 0, 0>>));
	ASSERT_EQ(r.value, 0);
	ASSERT_TRUE((std::is_same_v<decltype(r)::Ratio, std::ratio<1>>));
}

TEST(constructorQty, DefaultWithRatio){
	Qty<Metre, std::milli> m;
	ASSERT_TRUE((std::is_same_v<decltype(m)::Unit, Unit<1, 0, 0, 0, 0, 0, 0>>));
	ASSERT_EQ(m.value, 0);
	ASSERT_TRUE((std::is_same_v<decltype(m)::Ratio, std::ratio<1,1000>>));

	Qty<Kilogram, std::milli> kg;
	ASSERT_TRUE((std::is_same_v<decltype(kg)::Unit, Unit<0, 1, 0, 0, 0, 0, 0>>));
	ASSERT_EQ(kg.value, 0);
	ASSERT_TRUE((std::is_same_v<decltype(kg)::Ratio, std::ratio<1,1000>>));

	Qty<Second, std::milli> s;
	ASSERT_TRUE((std::is_same_v<decltype(s)::Unit, Unit<0, 0, 1, 0, 0, 0, 0>>));
	ASSERT_EQ(s.value, 0);
	ASSERT_TRUE((std::is_same_v<decltype(s)::Ratio, std::ratio<1,1000>>));

	Qty<Ampere, std::milli> a;
	ASSERT_TRUE((std::is_same_v<decltype(a)::Unit, Unit<0, 0, 0, 1, 0, 0, 0>>));
	ASSERT_EQ(a.value, 0);
	ASSERT_TRUE((std::is_same_v<decltype(a)::Ratio, std::ratio<1,1000>>));

	Qty<Kelvin, std::milli> k;
	ASSERT_TRUE((std::is_same_v<decltype(k)::Unit, Unit<0, 0, 0, 0, 1, 0, 0>>));
	ASSERT_EQ(k.value, 0);
	ASSERT_TRUE((std::is_same_v<decltype(k)::Ratio, std::ratio<1,1000>>));

	Qty<Mole, std::milli> mo;
	ASSERT_TRUE((std::is_same_v<decltype(mo)::Unit, Unit<0, 0, 0, 0, 0, 1, 0>>));
	ASSERT_EQ(mo.value, 0);
	ASSERT_TRUE((std::is_same_v<decltype(mo)::Ratio, std::ratio<1,1000>>));
	
	Qty<Candela, std::milli> c;
	ASSERT_TRUE((std::is_same_v<decltype(c)::Unit, Unit<0, 0, 0, 0, 0, 0, 1>>));
	ASSERT_EQ(c.value, 0);
	ASSERT_TRUE((std::is_same_v<decltype(c)::Ratio, std::ratio<1,1000>>));

	Qty<Radian, std::milli> r;
	ASSERT_TRUE((std::is_same_v<decltype(r)::Unit, Unit<0, 0, 0, 0, 0, 0, 0>>));
	ASSERT_EQ(r.value, 0);
	ASSERT_TRUE((std::is_same_v<decltype(r)::Ratio, std::ratio<1,1000>>));
}

TEST(constructorQty, WithParameter)
{
	Qty<Metre> m(1);
	ASSERT_TRUE((std::is_same_v<decltype(m)::Unit, Unit<1, 0, 0, 0, 0, 0, 0>>));
	ASSERT_EQ(m.value, 1);
	ASSERT_TRUE((std::is_same_v<decltype(m)::Ratio, std::ratio<1>>));

	Qty<Kilogram> kg(1);
	ASSERT_TRUE((std::is_same_v<decltype(kg)::Unit, Unit<0, 1, 0, 0, 0, 0, 0>>));
	ASSERT_EQ(kg.value, 1);
	ASSERT_TRUE((std::is_same_v<decltype(kg)::Ratio, std::ratio<1>>));

	Qty<Second> s(1);
	ASSERT_TRUE((std::is_same_v<decltype(s)::Unit, Unit<0, 0, 1, 0, 0, 0, 0>>));
	ASSERT_EQ(s.value, 1);
	ASSERT_TRUE((std::is_same_v<decltype(s)::Ratio, std::ratio<1>>));

	Qty<Ampere> a(1);
	ASSERT_TRUE((std::is_same_v<decltype(a)::Unit, Unit<0, 0, 0, 1, 0, 0, 0>>));
	ASSERT_EQ(a.value, 1);
	ASSERT_TRUE((std::is_same_v<decltype(a)::Ratio, std::ratio<1>>));

	Qty<Kelvin> k(1);
	ASSERT_TRUE((std::is_same_v<decltype(k)::Unit, Unit<0, 0, 0, 0, 1, 0, 0>>));
	ASSERT_EQ(k.value, 1);
	ASSERT_TRUE((std::is_same_v<decltype(k)::Ratio, std::ratio<1>>));

	Qty<Mole> mo(1);
	ASSERT_TRUE((std::is_same_v<decltype(mo)::Unit, Unit<0, 0, 0, 0, 0, 1, 0>>));
	ASSERT_EQ(mo.value, 1);
	ASSERT_TRUE((std::is_same_v<decltype(mo)::Ratio, std::ratio<1>>));
	
	Qty<Candela> c(1);
	ASSERT_TRUE((std::is_same_v<decltype(c)::Unit, Unit<0, 0, 0, 0, 0, 0, 1>>));
	ASSERT_EQ(c.value, 1);
	ASSERT_TRUE((std::is_same_v<decltype(c)::Ratio, std::ratio<1>>));

	Qty<Radian> r(1);
	ASSERT_TRUE((std::is_same_v<decltype(r)::Unit, Unit<0, 0, 0, 0, 0, 0, 0>>));
	ASSERT_EQ(r.value, 1);
	ASSERT_TRUE((std::is_same_v<decltype(r)::Ratio, std::ratio<1>>));
}

TEST(constructorQty, WithParameterWithRatio)
{
	Qty<Metre, std::milli> m(1);
	ASSERT_TRUE((std::is_same_v<decltype(m)::Unit, Unit<1, 0, 0, 0, 0, 0, 0>>));
	ASSERT_EQ(m.value, 1);
	ASSERT_TRUE((std::is_same_v<decltype(m)::Ratio, std::ratio<1,1000>>));

	Qty<Kilogram, std::milli> kg(1);
	ASSERT_TRUE((std::is_same_v<decltype(kg)::Unit, Unit<0, 1, 0, 0, 0, 0, 0>>));
	ASSERT_EQ(kg.value, 1);
	ASSERT_TRUE((std::is_same_v<decltype(kg)::Ratio, std::ratio<1,1000>>));

	Qty<Second, std::milli> s(1);
	ASSERT_TRUE((std::is_same_v<decltype(s)::Unit, Unit<0, 0, 1, 0, 0, 0, 0>>));
	ASSERT_EQ(s.value, 1);
	ASSERT_TRUE((std::is_same_v<decltype(s)::Ratio, std::ratio<1,1000>>));

	Qty<Ampere, std::milli> a(1);
	ASSERT_TRUE((std::is_same_v<decltype(a)::Unit, Unit<0, 0, 0, 1, 0, 0, 0>>));
	ASSERT_EQ(a.value, 1);
	ASSERT_TRUE((std::is_same_v<decltype(a)::Ratio, std::ratio<1,1000>>));

	Qty<Kelvin, std::milli> k(1);
	ASSERT_TRUE((std::is_same_v<decltype(k)::Unit, Unit<0, 0, 0, 0, 1, 0, 0>>));
	ASSERT_EQ(k.value, 1);
	ASSERT_TRUE((std::is_same_v<decltype(k)::Ratio, std::ratio<1,1000>>));

	Qty<Mole, std::milli> mo(1);
	ASSERT_TRUE((std::is_same_v<decltype(mo)::Unit, Unit<0, 0, 0, 0, 0, 1, 0>>));
	ASSERT_EQ(mo.value, 1);
	ASSERT_TRUE((std::is_same_v<decltype(mo)::Ratio, std::ratio<1,1000>>));
	
	Qty<Candela, std::milli> c(1);
	ASSERT_TRUE((std::is_same_v<decltype(c)::Unit, Unit<0, 0, 0, 0, 0, 0, 1>>));
	ASSERT_EQ(c.value, 1);
	ASSERT_TRUE((std::is_same_v<decltype(c)::Ratio, std::ratio<1,1000>>));

	Qty<Radian, std::milli> r(1);
	ASSERT_TRUE((std::is_same_v<decltype(r)::Unit, Unit<0, 0, 0, 0, 0, 0, 0>>));
	ASSERT_EQ(r.value, 1);
	ASSERT_TRUE((std::is_same_v<decltype(r)::Ratio, std::ratio<1,1000>>));
}


/**
 * Qty compound operators tests
*/

//sum

TEST(sumQty, SameRatio_large){
	Qty<Metre, std::femto> fm1(50);
	Qty<Metre, std::femto> fm2(30);
	fm1 += fm2;
	ASSERT_EQ(fm1.value, 80);
	ASSERT_TRUE((std::is_same_v<decltype(fm1)::Ratio, std::femto>));
	ASSERT_TRUE((std::is_same_v<decltype(fm2)::Ratio, std::femto>));
}

TEST(sumQty, SameRatio_1){
	Qty<Metre> m1(2);
	Qty<Metre> m2(12);
	m1 += m2;
	ASSERT_EQ(m1.value, 14);
	ASSERT_TRUE((std::is_same_v<decltype(m1)::Ratio, std::ratio<1>>));
	ASSERT_TRUE((std::is_same_v<decltype(m2)::Ratio, std::ratio<1>>));
}

TEST(sumQty, SameRatio_small){
	Qty<Metre, std::peta> pm1(50);
	Qty<Metre, std::peta> pm2(30);
	pm1 += pm2;
	ASSERT_EQ(pm1.value, 80);
	ASSERT_TRUE((std::is_same_v<decltype(pm1)::Ratio, std::peta>));
	ASSERT_TRUE((std::is_same_v<decltype(pm2)::Ratio, std::peta>));
}


TEST(sumQty, DifferentRatio_big_difference_1){
	Qty<Candela, std::kilo> kc(200);
	Qty<Candela, std::nano> nc(12);
	kc += nc;
	ASSERT_EQ(kc.value, 200);
	ASSERT_TRUE((std::is_same_v<decltype(kc)::Ratio, std::kilo>));
	ASSERT_TRUE((std::is_same_v<decltype(nc)::Ratio, std::nano>));
}

TEST(sumQty, DifferentRatio_big_difference_2){
	Qty<Candela, std::kilo> kc(200);
	Qty<Candela, std::nano> nc(12);
	nc += kc;
	intmax_t res = (2e+14)+12;
	ASSERT_EQ(nc.value, res);
	ASSERT_TRUE((std::is_same_v<decltype(kc)::Ratio, std::kilo>));
	ASSERT_TRUE((std::is_same_v<decltype(nc)::Ratio, std::nano>));
}

TEST(sumQty, DifferentRatio_small_difference_1){
	Qty<Radian, std::kilo> kr(200);
	Qty<Radian> k(12);
	kr += k;
	ASSERT_EQ(kr.value, 200);
	ASSERT_TRUE((std::is_same_v<decltype(kr)::Ratio, std::kilo>));
	ASSERT_TRUE((std::is_same_v<decltype(k)::Ratio, std::ratio<1>>));
}

TEST(sumQty, DifferentRatio_small_difference_2){
	Qty<Radian, std::kilo> kr(200);
	Qty<Radian> r(12);
	r += kr;
	ASSERT_EQ(r.value, 200012);
	ASSERT_TRUE((std::is_same_v<decltype(kr)::Ratio, std::kilo>));
	ASSERT_TRUE((std::is_same_v<decltype(r)::Ratio, std::ratio<1>>));
}

TEST(sumQty, Many){
	Qty<Radian> r(200);
	Qty<Radian, std::nano> nr(350);
	Qty<Radian, std::kilo> kr(1);
	Qty<Radian, std::milli> mr(80);
	r += nr += kr += mr;
	ASSERT_EQ(r.value, 1200);
	ASSERT_TRUE((std::is_same_v<decltype(r)::Ratio, std::ratio<1>>));
	ASSERT_TRUE((std::is_same_v<decltype(nr)::Ratio, std::nano>));
	ASSERT_TRUE((std::is_same_v<decltype(kr)::Ratio, std::kilo>));
	ASSERT_TRUE((std::is_same_v<decltype(mr)::Ratio, std::milli>));
}


//substraction

TEST(subQty, SameRatio_large){
	Qty<Metre, std::femto> fm1(50);
	Qty<Metre, std::femto> fm2(30);
	fm1 -= fm2;
	ASSERT_EQ(fm1.value, 20);
	ASSERT_TRUE((std::is_same_v<decltype(fm1)::Ratio, std::femto>));
	ASSERT_TRUE((std::is_same_v<decltype(fm2)::Ratio, std::femto>));
}

TEST(subQty, SameRatio_1){
	Qty<Metre> m1(2);
	Qty<Metre> m2(12);
	m1 -= m2;
	ASSERT_EQ(m1.value, -10);
	ASSERT_TRUE((std::is_same_v<decltype(m1)::Ratio, std::ratio<1>>));
	ASSERT_TRUE((std::is_same_v<decltype(m2)::Ratio, std::ratio<1>>));
}

TEST(subQty, SameRatio_small){
	Qty<Metre, std::peta> pm1(50);
	Qty<Metre, std::peta> pm2(30);
	pm1 -= pm2;
	ASSERT_EQ(pm1.value, 20);
	ASSERT_TRUE((std::is_same_v<decltype(pm1)::Ratio, std::peta>));
	ASSERT_TRUE((std::is_same_v<decltype(pm2)::Ratio, std::peta>));
}


TEST(subQty, DifferentRatio_big_difference_1){
	Qty<Candela, std::kilo> kc(200);
	Qty<Candela, std::nano> nc(12);
	kc -= nc;
	ASSERT_EQ(kc.value, 200);
	ASSERT_TRUE((std::is_same_v<decltype(kc)::Ratio, std::kilo>));
	ASSERT_TRUE((std::is_same_v<decltype(nc)::Ratio, std::nano>));
}

TEST(subQty, DifferentRatio_big_difference_2){
	Qty<Candela, std::kilo> kc(200);
	Qty<Candela, std::nano> nc(10);
	nc -= kc;
	ASSERT_EQ(nc.value, -199999999999990);
	ASSERT_TRUE((std::is_same_v<decltype(kc)::Ratio, std::kilo>));
	ASSERT_TRUE((std::is_same_v<decltype(nc)::Ratio, std::nano>));
}

TEST(subQty, DifferentRatio_small_difference_1){
	Qty<Radian, std::kilo> kr(200);
	Qty<Radian> r(12);
	kr -= r;
	ASSERT_EQ(kr.value, 200);
	ASSERT_TRUE((std::is_same_v<decltype(kr)::Ratio, std::kilo>));
	ASSERT_TRUE((std::is_same_v<decltype(r)::Ratio, std::ratio<1>>));
}

TEST(subQty, DifferentRatio_small_difference_2){
	Qty<Radian, std::kilo> kr(200);
	Qty<Radian> r(12);
	r -= kr;
	ASSERT_EQ(r.value, -199988);
	ASSERT_TRUE((std::is_same_v<decltype(kr)::Ratio, std::kilo>));
	ASSERT_TRUE((std::is_same_v<decltype(r)::Ratio, std::ratio<1>>));
}

TEST(subQty, Many){
	Qty<Radian> r(200);
	Qty<Radian, std::nano> nr(350);
	Qty<Radian, std::milli> mr(80);
	Qty<Radian, std::kilo> kr(1);
	r -= nr -= mr -= kr -= mr;
	ASSERT_EQ(r.value, -799);
	ASSERT_TRUE((std::is_same_v<decltype(r)::Ratio, std::ratio<1>>));
	ASSERT_TRUE((std::is_same_v<decltype(nr)::Ratio, std::nano>));
	ASSERT_TRUE((std::is_same_v<decltype(kr)::Ratio, std::kilo>));
	ASSERT_TRUE((std::is_same_v<decltype(mr)::Ratio, std::milli>));
}



/**
 * comparison operators tests
*/

// Equality operator
TEST(equalityOperator, NotEqual){
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(3000);
	ASSERT_FALSE(m == mm);
}

TEST(equalityOperator, SameRatio){
	Qty<Metre> m1(2);
	Qty<Metre> m2(2);
	ASSERT_TRUE(m1 == m2);
}

TEST(equalityOperator, DifferentRatioLittle){
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(2000);
	ASSERT_TRUE(m == mm);
}

TEST(equalityOperator, DifferentRatioBig){
	Qty<Metre, std::kilo> km(2);
	Qty<Metre, std::nano> nm(2000000000000);
	ASSERT_TRUE(km == nm);
}

TEST(equalityOperator, DifferentRatioWeird){
	Qty<Metre, std::ratio<3,25>> m1(3);
	Qty<Metre, std::ratio<1,2>> m2(0.18);
	ASSERT_TRUE(m1 == m2);
}


//non-equality operator
TEST(comparisonOperatorsNotEq, NotEqual){
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(3000);
	ASSERT_TRUE(m != mm);
}

TEST(nonEqualityOperator, SameRatio){
	Qty<Metre> m1(2);
	Qty<Metre> m2(2);
	ASSERT_FALSE(m1 != m2);
}

TEST(nonEqualityOperator, DifferentRatioLittle){
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(2000);
	ASSERT_FALSE(m != mm);
}

TEST(nonEqualityOperator, DifferentRatioBig){
	Qty<Metre, std::kilo> km(2);
	Qty<Metre, std::nano> nm(2000000000000);
	ASSERT_FALSE(km != nm);
}

TEST(nonEqualityOperator, DifferentRatioWeird){
	Qty<Metre, std::ratio<3,25>> m1(3);
	Qty<Metre, std::ratio<1,2>> m2(0.18);
	ASSERT_FALSE(m1 != m2);
}

//strict inferiority operator
TEST(comparisonOperatorsLt, Lower){
	Qty<Metre> m(2);
	Qty<Metre, std::centi> cm(2);
	ASSERT_TRUE(cm < m);
}

TEST(comparisonOperatorsLt, Equal){
	Qty<Metre> m(2);
	Qty<Metre, std::centi> cm(200);
	ASSERT_FALSE(cm < m);
}

TEST(comparisonOperatorsLt, Upper){
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(3000);
	ASSERT_FALSE(mm < m);
}

TEST(comparisonOperatorsLt, LowerSameRatio){
	Qty<Metre> m1(2);
	Qty<Metre> m2(3);
	ASSERT_TRUE(m1 < m2);
}

TEST(comparisonOperatorsLt, LowerDifferentRatioLittle){
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(3000);
	ASSERT_TRUE(m < mm);
}

TEST(comparisonOperatorsLt, LowerDifferentRatioBig){
	Qty<Metre, std::kilo> km(2);
	Qty<Metre, std::nano> nm(3000000000000);
	ASSERT_TRUE(km < nm);
}

TEST(comparisonOperatorsLt, LowerDifferentRatioWeird){
	Qty<Metre, std::ratio<3,25>> m1(3);
	Qty<Metre, std::ratio<1,2>> m2(12.18);
	ASSERT_TRUE(m1 < m2);
}

//inferiority operator

TEST(comparisonOperatorsLe, Lower){
	Qty<Metre> m(2);
	Qty<Metre, std::centi> cm(2);
	ASSERT_TRUE(cm <= m);
}

TEST(comparisonOperatorsLe, Equal){
	Qty<Metre> m(2);
	Qty<Metre, std::centi> cm(200);
	ASSERT_TRUE(cm <= m);
}

TEST(comparisonOperatorsLe, Upper){
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(3000);
	ASSERT_FALSE(mm <= m);
}

TEST(comparisonOperatorsLe, LowerSameRatio){
	Qty<Metre> m1(2);
	Qty<Metre> m2(3);
	ASSERT_TRUE(m1 <= m2);
}

TEST(comparisonOperatorsLe, LowerDifferentRatioLittle){
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(3000);
	ASSERT_TRUE(m <= mm);
}

TEST(comparisonOperatorsLe, LowerDifferentRatioBig){
	Qty<Metre, std::kilo> km(2);
	Qty<Metre, std::nano> nm(3000000000000);
	ASSERT_TRUE(km <= nm);
}

TEST(comparisonOperatorsLe, LowerDifferentRatioWeird){
	Qty<Metre, std::ratio<3,25>> m1(3);
	Qty<Metre, std::ratio<1,2>> m2(12.18);
	ASSERT_TRUE(m1 <= m2);
}

//strict superiority operator

TEST(comparisonOperatorsGt, Lower){
	Qty<Metre> m(2);
	Qty<Metre, std::centi> cm(2);
	ASSERT_FALSE(cm > m);
}

TEST(comparisonOperatorsGt, Equal){
	Qty<Metre> m(2);
	Qty<Metre, std::centi> cm(200);
	ASSERT_FALSE(cm > m);
}

TEST(comparisonOperatorsGt, Upper){
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(3000);
	ASSERT_TRUE(mm > m);
}

TEST(comparisonOperatorsGt, UpperSameRatio){
	Qty<Metre> m1(2);
	Qty<Metre> m2(3);
	ASSERT_TRUE(m2 > m1);
}

TEST(comparisonOperatorsGt, UpperDifferentRatioLittle){
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(3000);
	ASSERT_TRUE(mm > m);
}

TEST(comparisonOperatorsGt, UpperDifferentRatioBig){
	Qty<Metre, std::kilo> km(2);
	Qty<Metre, std::nano> nm(3000000000000);
	ASSERT_TRUE(nm > km);
}

TEST(comparisonOperatorsGt, UpperDifferentRatioWeird){
	Qty<Metre, std::ratio<3,25>> m1(3);
	Qty<Metre, std::ratio<1,2>> m2(12.18);
	ASSERT_TRUE(m2 > m1);
}

//superiority operator

TEST(comparisonOperatorsGe, Lower){
	Qty<Metre> m(2);
	Qty<Metre, std::centi> cm(2);
	ASSERT_FALSE(cm >= m);
}

TEST(comparisonOperatorsGe, Equal){
	Qty<Metre> m(2);
	Qty<Metre, std::centi> cm(200);
	ASSERT_TRUE(cm >= m);
}

TEST(comparisonOperatorsGe, Upper){
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(3000);
	ASSERT_TRUE(mm >= m);
}

TEST(comparisonOperatorsGe, UpperSameRatio){
	Qty<Metre> m1(2);
	Qty<Metre> m2(3);
	ASSERT_TRUE(m2 >= m1);
}

TEST(comparisonOperatorsGe, UpperDifferentRatioLittle){
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(3000);
	ASSERT_TRUE(mm >= m);
}

TEST(comparisonOperatorsGe, UpperDifferentRatioBig){
	Qty<Metre, std::kilo> km(2);
	Qty<Metre, std::nano> nm(3000000000000);
	ASSERT_TRUE(nm >= km);
}

TEST(comparisonOperatorsGe, UpperDifferentRatioWeird){
	Qty<Metre, std::ratio<3,25>> m1(3);
	Qty<Metre, std::ratio<1,2>> m2(12.18);
	ASSERT_TRUE(m2 >= m1);
}

/**
 * arithmetic operators tests
*/

TEST(arithmeticOperatorsAdd, Default){
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(2000);

	auto sum = m + mm;

	ASSERT_EQ(sum.value, 4000);
	ASSERT_TRUE((std::is_same_v<decltype(sum)::Ratio, std::milli>));
}

TEST(arithmeticOperatorsSub, Default){
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(1000);

	auto sub = m - mm;

	ASSERT_EQ(sub.value, 1000);
	ASSERT_TRUE((std::is_same_v<decltype(sub)::Ratio, std::milli>));
}

TEST(arithmeticOperatorsProduct, Default){
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(2000);

	auto product = mm * m;

	ASSERT_EQ(product.value, 4000000);
	ASSERT_TRUE((std::is_same_v<decltype(product)::Ratio, std::milli>));
	ASSERT_TRUE((std::is_same_v<decltype(product)::Unit , Unit<2, 0, 0, 0, 0, 0, 0>>));
}

TEST(arithmeticOperatorsQuotient, Default){
	Qty<Metre> m(4);
	Qty<Metre, std::milli> mm(2000);

	auto quotient = m / mm;

	
	ASSERT_EQ(quotient.value, 2);
	ASSERT_TRUE((std::is_same_v<decltype(quotient)::Ratio, std::milli>));
	ASSERT_TRUE((std::is_same_v<decltype(quotient)::Unit , Radian>));
}






/*
 * exemples units
 */
TEST(differentsUnits, Default)
{
	using squareMeter = Unit<2, 0, 0, 0, 0, 0, 0>;
	using speed = Unit<1, 0, -1, 0, 0, 0, 0>;
}


//tests miles / foot ....

/**
 * 
*/


TEST(castQuantity, Default){
	using Kilometre = Qty<Metre, std::kilo>;
	Qty<Kilometre> km(4);

	Qty<Metre> m = qtyCast<Qty<Metre>>(km);

	
	ASSERT_EQ(m.value, 4000);
	ASSERT_TRUE((std::is_same_v<decltype(m)::Ratio, std::ratio<1>>));
	ASSERT_TRUE((std::is_same_v<decltype(m)::Unit , Metre>));
}

TEST(literals, Default) {
    using namespace literals;

    auto len1 = 2_metres;
    auto len2 = 5_metres;

    ASSERT_EQ(len1.value, 2);
    ASSERT_EQ(len2.value, 5);
    ASSERT_TRUE((std::is_same_v<decltype(len1)::Ratio, std::ratio<1>>));
    ASSERT_TRUE((std::is_same_v<decltype(len1)::Unit, Metre>));
}

TEST(literals, Fahrenheit) {
	using namespace literals;

	auto temp = 0_fahrenheit;
	ASSERT_EQ(temp.value, -459); //Revoir
	
}
/*
//test mail
TEST(QuantityAdditionOperator, notSimpleAddition){
    Qty<Metre, std::ratio<73,125>> m1(5);
    Qty<Metre, std::ratio<127,342>> m2(8);
    auto m3 = m1 + m2;
    Qty<Metre, std::ratio<1,4275>> m4(25183);
    EXPECT_TRUE(m3 == m4);
}*/



int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
