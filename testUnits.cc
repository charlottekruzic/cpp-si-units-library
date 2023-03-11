#include "Units.h"

#include <iostream>
#include <type_traits>

#include <gtest/gtest.h>

using namespace phy;

/**
 * Definition of units and quantities 
*/

//Unit
using squareMeter = Unit<2, 0, 0, 0, 0, 0, 0>;
using squareSecond = Unit<0, 0, 2, 0, 0, 0, 0>;
using cubeMeter = Unit<3, 0, 0, 0, 0, 0, 0>;
using meterSecond = Unit<1, 0, -1, 0, 0, 0, 0>;

// Qty
using Kilometre = Qty<Metre, std::kilo>;
using squareKiloMeter = Qty<squareMeter, std::kilo>;
using squareCentiMeter = Qty<squareMeter, std::centi>;
using squareCentiSecond = Qty<squareSecond, std::centi>;
using cubeKilometer = Qty<cubeMeter, std::kilo>;
using cubeCentimeter = Qty<cubeMeter, std::centi>;
using kilometerSecond = Qty<meterSecond, std::kilo>;


/**
 * Qty constructors tests
 */
TEST(constructorQty, Default)
{
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

	Mile mi;
	ASSERT_TRUE((std::is_same_v<decltype(mi)::Unit, Unit<1, 0, 0, 0, 0, 0, 0>>));
	ASSERT_EQ(r.value, 0);
	ASSERT_TRUE((std::is_same_v<decltype(mi)::Ratio, std::ratio<1609304, 1000>>));

	Yard y;
	ASSERT_TRUE((std::is_same_v<decltype(y)::Unit, Unit<1, 0, 0, 0, 0, 0, 0>>));
	ASSERT_EQ(r.value, 0);
	ASSERT_TRUE((std::is_same_v<decltype(y)::Ratio, std::ratio<10000, 9144>>));

	Foot f;
	ASSERT_TRUE((std::is_same_v<decltype(f)::Unit, Unit<1, 0, 0, 0, 0, 0, 0>>));
	ASSERT_EQ(r.value, 0);
	ASSERT_TRUE((std::is_same_v<decltype(f)::Ratio, std::ratio<10000, 3048>>));

	Inch i;
	ASSERT_TRUE((std::is_same_v<decltype(i)::Unit, Unit<1, 0, 0, 0, 0, 0, 0>>));
	ASSERT_EQ(r.value, 0);
	ASSERT_TRUE((std::is_same_v<decltype(i)::Ratio, std::ratio<10000, 254>>));
}

TEST(constructorQty, DefaultWithRatio)
{
	Qty<Metre, std::milli> m;
	ASSERT_TRUE((std::is_same_v<decltype(m)::Unit, Unit<1, 0, 0, 0, 0, 0, 0>>));
	ASSERT_EQ(m.value, 0);
	ASSERT_TRUE((std::is_same_v<decltype(m)::Ratio, std::milli>));

	Qty<Kilogram, std::milli> kg;
	ASSERT_TRUE((std::is_same_v<decltype(kg)::Unit, Unit<0, 1, 0, 0, 0, 0, 0>>));
	ASSERT_EQ(kg.value, 0);
	ASSERT_TRUE((std::is_same_v<decltype(kg)::Ratio, std::milli>));

	Qty<Second, std::milli> s;
	ASSERT_TRUE((std::is_same_v<decltype(s)::Unit, Unit<0, 0, 1, 0, 0, 0, 0>>));
	ASSERT_EQ(s.value, 0);
	ASSERT_TRUE((std::is_same_v<decltype(s)::Ratio, std::milli>));

	Qty<Ampere, std::milli> a;
	ASSERT_TRUE((std::is_same_v<decltype(a)::Unit, Unit<0, 0, 0, 1, 0, 0, 0>>));
	ASSERT_EQ(a.value, 0);
	ASSERT_TRUE((std::is_same_v<decltype(a)::Ratio, std::milli>));

	Qty<Kelvin, std::milli> k;
	ASSERT_TRUE((std::is_same_v<decltype(k)::Unit, Unit<0, 0, 0, 0, 1, 0, 0>>));
	ASSERT_EQ(k.value, 0);
	ASSERT_TRUE((std::is_same_v<decltype(k)::Ratio, std::milli>));

	Qty<Mole, std::milli> mo;
	ASSERT_TRUE((std::is_same_v<decltype(mo)::Unit, Unit<0, 0, 0, 0, 0, 1, 0>>));
	ASSERT_EQ(mo.value, 0);
	ASSERT_TRUE((std::is_same_v<decltype(mo)::Ratio, std::milli>));

	Qty<Candela, std::milli> c;
	ASSERT_TRUE((std::is_same_v<decltype(c)::Unit, Unit<0, 0, 0, 0, 0, 0, 1>>));
	ASSERT_EQ(c.value, 0);
	ASSERT_TRUE((std::is_same_v<decltype(c)::Ratio, std::milli>));

	Qty<Radian, std::milli> r;
	ASSERT_TRUE((std::is_same_v<decltype(r)::Unit, Unit<0, 0, 0, 0, 0, 0, 0>>));
	ASSERT_EQ(r.value, 0);
	ASSERT_TRUE((std::is_same_v<decltype(r)::Ratio, std::milli>));
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

	Mile mi(3);
	ASSERT_TRUE((std::is_same_v<decltype(mi)::Unit, Unit<1, 0, 0, 0, 0, 0, 0>>));
	ASSERT_EQ(r.value, 3);
	ASSERT_TRUE((std::is_same_v<decltype(mi)::Ratio, std::ratio<1609304, 1000>>));

	Yard y(3);
	ASSERT_TRUE((std::is_same_v<decltype(y)::Unit, Unit<1, 0, 0, 0, 0, 0, 0>>));
	ASSERT_EQ(r.value, 3);
	ASSERT_TRUE((std::is_same_v<decltype(y)::Ratio, std::ratio<10000, 9144>>));

	Foot f(3);
	ASSERT_TRUE((std::is_same_v<decltype(f)::Unit, Unit<1, 0, 0, 0, 0, 0, 0>>));
	ASSERT_EQ(r.value, 3);
	ASSERT_TRUE((std::is_same_v<decltype(f)::Ratio, std::ratio<10000, 3048>>));

	Inch i(3);
	ASSERT_TRUE((std::is_same_v<decltype(i)::Unit, Unit<1, 0, 0, 0, 0, 0, 0>>));
	ASSERT_EQ(r.value, 3);
	ASSERT_TRUE((std::is_same_v<decltype(i)::Ratio, std::ratio<10000, 254>>));
}

TEST(constructorQty, WithParameterWithRatio)
{
	Qty<Metre, std::milli> m(1);
	ASSERT_TRUE((std::is_same_v<decltype(m)::Unit, Unit<1, 0, 0, 0, 0, 0, 0>>));
	ASSERT_EQ(m.value, 1);
	ASSERT_TRUE((std::is_same_v<decltype(m)::Ratio, std::milli>));

	Qty<Kilogram, std::milli> kg(1);
	ASSERT_TRUE((std::is_same_v<decltype(kg)::Unit, Unit<0, 1, 0, 0, 0, 0, 0>>));
	ASSERT_EQ(kg.value, 1);
	ASSERT_TRUE((std::is_same_v<decltype(kg)::Ratio, std::milli>));

	Qty<Second, std::milli> s(1);
	ASSERT_TRUE((std::is_same_v<decltype(s)::Unit, Unit<0, 0, 1, 0, 0, 0, 0>>));
	ASSERT_EQ(s.value, 1);
	ASSERT_TRUE((std::is_same_v<decltype(s)::Ratio, std::milli>));

	Qty<Ampere, std::milli> a(1);
	ASSERT_TRUE((std::is_same_v<decltype(a)::Unit, Unit<0, 0, 0, 1, 0, 0, 0>>));
	ASSERT_EQ(a.value, 1);
	ASSERT_TRUE((std::is_same_v<decltype(a)::Ratio, std::milli>));

	Qty<Kelvin, std::milli> k(1);
	ASSERT_TRUE((std::is_same_v<decltype(k)::Unit, Unit<0, 0, 0, 0, 1, 0, 0>>));
	ASSERT_EQ(k.value, 1);
	ASSERT_TRUE((std::is_same_v<decltype(k)::Ratio, std::milli>));

	Qty<Mole, std::milli> mo(1);
	ASSERT_TRUE((std::is_same_v<decltype(mo)::Unit, Unit<0, 0, 0, 0, 0, 1, 0>>));
	ASSERT_EQ(mo.value, 1);
	ASSERT_TRUE((std::is_same_v<decltype(mo)::Ratio, std::milli>));

	Qty<Candela, std::milli> c(1);
	ASSERT_TRUE((std::is_same_v<decltype(c)::Unit, Unit<0, 0, 0, 0, 0, 0, 1>>));
	ASSERT_EQ(c.value, 1);
	ASSERT_TRUE((std::is_same_v<decltype(c)::Ratio, std::milli>));

	Qty<Radian, std::milli> r(1);
	ASSERT_TRUE((std::is_same_v<decltype(r)::Unit, Unit<0, 0, 0, 0, 0, 0, 0>>));
	ASSERT_EQ(r.value, 1);
	ASSERT_TRUE((std::is_same_v<decltype(r)::Ratio, std::milli>));
}


/**
 * Qty compound operators tests
 */

// sum

TEST(sumQty, SameRatio_large)
{
	Qty<Metre, std::femto> fm1(50);
	Qty<Metre, std::femto> fm2(30);
	fm1 += fm2;
	ASSERT_EQ(fm1.value, 80);
	ASSERT_TRUE((std::is_same_v<decltype(fm1)::Ratio, std::femto>));
	ASSERT_TRUE((std::is_same_v<decltype(fm2)::Ratio, std::femto>));
}

TEST(sumQty, SameRatio_1)
{
	Qty<Metre> m1(2);
	Qty<Metre> m2(12);
	m1 += m2;
	ASSERT_EQ(m1.value, 14);
	ASSERT_TRUE((std::is_same_v<decltype(m1)::Ratio, std::ratio<1>>));
	ASSERT_TRUE((std::is_same_v<decltype(m2)::Ratio, std::ratio<1>>));
}

TEST(sumQty, SameRatio_small)
{
	Qty<Metre, std::peta> pm1(50);
	Qty<Metre, std::peta> pm2(30);
	pm1 += pm2;
	ASSERT_EQ(pm1.value, 80);
	ASSERT_TRUE((std::is_same_v<decltype(pm1)::Ratio, std::peta>));
	ASSERT_TRUE((std::is_same_v<decltype(pm2)::Ratio, std::peta>));
}

TEST(sumQty, DifferentRatio_big_difference_1)
{
	Qty<Candela, std::kilo> kc(200);
	Qty<Candela, std::nano> nc(12);
	kc += nc;
	ASSERT_EQ(kc.value, 200);
	ASSERT_TRUE((std::is_same_v<decltype(kc)::Ratio, std::kilo>));
	ASSERT_TRUE((std::is_same_v<decltype(nc)::Ratio, std::nano>));
}

TEST(sumQty, DifferentRatio_big_difference_2)
{
	Qty<Candela, std::kilo> kc(200);
	Qty<Candela, std::nano> nc(12);
	nc += kc;
	intmax_t res = (2e+14) + 12;
	ASSERT_EQ(nc.value, res);
	ASSERT_TRUE((std::is_same_v<decltype(kc)::Ratio, std::kilo>));
	ASSERT_TRUE((std::is_same_v<decltype(nc)::Ratio, std::nano>));
}

TEST(sumQty, DifferentRatio_small_difference_1)
{
	Qty<Radian, std::kilo> kr(200);
	Qty<Radian> k(12);
	kr += k;
	ASSERT_EQ(kr.value, 200);
	ASSERT_TRUE((std::is_same_v<decltype(kr)::Ratio, std::kilo>));
	ASSERT_TRUE((std::is_same_v<decltype(k)::Ratio, std::ratio<1>>));
}

TEST(sumQty, DifferentRatio_small_difference_2)
{
	Qty<Radian, std::kilo> kr(200);
	Qty<Radian> r(12);
	r += kr;
	ASSERT_EQ(r.value, 200012);
	ASSERT_TRUE((std::is_same_v<decltype(kr)::Ratio, std::kilo>));
	ASSERT_TRUE((std::is_same_v<decltype(r)::Ratio, std::ratio<1>>));
}

TEST(sumQty, Many)
{
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

TEST(sumQty, notSimpleAddition)
{
	Qty<Metre, std::ratio<73, 125>> m1(5);
	Qty<Metre, std::ratio<127, 342>> m2(8);
	auto m3 = m1 + m2;
	Qty<Metre, std::ratio<1, 4275>> m4(25183);
	EXPECT_TRUE(m3 == m4);
}


// substraction

TEST(subQty, SameRatio_large)
{
	Qty<Metre, std::femto> fm1(50);
	Qty<Metre, std::femto> fm2(30);
	fm1 -= fm2;
	ASSERT_EQ(fm1.value, 20);
	ASSERT_TRUE((std::is_same_v<decltype(fm1)::Ratio, std::femto>));
	ASSERT_TRUE((std::is_same_v<decltype(fm2)::Ratio, std::femto>));
}

TEST(subQty, SameRatio_1)
{
	Qty<Metre> m1(2);
	Qty<Metre> m2(12);
	m1 -= m2;
	ASSERT_EQ(m1.value, -10);
	ASSERT_TRUE((std::is_same_v<decltype(m1)::Ratio, std::ratio<1>>));
	ASSERT_TRUE((std::is_same_v<decltype(m2)::Ratio, std::ratio<1>>));
}

TEST(subQty, SameRatio_small)
{
	Qty<Metre, std::peta> pm1(50);
	Qty<Metre, std::peta> pm2(30);
	pm1 -= pm2;
	ASSERT_EQ(pm1.value, 20);
	ASSERT_TRUE((std::is_same_v<decltype(pm1)::Ratio, std::peta>));
	ASSERT_TRUE((std::is_same_v<decltype(pm2)::Ratio, std::peta>));
}

TEST(subQty, DifferentRatio_big_difference_1)
{
	Qty<Candela, std::kilo> kc(200);
	Qty<Candela, std::nano> nc(12);
	kc -= nc;
	ASSERT_EQ(kc.value, 200);
	ASSERT_TRUE((std::is_same_v<decltype(kc)::Ratio, std::kilo>));
	ASSERT_TRUE((std::is_same_v<decltype(nc)::Ratio, std::nano>));
}

TEST(subQty, DifferentRatio_big_difference_2)
{
	Qty<Candela, std::kilo> kc(200);
	Qty<Candela, std::nano> nc(10);
	nc -= kc;
	ASSERT_EQ(nc.value, -199999999999990);
	ASSERT_TRUE((std::is_same_v<decltype(kc)::Ratio, std::kilo>));
	ASSERT_TRUE((std::is_same_v<decltype(nc)::Ratio, std::nano>));
}

TEST(subQty, DifferentRatio_small_difference_1)
{
	Qty<Radian, std::kilo> kr(200);
	Qty<Radian> r(12);
	kr -= r;
	ASSERT_EQ(kr.value, 200);
	ASSERT_TRUE((std::is_same_v<decltype(kr)::Ratio, std::kilo>));
	ASSERT_TRUE((std::is_same_v<decltype(r)::Ratio, std::ratio<1>>));
}

TEST(subQty, DifferentRatio_small_difference_2)
{
	Qty<Radian, std::kilo> kr(200);
	Qty<Radian> r(12);
	r -= kr;
	ASSERT_EQ(r.value, -199988);
	ASSERT_TRUE((std::is_same_v<decltype(kr)::Ratio, std::kilo>));
	ASSERT_TRUE((std::is_same_v<decltype(r)::Ratio, std::ratio<1>>));
}

TEST(subQty, Many)
{
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
TEST(equalityOperator, NotEqual)
{
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(3000);
	ASSERT_FALSE(m == mm);
}

TEST(equalityOperator, SameRatio)
{
	Qty<Metre> m1(2);
	Qty<Metre> m2(2);
	ASSERT_TRUE(m1 == m2);
}

TEST(equalityOperator, DifferentRatioLittle)
{
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(2000);
	ASSERT_TRUE(m == mm);
}

TEST(equalityOperator, DifferentRatioBig)
{
	Qty<Metre, std::kilo> km(2);
	Qty<Metre, std::nano> nm(2000000000000);
	ASSERT_TRUE(km == nm);
}

TEST(equalityOperator, Square)
{
	squareKiloMeter km(1);
	squareCentiMeter cm(10000000000);
	ASSERT_TRUE(km == cm);
}


// non-equality operator
TEST(comparisonOperatorsNotEq, NotEqual)
{
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(3000);
	ASSERT_TRUE(m != mm);
}

TEST(nonEqualityOperator, SameRatio)
{
	Qty<Metre> m1(2);
	Qty<Metre> m2(2);
	ASSERT_FALSE(m1 != m2);
}

TEST(nonEqualityOperator, DifferentRatioLittle)
{
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(2000);
	ASSERT_FALSE(m != mm);
}

TEST(nonEqualityOperator, DifferentRatioBig)
{
	Qty<Metre, std::kilo> km(2);
	Qty<Metre, std::nano> nm(2000000000000);
	ASSERT_FALSE(km != nm);
}

// strict inferiority operator
TEST(comparisonOperatorsLt, Lower)
{
	Qty<Metre> m(2);
	Qty<Metre, std::centi> cm(2);
	ASSERT_TRUE(cm < m);
}

TEST(comparisonOperatorsLt, Equal)
{
	Qty<Metre> m(2);
	Qty<Metre, std::centi> cm(200);
	ASSERT_FALSE(cm < m);
}

TEST(comparisonOperatorsLt, Upper)
{
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(3000);
	ASSERT_FALSE(mm < m);
}

TEST(comparisonOperatorsLt, LowerSameRatio)
{
	Qty<Metre> m1(2);
	Qty<Metre> m2(3);
	ASSERT_TRUE(m1 < m2);
}

TEST(comparisonOperatorsLt, LowerDifferentRatioLittle)
{
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(3000);
	ASSERT_TRUE(m < mm);
}

TEST(comparisonOperatorsLt, LowerDifferentRatioBig)
{
	Qty<Metre, std::kilo> km(2);
	Qty<Metre, std::nano> nm(3000000000000);
	ASSERT_TRUE(km < nm);
}

// inferiority operator

TEST(comparisonOperatorsLe, Lower)
{
	Qty<Metre> m(2);
	Qty<Metre, std::centi> cm(2);
	ASSERT_TRUE(cm <= m);
}

TEST(comparisonOperatorsLe, Equal)
{
	Qty<Metre> m(2);
	Qty<Metre, std::centi> cm(200);
	ASSERT_TRUE(cm <= m);
}

TEST(comparisonOperatorsLe, Upper)
{
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(3000);
	ASSERT_FALSE(mm <= m);
}

TEST(comparisonOperatorsLe, LowerSameRatio)
{
	Qty<Metre> m1(2);
	Qty<Metre> m2(3);
	ASSERT_TRUE(m1 <= m2);
}

TEST(comparisonOperatorsLe, LowerDifferentRatioLittle)
{
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(3000);
	ASSERT_TRUE(m <= mm);
}

TEST(comparisonOperatorsLe, LowerDifferentRatioBig)
{
	Qty<Metre, std::kilo> km(2);
	Qty<Metre, std::nano> nm(3000000000000);
	ASSERT_TRUE(km <= nm);
}

// strict superiority operator

TEST(comparisonOperatorsGt, Lower)
{
	Qty<Metre> m(2);
	Qty<Metre, std::centi> cm(2);
	ASSERT_FALSE(cm > m);
}

TEST(comparisonOperatorsGt, Equal)
{
	Qty<Metre> m(2);
	Qty<Metre, std::centi> cm(200);
	ASSERT_FALSE(cm > m);
}

TEST(comparisonOperatorsGt, Upper)
{
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(3000);
	ASSERT_TRUE(mm > m);
}

TEST(comparisonOperatorsGt, UpperSameRatio)
{
	Qty<Metre> m1(2);
	Qty<Metre> m2(3);
	ASSERT_TRUE(m2 > m1);
}

TEST(comparisonOperatorsGt, UpperDifferentRatioLittle)
{
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(3000);
	ASSERT_TRUE(mm > m);
}

TEST(comparisonOperatorsGt, UpperDifferentRatioBig)
{
	Qty<Metre, std::kilo> km(2);
	Qty<Metre, std::nano> nm(3000000000000);
	ASSERT_TRUE(nm > km);
}


// superiority operator

TEST(comparisonOperatorsGe, Lower)
{
	Qty<Metre> m(2);
	Qty<Metre, std::centi> cm(2);
	ASSERT_FALSE(cm >= m);
}

TEST(comparisonOperatorsGe, Equal)
{
	Qty<Metre> m(2);
	Qty<Metre, std::centi> cm(200);
	ASSERT_TRUE(cm >= m);
}

TEST(comparisonOperatorsGe, Upper)
{
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(3000);
	ASSERT_TRUE(mm >= m);
}

TEST(comparisonOperatorsGe, UpperSameRatio)
{
	Qty<Metre> m1(2);
	Qty<Metre> m2(3);
	ASSERT_TRUE(m2 >= m1);
}

TEST(comparisonOperatorsGe, UpperDifferentRatioLittle)
{
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(3000);
	ASSERT_TRUE(mm >= m);
}

TEST(comparisonOperatorsGe, UpperDifferentRatioBig)
{
	Qty<Metre, std::kilo> km(2);
	Qty<Metre, std::nano> nm(3000000000000);
	ASSERT_TRUE(nm >= km);
}




/**
 * arithmetic operators tests
 */

// sum
TEST(arithmeticOperatorsSum, SameRatio)
{
	Qty<Metre> m1(2);
	Qty<Metre> m2(2000);
	auto sum = m1 + m2;
	ASSERT_EQ(sum.value, 2002);
	ASSERT_TRUE((std::is_same_v<decltype(sum)::Ratio, std::ratio<1>>));
}

TEST(arithmeticOperatorsSum, DifferentRatioFirstBiggest)
{
	Qty<Radian> r(2);
	Qty<Radian, std::milli> rm(2);
	auto sum = r + rm;
	ASSERT_EQ(sum.value, 2002);
	ASSERT_TRUE((std::is_same_v<decltype(sum)::Ratio, std::milli>));
}

TEST(arithmeticOperatorsSum, DifferentRatioSecondBiggest)
{
	Qty<Radian> r(2);
	Qty<Radian, std::milli> rm(2);
	auto sum = rm + r;
	ASSERT_EQ(sum.value, 2002);
	ASSERT_TRUE((std::is_same_v<decltype(sum)::Ratio, std::milli>));
}


// substraction

TEST(arithmeticOperatorsSub, SameRatio)
{
	Qty<Metre> m1(4);
	Qty<Metre> m2(2);
	auto sub = m1 - m2;
	ASSERT_EQ(sub.value, 2);
	ASSERT_TRUE((std::is_same_v<decltype(sub)::Ratio, std::ratio<1>>));
}

TEST(arithmeticOperatorsSub, DifferentRatioFirstBiggest)
{
	Qty<Radian, std::kilo> kr(4);
	Qty<Radian, std::milli> mr(200);
	auto sub = kr - mr;
	ASSERT_EQ(sub.value, 3999800);
	ASSERT_TRUE((std::is_same_v<decltype(sub)::Ratio, std::milli>));
}

TEST(arithmeticOperatorsSub, DifferentRatioSecondBiggest)
{
	Qty<Radian> r(2);
	Qty<Radian, std::milli> rm(4000);
	auto sub = rm - r;
	ASSERT_EQ(sub.value, 2000);
	ASSERT_TRUE((std::is_same_v<decltype(sub)::Ratio, std::milli>));
}

// product

TEST(arithmeticOperatorsProduct, SameRatio)
{
	Qty<Metre> m1(4);
	Qty<Metre> m2(2);
	auto product = m1 * m2;
	ASSERT_EQ(product.value, 8);
	ASSERT_TRUE((std::is_same_v<decltype(product)::Ratio, std::ratio<1>>));
	ASSERT_TRUE((std::is_same_v<decltype(product)::Unit, Unit<2, 0, 0, 0, 0, 0, 0>>));
}

TEST(arithmeticOperatorsProduct, DifferentRatioFirstBiggest)
{
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(2000);
	auto product = m * mm;
	ASSERT_EQ(product.value, 4000000);
	ASSERT_TRUE((std::is_same_v<decltype(product)::Ratio, std::milli>));
	ASSERT_TRUE((std::is_same_v<decltype(product)::Unit, Unit<2, 0, 0, 0, 0, 0, 0>>));
}

TEST(arithmeticOperatorsProduct, DifferentRatioSecondBiggest)
{
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(2000);
	auto product = mm * m;
	ASSERT_EQ(product.value, 4000000);
	ASSERT_TRUE((std::is_same_v<decltype(product)::Ratio, std::milli>));
	ASSERT_TRUE((std::is_same_v<decltype(product)::Unit, Unit<2, 0, 0, 0, 0, 0, 0>>));
}

TEST(arithmeticOperatorsProduct, DifferentRatioSecondBiggest_2)
{
	Qty<Metre, std::kilo> km(2);
	Qty<Metre, std::milli> mm(2000);
	auto product = mm * km;
	ASSERT_EQ(product.value, 4000000000);
	ASSERT_TRUE((std::is_same_v<decltype(product)::Ratio, std::milli>));
	ASSERT_TRUE((std::is_same_v<decltype(product)::Unit, Unit<2, 0, 0, 0, 0, 0, 0>>));
}

TEST(arithmeticOperatorsProduct, DifferentUnits)
{
	Qty<Metre, std::kilo> km(2);
	Qty<Second> s(2000);
	auto product = km * s;
	ASSERT_EQ(product.value, 4000000);
	ASSERT_TRUE((std::is_same_v<decltype(product)::Ratio, std::ratio<1>>));
	ASSERT_TRUE((std::is_same_v<decltype(product)::Unit, Unit<1, 0, 1, 0, 0, 0, 0>>));
}


// quotient

TEST(arithmeticOperatorsQuotient, SameRatioSameUnit)
{
	Qty<Metre> m1(4);
	Qty<Metre> m2(2);
	auto quotient = m1 / m2;
	ASSERT_EQ(quotient.value, 2);
	ASSERT_TRUE((std::is_same_v<decltype(quotient)::Ratio, std::ratio<1>>));
	ASSERT_TRUE((std::is_same_v<decltype(quotient)::Unit, Radian>));
}

TEST(arithmeticOperatorsQuotient, DifferentRatioFirstBiggestSameUnit)
{
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(2000);
	auto quotient = m / mm;
	ASSERT_EQ(quotient.value, 1);
	ASSERT_TRUE((std::is_same_v<decltype(quotient)::Ratio, std::milli>));
	ASSERT_TRUE((std::is_same_v<decltype(quotient)::Unit, Radian>));
}

TEST(arithmeticOperatorsQuotient, DifferentRatioSecondBiggestSameUnit)
{
	Qty<Metre> m(2);
	Qty<Metre, std::milli> mm(200);
	auto quotient = mm / m;
	ASSERT_EQ(quotient.value, 0.1);
	ASSERT_TRUE((std::is_same_v<decltype(quotient)::Ratio, std::milli>));
	ASSERT_TRUE((std::is_same_v<decltype(quotient)::Unit, Radian>));
}

TEST(arithmeticOperatorsQuotient, DifferentRatioSecondBiggest_2SameUnit)
{
	Qty<Metre, std::kilo> km(2);
	Qty<Metre, std::milli> mm(2000);
	auto quotient = mm / km;
	ASSERT_EQ(quotient.value, 0.001); // garder la bonne valeur, changer le ratio ??
	ASSERT_TRUE((std::is_same_v<decltype(quotient)::Ratio, std::milli>));
	ASSERT_TRUE((std::is_same_v<decltype(quotient)::Unit, Radian>));
}

TEST(arithmeticOperatorsQuotient, DifferentUnits)
{
	Qty<Metre, std::kilo> km(2);
	Qty<Second> s(2000);
	auto product = km / s;
	ASSERT_EQ(product.value, 1);
	ASSERT_TRUE((std::is_same_v<decltype(product)::Ratio, std::ratio<1>>)); // 1m/s
	ASSERT_TRUE((std::is_same_v<decltype(product)::Unit, Unit<1, 0, -1, 0, 0, 0, 0>>));
}

TEST(arithmeticOperatorsQuotient, DivisionWithRatio)
{
	Qty<Metre, std::milli> length(2);
	Qty<Second, std::centi> time(500);

	auto result = length / time;
	ASSERT_EQ(result.value, 0);

	ASSERT_TRUE((std::is_same_v<decltype(result)::Ratio, std::milli>));
	ASSERT_TRUE((std::is_same_v<decltype(result)::Unit, Unit<1, 0, -1, 0, 0, 0, 0>>));
}

TEST(arithmeticOperatorsQuotient, test1)
{
	Qty<cubeMeter, std::kilo> km3(12);
	Qty<squareSecond, std::centi> cs2(500);

	auto result = km3 / cs2;
	ASSERT_EQ(result.value, 2400);

	ASSERT_TRUE((std::is_same_v<decltype(result)::Ratio, std::centi>));
	ASSERT_TRUE((std::is_same_v<decltype(result)::Unit, Unit<3, 0, -2, 0, 0, 0, 0>>));
}

TEST(arithmeticOperatorsQuotient, test2)
{
	Qty<cubeMeter, std::centi> cm3(12);
	Qty<squareSecond, std::centi> cs2(500);

	auto result = cm3 / cs2;
	ASSERT_EQ(result.value, 0.024);

	ASSERT_TRUE((std::is_same_v<decltype(result)::Ratio, std::centi>));
	ASSERT_TRUE((std::is_same_v<decltype(result)::Unit, Unit<3, 0, -2, 0, 0, 0, 0>>));
}

/**
 * Cast tests
 */
TEST(castQuantity, KilometerToMeter)
{
	Kilometre km(4);

	auto m = qtyCast<Qty<Metre, std::ratio<1>>>(km);

	ASSERT_EQ(m.value, 4000);
	ASSERT_TRUE((std::is_same_v<decltype(m)::Ratio, std::ratio<1>>));
	ASSERT_TRUE((std::is_same_v<decltype(m)::Unit, Metre>));
}

TEST(castQuantity, SquareKiloeterToSquareMeter)
{
	squareKiloMeter km2(4);
	Qty<squareMeter> m2 = qtyCast<Qty<squareMeter, std::ratio<1>>>(km2);

	ASSERT_EQ(m2.value, 4000000);
	ASSERT_TRUE((std::is_same_v<decltype(m2)::Ratio, std::ratio<1>>));
	ASSERT_TRUE((std::is_same_v<decltype(m2)::Unit, squareMeter>));
}

TEST(castQuantity, SquareMeterToSquareKilometer)
{

	Qty<squareMeter> m2(4000000);
	auto km2 = qtyCast<squareKiloMeter>(m2);

	ASSERT_EQ(km2.value, 4);
	ASSERT_TRUE((std::is_same_v<decltype(km2)::Ratio, std::kilo>));
	ASSERT_TRUE((std::is_same_v<decltype(km2)::Unit, squareKiloMeter::Unit>));
}

TEST(castQuantity, SquareKilometerToSquareCentimeter)
{
	squareKiloMeter km2(3);
	auto cm2 = qtyCast<squareCentiMeter>(km2);

	ASSERT_EQ(cm2.value, 30000000000);
	ASSERT_TRUE((std::is_same_v<decltype(cm2)::Ratio, std::centi>));
	ASSERT_TRUE((std::is_same_v<decltype(cm2)::Unit, squareCentiMeter::Unit>));
}

TEST(castQuantity, CubeKilometerToCubeCentimeter)
{
	cubeKilometer km3(3);
	auto cm3 = qtyCast<cubeCentimeter>(km3);

	ASSERT_EQ(cm3.value, 3000000000000000);
	ASSERT_TRUE((std::is_same_v<decltype(cm3)::Ratio, std::centi>));
	ASSERT_TRUE((std::is_same_v<decltype(cm3)::Unit, cubeCentimeter::Unit>));
}

TEST(castQuantity, CubeCentimeterToCubeKilometer)
{
	cubeCentimeter cm3(3000000000000000);
	auto km3 = qtyCast<cubeKilometer>(cm3);

	ASSERT_EQ(km3.value, 3);
	ASSERT_TRUE((std::is_same_v<decltype(km3)::Ratio, std::kilo>));
	ASSERT_TRUE((std::is_same_v<decltype(km3)::Unit, cubeKilometer::Unit>));
}

TEST(castQuantity, meterSecondToKilometerSecond)
{
	Qty<meterSecond, std::ratio<1>> ms(3000);
	auto kms = qtyCast<kilometerSecond>(ms);

	ASSERT_EQ(kms.value, 3);
	ASSERT_TRUE((std::is_same_v<decltype(kms)::Ratio, std::kilo>));
	ASSERT_TRUE((std::is_same_v<decltype(kms)::Unit, kilometerSecond::Unit>));
}

/**
 * literals tests
 */

TEST(literals, Default)
{
	using namespace literals;

	auto len1 = 2_metres;
	auto len2 = 5_metres;

	ASSERT_EQ(len1.value, 2);
	ASSERT_EQ(len2.value, 5);
	ASSERT_TRUE((std::is_same_v<decltype(len1)::Ratio, std::ratio<1>>));
	ASSERT_TRUE((std::is_same_v<decltype(len1)::Unit, Metre>));
}

TEST(literals, Meter)
{
	using namespace literals;
	auto m = 2_metres;
	ASSERT_EQ(m.value, 2);
	ASSERT_TRUE((std::is_same_v<decltype(m)::Ratio, std::ratio<1>>));
	ASSERT_TRUE((std::is_same_v<decltype(m)::Unit, Metre>));
}

TEST(literals, Kilogram)
{
	using namespace literals;
	auto m = 2_kilograms;
	ASSERT_EQ(m.value, 2);
	ASSERT_TRUE((std::is_same_v<decltype(m)::Ratio, std::ratio<1>>));
	ASSERT_TRUE((std::is_same_v<decltype(m)::Unit, Kilogram>));
}

TEST(literals, Second)
{
	using namespace literals;
	auto m = 2_seconds;
	ASSERT_EQ(m.value, 2);
	ASSERT_TRUE((std::is_same_v<decltype(m)::Ratio, std::ratio<1>>));
	ASSERT_TRUE((std::is_same_v<decltype(m)::Unit, Second>));
}

TEST(literals, Ampere)
{
	using namespace literals;
	auto m = 2_amperes;
	ASSERT_EQ(m.value, 2);
	ASSERT_TRUE((std::is_same_v<decltype(m)::Ratio, std::ratio<1>>));
	ASSERT_TRUE((std::is_same_v<decltype(m)::Unit, Ampere>));
}

TEST(literals, Kelvin)
{
	using namespace literals;
	auto m = 2_kelvins;
	ASSERT_EQ(m.value, 2);
	ASSERT_TRUE((std::is_same_v<decltype(m)::Ratio, std::ratio<1>>));
	ASSERT_TRUE((std::is_same_v<decltype(m)::Unit, Kelvin>));
}

TEST(literals, Mole)
{
	using namespace literals;
	auto m = 2_moles;
	ASSERT_EQ(m.value, 2);
	ASSERT_TRUE((std::is_same_v<decltype(m)::Ratio, std::ratio<1>>));
	ASSERT_TRUE((std::is_same_v<decltype(m)::Unit, Mole>));
}

TEST(literals, Candela)
{
	using namespace literals;
	auto m = 2_candelas;
	ASSERT_EQ(m.value, 2);
	ASSERT_TRUE((std::is_same_v<decltype(m)::Ratio, std::ratio<1>>));
	ASSERT_TRUE((std::is_same_v<decltype(m)::Unit, Candela>));
}

TEST(literals, Celsius)
{
	using namespace literals;
	auto m = 25_celsius;
	ASSERT_EQ(m.value, 298.15);
	ASSERT_TRUE((std::is_same_v<decltype(m)::Ratio, std::ratio<1>>));
	ASSERT_TRUE((std::is_same_v<decltype(m)::Unit, Kelvin>));
}

TEST(literals, _Fahrenheit)
{
	using namespace literals;
	auto m = 10_fahrenheit;
	ASSERT_EQ(m.value, 260.928);
	ASSERT_TRUE((std::is_same_v<decltype(m)::Ratio, std::ratio<1>>));
	ASSERT_TRUE((std::is_same_v<decltype(m)::Unit, Kelvin>));
}

TEST(literals, Fahrenheit)
{
	using namespace literals;
	auto temp = 0_fahrenheit;
	ASSERT_EQ(temp.value, 255.372); // Revoir
}


/**
 * test meters conversion
 */
TEST(metersConversion, test1)
{
	Mile miles(1000);
	ASSERT_TRUE((std::is_same_v<decltype(miles)::Ratio, std::ratio<1609304, 1000>>));
	ASSERT_TRUE((std::is_same_v<decltype(miles)::Unit, Mile::Unit>));

	auto meters = qtyCast<Qty<Metre, std::ratio<1>>>(miles);

	ASSERT_EQ(meters.value, 1609000);
	ASSERT_TRUE((std::is_same_v<decltype(meters)::Ratio, std::ratio<1>>));
	ASSERT_TRUE((std::is_same_v<decltype(meters)::Unit, Metre>));
}

TEST(metersConversion, test2)
{
	Yard yards(100000);
	ASSERT_TRUE((std::is_same_v<decltype(yards)::Ratio, std::ratio<10000, 9144>>));
	ASSERT_TRUE((std::is_same_v<decltype(yards)::Unit, Mile::Unit>));

	auto meters = qtyCast<Qty<Metre, std::ratio<1>>>(yards);

	ASSERT_EQ(meters.value, 91440);
	ASSERT_TRUE((std::is_same_v<decltype(meters)::Ratio, std::ratio<1>>));
	ASSERT_TRUE((std::is_same_v<decltype(meters)::Unit, Metre>));
}

TEST(metersConversion, test3)
{
	Foot feet(20000);
	ASSERT_TRUE((std::is_same_v<decltype(feet)::Ratio, std::ratio<10000, 3048>>));
	ASSERT_TRUE((std::is_same_v<decltype(feet)::Unit, Mile::Unit>));

	auto meters = qtyCast<Qty<Metre, std::ratio<1>>>(feet);

	ASSERT_EQ(meters.value, 6096);
	ASSERT_TRUE((std::is_same_v<decltype(meters)::Ratio, std::ratio<1>>));
	ASSERT_TRUE((std::is_same_v<decltype(meters)::Unit, Metre>));
}

TEST(metersConversion, test4)
{
	Inch inches(10000);
	ASSERT_TRUE((std::is_same_v<decltype(inches)::Ratio, std::ratio<10000, 254>>));
	ASSERT_TRUE((std::is_same_v<decltype(inches)::Unit, Mile::Unit>));

	auto meters = qtyCast<Qty<Metre, std::ratio<1>>>(inches);

	ASSERT_EQ(meters.value, 254);
	ASSERT_TRUE((std::is_same_v<decltype(meters)::Ratio, std::ratio<1>>));
	ASSERT_TRUE((std::is_same_v<decltype(meters)::Unit, Metre>));
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}