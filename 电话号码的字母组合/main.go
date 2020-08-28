// 根据C++版实现修改而来
package main

import "fmt"

var phoneMap map[string]string = map[string]string{
	"2": "abc",
	"3": "def",
	"4": "ghi",
	"5": "jkl",
	"6": "mno",
	"7": "pqrs",
	"8": "tuv",
	"9": "wxyz",
}

var combinations []string

func letterCombinations(digits string) []string {
	if len(digits) == 0 {
		return []string{}
	}
	combinations = []string{}
	backtrack(digits, "", 0)
	return combinations
}

func backtrack(digits, combination string, index int) {
	if index == len(digits) {
		combinations = append(combinations, combination)
	} else {
		digit := string(digits[index])
		letters := phoneMap[digit]
		for i := 0; i < len(letters); i++ {
			backtrack(digits, combination+string(letters[i]), index+1)
		}
	}

}

func main() {
	res := letterCombinations("23")
	for _, re := range res {
		fmt.Println(re)
	}
}
