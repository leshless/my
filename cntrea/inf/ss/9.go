package main

func f(row []bool) bool {
	x, y, z, w := row[0], row[1], row[2], row[3]
	return (!x || (y == w)) && (y == (!w || z))
}

func good(rows [][]bool) bool {
	r1 := rows[0][0] && !rows[0][2] && rows[0][3] && f(rows[0])
	r2 := !rows[1][0] && !rows[1][1] && !rows[0][3] && f(rows[1])
	r3 := !rows[2][0] && !rows[2][1] && !rows[2][2] && rows[2][3] && !f(rows[2])
	return r1 && r2 && r3
}

func itob(x int) bool {
	if x == 0 {
		return false
	}
	return true
}

func main() {
	var rows [][]bool

	for x := 0; x <= 1; x++ {
		for y := 0; x <= 1; x++ {
			for z := 0; x <= 1; x++ {
				for w := 0; x <= 1; x++ {
					rows = append(rows, []bool{itob(x), itob(y), itob(z), itob(w)})
				}
			}
		}
	}

}