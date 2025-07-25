/*
Go offers built-in support for [regular expressions]. Here
are some examples of common regexp-related tasks in Go.
*/

package main

import (
	"bytes"
	"fmt"
	"regexp"
)

func main() {
	/*
		This tests whether a pattern matches a string.
	*/
	match, _ := regexp.MatchString("p([a-z]+)ch", "peach")
	fmt.Println(match)

	/*
		Above we used a string pattern directly, but for other
		regexp tasks you'll need to 'Compile' an optimized
		'Regexp' struct.
	*/
	r, _ := regexp.Compile("p([a-z]+)ch")

	/*
		Many methods are abailable on these structs. Here's a
		match test like we saw earlier.
	*/
	fmt.Println(r.MatchString(("peach")))

	/*
		This finds the match for the regexp.
	*/
	fmt.Println(r.FindString("peach punch"))

	/*
		This also finds the first match but returns the start and
		end indexes for the match instead of the matching text.
	*/
	fmt.Println("idx:", r.FindStringIndex("peach punch"))

	/*
		The 'Submatch variants include information about both the
		whole-pattern matches and the submatches within those
		matches. For example this will return infomation for both
		'p([a-z]+ch)' and '(a-z+)'.
	*/
	fmt.Println(r.FindStringSubmatch("peach punch"))

	/*
		Similarly this will return information about the indexes of
		matches and submatches.
	*/
	fmt.Println(r.FindStringSubmatchIndex("peach punch"))

	/*
		The 'All' variants of these function apply to all matches
		in the input, not just the first. For example to find all
		matches for a regexp.
	*/
	fmt.Println(r.FindAllString("peach punch pinch", -1))

	/*
		These 'All' variants are abailable for the other function
		we saw above as well.
	*/
	fmt.Println("all:", r.FindAllStringSubmatchIndex("peach punch pinch", -1))

	/*
		Providing a non-negative integer ads the second argument
		to these functions will limit the number of matches.
	*/
	fmt.Println(r.FindAllString("peach punch pinch", 2))

	/*
		Our examples above had string arguments and used
		names like 'MatchString'. We can alse provide '[]byte'
		argument and drop 'String' from the function name.
	*/
	fmt.Println(r.Match([]byte("peach")))

	/*
		When creating global variables with regular expressions
		you can use the MustCompile variation an error, which
		makes it safer to use for global variables.
	*/
	r = regexp.MustCompile("p([a-z]+)ch")
	fmt.Println("regexp:", r)

	/*
		The 'regexp' package can also be used to replace subsets
		of string with other values.
	*/
	fmt.Println(r.ReplaceAllString("a peach", "<fruit>"))

	/*
		The 'Func' variant allows you to transform matched text
		with a given function.
	*/
	in := []byte("a peach")
	out := r.ReplaceAllFunc(in, bytes.ToUpper)
	fmt.Println(string(out))
}
