func factorial(N: Int) -> (Int) {
    if N == 0 {
        return 1
    }
    if N < 0 {
        return 0
    }
    if N == 1 {
        return 1
    }
    return N * factorial(N - 1)
}