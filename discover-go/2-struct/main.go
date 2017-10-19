package main

import (
	"fmt"
	"time"
)

type user struct {
	Name string
	DOB  string `json:"date_of_birth"`
	City string
}

func main() {

	u := user{
		Name: "Betty Holberton",
		DOB:  "March 7, 1917",
		City: "Philadelphia",
	}

	hi(u)
	birth(u)
}

func hi(u user) {
	fmt.Println("Hello " + u.Name)

	return
}

func birth(u user) error {
	pa, err := time.Parse("January 2, 2006", u.DOB)
	if err != nil {
		return err
	}
	diff := time.Since(pa)
	amt := int(diff.Hours() / 24 / 365)
	fmt.Printf("%s who was born in %s would be %d years old today.\n", u.Name, u.City, amt)

	return nil
}
