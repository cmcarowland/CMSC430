using namespace std;
#include "gtest/gtest.h"
#include <stdio.h>
#include <stdlib.h>
#include <deque>

const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string LIGHT_BLUE = "\033[94m";
const string RESET = "\033[0m";

extern double parse();
extern void yyset_in  ( FILE * _in_str  );

namespace {
    class SuppliedTest : public testing::Test {
    protected:
        FILE *input;
        double result;

        SuppliedTest() {
            printf("SuppliedTest constructor called %lf\n", result);
        }

        ~SuppliedTest() {}

        void SetUp(string fileName) {
            printf("Running test: %s\n", fileName.c_str());
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
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(SuppliedTest, Test2) { 
        string s = "data/test2.txt";
       
        SetUp(s);
        EXPECT_EQ(1, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
    
    TEST_F(SuppliedTest, Test3) { 
        string s = "data/test3.txt";
       
        SetUp(s);
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
    
    TEST_F(SuppliedTest, Test4) { 
        string s = "data/test4.txt";
       
        SetUp(s);
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
    
    TEST_F(SuppliedTest, Test5) { 
        string s = "data/test5.txt";
       
        SetUp(s);
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
   
    TEST_F(SuppliedTest, Test6) { 
        string s = "data/test6.txt";
       
        SetUp(s);
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
   
    TEST_F(SuppliedTest, Test7) { 
        string s = "data/test7.txt";
       
        SetUp(s);
        EXPECT_EQ(2, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
   
    TEST_F(SuppliedTest, Test8) { 
        string s = "data/test8.txt";
       
        SetUp(s);
        EXPECT_EQ(5, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
}