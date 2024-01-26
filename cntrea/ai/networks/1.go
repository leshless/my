// package main

// type NodeIndex int

// type Node struct {
// 	op       func([]float64) float64
// 	children []NodeIndex
// }

// type Network struct {
// 	nodes *[]Node
// }

func (net Network) NewNode(op func([]float64) float64, children []NodeIndex) NodeIndex{
	var cldn []NodeIndex
	n := NodeIndex(len(*net.nodes))
	
	for _, u := range children{
		if (u >= n){
			panic(1)
		}else{
			cldn = append(cldn, u)
		}
	}
	
	*net.nodes = append(*net.nodes, Node{op, cldn})

	return n
}

func NewNetwork() Network{
	var nodes []Node
	return Network{&nodes}
}
