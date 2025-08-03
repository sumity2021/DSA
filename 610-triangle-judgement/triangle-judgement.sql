# Write your MySQL query statement below
SELECT x,y,z,
CASE 
    WHEN (x+y<=z) || (x+z<=y) || (y+z<=x) THEN 'No'
    ELSE 'Yes'
END AS triangle
FROM triangle