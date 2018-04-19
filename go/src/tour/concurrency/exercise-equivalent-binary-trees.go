package main

import (
	"golang.org/x/tour/tree"
	"fmt"
)

// A Tree is a binary tree with integer values
// type Tree struct {
// 	Left *Tree
// 	Value int
// 	Right *Tree
// }

// Walk walks the tree t sending all values
// from the tree to the channel ch.
func Walk(t *tree.Tree, ch chan int) {
	recursiveWalk(t, ch)
	close(ch)
}

func recursiveWalk(t *tree.Tree, ch chan int) {
	if t == nil {
		return
	}
	recursiveWalk(t.Left, ch)
	ch <- t.Value
	recursiveWalk(t.Right, ch)
}

// Same determines whether the trees
// t1 and t2 contain the same values.
func Same(t1, t2 *tree.Tree) bool {
	ch1 := make(chan int, 10)
	ch2 := make(chan int, 10)

	go Walk(t1, ch1)
	go Walk(t2, ch2)

	for v1 := range ch1 {
		v2 := <- ch2
		fmt.Println("v1,v2 - ", v1, v2)
		if v1 != v2 {
			return false
		}
	}
	return true
}

func main() {
	// func New(k int) *Tree
	// New returns a new, random binary tree holding the values
	// k, 2k, ..., 10k.
	fmt.Println(Same(tree.New(1), tree.New(1)))
	fmt.Println(Same(tree.New(1), tree.New(2)))
}
