package main

var ans [][]int
var res [] int

func combinationSum(candidates []int, target int) [][]int {
	ans = make([][]int,0)
	res = make([]int,0)
	dfs(candidates,target,0)
	return ans
}

func dfs(candidates []int,target,index int){
	if target == 0{
		tmp := make([]int,len(res))
		copy(tmp,res)
		ans = append(ans,tmp)
		return
	}
	if target < 0{
		return
	}
	for i := index;i<len(candidates);i++{
		res = append(res,candidates[i])
		dfs(candidates,target-candidates[i],i)
		res = res[:len(res)-1]
	}
}

func main() {
	
}