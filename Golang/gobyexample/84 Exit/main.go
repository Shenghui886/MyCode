/*
	Use 'os.Exit' to immediately exit with a given status.
*/

package main

import (
	"fmt"
	"os"
)

func main() {
	/*
		'defer' will not be run when using 'os.Exit', so this
		'fmt.Println' will never be called.
	*/
	defer fmt.Println("!")

	/*
		Exit with status 3.
	*/
	os.Exit(3)
}

/*
	Note that unlike e.g. C, Go dose not use an integer return
	value from 'main' to indicate exit status. If you'd like to
	exit with a non-zero status you should use 'os.Exit'.
*/
