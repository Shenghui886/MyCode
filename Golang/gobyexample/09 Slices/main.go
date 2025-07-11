/*
Key differences between array and slice:

1. Length
   - array: Fixed length (determined at declaration)
   - slice: Dynamic length (extensible)

2. Storage
   - array: Direct data storage
   - slice: References underlying array (pointer+len+cap)

3. Passing Mechanism
   - array: Passed by value (full copy)
   - slice: Passed by reference (header copy)

4. Capacity
   - array: Fixed and immutable
   - slice: Dynamically expandable (2x growth on append)

5. Initialization
   - array: Auto zero-initialized
   - slice: Zero value is nil (requires make or literal)

6. Comparison
   - array: Comparable (== operator)
   - slice: Not comparable (only vs nil)

7. Use Cases
   - array: Fixed-size data
   - slice: Dynamic collections (90%+ use cases)
*/

package main

import (
	"fmt"
	"slices"
)

func main() {

	var s []string
	fmt.Println("uninit:", s, s == nil, len(s) == 0)

	// string slices, every element is a string
	s = make([]string, 3)
	fmt.Println("emp:", s, "len:", len(s), "cap:", cap(s))

	s[0] = "a"
	s[1] = "b"
	s[2] = "c"
	fmt.Println("set:", s)
	fmt.Println("get:", s[2])

	fmt.Println("len:", len(s))

	s = append(s, "d")
	fmt.Println("apd:", s)
	fmt.Println("len:", len(s), "cap:", cap(s))

	s = append(s, "e", "ff")
	fmt.Println("apd:", s)
	fmt.Println("len:", len(s), "cap:", cap(s))

	c := make([]string, len(s))
	copy(c, s)
	fmt.Println("cpy:", c)

	l := s[2:5]
	fmt.Println("sl1:", l)

	l = s[:5]
	fmt.Println("sl2:", l)

	l = s[2:]
	fmt.Println("sl3:", l)

	t := []string{"g", "h", "i"}
	fmt.Println("dcl:", t)

	t2 := []string{"g", "h", "i"}
	if slices.Equal(t, t2) {
		fmt.Println("t == t2")
	}

	twoD := make([][]int, 3)
	for i := range 3 {
		innerLen := i + 1
		twoD[i] = make([]int, innerLen)
		for j := range innerLen {
			twoD[i][j] = i + j
		}
	}
	fmt.Println("2d: ", twoD)
}
