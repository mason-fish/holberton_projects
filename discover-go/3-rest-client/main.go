package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"net/http"
	"strconv"
)

type film struct {
	Title      string `json:"Title"`
	Year       int    `json:"Year,string"`
	Rated      string `json:"Rated"`
	Released   string `json:"Released"`
	Runtime    string `json:"Runtime"`
	Genre      string `json:"Genre"`
	Director   string `json:"Director"`
	Writer     string `json:"Writer"`
	Actors     string `json:"Actors"`
	Plot       string `json:"Plot"`
	Language   string `json:"Language"`
	Country    string `json:"Country"`
	Awards     string `json:"Awards"`
	Poster     string `json:"Poster"`
	Metascore  string `json:"Metascore"`
	ImdbRating string `json:"imdbRating"`
	ImdbVotes  string `json:"imdbVotes"`
	ImdbID     string `json:"imdbID"`
	Type       string `json:"Type"`
	Response   string `json:"Response"`
}

func main() {
	resp, err := http.Get("http://www.omdbapi.com/?i=tt0372784&plot=short&r=json")
	if err != nil {
		fmt.Println("an error occured", err)
		return
	}
	defer resp.Body.Close()
	fmt.Println("Status code is", resp.Status)

	body, err := ioutil.ReadAll(resp.Body)
	var movie film
	err1 := json.Unmarshal(body, &movie)
	if err1 != nil {
		fmt.Println("an error occured", err1)
		return
	}

	r1, err3 := strconv.ParseFloat(movie.ImdbRating, 64)
	if err3 != nil {
		fmt.Println("an error occured", err3)
		return
	}

	fmt.Println("The movie :", movie.Title, "was released in", movie.Year, "- the IMBD rating is", r1*10, "\b% with", movie.ImdbVotes, "votes")

}
