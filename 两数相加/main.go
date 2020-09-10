package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	s1, s2, carry := pushStack(l1), pushStack(l2), 0
	var ret *ListNode
	for len(*s1) > 0 || len(*s2) > 0 {
		carry += popStack(s1) + popStack(s2)
		ret, carry = &ListNode{Val: carry % 10, Next: ret}, carry/10
	}
	if carry != 0 {
		ret = &ListNode{Val: carry, Next: ret}
	}
	return ret
}

func pushStack(head *ListNode) *[]int {
	stack := new([]int)
	ptr := head
	for ptr != nil {
		*stack = append(*stack, ptr.Val)
		ptr = ptr.Next
	}
	return stack
}

func popStack(stack *[]int) (pop int) {
	if len(*stack) > 0 {
		pop = (*stack)[len(*stack)-1]
		*stack = (*stack)[0 : len(*stack)-1]
	}
	return
}

func main() {

}
