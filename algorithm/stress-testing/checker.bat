@echo off
D:
cd \workspace\competiitve-programming

g++ -std=c++17 soln.cpp -o soln
g++ -std=c++17 brute.cpp -o brute
g++ -std=c++17 test.cpp -o test


for /l %%x in (1, 1, 100) do (
	test > input.in
	soln < input.in > a.out
	brute < input.in > b.out
	fc a.out b.out > c || (
		echo correct:
		type b.out
		echo,  
		echo wrong: 
		type a.out 
		exit /b
	)
)

echo selesai
