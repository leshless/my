package main

import (
	"fmt"
	"math"
	"slices"
)

func main() {

	var n int
	fmt.Scan(&n)

	nums := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&nums[i])
	}

	slices.Sort(nums)

	pref := make([]int64, n)
	pref[0] = nums[0]
	for i := 1; i < n; i++ {
		pref[i] = pref[i-1] + nums[i]
	}

	sum := pref[n-1]
	res := int64(math.MaxInt64)
	for i := 1; i < n; i++ {
		left := nums[i]*int64(i+1) - pref[i]
		right := nums[n-1]*int64(n-i-1) - (sum - pref[i])
		if res > left+right {
			res = left + right
		}
	}

	if res == math.MaxInt {
		res = 0
	}
	fmt.Println(res)
}
