// lang: golang
func findMissingAndRepeatedValues(grid [][]int) []int {
    n := len(grid)
    fmt.Println(n)
    freq := make([]int, n*n+1)
    double, missing := 0,0
    for _, row := range grid {
        for _, no := range row {
            freq[no]++
            if freq[no] == 2 {
                double = no
            }
        }
    }
    for i := range n*n+1 {
        fmt.Println(i)
        if freq[i] == 0 {
            missing = i
        }
    }

    return []int{double, missing}
}