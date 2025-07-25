/*
	To wait for multiple goroutines to finish, we can use a wait
	group
*/

package main

import (
	"fmt"
	"sync"
	"time"
)

/*
This is the function we'll run in every goroutine.
*/
func worker(id int) {
	fmt.Printf("Worker %d starting\n", id)

	/*
		Sleep to simulate an expensive task.
	*/
	time.Sleep(time.Second)
	fmt.Printf("Worker %d done\n", id)
}

func main() {

	/*
		This WaitGroup is used to wait for all the goroutines
		launched here to finish. Note: if a WaitGroup is explicitly
		passed into functions, it should be done by pointer.
	*/
	var wg sync.WaitGroup

	/*
		Launch several goroutines and increment the WaitGroup
		counter for each.
	*/
	for i := 1; i <= 5; i++ {
		wg.Add(1)

		/*
			Wrap the worker call in a closure that makes sure
			to tell the Wait Group that this worker is done.
			This way the worker itself does not have to be aware
			of the concurrency primitives involved in its ececution.
		*/
		go func() {
			time.Sleep(time.Second)
			defer wg.Done()
			worker(i)
		}()
	}
	/*
		Block until the WaitGroup counter goes back to zero;
		all workers notified they're done.
	*/
	wg.Wait()
}
