/*
 * The `default' case in a `select' is run if no other case is ready.
 * Use a `default' case to try a send or receive without blocking
 */

package main

import (
	"fmt"
	"time"
)

func main() {
	// func Tick(d Duration) <-chan Time
	// Tick is a convenience wrapper for NewTicker providing access to the
	// ticking channel only.
	tick := time.Tick(100 * time.Millisecond)

	// func After(d Duration) <-chan Time
	// After waits for the duration to elapse and then sends the current time
	// on the returned channel.
	boom := time.After(500 * time.Millisecond)

	for {
		select {
		case <- tick:
			fmt.Println("tick.")
		case <- boom:
			fmt.Println("BOOM!")
			return
		default:
			fmt.Println("    .")
			time.Sleep(50 * time.Millisecond)
		}
	}
}