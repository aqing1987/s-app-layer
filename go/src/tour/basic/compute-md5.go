package main

import (
		"fmt"

		"os"
		"crypto/md5"
		"io"

		//"user/stringutil"
)

func ComputeMd5(filePath string) ([]byte, error) {
	var result []byte
	file, err := os.Open(filePath)
	if err != nil {
		return result, err
	}
	defer file.Close()

	hash := md5.New()
	if _, err := io.Copy(hash, file); err != nil {
		return result, err
	}

	return hash.Sum(result), nil
}

func main() {

		if b, err := ComputeMd5("./hello.go"); err != nil {
			fmt.Printf("Err: %v", err)
		} else {
			fmt.Println(string(b));
		}
		fmt.Printf("Hello, world.\n")
		//fmt.Printf(stringutil.Reverse("!oG, olleH"))
}
