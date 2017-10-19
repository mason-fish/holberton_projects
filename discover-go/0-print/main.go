package main

import "fmt"
import "time"

func main() {
	t := time.Now()

	fmt.Println("Hello, we are Holberton School")
	fmt.Println("the date is", t.Format("2006-01-02 15:04:05.999999999 Z0700 MST"))
	fmt.Println("the year is", t.Format("2006"))
	fmt.Println("the month is", t.Format("January"))
	fmt.Println("the day is", t.Format("2"))

}
