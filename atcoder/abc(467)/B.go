package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	if !scanner.Scan() {
		return
	}
	line := scanner.Text()
	n, err := strconv.Atoi(line)
	if err != nil {
		panic(err)
	}
	var sum int
	for i := 1; i <= n; i++ {
		scanner.Scan()
		line = scanner.Text()
		input := strings.Fields(line)
		a, err := strconv.Atoi(input[0])
		if err != nil {
			panic(err)
		}
		b, err := strconv.Atoi(input[1])
		if err != nil {
			panic(err)
		}
		c := b - a
		if input[2] == "keep" {
			sum += c
		}
	}
	fmt.Println(sum)
}
