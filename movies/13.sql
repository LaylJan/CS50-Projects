SELECT DISTINCT people.name
FROM people
JOIN stars ON people.id = stars.person_id
JOIN stars AS kevin_stars ON stars.movie_id = kevin_stars.movie_id
JOIN people AS kevin ON kevin_stars.person_id = kevin.id
WHERE kevin.name = 'Kevin Bacon' AND kevin.birth = 1958
    AND people.name != 'Kevin Bacon';