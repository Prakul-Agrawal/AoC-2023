# Advent of Code - 2023

## Code Details

> The code is written entirely in C++ and compiled simply with `g++` without any flags
>
> Compiling the code such as `g++ 'Day 1'/1.cpp` will create an executable file called `a.out` 
> which can be run with `./a.out`
> 
> The code is written in a way such that you can store your input for the day in a file such as `input.txt` and then
> redirect it to the executable file such as `./a.out < input.txt`
> 
> I have used my regular CP Template for the code, most of which can be omitted for the purpose of this event

## New Things I Learned

> Using `getline(cin, s)` to read a line from the input and the using `istringstream` to parse it made things much
> easier as the event progressed.
> 
> Making code more readable by naming variables properly and using functions to make the code more modular helps a 
> lot in debugging and understanding the code later on.
> 
> Sometimes, a simple brute force solution is all you need to solve the problem. You don't always have to
> over-engineer things.
> 
> Interesting variations of the `state` stored for problems involving graph traversal such as Dijkstra's, DFS etc.
> 
> Looking at the input structure can also give hints about the solution. At times, you can find a pattern or some
> heuristic that can work.