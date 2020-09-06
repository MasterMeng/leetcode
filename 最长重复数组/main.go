package main

func main() {

}

func findLength(A []int, B []int) int {
	ret := 0
	n, m := len(A), len(B)

	for i := 0; i < n; i++ {
		len := min(m, n-i)
		maxLen := maxLength(A, B, i, 0, len)
		ret = max(ret, maxLen)
	}
	for i := 0; i < m; i++ {
		len := min(n, m-i)
		maxLen := maxLength(A, B, 0, i, len)
		ret = max(ret, maxLen)
	}

	return ret
}

func maxLength(A, B []int, a, b, len int) int {
	ret, k := 0, 0
	for i := 0; i < len; i++ {
		if A[a+i] == B[b+i] {
			k++
		} else {
			k = 0
		}
		ret = max(ret, k)
	}
	return ret
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b

}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b

}
