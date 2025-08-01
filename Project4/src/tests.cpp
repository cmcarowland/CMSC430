/*
	Raymond Rowland
	CMSC 430 Compiler Theory and Design
	Project 3
	July 20, 2025

    tests.cpp

    Implements unit tests for the compiler project using Google Test framework.
    Tests cover various input files to validate parsing and evaluation logic.
    Each test reads an input file, sets up parameters, invokes the parser, and checks the
    result against expected values, providing detailed output for each test case.
*/

using namespace std;
#include "gtest/gtest.h"
#include <stdio.h>
#include <stdlib.h>
#include <deque>

const string RED = "\033[0;31m";
const string GREEN = "\033[0;32m";
const string YELLOW = "\033[0;33m";
const string LIGHT_BLUE = "\033[0;94m";
const string RESET = "\033[m";

extern double parse();
extern deque<double> args;
extern void yyset_in  ( FILE * _in_str  );
extern bool PRINT_RESULTS;

namespace {
    string problem_header(const deque<double>& arguments);

    class SuppliedTest : public testing::Test {
    protected:
        FILE *input;
        double result;

        SuppliedTest() {}

        ~SuppliedTest() 
        {
            args.clear();
        }

        void SetUp(string fileName, deque<double> arguments = deque<double>{}) {
            args = arguments;
            cout << problem_header(arguments);
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

    string problem_header(const deque<double>& arguments) {
        stringstream ss;
        ss << GREEN      << "[  PARAMS  ]" << RESET << "\t"; 
        if(arguments.empty()) {
            ss << "None";
        } else {
            for(size_t i = 0; i < arguments.size(); ++i) {
                if(i > 0) 
                    ss << ", ";

                ss << arguments[i];
            }
        }
        ss << endl;
        return ss.str();
    }

    string result_header(string equation, double result, double expected = 0) {
        stringstream ss;
        ss << LIGHT_BLUE << "[  RESULT  ]\t" << equation << " = " << result << " (expected: " << expected << ")" << RESET << endl;
        return ss.str();
    }

    TEST_F(SuppliedTest, Valid1) { 
        string s = "data/valid1.txt";
        SetUp(s);
        double expected = 0;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }


    TEST_F(SuppliedTest, Valid2) { 
        string s = "data/valid2.txt";
        SetUp(s);
        double expected = 0;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }

    TEST_F(SuppliedTest, Valid3) { 
        string s = "data/valid3.txt";
        SetUp(s);
        double expected = 0;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }

    TEST_F(SuppliedTest, Semantic1) { 
        string s = "data/semantic1.txt";
        SetUp(s);
        double expected = 1;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }

    TEST_F(SuppliedTest, Semantic2) { 
        string s = "data/semantic2.txt";
        SetUp(s);
        double expected = 1;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }

    TEST_F(SuppliedTest, Semantic3) { 
        string s = "data/semantic3.txt";
        SetUp(s);
        double expected = 1;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }

    TEST_F(SuppliedTest, Semantic4) { 
        string s = "data/semantic4.txt";
        SetUp(s);
        double expected = 1;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }

    TEST_F(SuppliedTest, Semantic5) { 
        string s = "data/semantic5.txt";
        SetUp(s);
        double expected = 1;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }

    TEST_F(SuppliedTest, Semantic6) { 
        string s = "data/semantic6.txt";
        SetUp(s);
        double expected = 1;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }

    TEST_F(SuppliedTest, Semantic7) { 
        string s = "data/semantic7.txt";
        SetUp(s);
        double expected = 1;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }

    TEST_F(SuppliedTest, Semantic8) { 
        string s = "data/semantic8.txt";
        SetUp(s);
        double expected = 1;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }

    TEST_F(SuppliedTest, Semantic9) { 
        string s = "data/semantic9.txt";
        SetUp(s);
        double expected = 1;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }

    TEST_F(SuppliedTest, Semantic10) { 
        string s = "data/semantic10.txt";
        SetUp(s);
        double expected = 1;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }

    TEST_F(SuppliedTest, Semantic11) { 
        string s = "data/semantic11.txt";
        SetUp(s);
        double expected = 1;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }

    TEST_F(SuppliedTest, Semantic12) { 
        string s = "data/semantic12.txt";
        SetUp(s);
        double expected = 2;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }

    TEST_F(SuppliedTest, Semantic13) { 
        string s = "data/semantic13.txt";
        SetUp(s);
        double expected = 1;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }

    TEST_F(SuppliedTest, Semantic14) { 
        string s = "data/semantic14.txt";
        SetUp(s);
        double expected = 1;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }

    TEST_F(SuppliedTest, Semantic14B) { 
        string s = "data/semantic14B.txt";
        SetUp(s);
        double expected = 1;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }

    TEST_F(SuppliedTest, Semantic14C) { 
        string s = "data/semantic14C.txt";
        SetUp(s);
        double expected = 1;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }

    TEST_F(SuppliedTest, Semantic15) { 
        string s = "data/semantic15.txt";
        SetUp(s);
        double expected = 1;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }

    TEST_F(SuppliedTest, Semantic15ListVariable) { 
        string s = "data/semantic15_list_variable.txt";
        SetUp(s);
        double expected = 1;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }

    TEST_F(SuppliedTest, Semantic15ListNumericVariable) { 
        string s = "data/semantic15_list_numeric.txt";
        SetUp(s);
        double expected = 0;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }

    TEST_F(SuppliedTest, Semantic15ListNumericInline) { 
        string s = "data/semantic15_list_numeric_inline.txt";
        SetUp(s);
        double expected = 0;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }

    TEST_F(SuppliedTest, Semantic15ListMissingVariable) { 
        string s = "data/semantic15_list_no_variable.txt";
        SetUp(s);
        double expected = 1;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }

    TEST_F(SuppliedTest, Semantic16) { 
        string s = "data/semantic16.txt";
        SetUp(s);
        double expected = 1;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }

    TEST_F(SuppliedTest, Semantic16_Widen) { 
        string s = "data/semantic16_widen.txt";
        SetUp(s);
        double expected = 0;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }

    TEST_F(SuppliedTest, Semantic16_Function) { 
        string s = "data/semantic16_function.txt";
        SetUp(s);
        double expected = 1;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }

    TEST_F(SuppliedTest, Semantic16_Function_Widen) { 
        string s = "data/semantic16_function_widen.txt";
        SetUp(s);
        double expected = 0;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }

    TEST_F(SuppliedTest, Semantic17) { 
        string s = "data/semantic17.txt";
        SetUp(s);
        double expected = 1;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }

    TEST_F(SuppliedTest, Semantic18) { 
        string s = "data/semantic18.txt";
        SetUp(s);
        double expected = 2;
        EXPECT_EQ(expected, result) << "Failed!! " << s;
        cout << result_header(s, result, expected);
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    for (int i = 1; i < argc; ++i) {
        if(strncmp("-h", argv[i], 3) == 0 || strncmp("--help", argv[i], 6) == 0) {
            printf("Usage: %s [options]\n", argv[0]);
            printf("Options:\n");
            printf("  -s, --silent          Suppress printing of input files in the output\n");
            printf("  -h, --help            Show this help message\n");
            return EXIT_SUCCESS;
        }else if(strncmp("-s", argv[i], 3) == 0 || strncmp("--silent", argv[i], 9) == 0) {
            PRINT_RESULTS = false;
        } else {
            printf("Unknown option: %s\n", argv[i]);
            printf("Use -h or --help for usage information.\n");
            return EXIT_FAILURE;
        }
    }

    return RUN_ALL_TESTS();
}