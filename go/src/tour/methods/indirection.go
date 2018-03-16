/*
 * functions with a pointer argument must take a pointer
 * while methods with pointer receivers take either a value or a pointer as the
 * receiver when they are called
 */

package main

import "fmt"

type Vertex struct {
	X, Y float64
}

func (v *Vertex) Scale(f float64) {
	v.X = v.X * f
	v.Y = v.Y * f
}

func ScaleFunc(v *Vertex, f float64) {
	v.X = v.X * f
	v.Y = v.Y * f
}

func main() {
	v := Vertex{3, 4}
	// even though v is a value and not a pointer, the method with the pointer
	// receiver is called automatically. That is, as a convenience, Go
	// interprets the statement `v.Scale(2)` as `(&v).Scale(2)` since the
	// `Scale` method has a pinter receiver.
	v.Scale(2)
	ScaleFunc(&v, 10)

	p := &Vertex{4, 3}
	p.Scale(3)
	ScaleFunc(p, 8)

	fmt.Println(v, p)
}