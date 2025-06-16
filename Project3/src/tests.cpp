using namespace std;
#include "gtest/gtest.h"
#include <stdio.h>
#include <stdlib.h>

const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string LIGHT_BLUE = "\033[94m";
const string RESET = "\033[0m";

#define TESTING 1

double parse();
void yyset_in  ( FILE * _in_str  );

namespace {
    class SuppliedTest : public testing::Test {
    protected:
        FILE *input;
        double result;

        SuppliedTest() {}

        ~SuppliedTest() {}

        void SetUp(string fileName) {
            input = fopen(fileName.c_str(), "r");
            if(!input)
            {
                perror("fopen failed");
                exit(EXIT_FAILURE);
            }
            yyset_in(input);
            result = parse();
            fclose(input);
            input = nullptr; 
        }
    };

    string result_header(string equation, double result) {
        stringstream ss;
        ss << LIGHT_BLUE << "[  RESULT  ]\t" << equation << " = " << result << RESET << endl;
        return ss.str();
    }

    TEST_F(SuppliedTest, Test1) { 
        string s = "data/test1.txt";
       
        SetUp(s);
        EXPECT_EQ(25, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(SuppliedTest, Test2) { 
        string s = "data/test2.txt";
       
        SetUp(s);
        EXPECT_EQ(9, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
    
    TEST_F(SuppliedTest, Test3) { 
        string s = "data/test3.txt";
       
        SetUp(s);
        EXPECT_EQ(99, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
    
    TEST_F(SuppliedTest, Test4) { 
        string s = "data/test4.txt";
       
        SetUp(s);
        EXPECT_EQ(8, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
    
    TEST_F(SuppliedTest, Test5) { 
        string s = "data/test5.txt";
       
        SetUp(s);
        EXPECT_EQ(115.57, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
   
    TEST_F(SuppliedTest, Test6) { 
        string s = "data/test6.txt";
       
        SetUp(s);
        EXPECT_EQ(12, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
   
    TEST_F(SuppliedTest, TestAdd) { 
        string s = "data/test_add.txt";

        SetUp(s);
        EXPECT_EQ(11, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(SuppliedTest, TestSubtract) { 
        string s = "data/test_subtract.txt";

        SetUp(s);
        EXPECT_EQ(3, result) << "Failed!! " << s;
        cout << result_header(s, result);
   }

   TEST_F(SuppliedTest, TestMultiply) { 
        string s = "data/test_multiply.txt";

        SetUp(s);
        EXPECT_EQ(40, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
    
    TEST_F(SuppliedTest, TestDivide) { 
        string s = "data/test_divide.txt";

        SetUp(s);
        EXPECT_EQ(5, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
    
    TEST_F(SuppliedTest, TestMod) { 
        string s = "data/test_mod.txt";

        SetUp(s);
        EXPECT_EQ(3, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
    
    TEST_F(SuppliedTest, TestExp) { 
        string s = "data/test_exp.txt";

        SetUp(s);
        EXPECT_EQ(65536, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(SuppliedTest, Test7) { 
        string s = "data/test7.txt";
       
        SetUp(s);
        EXPECT_EQ(5, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
   TEST_F(SuppliedTest, TestAnd) { 
       string s = "data/test_and.txt";
       
        SetUp(s);
        EXPECT_EQ(1, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
   
    TEST_F(SuppliedTest, TestAndFalse) { 
        string s = "data/test_and_false.txt";
       
        SetUp(s);
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
   
    TEST_F(SuppliedTest, TestNot) { 
        string s = "data/test_not.txt";
       
        SetUp(s);
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
   
    TEST_F(SuppliedTest, TestNeq) { 
        string s = "data/test_neq.txt";
       
        SetUp(s);
        EXPECT_EQ(1, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
   
    TEST_F(SuppliedTest, TestOr) { 
        string s = "data/test_or.txt";
       
        SetUp(s);
        EXPECT_EQ(1, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
   
    TEST_F(SuppliedTest, TestOrFalse) { 
        string s = "data/test_or_false.txt";
       
        SetUp(s);
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
   
    TEST_F(SuppliedTest, Test8) { 
        string s = "data/test8.txt";
       
        SetUp(s);
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(SuppliedTest, Test9_lt10) { 
        string s = "data/test9_lt10.txt";
       
        SetUp(s);
        EXPECT_EQ(1, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(SuppliedTest, Test9_lt20) { 
        string s = "data/test9_lt20.txt";
       
        SetUp(s);
        EXPECT_EQ(2, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(SuppliedTest, Test9_gt30) { 
        string s = "data/test9_gt30.txt";
       
        SetUp(s);
        EXPECT_EQ(4, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
   
    TEST_F(SuppliedTest, Test9_noelsifs) { 
        string s = "data/test9_noelsif.txt";
       
        SetUp(s);
        EXPECT_EQ(4, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(SuppliedTest, Test9) { 
        string s = "data/test9.txt";
       
        SetUp(s);
        EXPECT_EQ(3, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(SuppliedTest, Test10) { 
        string s = "data/test10.txt";
       
        SetUp(s);
        EXPECT_EQ(10, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(SuppliedTest, Test11) { 
        string s = "data/test11.txt";
       
        SetUp(s);
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    // TEST_F(SuppliedTest, Test12) { 
    //     string s = "data/test12.txt";
       
    //     SetUp(s);
    //     EXPECT_EQ(0, result) << "Failed!! " << s;
    //     cout << result_header(s, result);
    // }

    // TEST_F(SuppliedTest, Test13) { 
    //     string s = "data/test13.txt";
       
    //     SetUp(s);
    //     EXPECT_EQ(0, result) << "Failed!! " << s;
    //     cout << result_header(s, result);
    // }

    // TEST_F(SuppliedTest, Test14) { 
    //     string s = "data/test14.txt";
       
    //     SetUp(s);
    //     EXPECT_EQ(0, result) << "Failed!! " << s;
    //     cout << result_header(s, result);
    // }

    // TEST_F(SuppliedTest, Test15) { 
    //     string s = "data/test15.txt";
       
    //     SetUp(s);
    //     EXPECT_EQ(1, result) << "Failed!! " << s;
    //     cout << result_header(s, result);
    // }

    // TEST_F(SuppliedTest, Test16) { 
    //     string s = "data/test16.txt";

    //     SetUp(s);
    //     EXPECT_EQ(1, result) << "Failed!! " << s;
    //     cout << result_header(s, result);
    // }
}