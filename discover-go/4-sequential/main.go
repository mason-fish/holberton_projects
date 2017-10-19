package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"io/ioutil"
	"net/http"
	"strconv"
	"time"
)

// Film struct for JSON from name based search
type Film struct {
	Search       []Inner `json:"Search"`
	TotalResults string  `json:"totalResults"`
	Response     string  `json:"Response"`
}

// Inner struct for nested JSON from name based search
type Inner struct {
	Title  string `json:"Title"`
	Year   string `json:"Year"`
	ImdbID string `json:"imdbID"`
	Type   string `json:"Type"`
	Poster string `json:"Poster"`
}

// IDFilm struct for JSON from id based search
type IDFilm struct {
	Title      string `json:"Title"`
	Year       string `json:"Year"`
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
	start := time.Now()
	var movieName string
	flag.StringVar(&movieName, "movie", "Batman", "a string for a movie")
	flag.Parse()

	getID(movieName)
	elapsed := time.Since(start)
	fmt.Printf("execution time is: %s\n", elapsed)
}
func getMovie(movieID string) {
	resp, err := http.Get("http://www.omdbapi.com/?i=" + movieID + "&plot=short&r=json")
	if err != nil {
		fmt.Println("an error occured", err)
		return
	}
	defer resp.Body.Close()

	body, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		fmt.Println("ioutil ===", err)
		return
	}
	var movie IDFilm
	err1 := json.Unmarshal(body, &movie)
	if err1 != nil {
		fmt.Println("json ===", err1)
		return
	}

	r1, err3 := strconv.ParseFloat(movie.ImdbRating, 64)
	if err3 != nil {
		fmt.Println("an error occured", err3)
		return
	}

	fmt.Println("The movie :", movie.Title, "was released in", movie.Year, "- the IMBD rating is", r1*10, "\b% with", movie.ImdbVotes, "votes")

}

func getID(opt string) {
	resp, err := http.Get("http://www.omdbapi.com/?s=" + opt)
	if err != nil {
		return
	}
	defer resp.Body.Close()

	body, err := ioutil.ReadAll(resp.Body)
	var movie Film
	err5 := json.Unmarshal(body, &movie)
	if err5 != nil {
		return
	}

	for i := 0; i < len(movie.Search); i++ {
		getMovie(movie.Search[i].ImdbID)
	}
	return
}
