/*
	Unit testing is an important part of writing principled Go
	programs. The 'testing' package provides the tools we need
	to write unit tests and the 'go test' command runs tests.

	For the sake of demonstration, this code is in package
	'main', but it could be any package. Testing code typically
	lives in the same package as the code it tests.
*/

package main

import (
	"fmt"
	"testing"
)

/*
We'll be testing this simple implementation of an integer
minimum. Typically, the code we're testing would be in a
source file named something like 'intutils.go', and the test
file for it would then be named 'intutils_test.go'.
*/
func IntMin(a, b int) int {
	if a < b {
		return a
	}
	return b
}

/*
A test is created by writing a function with a name
beginning with 'Test'.
*/
func TestIntMinBasic(t *testing.T) {
	ans := IntMin(2, -2)
	/*
		't.Error*' will report test failures but continue executing
		the test 't.Fatal*' will report test failures and stop the
		test immediately.
	*/
	if ans != -2 {
		t.Errorf("IntMin(2, -2) = %d; want -2", ans)
	}
}

/*
Writing tests can be repetitive, so it's idiomatic to use a
'table-driven' style, where test inputs and expected outputs
are listed in a table and a single loop walks over then and
performs the test logic.
*/
func TestIntMinTableDriven(t *testing.T) {
	var tests = []struct {
		a, b int
		want int
	}{
		{0, 1, 0},
		{1, 0, 0},
		{2, -2, -2},
		{0, -1, -1},
		{-1, 0, -1},
	}
	/*
		't.Run' enables running "subtests", one for each table entry.
		These are shown separately when executing 'go test -v'.
	*/
	for _, tt := range tests {
		testname := fmt.Sprintf("%d, %d", tt.a, tt.b)
		t.Run(testname, func(t *testing.T) {
			ans := IntMin(tt.a, tt.b)
			if ans != tt.want {
				t.Errorf("got %d, want %d", ans, tt.want)
			}
		})
	}
}

/*
Benchmark tests typically go in '_test.go' files and are
named beginning with 'Benchmark'. Any code that's required
for the benchmark to run but should not be measured goes
before this loop
*/
func BenchmarkIntMin(b *testing.B) {
	/*
		The benchmark runner will automatically execute this
		loop body many times to determine a reasonable estimate
		of the run-time of a single iteration.
	*/
	for b.Loop() {
		IntMin(1, 2)
	}
}

func main() {
	fmt.Println("hello go!")
}
