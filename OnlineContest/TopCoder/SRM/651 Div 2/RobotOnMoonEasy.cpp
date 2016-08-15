#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <list>
#include <set>
#include <algorithm>

using namespace std;


struct RobotOnMoonEasy
{
    string isSafeCommand(vector <string> board, string S)
    {
        string ret = "Alive";
        int a = 0, b = 0, ro = board.size(), co = board[0].size();

        //cout << ro << " " << co << endl;

        for(int i = 0; i < ro; i++)
        {
            for(int j = 0; j < co; j++)
            {
                if(board[ i ][ j ] == 'S')
                {
                    a = i;
                    b = j;
                    break;
                }
            }
        }


        for(int i = 0; i < S.size(); i++)
        {
            if(S[ i ] == 'U')
            {
                int x = a - 1;
                int y = b;

                if(x < 0)
                {
                    ret = "Dead";
                }
                else
                {
                    if(x >= 0 && x < ro && y >= 0 && y < co)
                    {
                        char ch = board[ x ][ y ];
                        if(ch != '#')
                        {
                            a = x;
                            b = y;
                        }
                    }
                }
            }
            else if(S[ i ] == 'D')
            {
                int x = a + 1;
                int y = b;

                if(x >= ro)
                {
                    ret = "Dead";
                }
                else
                {
                    if(x >= 0 && x < ro && y >= 0 && y < co)
                    {
                        char ch = board[ x ][ y ];
                        if(ch != '#')
                        {
                            a = x;
                            b = y;
                        }
                    }
                }
            }
            else if(S[ i ] == 'L')
            {
                int x = a;
                int y = b - 1;

                if(y < 0)
                {
                    ret = "Dead";
                }
                else
                {
                    if(x >= 0 && x < ro && y >= 0 && y < co)
                    {
                        char ch = board[ x ][ y ];
                        if(ch != '#')
                        {
                            a = x;
                            b = y;
                        }
                    }
                }
            }
            else if(S[ i ] == 'R')
            {
                int x = a;
                int y = b + 1;

                if(y >= co)
                {
                    ret = "Dead";
                }
                else
                {
                    if(x >= 0 && x < ro && y >= 0 && y < co)
                    {
                        char ch = board[ x ][ y ];
                        if(ch != '#')
                        {
                            a = x;
                            b = y;
                        }
                    }
                }
            }
        }

        return ret;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".....",
 ".###.",
 "..S#.",
 "...#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "URURURURUR"; string Arg2 = "Alive"; verify_case(0, Arg2, isSafeCommand(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {".....",
 ".###.",
 "..S..",
 "...#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "URURURURUR"; string Arg2 = "Dead"; verify_case(1, Arg2, isSafeCommand(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {".....",
 ".###.",
 "..S..",
 "...#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "URURU"; string Arg2 = "Alive"; verify_case(2, Arg2, isSafeCommand(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"#####",
 "#...#",
 "#.S.#",
 "#...#",
 "#####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD"; string Arg2 = "Alive"; verify_case(3, Arg2, isSafeCommand(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"#####",
 "#...#",
 "#.S.#",
 "#...#",
 "#.###"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD"; string Arg2 = "Dead"; verify_case(4, Arg2, isSafeCommand(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "R"; string Arg2 = "Dead"; verify_case(5, Arg2, isSafeCommand(Arg0, Arg1)); }

// END CUT HERE
};

void input();

/**************************Templet end*********************************/

// BEGIN CUT HERE
int main()
{
    RobotOnMoonEasy ___test;
    ___test.run_test(-1);
    int gbase;

    #ifdef monkey
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    input();

    return 0;
}
// END CUT HERE
void input()
{

}
