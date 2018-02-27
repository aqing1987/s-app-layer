/*
 * Implement a fibonacci functio that returns a function (a closure) that
 * returns successive fibonacci numbers (0, 1, 1, 2, 3, 5, ...)
 */
package main

import "fmt"

// fibonacci is a function that returns a function that returns an int
func fibonacci() func() int {
	i := 0
	j := 1
	sum := 0
	return func() int {
		sum = i + j
		i = j
		j = sum

		return j - i
	}
}

func main() {
	f := fibonacci()
	for i := 0; i < 10; i++ {
		fmt.Println(f())
	}
}