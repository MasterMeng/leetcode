package main

func longestConsecutive(nums []int) int {
	numSet := map[int]bool{}
	for _, val := range nums {
		numSet[val] = true
	}

	longest := 0

	for num := range numSet {
		if !numSet[num-1] {
			cur := num
			step := 1
			for numSet[cur+1] {
				cur++
				step++
			}
			if longest < step {
				longest = step
			}
		}
	}
	return longest
}

func main() {

}
