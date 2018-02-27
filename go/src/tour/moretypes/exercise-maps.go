package main

import (
	"golang.org/x/tour/wc"
	"strings"
)

// return a map of the counts of each "word" in the string s
func WordCount(s string) map[string]int {
	m := make(map[string]int)
	a := strings.Fields(s)

	for _, v := range a {
		m[v]++
	}

	return m
}

func main() {
	wc.Test(WordCount)
}