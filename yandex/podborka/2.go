package main

import (
	"fmt"
	"math/big"
	"slices"
)

func Gcd(a, b int) int {
	for {
		if b == 0 {
			break
		}
		a, b = b, a%b
	}
	return a
}

func main() {
	var n int
	fmt.Scan(&n)

	triangles := map[*big.Int]bool{}
	for i := 0; i < n; i++ {
		sides := make([]int, 3)
		for j := 0; j < 3; j++ {
			fmt.Scan(&sides[j])
		}
		slices.Sort(sides)

		gcd := Gcd(Gcd(sides[0], sides[1]), sides[2])
		a := float64(sides[0] / gcd)
		b := float64(sides[1] / gcd)
		c := float64(sides[2] / gcd)

		hash := 
	}

	fmt.Println(len(triangles))
}
