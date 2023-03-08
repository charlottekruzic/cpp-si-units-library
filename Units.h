#ifndef UNITS_H
#define UNITS_H

#include <cstdint>
#include <ratio>

#include <iostream> //enlever

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
    		value += other.value * std::ratio_divide<ROther, Ratio>::num / std::ratio_divide<ROther, Ratio>::den;
			return *this;
		}

		template <typename ROther>
		Qty &operator-=(Qty<U, ROther> other)
		{
			value -= other.value * std::ratio_divide<ROther, Ratio>::num / std::ratio_divide<ROther, Ratio>::den;
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

	using Mile = Qty<Metre, std::ratio<1609304, 1000>>;
	using Yard = Qty<Metre, std::ratio<10000, 9144>>;
	using Foot = Qty<Metre, std::ratio<10000, 3048>>;
	using Inch = Qty<Metre, std::ratio<10000, 254>>;

	/*
	 * Comparison operators
	 */

	template <typename U, typename R1, typename R2>
	bool operator==(Qty<U, R1> q1, Qty<U, R2> q2)
	{
		if (q1.value * R1::num / R1::den == q2.value * R2::num / R2::den)
		{
			return true;
		}
		return false;
	}

	template <typename U, typename R1, typename R2>
	bool operator!=(Qty<U, R1> q1, Qty<U, R2> q2)
	{
		if (q1.value * R1::num / R1::den == q2.value * R2::num / R2::den)
		{
			return false;
		}
		return true;
	}

	template <typename U, typename R1, typename R2>
	bool operator<(Qty<U, R1> q1, Qty<U, R2> q2)
	{
		if (q1.value * R1::num / R1::den < q2.value * R2::num / R2::den)
		{
			return true;
		}
		return false;
	}

	template <typename U, typename R1, typename R2>
	bool operator<=(Qty<U, R1> q1, Qty<U, R2> q2)
	{
		if (q1.value * R1::num / R1::den <= q2.value * R2::num / R2::den)
		{
			return true;
		}
		return false;
	}

	template <typename U, typename R1, typename R2>
	bool operator>(Qty<U, R1> q1, Qty<U, R2> q2)
	{
		if (q1.value * R1::num / R1::den > q2.value * R2::num / R2::den)
		{
			return true;
		}
		return false;
	}

	template <typename U, typename R1, typename R2>
	bool operator>=(Qty<U, R1> q1, Qty<U, R2> q2)
	{
		if (q1.value * R1::num / R1::den >= q2.value * R2::num / R2::den)
		{
			return true;
		}
		return false;
	}

	/*
	 * Arithmetic operators
	 */

	/**
	 * choix ratio
	 */
	template <typename R1, typename R2, bool l>
	struct chooseRatio
	{
		using type = R1;
	};

	template <typename R1, typename R2>
	struct chooseRatio<R1, R2, true>
	{
		using type = R2;
	};

	template <typename U, typename R1, typename R2>
	Qty<U, typename chooseRatio<R1, R2, (R1::num * R2::den > R2::num * R1::den)>::type> operator+(Qty<U, R1> q1, Qty<U, R2> q2)
	{
		using new_ratio = typename chooseRatio<R1, R2, ((R1::num * R2::den) > (R2::num * R1::den))>::type; // même dénominateur si on fait ca
		intmax_t new_value = q1.value * new_ratio::den / R1::den + q2.value * new_ratio::den / R2::den;
		return Qty<U, new_ratio>(new_value);
	}

	template <typename U, typename R1, typename R2>
	Qty<U, typename chooseRatio<R1, R2, (R1::num * R2::den > R2::num * R1::den)>::type> operator-(Qty<U, R1> q1, Qty<U, R2> q2)
	{
		using new_ratio = typename chooseRatio<R1, R2, ((R1::num * R2::den) > (R2::num * R1::den))>::type; // même dénominateur si on fait ca
		intmax_t new_value = q1.value * new_ratio::den / R1::den - q2.value * new_ratio::den / R2::den;
		return Qty<U, new_ratio>(new_value);
	}

	/**
	 * produit Unit
	 */
	template <typename U1, typename U2>
	using product_unit = Unit<U1::metre + U2::metre, U1::kilogram + U2::kilogram,
							  U1::second + U2::second, U1::ampere + U2::ampere,
							  U1::kelvin + U2::kelvin, U1::mole + U2::mole, U1::candela + U2::candela>;

	template <typename U1, typename R1, typename U2, typename R2>
	Qty<product_unit<U1, U2>, typename chooseRatio<R1, R2, (R1::num * R2::den > R2::num * R1::den)>::type> operator*(Qty<U1, R1> q1, Qty<U2, R2> q2)
	{
		using new_ratio = typename chooseRatio<R1, R2, ((R1::num * R2::den) > (R2::num * R1::den))>::type;
		using new_unit = product_unit<U1, U2>;
		intmax_t new_value = (q1.value * new_ratio::den / R1::den) * (q2.value * new_ratio::den / R2::den);
		return Qty<new_unit, new_ratio>(new_value);
	}

	/**
	 * quotient Unit
	 */
	template <typename U1, typename U2>
	using quotient_unit = Unit<U1::metre - U2::metre, U1::kilogram - U2::kilogram,
							   U1::second - U2::second, U1::ampere - U2::ampere,
							   U1::kelvin - U2::kelvin, U1::mole - U2::mole, U1::candela - U2::candela>;

	template <typename U1, typename R1, typename U2, typename R2>
	Qty<quotient_unit<U1, U2>, typename chooseRatio<R1, R2, (R1::num * R2::den > R2::num * R1::den)>::type> operator/(Qty<U1, R1> q1, Qty<U2, R2> q2)
	{
		using new_ratio = typename chooseRatio<R1, R2, ((R1::num * R2::den) > (R2::num * R1::den))>::type;
		using new_unit = quotient_unit<U1, U2>;
		intmax_t new_value = (q1.value * new_ratio::den / R1::den) / (q2.value * new_ratio::den / R2::den);
		return Qty<new_unit, new_ratio>(new_value);
	}

	/*
	 * Cast function between two quantities
	 */
	template <typename ResQty, typename U, typename R>
	ResQty qtyCast(Qty<U, R> q)
	{
		using new_ratio = typename ResQty::Ratio;
		using old_ratio = typename U::Ratio;
		intmax_t value_in_new_units = static_cast<intmax_t>(q.value * old_ratio::num * new_ratio::den / (new_ratio::num * old_ratio::den));
		return ResQty(value_in_new_units);
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
			return Temperature(val - 273.15);
		}

		Temperature operator"" _fahrenheit(unsigned long long int val)
		{
			return Temperature(val * 9.0 / 5.0 - 459.67);
		}
	}

	namespace details
	{
		/**
		 * additional types
		 */

	}

}

#endif // UNITS_H
