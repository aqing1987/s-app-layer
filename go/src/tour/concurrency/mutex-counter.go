/*
 * What if we just want to make sure only one goroutine can access a variable
 * at a time to avoid conflicts?
 * This concept is called `mutual exclusion', and the conventional name for the
 * data structure that provides it is `mutex'.
 *
 * Go's standard library provides mutual exclusion with `sync.Mutex' and its
 * two methods:
 *   Lock
 *   Unlock
 *
 * We can also use `defer' to ensure the mutex will be unlocked as in the
 * `Value' method.
 */
package main

import (
	"fmt"
	"sync"
	"time"
)

// SafeCounter is safe to use concurrently
type SafeCounter struct {
	v map[string]int
	mux sync.Mutex
}

// Inc increments the counter for the given key
func (c *SafeCounter) Inc(key string) {
	c.mux.Lock()
	// Lock so only one goroutine at a time can access the map c.v
	c.v[key]++
	c.mux.Unlock()
}

// Value returns the current value of the counter for the given key
func (c *SafeCounter) Value(key string) int {
	c.mux.Lock()
	defer c.mux.Unlock()

	return c.v[key]
}

func main() {
	c := SafeCounter{v: make(map[string]int)}
	for i := 0; i < 1000; i ++ {
		go c.Inc("somekey")
	}

	time.Sleep(time.Second)
	fmt.Println(c.Value("somekey"))
}