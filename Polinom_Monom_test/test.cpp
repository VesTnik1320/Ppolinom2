#include "pch.h"
#include "../Ppolinom/Polinom.h"
#include "../pPolinom/Polinom.cpp"
#include "../pPolinom/Monom.h"
#include "../pPolinom/Monom.cpp"
#include <string>
TEST(Monom, CAN_CREATE_NULL_MONOM)
{
	ASSERT_NO_THROW(Monom m);
}

TEST(Monom, CAN_CREATE_MONOM)
{
	ASSERT_NO_THROW(Monom m(3.0, 4, 5, 1));
}

TEST(Monom, CAN_COMPARE_TWO_MONOM_LESS)
{
	Monom m1(3.0, 4, 5, 1);
	Monom m2(5.0, 1, 2, 3);
	EXPECT_TRUE(m2 < m1);
}

TEST(Monom, CAN_COMPARE_TWO_MONOM_GREAT)
{
	Monom m1(3.0, 4, 5, 1);
	Monom m2(5.0, 1, 2, 3);
	EXPECT_TRUE(m2 < m1);
}

TEST(Monom, CAN_COMPARE_EQUAL_MONOM) 
{
	Monom m1(4.0, 1, 2, 3);
	Monom m2(4.0, 1, 2, 3);
	EXPECT_TRUE(m1 == m2);
}

TEST(Polinom, CAN_CREATE_NULL_POLINOM)
{
	ASSERT_NO_THROW(Polinom p);
}

TEST(Polinom, CHECK_FOR_NULL)
{
	Polinom p;
	Monom m1(3.0, 2, 4, 1);
	ASSERT_NO_THROW(p.AddMonom(m1));
	EXPECT_FALSE(p.IsEmpty());
}

TEST(Polinom, CAN_DELETE_ZERO_POLINOM)
{
	Polinom p;
	p.AddMonom(Monom(1, 1, 1, 0));
	p.AddMonom(Monom(-1, 1, 1, 0));
	EXPECT_TRUE(p.IsEmpty());
}

TEST(Polinom, CAN_PLUS_POLINOM_1)//с удалением в середине
{
	Polinom p1, p2, p3;

	p1.AddMonom(Monom(1, 3, 1, 1));//1
	p1.AddMonom(Monom(-3, 2, 3, 0));//2

	p2.AddMonom(Monom(3, 2, 3, 0));//2
	p2.AddMonom(Monom(-3, 0, 1, 1));//3

	p3.AddMonom(Monom(1, 3, 1, 1));//1
	p3.AddMonom(Monom(-3, 0, 1, 1));//3

	Polinom pRes = p1 + p2;
	EXPECT_EQ(pRes, p3);
	pRes = p2 + p1;
	EXPECT_EQ(pRes, p3);
}

TEST(Polinom, CAN_PLUS_POLINOM_2)//с удалением в начале
{
	Polinom p1, p2, p3;

	p1.AddMonom(Monom(1, 3, 1, 1));
	p1.AddMonom(Monom(-3, 2, 3, 0));

	p2.AddMonom(Monom(-1, 3, 1, 1));
	p2.AddMonom(Monom(-3, 0, 1, 1));

	p3.AddMonom(Monom(-3, 2, 3, 0));
	p3.AddMonom(Monom(-3, 0, 1, 1));

	Polinom pRes = p1 + p2;
	EXPECT_EQ(pRes, p3);
}

TEST(Polinom, CAN_PLUS_POLINOM_3)//с удалением в конце
{
	Polinom p1, p2, p3;

	p1.AddMonom(Monom(1, 3, 1, 1));
	p1.AddMonom(Monom(-3, 2, 3, 0));

	p2.AddMonom(Monom(3, 2, 3, 0));
	p2.AddMonom(Monom(1, 2, 1, 1));

	p3.AddMonom(Monom(1, 3, 1, 1));
	p3.AddMonom(Monom(1, 2, 1, 1));

	Polinom pRes = p1 + p2;
	EXPECT_EQ(pRes, p3);
}

TEST(Polinom, CAN_PLUS_POLINOM_4)//с слиянием в середине
{
	Polinom p1, p2, p3;

	p1.AddMonom(Monom(1, 3, 1, 1));
	p1.AddMonom(Monom(3, 2, 3, 0));

	p2.AddMonom(Monom(3, 2, 3, 0));
	p2.AddMonom(Monom(1, 2, 1, 1));

	p3.AddMonom(Monom(1, 3, 1, 1));
	p3.AddMonom(Monom(6, 2, 3, 0));
	p3.AddMonom(Monom(1, 2, 1, 1));
	Polinom pRes = p1 + p2;
	EXPECT_EQ(pRes, p3);
}

TEST(Polinom, CAN_PLUS_POLINOM_5)//с слиянием в начале
{
	Polinom p1, p2, p3;

	p1.AddMonom(Monom(1, 3, 1, 1));
	p1.AddMonom(Monom(3, 2, 3, 0));

	p2.AddMonom(Monom(-2, 3, 1, 1));
	p2.AddMonom(Monom(1, 2, 1, 1));

	p3.AddMonom(Monom(-1, 3, 1, 1));
	p3.AddMonom(Monom(3, 2, 3, 0));
	p3.AddMonom(Monom(1, 2, 1, 1));
	Polinom pRes = p1 + p2;
	EXPECT_EQ(pRes, p3);
}

TEST(Polinom, CAN_PLUS_POLINOM_6)//с слиянием в конце
{
	Polinom p1, p2, p3;

	p1.AddMonom(Monom(1, 3, 1, 1));
	p1.AddMonom(Monom(3, 2, 3, 0));

	p2.AddMonom(Monom(-2, 3, 1, 0));
	p2.AddMonom(Monom(1, 2, 3, 0));

	p3.AddMonom(Monom(1, 3, 1, 1));
	p3.AddMonom(Monom(-2, 3, 1, 0));
	p3.AddMonom(Monom(4, 2, 3, 0));
	Polinom pRes = p1 + p2;
	EXPECT_EQ(pRes, p3);
}

TEST(Polinom, CAN_MINUS_POLINOM_1) // с удалением в начале
{
	Polinom p1, p2, p3;

	p1.AddMonom(Monom(1, 3, 1, 1));
	p1.AddMonom(Monom(-3, 2, 3, 0));

	p2.AddMonom(Monom(-1, 3, 1, 1));
	p2.AddMonom(Monom(-3, 0, 1, 1));

	p3.AddMonom(Monom(2, 3, 1, 1)); // 1 - (-1) = 2
	p3.AddMonom(Monom(-3, 2, 3, 0));
	p3.AddMonom(Monom(3, 0, 1, 1)); // 0 - (-3) = 3

	Polinom pRes = p1 - p2;
	EXPECT_EQ(pRes, p3);
}

TEST(Polinom, CAN_MINUS_POLINOM_2) // с удалением в конце
{
	Polinom p1, p2, p3;

	p1.AddMonom(Monom(1, 3, 1, 1));
	p1.AddMonom(Monom(-3, 2, 3, 0));

	p2.AddMonom(Monom(3, 2, 3, 0));
	p2.AddMonom(Monom(1, 2, 1, 1));

	p3.AddMonom(Monom(1, 3, 1, 1));
	p3.AddMonom(Monom(-6, 2, 3, 0)); // -3 - 3 = -6
	p3.AddMonom(Monom(-1, 2, 1, 1)); // 0 - 1 = -1

	Polinom pRes = p1 - p2;
	EXPECT_EQ(pRes, p3);
}


TEST(Polinom, CAN_MINUS_POLINOM_3) // с слиянием в начале
{
	Polinom p1, p2, p3;

	p1.AddMonom(Monom(1, 3, 1, 1));
	p1.AddMonom(Monom(3, 2, 3, 0));

	p2.AddMonom(Monom(-2, 3, 1, 1));
	p2.AddMonom(Monom(1, 2, 1, 1));

	p3.AddMonom(Monom(3, 3, 1, 1)); // 1 - (-2) = 3
	p3.AddMonom(Monom(3, 2, 3, 0));
	p3.AddMonom(Monom(-1, 2, 1, 1)); // 0 - 1 = -1

	Polinom pRes = p1 - p2;
	EXPECT_EQ(pRes, p3);
}

TEST(Polinom, CAN_MINUS_POLINOM_4) // с слиянием в конце
{
	Polinom p1, p2, p3;

	p1.AddMonom(Monom(1, 3, 1, 1));
	p1.AddMonom(Monom(3, 2, 3, 0));

	p2.AddMonom(Monom(-2, 3, 1, 0));
	p2.AddMonom(Monom(1, 2, 3, 0));

	p3.AddMonom(Monom(1, 3, 1, 1));
	p3.AddMonom(Monom(2, 3, 1, 0)); // 0 - (-2) = 2
	p3.AddMonom(Monom(2, 2, 3, 0)); // 3 - 1 = 2

	Polinom pRes = p1 - p2;
	EXPECT_EQ(pRes, p3);
}

TEST(Polinom, CAN_MULT_POLINOM_BY_COEFF)
{
	Polinom p1, p2;
	p1.AddMonom(Monom(2, 1, 1, 0));
	p2.AddMonom(Monom(6, 1, 1, 0));
	Polinom pRes = p1 * 3.0;
	EXPECT_EQ(p2, pRes);
}

TEST(Polinom, CAN_MULT_POLINOM_BY_MONOM)
{
	Polinom p1, p2;
	p1.AddMonom(Monom(1, 1, 1, 1));
	Monom m1(3, 2, 0, 0);
	p2.AddMonom(Monom(3, 3, 1, 1));
	Polinom pRes = p1 * m1;
	EXPECT_EQ(p2, pRes);
}

TEST(Polinom, CAN_COMPARE_TWO_POLINOM) {
	Polinom p1, p2, p3;
	p1.AddMonom(Monom(1.0, 1, 0, 0));
	p1.AddMonom(Monom(2.0, 2, 0, 0));
	p1.AddMonom(Monom(3.0, 3, 0, 0));

	p2.AddMonom(Monom(1.0, 1, 0, 0));
	p2.AddMonom(Monom(2.0, 2, 0, 0));
	p2.AddMonom(Monom(3.0, 3, 0, 0));

	p3.AddMonom(Monom(3.0, 3, 0, 0));
	p3.AddMonom(Monom(2.0, 2, 0, 0));

	EXPECT_TRUE(p1 == p2);
	EXPECT_FALSE(p1 == p3);
}

TEST(Polinom, CHECK_MULT_POLINOM_AND_ZERO)
{
	Polinom p1,p2;
	p1.AddMonom(Monom(1.0, 1, 0, 0));
	p1.AddMonom(Monom(2.0, 2, 0, 0));

	Polinom pRes = p1 * 0.0;

	EXPECT_EQ(p2, pRes);
}

TEST(Polinom, CHECK_MULT_POLINOM_AND_ZERO_COEFF_MONOM)
{
	Polinom p1, p2;
	p1.AddMonom(Monom(1.0, 1, 0, 0));
	Monom m1(0.0, 2, 0, 0);

	Polinom pRes = p1 * m1;

	EXPECT_EQ(p2, pRes);
}

TEST(Polinom, CHECK_MULT_POLINOM_AND_NULL_POLINOM)
{
	Polinom p1, P2, p3;
	p1.AddMonom(Monom(1.0, 1, 0, 0));

	Polinom pRes = p1 * P2;

	EXPECT_EQ(p3, pRes);
}
TEST(Polinom, CAN_MULT_POLINOM)
{
	Monom m1[2] = { Monom(2, 2, 2, 0), Monom(1, 1, 1, 1) };
	Monom m2[2] = { Monom(3, 3, 3, 3), Monom(2) };
	Monom m3[4] = { Monom(6, 5, 5, 3), Monom(3, 4, 4, 4),
					 Monom(4, 2, 2, 0), Monom(2, 1, 1, 1) };
	Polinom p1(m1, 2), p2(m2, 2), res, expect(m3, 4);
	res = p1 * p2;
	EXPECT_EQ(res, expect);
	res = p2 * p1;
	EXPECT_EQ(res, expect);
}
//+ УМНОЖЕНИЕ ПОЛИНОМА НА ПОЛ ПОЛИНОМ, ОТРИЦ ПОЛИНОМ