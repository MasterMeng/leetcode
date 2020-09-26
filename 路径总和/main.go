package main

func main() {

}

// TreeNode struct define
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 声明两个全局变量用来保存结果
// ans保存所有满足条件的路径
var ans [][]int

// path保存一条满足条件的路径
var path []int

// 深度搜索优先，递归调用
func dfs(root *TreeNode, sum int) {
	if root == nil {
		return
	}
	path = append(path, root.Val)
	sum -= root.Val
	if root.Left == nil && root.Right == nil && sum == 0 {
		// path是全局共享的
		tmp := make([]int, len(path))
		copy(tmp, path)
		ans = append(ans, tmp)
	}
	dfs(root.Left, sum)
	dfs(root.Right, sum)
	path = path[:len(path)-1]
}

func pathSum(root *TreeNode, sum int) [][]int {
	ans = [][]int{}
	path = []int{}
	dfs(root, sum)
	return ans
}
