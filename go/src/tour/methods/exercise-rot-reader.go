/*
 * A common pattern is an io.Reader that wraps another io.Reader, modifying
 * the stream in some way.
 */

package main

import (
	"io"
	"os"
	"strings"
)

//from the wikipedia article linked:
var enc = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
var dec = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm"

type rot13Reader struct {
	r io.Reader
}

// Implement a rot13Reader that implementations io.Reader and reads from an
// io.Reader, modifying the stream by applying the rot13 substituion cipher to
// all alphabetical characters.
func (rot rot13Reader) Read(bytes []byte) (n int, err error) {
	n, err = rot.r.Read(bytes)

	for i := 0; i < n; i++ {
		if j := strings.IndexByte(enc, bytes[i]); j >= 0 {
			bytes[i] = dec[j]
		}
	}

	return
}

func main() {
	s := strings.NewReader("Lbh penpxrq gur pbqr!\n")
	r := rot13Reader{s}
	io.Copy(os.Stdout, &r)
}