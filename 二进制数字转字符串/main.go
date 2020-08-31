package main

func main() {

}

func printBin(num float64) string {
	res := "0."

	// for num != float64(0) {
	// 	num *= 2
	// 	if num >= 1 {
	// 		res += "1"
	// 		num--
	// 	} else {
	// 		res += "0"
	// 	}
	// 	if len(res) > 32 {
	// 		return "ERROR"
	// 	}
	// }

	i := 0
	for i < 30 {
		num *= 2
		if num >= 1 {
			res += "1"
			num--
		} else {
			res += "0"
		}
		if num == 0 {
			break
		}
		i++
	}
	if num != 0 {
		return "ERROR"
	}
	return res

}
