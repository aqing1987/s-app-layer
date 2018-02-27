/*
 * It is common to append new elements to a slice, and so Go provides a built-in
 * `append` function.
 * The resulting value of append is a slice containing all the elements of the
 * original slice plus the provided values.
 */

package main

import "fmt"

func main() {
	var s []int
	printSlice(s)

	// append works on nil slices
	s = append(s, 0)
	printSlice(s)

	// the slice grows as needed
	s = append(s, 1)
	printSlice(s)

	// we can add more than one element at a time
	s = append(s, 2, 3, 4)
	printSlice(s)
}

func printSlice(s []int) {
	fmt.Printf("len = %d cap = %d %v\n", len(s), cap(s), s)
}