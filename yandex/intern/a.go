package main

import (
	"fmt"
	"strings"
)

func main() {
	var sb strings.Builder

	for {
		var s string
		n, _ := fmt.Scan(&s)
		if n == 0 {
			break
		}

		if s[0] != ',' && sb.Len() != 0 {
			sb.WriteString(" ")
		}
		sb.WriteString(s)
	}

	s := []rune(sb.String())
	sb.Reset()

	mx := 0
	cur := 0
	for i := range s {
		sb.WriteRune(s[i])
		if i != len(s)-1 && s[i] == ',' && s[i+1] != ' ' {
			sb.WriteRune(' ')
		}

		if s[i] == ',' || s[i] == ' ' {
			cur = 0
		} else {
			cur += 1
		}
		if cur > mx {
			mx = cur
		}
	}
	mx *= 3

	ss := strings.Split(sb.String(), " ")
	var res strings.Builder
	cur = 0

	for i, s := range ss {
		if cur != 0 {
			// нужен пробел
			if cur+len(s)+1 > mx {
				res.WriteRune('\n')
				res.WriteString(s)
				cur = len(s)
			} else {
				res.WriteRune(' ')
				res.WriteString(s)
				cur += 1 + len(s)
			}
		} else {
			// не нужен пробел
			res.WriteString(s)
			cur += len(s)
		}

		if cur == mx && i != len(ss)-1 {
			res.WriteRune('\n')
			cur = 0
		}
	}

	fmt.Println(res.String())
}
