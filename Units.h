#ifndef UNITS_H
#define UNITS_H

#include <cstdint>
#include <ratio>

#include <math.h>

namespace phy
{

	/*
	 * A unit defined in terms of the base units
	 */
	template <int Metre, int Kilogram, int Second, int Ampere, int Kelvin, int Mole, int Candela>
	struct Unit
	{
		static constexpr int metre = Metre;
		static constexpr int kilogram = Kilogram;
		static constexpr int second = Second;
		static constexpr int ampere = Ampere;
		static constexpr int kelvin = Kelvin;
		static constexpr int mole = Mole;
		static constexpr int candela = Candela;
	};

	/*
	 * Various type aliases
	 */

	using Metre = Unit<1, 0, 0, 0, 0, 0, 0>;
	using Kilogram = Unit<0, 1, 0, 0, 0, 0, 0>;
	using Second = Unit<0, 0, 1, 0, 0, 0, 0>;
	using Ampere = Unit<0, 0, 0, 1, 0, 0, 0>;
	using Kelvin = Unit<0, 0, 0, 0, 1, 0, 0>;
	using Mole = Unit<0, 0, 0, 0, 0, 1, 0>;
	using Candela = Unit<0, 0, 0, 0, 0, 0, 1>;
	using Radian = Unit<0, 0, 0, 0, 0, 0, 0>;

	/*
	 * A quantity is a value associated with a unit and a ratio
	 */
	template <class U, class R = std::ratio<1>>
	struct Qty
	{
		using Unit = U;
		using Ratio = R;

		intmax_t value;

		Qty() : value(0)
		{
		}

		Qty(intmax_t v) : value(v)
		{
		}

		template <typename ROther>
		Qty &operator+=(Qty<U, ROther> other)
		{
			using new_ratio = std::ratio_divide<ROther, Ratio>;
			value += other.value * new_ratio::num / new_ratio::den;
			return *this;
		}

		template <typename ROther>
		Qty &operator-=(Qty<U, ROther> other)
		{
			using new_ratio = std::ratio_divide<ROther, Ratio>;
			value -= other.value * new_ratio::num / new_ratio::den;
			return *this;
		}
	};

	/*
	 * Various quantities
	 */

	using Length = Qty<Metre>;
	using Mass = Qty<Kilogram>;
	using Time = Qty<Second>;
	using Current = Qty<Ampere>;
	using Temperature = Qty<Kelvin>;
	using Amount = Qty<Mole>;
	using LuminousIntensity = Qty<Candela>;

	/*
	 * Some weird quantities
	 */

	using Mile = Qty<Metre, std::ratio<1000, 1609304>>;
	using Yard = Qty<Metre, std::ratio<9144, 10000>>;
	using Foot = Qty<Metre, std::ratio<3048, 10000>>;
	using Inch = Qty<Metre, std::ratio<254, 10000>>;

	/*
	 * Comparison operators
	 */

	/**
	 * Returns the number of powers of 10 that separate 2 ratios
	 */
	template <typename R1, typename R2>
	int ratios_difference()
	{
		if (std::ratio_less_v<R1, R2>)
		{
			return std::log10(R2::num * R1::den / R1::num / R2::den);
		}
		return std::log10(R1::num * R2::den / R2::num / R1::den);
	}

	template <typename U, typename R1, typename R2>
	bool operator==(Qty<U, R1> q1, Qty<U, R2> q2)
	{
		int exposant_1 = ratios_difference<R1, R2>();
		int exposant_2 = U::metre + U::kilogram + U::second + U::ampere + U::kelvin + U::mole + U::candela;
		if (std::ratio_equal_v<R1, R2> && (q1.value * R1::num / R1::den == q2.value * R2::num / R2::den))
		{
			return true;
		}
		else if (std::ratio_less_v<R2, R1> && (q1.value * std::pow(10, exposant_1 * exposant_2) == q2.value))
		{
			return true;
		}
		else if (std::ratio_less_v<R1, R2> && (q1.value == q2.value * std::pow(10, exposant_1 * exposant_2)))
		{
			return true;
		}
		return false;
	}

	template <typename U, typename R1, typename R2>
	bool operator!=(Qty<U, R1> q1, Qty<U, R2> q2)
	{
		int exposant_1 = ratios_difference<R1, R2>();
		int exposant_2 = U::metre + U::kilogram + U::second + U::ampere + U::kelvin + U::mole + U::candela;

		if (std::ratio_equal_v<R1, R2> && (q1.value * R1::num / R1::den != q2.value * R2::num / R2::den))
		{
			return true;
		}
		else if (std::ratio_less_v<R2, R1> && (q1.value * std::pow(10, exposant_1 * exposant_2) != q2.value))
		{
			return true;
		}
		else if (std::ratio_less_v<R1, R2> && (q1.value != q2.value * std::pow(10, exposant_1 * exposant_2)))
		{
			return true;
		}
		return false;
	}

	template <typename U, typename R1, typename R2>
	bool operator<(Qty<U, R1> q1, Qty<U, R2> q2)
	{
		int exposant_1 = ratios_difference<R1, R2>();
		int exposant_2 = U::metre + U::kilogram + U::second + U::ampere + U::kelvin + U::mole + U::candela;

		if (std::ratio_equal_v<R1, R2> && (q1.value * R1::num / R1::den < q2.value * R2::num / R2::den))
		{
			return true;
		}
		else if (std::ratio_less_v<R2, R1> && (q1.value * std::pow(10, exposant_1 * exposant_2) < q2.value))
		{
			return true;
		}
		else if (std::ratio_less_v<R1, R2> && (q1.value < q2.value * std::pow(10, exposant_1 * exposant_2)))
		{
			return true;
		}
		return false;
	}

	template <typename U, typename R1, typename R2>
	bool operator<=(Qty<U, R1> q1, Qty<U, R2> q2)
	{
		int exposant_1 = ratios_difference<R1, R2>();
		int exposant_2 = U::metre + U::kilogram + U::second + U::ampere + U::kelvin + U::mole + U::candela;

		if (std::ratio_equal_v<R1, R2> && (q1.value * R1::num / R1::den <= q2.value * R2::num / R2::den))
		{
			return true;
		}
		else if (std::ratio_less_v<R2, R1> && (q1.value * std::pow(10, exposant_1 * exposant_2) <= q2.value))
		{
			return true;
		}
		else if (std::ratio_less_v<R1, R2> && (q1.value <= q2.value * std::pow(10, exposant_1 * exposant_2)))
		{
			return true;
		}
		return false;
	}

	template <typename U, typename R1, typename R2>
	bool operator>(Qty<U, R1> q1, Qty<U, R2> q2)
	{
		int exposant_1 = ratios_difference<R1, R2>();
		int exposant_2 = U::metre + U::kilogram + U::second + U::ampere + U::kelvin + U::mole + U::candela;

		if (std::ratio_equal_v<R1, R2> && (q1.value * R1::num / R1::den > q2.value * R2::num / R2::den))
		{
			return true;
		}
		else if (std::ratio_less_v<R2, R1> && (q1.value * std::pow(10, exposant_1 * exposant_2) > q2.value))
		{
			return true;
		}
		else if (std::ratio_less_v<R1, R2> && (q1.value > q2.value * std::pow(10, exposant_1 * exposant_2)))
		{
			return true;
		}
		return false;
	}

	template <typename U, typename R1, typename R2>
	bool operator>=(Qty<U, R1> q1, Qty<U, R2> q2)
	{
		int exposant_1 = ratios_difference<R1, R2>();
		int exposant_2 = U::metre + U::kilogram + U::second + U::ampere + U::kelvin + U::mole + U::candela;

		if (std::ratio_equal_v<R1, R2> && (q1.value * R1::num / R1::den >= q2.value * R2::num / R2::den))
		{
			return true;
		}
		else if (std::ratio_less_v<R2, R1> && (q1.value * std::pow(10, exposant_1 * exposant_2) >= q2.value))
		{
			return true;
		}
		else if (std::ratio_less_v<R1, R2> && (q1.value >= q2.value * std::pow(10, exposant_1 * exposant_2)))
		{
			return true;
		}
		return false;
	}

	/**
	 * Returns the lowest ratio
	 */
	template <typename R1, typename R2, bool l>
	struct chooseRatio
	{
		using type = R1;
	};

	template <typename R1, typename R2>
	struct chooseRatio<R1, R2, false>
	{
		using type = R2;
	};

	template <typename R1, typename R2>
	using chooseRatio_t = typename chooseRatio<R1, R2, std::ratio_less_v<R1, R2>>::type;

	/*
	 * Arithmetic operators
	 */

	template <typename U, typename R1, typename R2>
	Qty<U, chooseRatio_t<R1, R2>> operator+(Qty<U, R1> q1, Qty<U, R2> q2)
	{
		using new_ratio = typename chooseRatio_t<R1, R2>::type;
		intmax_t new_value = 0;
		if (std::ratio_equal<new_ratio, R1>::value)
		{
			using r = std::ratio_divide<R2, R1>;
			new_value = q1.value + q2.value * r::num / r::den;
		}
		else
		{
			using r = std::ratio_divide<R1, R2>;
			new_value = q1.value * r::num / r::den + q2.value;
		}
		return Qty<U, new_ratio>(new_value);
	}

	template <typename U, typename R1, typename R2>
	Qty<U, chooseRatio_t<R1, R2>> operator-(Qty<U, R1> q1, Qty<U, R2> q2)
	{
		using new_ratio = typename chooseRatio_t<R1, R2>::type;
		intmax_t new_value = 0;
		if (std::ratio_equal<new_ratio, R1>::value)
		{
			using r = std::ratio_divide<R2, R1>;
			new_value = q1.value - q2.value * r::num / r::den;
		}
		else
		{
			using r = std::ratio_divide<R1, R2>;
			new_value = q1.value * r::num / r::den - q2.value;
		}
		return Qty<U, new_ratio>(new_value);
	}

	/**
	 * Calculate the product of unity
	 */
	template <typename U1, typename U2>
	using product_unit = Unit<U1::metre + U2::metre, U1::kilogram + U2::kilogram,
							  U1::second + U2::second, U1::ampere + U2::ampere,
							  U1::kelvin + U2::kelvin, U1::mole + U2::mole, U1::candela + U2::candela>;


	template <typename U1, typename R1, typename U2, typename R2>
	Qty<product_unit<U1, U2>, chooseRatio_t<R1, R2>> operator*(Qty<U1, R1> q1, Qty<U2, R2> q2)
	{
		using new_ratio = typename chooseRatio_t<R1, R2>::type;
		using new_unit = product_unit<U1, U2>;

		intmax_t new_value = 0;
		if (std::ratio_equal<new_ratio, R1>::value)
		{
			using r = std::ratio_divide<R2, R1>;
			new_value = q1.value * (q2.value * r::num / r::den);
		}
		else
		{
			using r = std::ratio_divide<R1, R2>;
			new_value = (q1.value * r::num / r::den) * q2.value;
		}
		return Qty<new_unit, new_ratio>(new_value);
	}

	/**
	 * Calculate the quotient of unity
	 */
	template <typename U1, typename U2>
	using quotient_unit = Unit<U1::metre - U2::metre, U1::kilogram - U2::kilogram,
							   U1::second - U2::second, U1::ampere - U2::ampere,
							   U1::kelvin - U2::kelvin, U1::mole - U2::mole, U1::candela - U2::candela>;


	template <typename U1, typename R1, typename U2, typename R2>
	Qty<quotient_unit<U1, U2>, chooseRatio_t<R1, R2>> operator/(Qty<U1, R1> q1, Qty<U2, R2> q2)
	{
		using new_ratio = typename chooseRatio_t<R1, R2>::type;
		using new_unit = quotient_unit<U1, U2>;
		double new_value = 0;
		if (std::ratio_equal<new_ratio, R1>::value)
		{
			using r = std::ratio_divide<R2, R1>;
			new_value = q1.value / (q2.value * r::num / r::den);
		}
		else
		{
			using r = std::ratio_divide<R1, R2>;
			new_value = (q1.value * r::num / r::den) / q2.value;
		}
		return Qty<new_unit, new_ratio>(new_value);
	}

	/*
	 * Cast function between two quantities
	 */

	template <typename ResQty, typename U, typename R>
	ResQty qtyCast(Qty<U, R> other)
	{
		using new_ratio = typename ResQty::Ratio;

		int exposant_1 = ratios_difference<R, new_ratio>();
		int exposant_2 = U::metre + U::kilogram + U::second + U::ampere + U::kelvin + U::mole + U::candela;

		int exposant_tot = exposant_1 * exposant_2;
		if (std::ratio_less_v<R, new_ratio>)
		{
			exposant_tot = -exposant_tot;
		}

		intmax_t new_value = 0;
		new_value = other.value * std::pow(10, exposant_tot);
		return ResQty(new_value);
	}

	namespace literals
	{

		/*
		 * Some user-defined literals
		 */

		Length operator"" _metres(unsigned long long int val)
		{
			return Length(val);
		}

		Mass operator"" _kilograms(unsigned long long int val)
		{
			return Mass(val);
		}

		Time operator"" _seconds(unsigned long long int val)
		{
			return Time(val);
		}

		Current operator"" _amperes(unsigned long long int val)
		{
			return Current(val);
		}

		Temperature operator"" _kelvins(unsigned long long int val)
		{
			return Temperature(val);
		}

		Amount operator"" _moles(unsigned long long int val)
		{
			return Amount(val);
		}
		LuminousIntensity operator"" _candelas(unsigned long long int val)
		{
			return LuminousIntensity(val);
		}

		/*
		 * Temperature literals
		 */

		Temperature operator"" _celsius(unsigned long long int val)
		{
			return Temperature(val + 273.15);
		}

		Temperature operator"" _fahrenheit(unsigned long long int val)
		{
			return Temperature((5.0 / 9.0) * (val + 459.67));
		}
	}

}

#endif // UNITS_H
