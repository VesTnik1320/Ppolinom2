#include "pch.h"
#include "../Ppolinom/Monom.h"
#include "../Ppolinom/Polinom.h"

TEST(TPolinom, Polinom_Assign) {
	Monom m1[3] = { Monom(1, 2, 1, 1), Monom(-3, 1, 0, 0), Monom(4, 0, 2, 1) };
	Monom m2[3] = { Monom(1, 2, 1, 1), Monom(-3, 1, 0, 0) };
	Polinom p1(m1, 3), p2(m2, 2);
	p1 = p2;
	EXPECT_EQ(p1, p2);
	p1 = p1 + p1;
	EXPECT_NE(p1, p2);//
}
TEST(TPolinom, Add_Monome_or_DelLast) {
	Monom m1[3] = { Monom(1, 2, 1, 1), Monom(-3, 1, 0, 0), Monom(4, 0, 2, 1) };
	Monom m2[3] = { Monom(1, 2, 1, 1), Monom(-3, 1, 0, 0) };
	Monom m3[3] = { Monom(-1, 2, 1, 1), Monom(-3, 1, 0, 0), Monom(4, 0, 3, 1) };
	Polinom p1(m1, 3), res(m2, 2);
	Monom monom(-4, 0, 2, 1);
	p1.AddMonom(monom);
	EXPECT_EQ(p1, res);
}
TEST(TPolinom, Add_Polinom_To_Mid) {
	Monom m1[2] = { Monom(1, 3, 1, 1), Monom(-3, 2, 3, 0) };
	Monom m2[2] = { Monom(1, 3, 0, 0), Monom(-3, 0, 1, 1) };
	Monom m3[4] = { Monom(1, 3, 1, 1), Monom(1, 3, 0, 0),
					 Monom(-3, 2, 3, 0),Monom(-3, 0, 1, 1) };
	Polinom p1(m1, 2), p2(m2, 2), res, expect(m3, 4);
	res = p1 + p2;
	EXPECT_EQ(res, expect);
	res = p2 + p1;
	EXPECT_EQ(res, expect);
}
TEST(TPolinom, Add_Polinom_With_Del_In_Mid) {
	Monom m1[2] = { Monom(1, 3, 1, 1), Monom(-3, 2, 3, 0) };
	Monom m2[2] = { Monom(3, 2, 3, 0), Monom(-3, 0, 1, 1) };
	Monom m3[2] = { Monom(1, 3, 1, 1), Monom(-3, 0, 1, 1) };
	Polinom p1(m1, 2), p2(m2, 2), res, expect(m3, 2);
	res = p1 + p2;
	EXPECT_EQ(res, expect);
	res = p2 + p1;
	EXPECT_EQ(res, expect);
}
TEST(TPolinom, Add_Polinom_With_Del_In_Front) {
	Monom m1[2] = { Monom(1, 3, 1, 1),  Monom(-3, 2, 3, 0) };
	Monom m2[2] = { Monom(-1, 3, 1, 1), Monom(-3, 0, 1, 1) };
	Monom m3[2] = { Monom(-3, 2, 3, 0), Monom(-3, 0, 1, 1) };
	Polinom p1(m1, 2), p2(m2, 2), res, expect(m3, 2);
	res = p1 + p2;
	EXPECT_EQ(res, expect);
	res = p2 + p1;
	EXPECT_EQ(res, expect);
}
TEST(TPolinom, Add_Polinom_With_Del_In_Back) {
	Monom m1[2] = { Monom(1, 3, 1, 1), Monom(-3, 2, 3, 0) };
	Monom m2[2] = { Monom(3, 2, 3, 0), Monom(1, 2, 1, 1) };
	Monom m3[2] = { Monom(1, 3, 1, 1), Monom(1, 2, 1, 1), };
	Polinom p1(m1, 2), p2(m2, 2), res, expect(m3, 2);
	res = p1 + p2;
	EXPECT_EQ(res, expect);
	res = p2 + p1;
	EXPECT_EQ(res, expect);
}
TEST(TPolinom, Add_Polinom_With_Merge_In_Mid) {
	Monom m1[2] = { Monom(1, 3, 1, 1), Monom(3, 2, 3, 0) };
	Monom m2[2] = { Monom(3, 2, 3, 0), Monom(1, 2, 1, 1) };
	Monom m3[3] = { Monom(1, 3, 1, 1), Monom(6, 2, 3, 0), Monom(1, 2, 1, 1) };
	Polinom p1(m1, 2), p2(m2, 2), res, expect(m3, 3);
	res = p1 + p2;
	EXPECT_EQ(res, expect);
	res = p2 + p1;
	EXPECT_EQ(res, expect);
}
TEST(TPolinom, Add_Polinom_With_Merge_In_Front) {
	Monom m1[2] = { Monom(1, 3, 1, 1), Monom(3, 2, 3, 0) };
	Monom m2[2] = { Monom(-2, 3, 1, 1), Monom(1, 2, 1, 1) };
	Monom m3[3] = { Monom(-1, 3, 1, 1), Monom(3, 2, 3, 0), Monom(1, 2, 1, 1) };
	Polinom p1(m1, 2), p2(m2, 2), res, expect(m3, 3);
	res = p1 + p2;
	EXPECT_EQ(res, expect);
	res = p2 + p1;
	EXPECT_EQ(res, expect);
}
TEST(TPolinom, Add_Polinom_With_Merge_In_Back) {
	Monom m1[2] = { Monom(1, 3, 1, 1), Monom(3, 2, 3, 0) };
	Monom m2[2] = { Monom(-2, 3, 1, 0), Monom(1, 2, 3, 0) };
	Monom m3[3] = { Monom(1, 3, 1, 1), Monom(-2, 3, 1, 0), Monom(4, 2, 3, 0) };
	Polinom p1(m1, 2), p2(m2, 2), res, expect(m3, 3);
	res = p1 + p2;
	EXPECT_EQ(res, expect);
	res = p2 + p1;
	EXPECT_EQ(res, expect);
}
TEST(TPolinom, Add_Polinom) {//1 del  2 merge 3 ne peresek
	Monom m1[3] = { Monom(1, 3, 1, 1),  Monom(-3, 2, 3, 0), Monom(4, 1, 2, 1) };
	Monom m2[3] = { Monom(-1, 3, 1, 1), Monom(-3, 2, 3, 0), Monom(4, 0, 0, 1) };
	Monom m3[3] = { Monom(-6, 2, 3, 0), Monom(4, 1, 2, 1),  Monom(4, 0, 0, 1) };
	Polinom p1(m1, 3), p2(m2, 3), res, expect(m3, 3);
	res = p1 + p2;
	EXPECT_EQ(res, expect);
	res = p2 + p1;
	EXPECT_EQ(res, expect);
}
//6*x^5*y^5*z^3 +3*x^4*y^4*z^4 +4*x^2*y^2 +2*x^1*y^1*z^1 p6 * p7
TEST(TPolinom, Mult_Polinom) {
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
TEST(TPolinom, Mult_On_Int) {
	Monom m1[2] = { Monom(3, 3, 3, 3), Monom(2) };
	Monom m2[2] = { Monom(6, 3, 3, 3), Monom(4) };
	Polinom p1(m1, 2), res, expect(m2, 2);
	res = p1 * 2;
	EXPECT_EQ(res, expect);
}
TEST(TPolinom, Mult_On_Zero) {
	Monom m1[2] = { Monom(3, 3, 3, 3), Monom(2) };
	Polinom p1(m1, 2), res, expect;
	res = p1 * 0;
	EXPECT_EQ(res, expect);
}