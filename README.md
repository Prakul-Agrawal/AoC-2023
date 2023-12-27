# Advent of Code - 2023

## Code Details

> The code is written entirely in C++ and compiled simply with `g++` without any flags
>
> Compiling the code such as `g++ 'Day 1'/1.cpp` will create an executable file called `a.out` which can be run with `./a.out`
> 
> The code is written in a way such that you can store your input for the day in a file such as `input.txt` and then redirect it to the executable file such as `./a.out < input.txt`
> 
> I have used my regular CP Template for the code, most of which can be omitted for the purpose of this event

## New Things I Learned

> Using `getline(cin, s)` to read a line from the input and the using `istringstream` to parse it made things much easier as the event progressed.
> 
> Making code more readable by naming variables properly and using functions to make the code more modular helps a lot in debugging and understanding the code later on.
> 
> Sometimes, a simple brute force solution is all you need to solve the problem. You don't always have to over-engineer things.
> 
> Interesting variations of the `state` stored for problems involving graph traversal such as Dijkstra's, DFS etc.
> 
> Looking at the input structure can also give hints about the solution. At times, you can find a pattern or some heuristic that can work.

## Solution Explanations

### Day 1
> Part 1:
> - Simply iterate over the characters storing the first and last occurrence of a 'digit' character and evaluate the number formed by them.

> Part 2:
> - In addition to Part 1, we now create a map of each numerical word to the digit itself. Then we find the position of these numerical words in the string to determine the first and last occurrence of digits.

### Day 2
> Part 1:
> - Mostly input parsing again, where you have to ensure that you count the value of the corresponding colour correctly.

> Part 2:
> - You need to also store the maximum value for each colour seen in the game. You can just have three variables to store these values and update them accordingly.

### Day 3
> Part 1:
> - I create two sets in order to solve this. The first set is to store the coordinates of the points which have symbols. Next I go through the neighbouring points of all these symbol coordinates and if I find a digit there, I add the point to the second set. Finally, I go through all the numbers and if they contain a point in the second set, I increment the total.

> Part 2:
> - My approach is to again maintain a set for the `*` symbol. Next, I go through all the numerical values and store the value in corresponding cells in a 2D grid. This will help me to determine if there are _exactly_ two numbers adjacent to a `*`.
> - Now I go through the positions of all the `*` and check the adjacent cells. This part is not elegant. The tricky case is that the same number could continue in all the cells above or below the `*`. So, I maintain flags to check if there is any continuous number present. If the count of number is exactly 2, then that `*` is valid.