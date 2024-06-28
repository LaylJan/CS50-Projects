SELECT DISTINCT movies.title FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON people.id = stars.person_id
JOIN ratings ON movies.id = ratings.movie_id
WHERE people.name LIKE 'Bradley Cooper' AND movies.id IN (
    SELECT movie_id FROM stars
    JOIN people ON people.id = stars.person_id
    WHERE people.name LIKE 'Jennifer Lawrence'
);