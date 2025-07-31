/*
	Go provides built-in support for [base64
	encoding/decoding]
*/

package main

import (
	"encoding/base64"
	"fmt"
)

func main() {
	/*
		Here's the 'string' we'll encode/decode.
	*/
	data := "abc123!?$*&()'-=@~"
	data = "asldkfalskjdfalksdjfalk =-= - = -=sd1231231dfk"

	/*
		Go supports both standard and URL-compatible base64.
		Here's how to encode using the standard encoder. The
		encoder requires a '[]byte' so we convert our 'string'
		to that type.
	*/
	sEnc := base64.StdEncoding.EncodeToString([]byte(data))
	fmt.Println(sEnc)

	/*
		Decoding may return an error, which you can check if you
		don't already know the input to be well-formed.
	*/
	sDec, _ := base64.StdEncoding.DecodeString(sEnc)
	fmt.Println(string(sDec))
	// fmt.Printf("%s\n", sDec)
	fmt.Println()

	/*
		This encodes/decodes using a URL-compatible base64
		format.
	*/
	uEnc := base64.URLEncoding.EncodeToString([]byte(data))
	fmt.Println(uEnc)
	uDec, _ := base64.URLEncoding.DecodeString(uEnc)
	fmt.Println(string(uDec))
}
