/*
 * C's `while` is spelled `for` in Go.
 *
 * At that point you can drop the semicolons.
 */

package main

import "fmt"

func main() {
	sum := 1
	for sum < 1000 {
		sum += sum
	}

	fmt.Println(sum)
}