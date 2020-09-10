package main

func longestValidParentheses(s string) int {
	var ret int
	stack := []int{}
	stack = append(stack, -1)
	for i := 0; i < len(s); i++ {
		if s[i] == '(' {
			stack = append(stack, i)
		} else {
			stack = stack[:len(stack)-1]
			if len(stack) == 0 {
				stack = append(stack, i)
			} else {
				ret = max(ret, i-stack[len(stack)-1])
			}
		}
	}
	return ret
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {

}
