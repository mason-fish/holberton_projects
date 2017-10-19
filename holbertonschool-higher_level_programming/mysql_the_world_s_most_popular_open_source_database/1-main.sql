\! echo "\nNumber of seasons by tvshow_id?"
SELECT TVShow.id, COUNT(Season.id) FROM TVShow JOIN Season ON TVShow.id=Season.tvshow_id GROUP BY TVShow.id;
\! echo "\nNumber of occurrences of the same episode number ordered by episode number?"
SELECT Episode.number, COUNT(Episode.number) FROM Episode GROUP BY Episode.number;
\! echo "\nTop 3 of the Genre's occurrences in all TVShows ordered by this number?"
SELECT TVShowGenre.genre_id, COUNT(TVShowGenre.genre_id) AS occurrences_genre FROM TVShowGenre GROUP BY TVShowGenre.genre_id ORDER BY COUNT(TVShowGenre.genre_id) DESC LIMIT 3;
\! echo "\nSearch all TVShow with this letter sequence 'th' case insensitive and display with the name in lowercase?"
SELECT name FROM TVShow WHERE name LIKE '%th%';
