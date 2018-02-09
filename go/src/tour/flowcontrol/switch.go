/*
 * 1. do not need `break` statement anymore
 * 2. Go's switch cases need not be constants, and the values involved need
 * not be integers.
 */

package main

import (
	"fmt"
	"runtime"
)

func main() {
	fmt.Print("Go runs on ")
	switch os := runtime.GOOS; os {
	case "darwin":
		fmt.Println("OS X.")
	case "linux":
		fmt.Println("Linux.")
	default:
		// freebsd, openbsd, plan9, windows ...
		fmt.Printf("%s.", os)
	}
}