# Write your MySQL query statement below
SELECT employee_id, department_id
FROM employee 
WHERE primary_flag='y' 
OR employee_id 
IN (SELECT employee_id
FROM employee
GROUP BY employee_id
HAVING COUNT(*)=1)