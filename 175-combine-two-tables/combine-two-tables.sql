# Write your MySQL query statement below
SELECT firstName, lastName,city,state FROM Person p LEFT JOIN address a ON p.personid = a.personid;
