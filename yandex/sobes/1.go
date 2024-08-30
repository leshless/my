package main

import (
	"fmt"
	"slices"
)

// [1, 0, 2, 3, 0, 4] -> [1, 2, 3, 4, 0, 0]
func move_zeroes(nums []int) {
	n := len(nums)
	if n <= 1 {
		return
	}

	i := 0
	for j := 0; j < n; j++ {
		if nums[j] != 0 {
			nums[i], nums[j] = nums[j], nums[i]
			i++
		}
	}
}

func count_jars(nums []int, cap int) int {
	n := len(nums)
	if n == 0 {
		return 0
	}

	res := 1
	cur := 0

	for i := 0; i < n; i++ {
		if nums[i] > cap {
			return -1
		}
		if nums[i]+cur > cap {
			res++
			cur = nums[i]
		} else {
			cur += nums[i]
		}
	}

	return res
}

func reverse(nums []int) {
	n := len(nums)

	for i := 0; i < n/2; i++ {
		j := n - i - 1
		nums[i], nums[j] = nums[j], nums[i]
	}
}

type span struct {
	l int
	r int
}

func unition(spans []span) []span {
	n := len(spans)
	if n == 0 {
		return nil
	}

	slices.SortFunc(spans, func(a, b span) int {
		if a.l < b.l {
			return -1
		}
		if a.l > b.l {
			return 1
		}
		return 0
	})

	var res []span
	cur := spans[0]
	for i := 1; i < n; i++ {
		s := spans[i]
		if s.l <= cur.r {
			cur.r = s.r
		} else {
			res = append(res, cur)
			cur = s
		}
	}
	res = append(res, cur)

	return res
}

func subs_len(s string) int {
	present := make(map[rune]bool)
	for i := 'a'; i <= 'z'; i++ {
		present[i] = false
	}

	runes := []rune(s)
	n := len(runes)
	l := 0
	r := 0

	for {
		x := runes[r]
		if present[x] {

		} else {

		}
	}
}

func main() {
	myspans := []span{{2, 6}, {1, 3}, {8, 10}, {15, 18}}
	fmt.Println(unition(myspans))
}
