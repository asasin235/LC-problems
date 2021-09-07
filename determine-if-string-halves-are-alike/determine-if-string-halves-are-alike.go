func halvesAreAlike(s string) bool {
    half := len(s) / 2
    ctr := 0
    for i,r := range s {
        switch r {
            case 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U':
                if i < half {
                    ctr++
                } else {
                    ctr--
                }
        }
    }
    return ctr == 0
}