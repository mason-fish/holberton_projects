SELECT DISTINCT
       TVShow.name,
       SUM(Person.age)
FROM TVShow
INNER JOIN Person, TVShowPerson
ON Person.id=TVShowPerson.person_id
AND TVShowPerson.tvshow_id=TVShow.id
GROUP BY TVShow.name
ORDER BY SUM(Person.age) ASC;

SELECT DISTINCT
       TVShow.name,
       Person.first_name,
       Person.last_name,
       MIN(Person.age)
FROM Person
INNER JOIN TVShow, TVShowPerson
ON Person.id=TVShowPerson.person_id
AND TVShowPerson.tvshow_id=TVShow.id
GROUP BY TVShow.name
ORDER BY Person.age ASC;

       
