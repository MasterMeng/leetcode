// 根据C++实现修改而来
package main

var visitCount int = 0

func canVisitAllRooms(rooms [][]int) bool {
	n := len(rooms)
	vis := make([]bool, n)
	visitCount = 0
	dfs(rooms, 0, vis)
	return visitCount == n
}

func dfs(rooms [][]int, index int, vis []bool) {
	vis[index] = true
	visitCount++
	for _, key := range rooms[index] {
		if !vis[key] {
			dfs(rooms, key, vis)
		}
	}
}

func main() {

}
