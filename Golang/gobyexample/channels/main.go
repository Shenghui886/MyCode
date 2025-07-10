/*
	Channels are the pipes that connect concurrent
	goroutines. You can send values into channels
	from one goroutine and receive those values into
	another goroutine.

	By default sends and receives block until both the
	sender and receiver are ready. This property allowed
	us to wait at the end of our program for the message
	"ping" without having to use any other synchronization.
*/

package main

import "fmt"

func main() {

	/*
		Create a new channel with make(chan val-type).
		Channels are typed by the values they convey.
	*/
	messages := make(chan string)

	/*
		Send a value into a channel using the syntax
		'channel <- value'. Here we send "ping" to the
		channel messages we made above, from a new goroutine.
	*/
	go func() { messages <- "ping" }()

	/*
		The syntax '<- channel' receives a value from
		the channel. Here we'll receive the message "ping"
		we sent above and print it out.
	*/
	msg := <-messages
	fmt.Println(msg)
}
