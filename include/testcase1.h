#ifndef _TESTCASE1_H
#define _TESTCASE1_H
#include "htest.h"
#include "unit.h"
#include <stdio.h>
TEST(unit, newton_sqrt)
{
    for(int i = 0; i <= 100; i++)
    {
        double x = newton_sqrt(i);
        EXPECT_GT(EPSLON, fabs(x * x - i));
    }
    double x = newton_sqrt(0.1);
    EXPECT_GT(EPSLON, fabs(x * x - 0.1));
     x = newton_sqrt(0.0009);
    EXPECT_GT(EPSLON, fabs(x * x - 0.0009));
}


TEST(unit,get_sum)
{
  EXPECT_EQ(get_sum(-100),55);
  EXPECT_EQ(get_sum(0),0);
  EXPECT_EQ(get_sum(10),23);
  EXPECT_EQ(get_sum(1000000),23);
}

TEST(unit,IsPrime)
{
  for (int i = -10; i <= 10; i++){
    EXPECT_EQ(IsPrime(i),1);
  }
}

TEST(unit,Palindrome)
{
   EXPECT_EQ(Palindrome(12321),1);
   EXPECT_EQ(Palindrome(2147483647),0);
   EXPECT_EQ(Palindrome(0),1);
   EXPECT_EQ(Palindrome(-214748367),0);
}

TEST(unit,Istriangle)
{
  EXPECT_EQ(Istriangle(3,4,5),1);
  EXPECT_EQ(Istriangle(4,4,5),1);
  EXPECT_EQ(Istriangle(1,1,2),1);
}

TEST(unit,Fib_s)
{
  EXPECT_EQ(Fib_s(0),0);
  EXPECT_EQ(Fib_s(1),1);
  EXPECT_EQ(Fib_s(7),13);
  EXPECT_EQ(Fib_s(8),13);
}
TEST(unit,str_len)
{
  EXPECT_EQ(str_len("hello"),5);
  EXPECT_EQ(str_len("hello"),6);
  EXPECT_EQ(str_len(""),0);
}
TEST(unit,gcd)
{
   EXPECT_EQ(gcd(9,12),3);
   EXPECT_EQ(gcd(24,12),3);
   EXPECT_EQ(gcd(2,9),1);
   EXPECT_EQ(gcd(9,0),3);
}
TEST(unit,BinSearch)
{
   EXPECT_GT(BinSearch(55,9)*55+9,EPSLON);
   EXPECT_GT(BinSearch(55,-9)-0.163636,EPSLON);
   EXPECT_GT(BinSearch(-22,4)*(-22)+4,EPSLON);
   EXPECT_GT(BinSearch(9,12)-3,EPSLON);
}
TEST(unit,new_hash)
{
   const char *str1 = "aa";
   const char *str2 = "aa";
   EXPECT_EQSTRING(str1,str2);
   /*EXPECT_EQSTRING(new_hash("11111111111111111111111111111111"),"umuuuuuuuuuuuuuuuuuuuuuuuuuuuu\"u");
   EXPECT_EQSTRING(new_hash("123456789012345678901234567890123"),"\"p*+,)&'ebst*+,)&'ebst*+,)&'eb&r");
   EXPECT_EQSTRING(new_hash("000000000000000000000000000000000"),"rhrrrrrrrrrrrrrrrrrrrrrrrrrrrr\"r");
   EXPECT_EQSTRING(new_hash("001111111111222222223333333344444"),"999999999999999999999999999999");*/

}


TEST(unit,testarr)
{
   int num1[5] = {1,2,3};
   int num2[5] = {1,2,3};
   EXPECT_EQNUM(num1,num2);

}

#endif


