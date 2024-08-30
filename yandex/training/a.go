// package main

// import (
// 	"fmt"
// 	"strconv"
// 	"strings"
// )

// func main() {
// 	var n int
// 	fmt.Scan(&n)

// 	var res []string
// 	for j := 0; j < n; j++ {
// 		var s string
// 		fmt.Scan(&s)

// 		w := strings.Split(s, ",")
// 		f := w[0]
// 		i := w[1]
// 		o := w[2]
// 		d, _ := strconv.Atoi(w[3])
// 		m, _ := strconv.Atoi(w[4])

// 		cnt := make(map[rune]bool)
// 		for _, x := range f {
// 			cnt[x] = true
// 		}
// 		for _, x := range i {
// 			cnt[x] = true
// 		}
// 		for _, x := range o {
// 			cnt[x] = true
// 		}
// 		x1 := len(cnt)

// 		x2 := 64 * (d%10 + d/10 + m%10 + m/10)

// 		x3 := int(256 * ([]rune(f)[0] - rune('A') + 1))

// 		x := fmt.Sprintf("%X", x1+x2+x3)
// 		res = append(res, x[len(x)-3:])
// 	}

// 	for _, s := range res {
// 		fmt.Printf("%s ", s)
// 	}
// 	fmt.Println("")
// }
