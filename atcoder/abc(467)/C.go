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
	n, err := strconv.Atoi(scanner.Text())
	if err != nil {
		panic(err)
	}
	scanner.Scan()
	_, err = strconv.Atoi(scanner.Text())
	if err != nil {
		panic(err)
	}
	a := make([]int, n)
	b := make([]int, n-1)
	for i := 0; i < n; i++ {
		scanner.Scan()
		a[i], err = strconv.Atoi(scanner.Text())
		if err != nil {
			panic(err)
		}
	}
	for i := 0; i < n-1; i++ {
		scanner.Scan()
		b[i], err = strconv.Atoi(scanner.Text())
		if err != nil {
			panic(err)
		}
	}
	dp := [2]int{0, 1}
	for i := 0; i < n-1; i++ {
		ndp := [2]int{1e9, 1e9}
		val := a[i] ^ a[i+1] ^ b[i]
		for x := 0; x < 2; x++ {
			y := x ^ val
			ndp[y] = min(ndp[y], dp[x]+y)
		}
		dp = ndp
	}
	fmt.Println(min(dp[0], dp[1]))
}
