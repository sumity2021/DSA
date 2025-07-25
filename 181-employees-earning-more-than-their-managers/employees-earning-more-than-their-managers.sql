# Write your MySQL query statement below
SELECT e.name as employee
FROM employee e 
JOIN 
employee m
ON e.managerID = m.id
WHERE e.salary>m.salary;