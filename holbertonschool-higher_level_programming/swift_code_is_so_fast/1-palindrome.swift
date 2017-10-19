func is_palindrome(s: String) -> (Bool) {
    if String(s.characters.reverse()) == s {
        return true
    }
    return false
}