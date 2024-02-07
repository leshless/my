// package main

// type NodeIndex int

// type NodeOp struct {
// 	Op func([]float64) float64
// 	Grad func([]float64) []float64
// }

// type Node struct {
// 	op NodeOp
// 	children []NodeIndex
// 	value float64
// 	derivative float64
// }

// type NetworkData struct {
// 	nodes []Node
// 	valuesReady bool
// }

// type Network struct {
// 	data *NetworkData
// }

// func NewNetwork() Network{
// 	nodes := []Node{}
// 	valuesReady := true
// 	return Network{&NetworkData{nodes, valuesReady}}
// }

// func (net Network) Value(u NodeIndex) float64{
// 	n := NodeIndex(len(net.data.nodes))

// 	if u >= n{
// 		panic(1)
// 	}

// 	if !net.data.valuesReady{
// 		for v := NodeIndex(0); v < n; v++{
// 			values := []float64{}
// 			for _, w := range net.data.nodes[v].children{
// 				values = append(values, net.data.nodes[w].value)
// 			}

// 			net.data.nodes[v].value = net.data.nodes[v].op.Op(values)
// 		}
// 	}
// 	net.data.valuesReady = true

// 	return net.data.nodes[u].value
// }

// func (net Network) SetOp(u NodeIndex, op NodeOp){
// 	n := NodeIndex(len(net.data.nodes))

// 	if u >= n{
// 		panic(1)
// 	}

// 	net.data.nodes[u].op = op
// 	net.data.valuesReady = false
// }

// func (net Network) CalculateDerivativesOf(u NodeIndex){
// 	n := NodeIndex(len(net.data.nodes))

// 	if u >= n{
// 		panic(1)
// 	}

// 	for v := NodeIndex(0); v < n; v++{
// 		if v == u{
// 			net.data.nodes[v].derivative = 1
// 		}else{
// 			net.data.nodes[v].derivative = 0
// 		}
// 	}

// 	for v := u; v >= NodeIndex(0); v--{
// 		values := []float64{}
// 		for _, w := range net.data.nodes[v].children{
// 			values = append(values, net.Value(w))
// 		}

// 		grad := net.data.nodes[v].op.Grad(values)
// 		for i, w := range net.data.nodes[v].children{
// 			net.data.nodes[w].derivative += net.data.nodes[v].derivative * grad[i]
// 		}
// 	}
// }

// func (net Network) Derivative(u NodeIndex) float64{
// 	n := NodeIndex(len(net.data.nodes))

// 	if u >= n{
// 		panic(1)
// 	}

// 	return net.data.nodes[u].derivative
// }

// func (net Network) SetValues(weights map[NodeIndex]float64) {
//     for idx := range weights {
//         i := idx

//         net.SetOp(i, NodeOp {
//             Op: func([]float64) float64 {
//                 return weights[i]
//             },

//             Grad: func(xs []float64) []float64 {
//                 return make([]float64, len(xs))
//             },
//         })
//     }
// }

// func (net Network) ValuesChanged() {
//     net.data.valuesReady = false
// }

// func (net Network) Optimize(weights map[NodeIndex]float64, target NodeIndex, rate float64){
// 	net.SetValues(weights)
// 	net.ValuesChanged()

// 	net.CalculateDerivativesOf(target)
// 	for u := range weights{
// 		weights[u] -= net.Derivative(u) * rate
// 	}
// }

func (net Network) AdaptiveOptimize(weights map[NodeIndex]float64, target NodeIndex, rate float64) float64{
	net.CalculateDerivativesOf(target)
	
	oldf := net.Value(target)
	oldweights := map[NodeIndex]float64{}
	for u, w := range weights{
		oldweights[u] = w
	} 

	for i := 0; i < 21; i++{
		for u := range weights{
			weights[u] = oldweights[u] - net.Derivative(u) * rate
		}
		net.ValuesChanged()

		f := net.Value(target)
		if f < oldf{
			return rate
		}	

		rate /= 2
	}

	return 0
}