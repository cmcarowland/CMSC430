using namespace std;
#include "gtest/gtest.h"
#include <stdio.h>
#include <stdlib.h>
#include <deque>

const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string LIGHT_BLUE = "\033[94m";
const string RESET = "\033[m";

extern double parse();
extern deque<double> args;
extern void yyset_in  ( FILE * _in_str  );
extern bool PRINT_RESULTS;

namespace {
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

     string problem_header(string equation) {
        stringstream ss;
        ss << GREEN      << "[  PARAMS  ]" << RESET << "\t" << equation << endl;
        return ss.str();
    }

    string result_header(string equation, double result, double expected = 0) {
        stringstream ss;
        ss << LIGHT_BLUE << "[  RESULT  ]\t" << equation << " = " << result << " (expected: " << expected << ")" << RESET << endl;
        return ss.str();
    }

     TEST_F(SuppliedTest, Discussion0) { 
        string s = "data/discussion.txt";
        double answer = 0;
        SetUp(s, deque<double>{0, 0, 0});
        cout << problem_header("0, 0, 0");
        EXPECT_EQ(answer, result) << "Failed!! " << s;
        cout << result_header(s, result, answer);

        SetUp(s, deque<double>{1, 0, 0});
        answer = 53;
        cout << problem_header("1, 0, 0");
        EXPECT_EQ(answer, result) << "Failed!! " << s;
        cout << result_header(s, result, answer);

        SetUp(s, deque<double>{2, 0, 0});
        answer = 14;
        cout << problem_header("2, 0, 0");
        EXPECT_EQ(answer, result) << "Failed!! " << s;
        cout << result_header(s, result, answer);
        
        SetUp(s, deque<double>{3, 0, 0});
        answer = 0;
        cout << problem_header("3, 0, 0");
        EXPECT_EQ(answer, result) << "Failed!! " << s;
        cout << result_header(s, result, answer);

        SetUp(s, deque<double>{0, 1, 0});
        answer = 1;
        cout << problem_header("0, 1, 0");
        EXPECT_EQ(answer, result) << "Failed!! " << s;
        cout << result_header(s, result, answer);

        SetUp(s, deque<double>{0, 2, 0});
        answer = 2;
        cout << problem_header("0, 2, 0");
        EXPECT_EQ(answer, result) << "Failed!! " << s;
        cout << result_header(s, result, 2);

        SetUp(s, deque<double>{1, 1, '+'});
        answer = 54;
        cout << problem_header("1, 1, '+'");
        EXPECT_EQ(answer, result) << "Failed!! " << s;
        cout << result_header(s, result, answer);
    
        SetUp(s, deque<double>{2, 2, '+'});
        answer = 1;
        cout << problem_header("2, 2, '+'");
        EXPECT_EQ(answer, result) << "Failed!! " << s;
        cout << result_header(s, result, answer);

        SetUp(s, deque<double>{3, 2, '+'});
        answer = 2;
        cout << problem_header("3, 2, '+'");
        EXPECT_EQ(answer, result) << "Failed!! " << s;
        cout << result_header(s, result, answer);

        SetUp(s, deque<double>{3, 3, '+'});
        answer = 3;
        cout << problem_header("3, 3, '+'");
        EXPECT_EQ(answer, result) << "Failed!! " << s;
        cout << result_header(s, result, answer);

        SetUp(s, deque<double>{1, 1, '-'});
        answer = 52;
        cout << problem_header("1, 1, '-'");
        EXPECT_EQ(answer, result) << "Failed!! " << s;
        cout << result_header(s, result, answer);

        SetUp(s, deque<double>{1, 2, '-'});
        answer = 53;
        cout << problem_header("1, 2, '-'");
        EXPECT_EQ(answer, result) << "Failed!! " << s;
        cout << result_header(s, result, answer);

        SetUp(s, deque<double>{2, 2, '-'});
        answer = 12;
        cout << problem_header("2, 2, '-'");
        EXPECT_EQ(answer, result) << "Failed!! " << s;
        cout << result_header(s, result, answer);

        SetUp(s, deque<double>{3, 20, '+'});
        answer = 5;
        cout << problem_header("3, 20, '+'");
        EXPECT_EQ(answer, result) << "Failed!! " << s;
        cout << result_header(s, result, answer);

        SetUp(s, deque<double>{3, 108, '+'});
        answer = 9;
        cout << problem_header("3, 108, '+'");
        EXPECT_EQ(answer, result) << "Failed!! " << s;
        cout << result_header(s, result, answer);

        SetUp(s, deque<double>{3, 108, '-'});
        answer = 3;
        cout << problem_header("3, 108, '-'");
        EXPECT_EQ(answer, result) << "Failed!! " << s;
        cout << result_header(s, result, answer);

        SetUp(s, deque<double>{108, 108, '+'});
        answer = 9;
        cout << problem_header("108, 108, '+'");
        EXPECT_EQ(answer, result) << "Failed!! " << s;
        cout << result_header(s, result, answer);

        SetUp(s, deque<double>{108, 108, '-'});
        answer = 3;
        cout << problem_header("108, 108, '-'");
        EXPECT_EQ(answer, result) << "Failed!! " << s;
        cout << result_header(s, result, answer);

        SetUp(s, deque<double>{2196, 1024, '+'});
        answer = 1;
        cout << problem_header("2196, 1024, '+'");
        EXPECT_EQ(answer, result) << "Failed!! " << s;
        cout << result_header(s, result, answer);
        
        SetUp(s, deque<double>{2196, 1024, '-'});
        answer = 8;
        cout << problem_header("2196, 1024, '-'");
        EXPECT_EQ(answer, result) << "Failed!! " << s;
        cout << result_header(s, result, answer);
    }

    TEST_F(SuppliedTest, Test1) { 
        string s = "data/test1.txt";
       
        SetUp(s);
        EXPECT_EQ(25, result) << "Failed!! " << s;
        cout << result_header(s, result, 25);
    }

    TEST_F(SuppliedTest, Test2) { 
        string s = "data/test2.txt";
       
        SetUp(s);
        EXPECT_EQ(9, result) << "Failed!! " << s;
        cout << result_header(s, result, 9);
    }
    
    TEST_F(SuppliedTest, Test3) { 
        string s = "data/test3.txt";
       
        SetUp(s);
        EXPECT_EQ(99, result) << "Failed!! " << s;
        cout << result_header(s, result, 99);
    }
    
    TEST_F(SuppliedTest, Test4) { 
        string s = "data/test4.txt";
       
        SetUp(s);
        EXPECT_EQ(8, result) << "Failed!! " << s;
        cout << result_header(s, result, 8);
    }
    
    TEST_F(SuppliedTest, Test5) { 
        string s = "data/test5.txt";
       
        SetUp(s);
        EXPECT_EQ(115.57, result) << "Failed!! " << s;
        cout << result_header(s, result, 115.57);
    }
   
    TEST_F(SuppliedTest, Test6) { 
        string s = "data/test6.txt";
       
        SetUp(s);
        EXPECT_EQ(12, result) << "Failed!! " << s;
        cout << result_header(s, result, 12);
    }
   
    TEST_F(SuppliedTest, TestAdd) { 
        string s = "data/test_add.txt";

        SetUp(s);
        EXPECT_EQ(11, result) << "Failed!! " << s;
        cout << result_header(s, result, 11);
    }

    TEST_F(SuppliedTest, TestSubtract) { 
        string s = "data/test_subtract.txt";

        SetUp(s);
        EXPECT_EQ(3, result) << "Failed!! " << s;
        cout << result_header(s, result, 3);
   }

   TEST_F(SuppliedTest, TestMultiply) { 
        string s = "data/test_multiply.txt";

        SetUp(s);
        EXPECT_EQ(40, result) << "Failed!! " << s;
        cout << result_header(s, result, 40);
    }
    
    TEST_F(SuppliedTest, TestDivide) { 
        string s = "data/test_divide.txt";

        SetUp(s);
        EXPECT_EQ(5, result) << "Failed!! " << s;
        cout << result_header(s, result, 5);
    }
    
    TEST_F(SuppliedTest, TestMod) { 
        string s = "data/test_mod.txt";

        SetUp(s);
        EXPECT_EQ(3, result) << "Failed!! " << s;
        cout << result_header(s, result, 3);
    }
    
    TEST_F(SuppliedTest, TestExp) { 
        string s = "data/test_exp.txt";

        SetUp(s);
        EXPECT_EQ(65536, result) << "Failed!! " << s;
        cout << result_header(s, result, 65536);
    }

    TEST_F(SuppliedTest, Test7) { 
        string s = "data/test7.txt";
       
        SetUp(s);
        EXPECT_EQ(5, result) << "Failed!! " << s;
        cout << result_header(s, result, 5);
    }

    TEST_F(SuppliedTest, TestAnd) { 
       string s = "data/test_and.txt";
       
        SetUp(s);
        EXPECT_EQ(1, result) << "Failed!! " << s;
        cout << result_header(s, result, 1);
    }
   
    TEST_F(SuppliedTest, TestAndFalse) { 
        string s = "data/test_and_false.txt";
       
        SetUp(s);
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result, 0);
    }
   
    TEST_F(SuppliedTest, TestNot) { 
        string s = "data/test_not.txt";
       
        SetUp(s);
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result, 0);
    }
   
    TEST_F(SuppliedTest, TestNeq) { 
        string s = "data/test_neq.txt";
       
        SetUp(s);
        EXPECT_EQ(1, result) << "Failed!! " << s;
        cout << result_header(s, result, 1);
    }
   
    TEST_F(SuppliedTest, TestOr) { 
        string s = "data/test_or.txt";
       
        SetUp(s);
        EXPECT_EQ(1, result) << "Failed!! " << s;
        cout << result_header(s, result, 1);
    }
   
    TEST_F(SuppliedTest, TestOrFalse) { 
        string s = "data/test_or_false.txt";
       
        SetUp(s);
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result, 0);
    }
   
    TEST_F(SuppliedTest, Test8) { 
        string s = "data/test8.txt";
       
        SetUp(s);
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result, 0);
    }

    TEST_F(SuppliedTest, Test9_lt10) { 
        string s = "data/test9_lt10.txt";
       
        SetUp(s);
        EXPECT_EQ(1, result) << "Failed!! " << s;
        cout << result_header(s, result, 1);
    }

    TEST_F(SuppliedTest, Test9_lt20) { 
        string s = "data/test9_lt20.txt";
       
        SetUp(s);
        EXPECT_EQ(2, result) << "Failed!! " << s;
        cout << result_header(s, result, 2);
    }

    TEST_F(SuppliedTest, Test9_gt30) { 
        string s = "data/test9_gt30.txt";
       
        SetUp(s);
        EXPECT_EQ(4, result) << "Failed!! " << s;
        cout << result_header(s, result, 4);
    }
   
    TEST_F(SuppliedTest, Test9_noelsifs) { 
        string s = "data/test9_noelsif.txt";
       
        SetUp(s);
        EXPECT_EQ(4, result) << "Failed!! " << s;
        cout << result_header(s, result, 4);
    }

    TEST_F(SuppliedTest, Test9) { 
        string s = "data/test9.txt";
       
        SetUp(s);
        EXPECT_EQ(3, result) << "Failed!! " << s;
        cout << result_header(s, result, 3);
    }

    TEST_F(SuppliedTest, Test10) { 
        string s = "data/test10.txt";
       
        SetUp(s);
        EXPECT_EQ(10, result) << "Failed!! " << s;
        cout << result_header(s, result, 10);
    }

    TEST_F(SuppliedTest, Test11) { 
        string s = "data/test11.txt";
        
        SetUp(s, deque<double>{6.8});
        EXPECT_EQ(8.3, result) << "Failed!! " << s;
        cout << result_header(s, result, 8.3);
        args.clear();
    }

    TEST_F(SuppliedTest, Test12) { 
        string s = "data/test12.txt";
       
        SetUp(s, deque<double>{16, 15.9});
        EXPECT_EQ(14.9, result) << "Failed!! " << s;
        cout << result_header(s, result, 14.9);
    }

    TEST_F(SuppliedTest, Test12_several) { 
        string s = "data/test12_several.txt";
       
        SetUp(s, deque<double>{1,2.2,3.3,4});
        EXPECT_EQ(10.5, result) << "Failed!! " << s;
        cout << result_header(s, result, 10.5);
    }

    TEST_F(SuppliedTest, Test13) { 
        string s = "data/test13.txt";
       
        SetUp(s);
        EXPECT_EQ(2, result) << "Failed!! " << s;
        cout << result_header(s, result, 2);
    }

    TEST_F(SuppliedTest, Test14) { 
        string s = "data/test14.txt";
       
        SetUp(s);
        EXPECT_EQ(0, result) << "Failed!! " << s;
        cout << result_header(s, result, 0);
    }

    TEST_F(SuppliedTest, Test15) { 
        string s = "data/test15.txt";
       
        SetUp(s, deque<double>{1, 2.5, 65});
        EXPECT_EQ(1, result) << "Failed!! " << s;
        cout << result_header(s, result, 1);
    }

    TEST_F(SuppliedTest, Test16) { 
        string s = "data/test16.txt";

        SetUp(s, deque<double>{10, -10});
        EXPECT_EQ(52, result) << "Failed!! " << s;
        cout << result_header(s, result, 52);
    }
   
    TEST_F(SuppliedTest, Test16_1) { 
        string s = "data/test16.txt";

        SetUp(s, deque<double>{10, 5});
        EXPECT_EQ(49, result) << "Failed!! " << s;
        cout << result_header(s, result, 49);
    }
    
    TEST_F(SuppliedTest, Test16_4) { 
        string s = "data/test16.txt";

        SetUp(s, deque<double>{10, -34});
        EXPECT_EQ(52, result) << "Failed!! " << s;
        cout << result_header(s, result, 52);
    }

    TEST_F(SuppliedTest, Test16_Y) { 
        string s = "data/test16.txt";

        SetUp(s, deque<double>{10, 0});
        EXPECT_EQ(89, result) << "Failed!! " << s;
        cout << result_header(s, result, 89);
    }

    TEST_F(SuppliedTest, Test16_3) { 
        string s = "data/test16.txt";

        SetUp(s, deque<double>{-55, 99});
        EXPECT_EQ(51, result) << "Failed!! " << s;
        cout << result_header(s, result, 51);
    }

    TEST_F(SuppliedTest, Test16_2) { 
        string s = "data/test16.txt";

        SetUp(s, deque<double>{-55, -99});
        EXPECT_EQ(50, result) << "Failed!! " << s;
        cout << result_header(s, result, 50);
    }

        
    TEST_F(SuppliedTest, Test16_Y_Xlt0) { 
        string s = "data/test16.txt";

        SetUp(s, deque<double>{-34, 0});
        EXPECT_EQ(89, result) << "Failed!! " << s;
        cout << result_header(s, result, 89);
    }

    TEST_F(SuppliedTest, Test16_X0_Y0) { 
        string s = "data/test16.txt";

        SetUp(s, deque<double>{0, 0});
        EXPECT_EQ('O', result) << "Failed!! " << s;
        cout << result_header(s, result, 'O');
    }

    TEST_F(SuppliedTest, Test16_X0_Ylt0) { 
        string s = "data/test16.txt";

        SetUp(s, deque<double>{0, -1});
        EXPECT_EQ('X', result) << "Failed!! " << s;
        cout << result_header(s, result, 'X');
    }

    TEST_F(SuppliedTest, Test16_X0_Ygt0) { 
        string s = "data/test16.txt";

        SetUp(s, deque<double>{0, 1123});
        EXPECT_EQ('X', result) << "Failed!! " << s;
        cout << result_header(s, result, 'X');
    }

    TEST_F(SuppliedTest, Syntax1) { 
        string s = "data/syntax1.txt";

        SetUp(s);
        EXPECT_EQ(1, result) << "Failed!! " << s;
        cout << result_header(s, result, 1);
    }

    TEST_F(SuppliedTest, Syntax2) { 
        string s = "data/syntax2.txt";

        SetUp(s);
        EXPECT_EQ(1, result) << "Failed!! " << s;
        cout << result_header(s, result, 1);
    }

    TEST_F(SuppliedTest, Syntax3) { 
        string s = "data/syntax3.txt";

        SetUp(s, deque<double>{14});
        EXPECT_EQ(1, result) << "Failed!! " << s;
        cout << result_header(s, result, 1);
    }

    TEST_F(SuppliedTest, Syntax4) { 
        string s = "data/syntax4.txt";

        SetUp(s, deque<double>{28});
        EXPECT_EQ(2, result) << "Failed!! " << s;
        cout << result_header(s, result, 2);
    }

    TEST_F(SuppliedTest, Syntax5) { 
        string s = "data/syntax5.txt";

        SetUp(s);
        EXPECT_EQ(5, result) << "Failed!! " << s;
        cout << result_header(s, result, 5);
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