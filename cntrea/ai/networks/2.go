	// package main

	// type NodeIndex int

	// type NodeOp struct {
	//   Op func([]float64) float64
	// }

	// type Node struct {
	//     op NodeOp
	//     children []NodeIndex
	//     value float64
	// }

	// type NetworkData struct {
	//     nodes []Node
	//     valuesReady bool
	// }

	// type Network struct {
	//     data *NetworkData
	// }

func NewNetwork() Network{
	nodes := []Node{}
	valuesReady := true
	return Network{&NetworkData{nodes, valuesReady}}
}

func (net Network) NewNode(op NodeOp, children []NodeIndex) NodeIndex{
	n := NodeIndex(len(net.data.nodes))

	var cldn []NodeIndex
	var values []float64
	
	for _, u := range children{
		if (u >= n){
			panic(1)
		}else{
			cldn = append(cldn, u)
			values = append(values, net.data.nodes[u].value)
		}
	}

	if net.data.valuesReady{
		net.data.nodes = append(net.data.nodes, Node{op, cldn, op.Op(values)})
	}else{
		net.data.nodes = append(net.data.nodes, Node{op, cldn, 0})
	}

	return n
}

func (net Network) Value(u NodeIndex) float64{
	n := NodeIndex(len(net.data.nodes))

	if u >= n{
		panic(1)
	}

	if !net.data.valuesReady{
		for v := NodeIndex(0); v < n; v++{
			values := []float64{}
			for _, w := range net.data.nodes[v].children{
				values = append(values, net.data.nodes[w].value)
			}

			net.data.nodes[v].value = net.data.nodes[v].op.Op(values)
		}
	}
	net.data.valuesReady = true

	return net.data.nodes[u].value
}

func (net Network) SetOp(u NodeIndex, op NodeOp){
	n := NodeIndex(len(net.data.nodes))

	if u >= n{
		panic(1)
	}

	net.data.nodes[u].op = op
	net.data.valuesReady = false
}
