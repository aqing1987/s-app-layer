/*
 * You can declare methods with pointer receivers.
 *
 * This means the receiver type has the literal syntax *T for some type T.
 * (Also, T cannot itself be a pointer such as *int).
 *
 * Methods with pointer receivers can modify the value to which the receiver
 * points. Since methods often need to modify their receiver, pointer receivers
 * are more common than value receivers.
 */

package main

import (
	"fmt"
	"math"
)

type Vertex struct {
	X, Y float64
}

// With a value receiver, the `Abs` method operates on a copy of the original
// Vertex value.
func (v Vertex) Abs() float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

// The `Scale` method must have a pointer receiver to change the `Vertex` value
// declared in the main function.
func (v *Vertex) Scale(f float64) {
	v.X = v.X * f
	v.Y = v.Y * f
}

func main() {
	v := Vertex{3, 4}

	v.Scale(10)
	fmt.Println(v.Abs())
}