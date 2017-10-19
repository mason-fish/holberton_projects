func longest_word(text:String) -> (String) {
    let str_arr:Array = text.characters.split{$0 == " "}.map(String.init)
    var longest:String = ""
    for str in str_arr {
        if str.characters.count > longest.characters.count {
            longest = str
        }
    }
    return longest
}