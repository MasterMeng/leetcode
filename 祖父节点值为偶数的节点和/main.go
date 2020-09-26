package main

func main() {

}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var ans int

func dfs(gpVal, ppVal int, root *TreeNode) {
	if root == nil {
		return
	}
	if gpVal%2 == 0 {
		ans += root.Val
	}
	dfs(ppVal, root.Val, root.Left)
	dfs(ppVal, root.Val, root.Right)
}

func sumEvenGrandparent(root *TreeNode) int {
	ans = 0
	dfs(1, 1, root)
	return ans
}
