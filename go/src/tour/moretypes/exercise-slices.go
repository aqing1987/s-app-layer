package main

import "golang.org/x/tour/pic"

func Pic(dx, dy int) [][]uint8 {

	// allocate two-dimensional array
	a := make([][]uint8, dy)

	for i := range a {
		a[i] = make([]uint8, dx)
	}

	// do something
	for i := range a {
		for j := range a[i] {
			a[i][j] = uint8((dx+dy)/2)
		}
	}

	return a
}

func main() {
	pic.Show(Pic)
}