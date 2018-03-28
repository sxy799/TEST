#ifndef _HTEST_H
#define _HTEST_H
#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef struct TEST_INFO
{
    int testNum;
    int YesNum;
    int NoNum;
} TEST_INFO;

#define TEST(a, b) \
        void test##a##_##b(TEST_INFO *_ti); \
        int p##_##a##b_##b = haizei_test_run(test##a##_##b, #a, #b); \
        void test##a##_##b(TEST_INFO *_ti)

#define EXPECT_GT(a, b) {\
    (a)>(b)?_ti->YesNum++ : _ti->NoNum++;  \
    _ti->testNum++;                        \
}

#define EXPECT_LT(a, b) {\
    (a)<(b)?_ti->YesNum++ : _ti->NoNum++;  \
    _ti->testNum++;                        \
}
#define EXPECT_GE(a, b) {\
    (a)>=(b)?_ti->YesNum++ : _ti->NoNum++;  \
    _ti->testNum++;                        \
}
#define EXPECT_LE(a, b) {\
    (a)<=(b)?_ti->YesNum++ : _ti->NoNum++;  \
    _ti->testNum++;                        \
}
#define EXPECT_EQ(a, b) {\
    (a)==(b)?_ti->YesNum++ : _ti->NoNum++;  \
    _ti->testNum++;                    \
}
#define EXPECT_EQSTRING(a, b) {\
    if (strcmp(a,b) == 0 )_ti->YesNum++;\
    else _ti->NoNum++;  \
    _ti->testNum++;                    \
}

#define EXPECT_EQNUM(a, b) {\
   __typeof(a)  _a = (a);\
   __typedef(b) _b = (b);\
    int l1 = sizeof(_a);\
    int l2 = sizeof(_b);\
    int flag = 1;\
    if (l1 != l2 ) flag = 0;\
    else {\
     for (int i=0; i<l1; i++){\
        if(*_a != *_b){ flag = 0; }\
     }\
    if(flag)_ti->YesNum++;\
    else _ti->NoNum++;\
     _ti->testNum++;\
}

#define EXPECT_NE(a, b) {\
    (a)!=(b)?_ti->YesNum++ : _ti->NoNum++;  \
    _ti->testNum++;                        \
}

#define ASSERT_GT(a, b) {\
    (a)>(b)?_ti->YesNum++ : _ti->NoNum++;  \
    _ti->testNum++; \
    assert(a>b);    \
}

#define ASSERT_LT(a, b) {\
    (a)<(b)?_ti->YesNum++ : _ti->NoNum++;  \
    _ti->testNum++;                        \
    assert(a<b);    \
}
#define ASSERT_GE(a, b) {\
    (a)>=(b)?_ti->YesNum++ : _ti->NoNum++;  \
    _ti->testNum++;                        \
    assert(a>=b);    \
}
#define ASSERT_LE(a, b) {\
    (a)<=(b)?_ti->YesNum++ : _ti->NoNum++;  \
    _ti->testNum++;                        \
   assert(a<=b);    \
}
#define ASSERT_EQ(a, b) {\
    (a)==(b)?_ti->YesNum++ : _ti->NoNum++;  \
    _ti->testNum++;                        \
    assert(a==b);    \
}
#define ASSERT_NE(a, b) {\
    (a)!=(b)?_ti->YesNum++ : _ti->NoNum++;  \
    _ti->testNum++;                        \
    assert(a!=b);    \
}

int haizei_test_run(void (*func)(TEST_INFO *), const char *str1, const char *str2)
{
    TEST_INFO ti = {0, 0, 0}; 
    printf("\33[32m[    RUN    ]\33[0m  %s.%s\n", str1, str2);
    func(&ti);
    if (ti.NoNum == 0 )
        printf("\033[32m[    OK     ]\033[0m  %s.%s\n", str1, str2);
    else 
       printf("\033[31m[    FAILED ]\033[0m  %s.%s  pass %d  failed %d\n", str1, str2,ti.YesNum, ti.NoNum);
    return 0;
}

#endif
