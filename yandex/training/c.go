// package main

// import (
// 	"fmt"
// 	"strings"
// )

// var tree map[int]*vertex

// type vertex struct {
// 	x  int
// 	p  *vertex
// 	lc *vertex
// 	rc *vertex
// }

// func (v *vertex) build(n int) {
// 	tree[v.x] = v
// 	if v.x*2 <= n {
// 		v.lc = &vertex{v.x * 2, v, nil, nil}
// 		v.lc.build(n)
// 	}
// 	if v.x*2+1 <= n {
// 		v.rc = &vertex{v.x*2 + 1, v, nil, nil}
// 		v.rc.build(n)
// 	}
// }

// func (v *vertex) swap() {
// 	p := v.p
// 	if p == nil {
// 		return
// 	}
// 	pp := p.p

// 	v.p = pp
// 	if pp != nil {
// 		if pp.lc == p {
// 			pp.lc = v
// 		} else {
// 			pp.rc = v
// 		}
// 	}

// 	if v == p.lc {
// 		vl := v.lc

// 		v.lc = p
// 		p.lc = vl

// 		p.p = v
// 		if vl != nil {
// 			vl.p = p
// 		}
// 	} else {
// 		vr := v.rc

// 		v.rc = p
// 		p.rc = vr

// 		p.p = v
// 		if vr != nil {
// 			vr.p = p
// 		}
// 	}
// }

// func (v *vertex) getres(res *strings.Builder) {
// 	if v.lc != nil {
// 		v.lc.getres(res)
// 	}
// 	res.WriteString(fmt.Sprintf("%v ", v.x))
// 	if v.rc != nil {
// 		v.rc.getres(res)
// 	}
// }

// func main() {
// 	var n, q int
// 	fmt.Scanf("%d %d", &n, &q)

// 	tree = make(map[int]*vertex)

// 	root := &vertex{1, nil, nil, nil}
// 	root.build(n)

// 	for i := 0; i < q; i++ {
// 		var v int
// 		fmt.Scan(&v)
// 		tree[v].swap()
// 	}

// 	for i := 1; i <= n; i++ {
// 		v := tree[i]
// 		if v.p == nil {
// 			root = v
// 			break
// 		}
// 	}

// 	res := &strings.Builder{}
// 	root.getres(res)

// 	fmt.Println(res)
// }
