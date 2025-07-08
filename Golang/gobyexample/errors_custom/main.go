/*
	It's possible to use custom types as errors
	by implementing the Error() memthod on them.

	Here's a variant on the example obove that
	uses a custom type to explicitly represent
	an argument error.
*/

package main

import (
	"errors"
	"fmt"
)

// A custom error type usually has the suffix "Error".
type argError struct {
	arg     int
	message string
}

// Adding this method makes implement the interface.
func (e *argError) Error() string {
	return fmt.Sprintf("%d - %s", e.arg, e.message)
}

func f(arg int) (int, error) {
	if arg == 42 {
		// Return our custom error.
		return -1, &argError{arg, "can't work with it"}
	}
	return arg + 3, nil
}

func main() {
	_, err := f(42)
	var ae *argError
	/*
		errors.As is a more advanced version of errors.Is.

		It checks that a given error(or any error in its chain)
		matches a specific error type and converts to a value
		of that type, returning true on success.
		If there's no match, it returns false.
	*/
	if errors.As(err, &ae) {
		fmt.Println(ae.arg)
		fmt.Println(ae.message)
	} else {
		fmt.Println("err doesn't match argError")
	}
}
