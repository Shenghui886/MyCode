/*
	Branching with 'if' and 'else' in Go is straight-forward.
*/

package main

import "fmt"

func main() {

	/*
		Here's a basic example.
	*/
	if 7%2 == 0 {
		fmt.Println("7 is even")
	} else {
		fmt.Println("7 is odd")
	}

	/*
		You can have an 'if' statement without an else.
	*/
	if 8%4 == 0 {
		fmt.Println("8 is divisible by 4")
	}

	/*
		Logical operatiors like && and || are often useful in
		conditions.
	*/
	if 8%2 == 0 || 7%2 == 0 {
		fmt.Println("eighter 8 or 7 are even")
	}

	/*
		A statement can precede conditionals; any variables
		declared in this statement are abailable in the current
		and all subsequent branches.
	*/
	if num := 9; num < 0 {
		fmt.Println(num, "is negative")
	} else if num < 10 {
		fmt.Println(num, "has 1 digit")
	} else {
		fmt.Println(num, "has multiple digits")
	}
}

/*
	Note that you don't need parentheses around conditions in
	Go, but that the braces are required.
*/
