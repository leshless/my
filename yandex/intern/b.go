package main

import (
	"fmt"
	"math"
	"strings"
)

type node struct {
	x   int
	nbs map[rune]*node
}

func (n *node) add(w []rune, i int, x int) {
	if i == len(w) {
		n.x = x
		return
	}

	r := w[i]
	next, ok := n.nbs[r]

	if !ok {
		next = &node{math.MaxInt, map[rune]*node{}}
		n.nbs[r] = next
	}

	next.add(w, i+1, x)
	if next.x < n.x {
		n.x = next.x
	}
}

func (n *node) get(p []rune, i int) int {
	if i == len(p) {
		return n.x
	}

	r := p[i]
	next, ok := n.nbs[r]
	if ok {
		return next.get(p, i+1)
	} else {
		return -1
	}
}

func main() {
	var n, q int
	fmt.Scan(&n)
	fmt.Scan(&q)

	trie := &node{math.MaxInt, map[rune]*node{}}
	var words [][]rune

	for i := 0; i < n; i++ {
		var w string
		fmt.Scan(&w)

		trie.add([]rune(w), 0, i)
		words = append(words, []rune(w))
	}

	var res strings.Builder
	for i := 0; i < q; i++ {
		var k int64
		var p string
		fmt.Scan(&k)
		fmt.Scan(&p)

		if i != 0 {
			res.WriteRune('\n')
		}

		j := int64(trie.get([]rune(p), 0))
		if j == -1 || j == math.MaxInt {
			res.WriteString(fmt.Sprintf("%d", -1))
			continue
		}

		j += k - 1
		if j >= int64(n) {
			res.WriteString(fmt.Sprintf("%d", -1))
			continue
		}

		w := string(words[j])
		if !strings.HasPrefix(w, p) {
			res.WriteString(fmt.Sprintf("%d", -1))
			continue
		}

		res.WriteString(fmt.Sprintf("%d", j+1))
	}

	fmt.Println(res.String())
}
