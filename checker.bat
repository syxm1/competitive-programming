@echo off
D:
cd \Workspace\Competitive Programming
g++ -std=c++17 test.cpp -o  test
g++ -std=c++17 soln.cpp -o  soln
g++ -std=c++17 brute.cpp -o  brute 
for /l %%x in (1, 1, 100) do (
    test > input.in
    soln < input.in > output.out 
    brute < input.in > output2.out
    fc output.out output2.out > diagnostics || (echo Test %%x [1m[31mFAILED[0m & echo, & echo [1m[36mFailed Test:[0m & type input.in  & echo, & echo [1m[32mCorrect Answer:[0m  & type output2.out & echo,  & echo [1m[31mYour Answer:[0m  & type output.out & exit /b)
    echo Test %%x [1m[32mPASSED[0m
)

echo all generated tests [1m[32mPASSED[0m
@REM pause
