# Write your MySQL query statement below
SELECT DISTINCT author_id AS id
FROM Views 
WHERE views.author_id=views.viewer_id
ORDER BY author_id