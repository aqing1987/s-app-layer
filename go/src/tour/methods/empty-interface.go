/*
 * The interface type that specifies zero methods is known as the empty
 * interface:
 *   interface{}
 *
 * An empty interface may hold values of any type. (every type implements at
 * least zero methods.)
 *
 * Empty interfaces are used by code that handles values of unknown type.
 */

package main

import "fmt"

func main() {
	var i interface{}
	describe(i)

	i = 42
	describe(i)

	i = "hello"
	describe(i)
}

// fmt.Print takes any number of arguments of type interface{}
func describe(i interface{}) {
	fmt.Printf("(%v, %T)\n", i, i)
}