/*
 * Go has only one looping construct, the for loop.
 *
 * Note: there are no parentheses surrounding the three components of the
 * for statement and the braces {} are always required.
 */

package main

import "fmt"

func main() {
	sum := 0
	for i := 0; i < 10; i++ {
		sum += i
	}
	fmt.Println(sum)
}