package main

func main() {

}
func maxSlidingWindow(nums []int, k int) []int {
	var res []int
	tmp := make([]int, k)

	if len(nums) == 0 {
		return nums
	}
	if k <= 0 {
		return res
	}

	for index,val := range nums{
		if index >= k && tmp[0] <= index-k{
			tmp = tmp[1:]
		}
		for len(tmp) >0 && nums[tmp[len(tmp)-1]] <= val{
			tmp = tmp[:(len(tmp)-1)]
		}
		tmp = append(tmp,index)

		if index >= k-1{
			res = append(res,nums[tmp[0]])
		}
	}

	return res
}
