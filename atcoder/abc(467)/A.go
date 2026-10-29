package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	h, err := strconv.Atoi(scanner.Text())
	if err != nil {
		panic(err)
	}

	scanner.Scan()
	w, err := strconv.Atoi(scanner.Text())
	if err != nil {
		panic(err)
	}

	w *= 10000

	bmi := w / h / h
	if bmi >= 25 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
