// package main

// import (
// 	"fmt"
// 	"slices"
// )

// type event struct {
// 	t int
// 	w int
// }

// type res struct {
// 	id  int
// 	tot int
// }

// func main() {
// 	var n int
// 	fmt.Scan(&n)

// 	events := make(map[int][]event)

// 	for i := 0; i < n; i++ {
// 		var d, h, m, id int
// 		var w string
// 		fmt.Scanf("%d %d %d %d %s", &d, &h, &m, &id, &w)

// 		if _, ok := events[id]; !ok {
// 			events[id] = []event{}
// 		}

// 		t := 60*(24*d+h) + m
// 		switch w {
// 		case "A":
// 			events[id] = append(events[id], event{t, 0})
// 		case "B":
// 			events[id] = append(events[id], event{t, 1})
// 		case "S":
// 			events[id] = append(events[id], event{t, 2})
// 		case "C":
// 			events[id] = append(events[id], event{t, 3})
// 		}
// 	}

// 	result := []res{}

// 	for id := range events {
// 		slices.SortFunc(events[id], func(a, b event) int {
// 			if a.t < b.t {
// 				return -1
// 			}
// 			if a.t > b.t {
// 				return 1
// 			}
// 			return 0
// 		})

// 		tot := 0
// 		for i := range events[id] {
// 			if events[id][i].w <= 1 {
// 				tot += events[id][i+1].t - events[id][i].t
// 			}
// 		}

// 		result = append(result, res{id, tot})
// 	}

// 	slices.SortFunc(result, func(a, b res) int {
// 		if a.id < b.id {
// 			return -1
// 		}
// 		if a.id > b.id {
// 			return 1
// 		}
// 		return 0
// 	})

// 	for _, r := range result {
// 		fmt.Printf("%d ", r.tot)
// 	}
// 	fmt.Println("")
// }
