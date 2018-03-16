package main

import (
	"fmt"
	"math"
)

type ErrNegativeSqrt float64

func (e ErrNegativeSqrt) Error() string {
	return fmt.Sprintf("cannot Sqrt negative number: %v", float64(e))
}

// Sqrt should return a non-nil error value when given a negative number, as
// it doesn't support complex numbers.
func Sqrt(x float64) (float64, error) {

	if x < 0 {
		return x, ErrNegativeSqrt(x)
	}

	Delta := 1e-3
	// x is input, g is the guess
	g := float64(1)
	for {
		// t, what we're looking at
		t := g - (g*g - x)/2 * g
		// d is the delta
		if d := math.Abs(g-t); d < Delta {
			return t, nil
			break
		}
		g = t
	}

	return g, nil
}

func main() {
	fmt.Println(Sqrt(2))
	fmt.Println(Sqrt(-2))
}