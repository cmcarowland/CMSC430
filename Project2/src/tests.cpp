using namespace std;
#include "gtest/gtest.h"
#include <stdio.h>
#include <stdlib.h>

const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string LIGHT_BLUE = "\033[94m";
const string RESET = "\033[0m";


namespace {
    class SuppliedTest : public testing::Test {
    protected:
        const int MAX_LINE = 1024;
        const string binaryPath = "bin/project2.elf";
        FILE *pipe;
        FILE *input;

        SuppliedTest() {}

        ~SuppliedTest() {
            if (input) {
                fclose(input);
            }
        }

        int SetUp(string fileName) {
            pipe = popen(binaryPath.c_str(), "w");
            if(!pipe)
            {
                perror("popen failed");
                exit(EXIT_FAILURE);
            }

            input = fopen(fileName.c_str(), "r");
            if(!input)
            {
                perror("fopen failed");
                exit(EXIT_FAILURE);
            }

            char buffer[MAX_LINE];
            while(fgets(buffer, sizeof(buffer), input)) {
                fputs(buffer, pipe);
            }

            int status = pclose(pipe);
            if (WIFEXITED(status)) {
                return WEXITSTATUS(status);
            }

            return -1;
        }
    };

    string result_header(string equation, double result) {
        stringstream ss;
        ss << LIGHT_BLUE << "[  RESULT  ]\t" << equation << " = " << result << RESET << endl;
        return ss.str();
    }

    TEST_F(SuppliedTest, Test1) { 
        string s = "data/test1.txt";
       
        double result = SetUp(s);
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(SuppliedTest, Test2) { 
        string s = "data/test2.txt";
       
        double result = SetUp(s);
        EXPECT_EQ(1, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
    
    TEST_F(SuppliedTest, Test3) { 
        string s = "data/test3.txt";
       
        double result = SetUp(s);
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
    
    TEST_F(SuppliedTest, Test4) { 
        string s = "data/test4.txt";
       
        double result = SetUp(s);
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
    
    TEST_F(SuppliedTest, Test5) { 
        string s = "data/test5.txt";
       
        double result = SetUp(s);
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
   
    TEST_F(SuppliedTest, Test6) { 
        string s = "data/test6.txt";
       
        double result = SetUp(s);
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
   
    TEST_F(SuppliedTest, Test7) { 
        string s = "data/test7.txt";
       
        double result = SetUp(s);
        EXPECT_EQ(2, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
   
    TEST_F(SuppliedTest, Test8) { 
        string s = "data/test8.txt";
       
        double result = SetUp(s);
        EXPECT_EQ(5, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
}