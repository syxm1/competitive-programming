/*
	syxm1
    easier debug using trace(...)
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <climits>
#include <cstring>

using namespace std;

template<typename T> void __print(T x) 
{
        cerr << "\033[35m" << x;
}

template<typename T, typename U> void __print(pair<T, U> x) 
{       
        cerr << "\033[35m{" << x.first << ", " << x.second << "}";
}

template<typename T> void __print(vector<T> &x) 
{
        cerr << "\033[35m{";
        for (size_t i = 0; i < x.size(); i++) {
                __print(x[i]);
                if (i + 1 < x.size()) cerr << ", ";
        }
        cerr << "}\033[0m";
}

template<typename T> void __print(set<T> &x) 
{
        cerr << "\033[35m{";
        for (auto it = x.begin(); it != x.end(); it++) {
                __print(*it);
                if (it != prev(x.end())) cerr << ", ";
        }
        cerr << "}\033[0m";
}


template<typename T> void __print(multiset<T> &x) 
{
        cerr << "\033[35m{";
        for (auto it = x.begin(); it != x.end(); it++) {
                __print(*it);
                if (it != prev(x.end())) cerr << ", ";
        }
        cerr << "}\033[0m";
}

template<typename T, typename U> void __print(map<T, U> &x) 
{
        cerr << "\033[35m{";
        for (auto it = x.begin(); it != x.end(); it++) {
                cerr << '{';
                __print(it->first);
                cerr << " : ";
                __print(it->second);
                cerr << '}';
                if (it != prev(x.end())) cerr << ", ";
        }
        cerr << "}\033[0m";
}

template<typename T> void __print(stack<T> &x) 
{
        stack<T> y = x;
        while (!y.empty()) {
                __print(y.top());
                y.pop();
        }
}

template<typename T> void __print(queue<T> &x) 
{
        queue<T> y = x;
        while (!y.empty()) {
                __print(y.front());
                y.pop();
        }
}

template<typename T> void __print(priority_queue<T> &x) 
{
        priority_queue<T> y = x;
        while (!y.empty()) {
                __print(y.top());
                y.pop();
        }
}

template<typename T> void debug(string s, T x) 
{
	cerr << "\033[1;34m" << s << "\033[0;32m = ";
        __print(x);
        cerr << "\033[0m\n";
}

template<typename T, typename... Args> void debug(string s, T x, Args... args) 
{
	for (int i=0, b=0; i<(int)s.size(); i++) {
                if (s[i] == '(' || s[i] == '{') {
                	b++;
                }
                else if (s[i] == ')' || s[i] == '}') {
                	b--; 
                }
                else if (s[i] == ',' && b == 0) {
                	cerr << "\033[1;34m" << s.substr(0, i) << "\033[0;32m = "; 
                        __print(x);
                        cerr << "\033[31m | "; 
                        debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); 
                	break;
                }
        }
}

 
#ifndef ONLINE_JUDGE
#define trace(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 37
#endif
 
