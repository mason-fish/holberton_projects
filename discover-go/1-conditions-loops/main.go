package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	s := rand.NewSource(time.Now().UnixNano())
	r := rand.New(s)

	randomNumber := r.Intn(100)
	school := "Holberton School"
	beautifulWeather := true
	holbertonFounders := [3]string{"Rudy Rigot", "Sylvain Kalache", "Julien Barbier"}

	if randomNumber > 50 {
		fmt.Printf("my random number is %d and is greater than 50\n", randomNumber)
	} else {
		fmt.Printf("my random number is %d and is less than 50\n", randomNumber)
	}

	if school == "Holberton School" {
		fmt.Println("I am a student of the Holberton School")
	} else {
		fmt.Println("I am a student of the Holberton School")
	}

	if beautifulWeather {
		fmt.Println("It's a beautiful weather!")
	} else {
		fmt.Println("It's a terrible weather!")
	}

	for _, x := range holbertonFounders {
		fmt.Printf("%s is a founder\n", x)
	}

}
