// lang: golang
func coloredCells(n int) int64 {
    ans := int64(1)
    for i := 2; i <= n; i++ {
        ans += int64(i-1) * 4
    }
    return ans
}