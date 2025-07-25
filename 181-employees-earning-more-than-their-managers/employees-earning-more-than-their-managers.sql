# Write your MySQL query statement below
SELECT m.name as employee
FROM employee e 
JOIN 
employee m
ON e.id = m.managerId
WHERE e.salary<m.salary;