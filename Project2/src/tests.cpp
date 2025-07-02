/*
    Raymond Rowland
	CMSC 430 Compiler Theory and Design
	Project 2 Skeleton
	July 1, 2025

    tests.cpp
    Unit tests for the parser and scanner using Google Test framework.
    This file contains tests for the supplied input files and syntax error cases.
    Exercises the parse function and checks the results against expected values.
    The tests are designed to ensure that the parser correctly handles valid input
    and reports errors for invalid input.

    Usage: ./bin/test.elf [options]
    Options:
        -s, --silent          Suppress printing of input files in the output
        -h, --help            Show this help message
*/

using namespace std;
#include "gtest/gtest.h"
#include <stdio.h>
#include <stdlib.h>

const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string LIGHT_BLUE = "\033[94m";
const string RESET = "\033[0m";

extern double parse();
extern void yyset_in  ( FILE * _in_str  );
extern bool PRINT_RESULTS;

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
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(SuppliedTest, Test2) { 
        string s = "data/test2.txt";
       
        SetUp(s);
        EXPECT_EQ(0, result) << "Failed!! " << s;
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
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
   
    TEST_F(SuppliedTest, Test8) { 
        string s = "data/test8.txt";
       
        SetUp(s);
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(SuppliedTest, Test9) { 
        string s = "data/test9.txt";
       
        SetUp(s);
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(SuppliedTest, Test10) { 
        string s = "data/test10.txt";
       
        SetUp(s);
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(SuppliedTest, Test11) { 
        string s = "data/test11.txt";
       
        SetUp(s);
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(SuppliedTest, Test12) { 
        string s = "data/test12.txt";
       
        SetUp(s);
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(SuppliedTest, Test13) { 
        string s = "data/test13.txt";
       
        SetUp(s);
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(SuppliedTest, Test14) { 
        string s = "data/test14.txt";
       
        SetUp(s);
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(SuppliedTest, Syntax1) { 
        string s = "data/syntax1.txt";
       
        SetUp(s);
        EXPECT_EQ(1, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(SuppliedTest, Syntax2) { 
        string s = "data/syntax2.txt";
       
        SetUp(s);
        EXPECT_EQ(1, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(SuppliedTest, Syntax3) { 
        string s = "data/syntax3.txt";
       
        SetUp(s);
        EXPECT_EQ(1, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(SuppliedTest, Syntax4) { 
        string s = "data/syntax4.txt";
       
        SetUp(s);
        EXPECT_EQ(2, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(SuppliedTest, Syntax5) { 
        string s = "data/syntax5.txt";
       
        SetUp(s);
        EXPECT_EQ(5, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    for (int i = 1; i < argc; ++i) {
        if((strncmp("-h", argv[i], 3) & strncmp("--help", argv[i], 6)) == 0) {
            printf("Usage: %s [options]\n", argv[0]);
            printf("Options:\n");
            printf("  -s, --silent          Suppress printing of input files in the output\n");
            printf("  -h, --help            Show this help message\n");
            return EXIT_SUCCESS;
        }else if((strncmp("-s", argv[i], 3) & strncmp("--silent", argv[i], 9)) == 0) {
            PRINT_RESULTS = false;
        } else {
            printf("Unknown option: %s\n", argv[i]);
            printf("Use -h or --help for usage information.\n");
            return EXIT_FAILURE;
        }
    }

    return RUN_ALL_TESTS();
}
