# Write your MySQL query statement below
SELECT e2.employee_id
FROM employees e1
RIGHT JOIN employees e2
ON e1.employee_id=e2.manager_id
WHERE e2.salary<30000 AND e2.manager_id IS NOT NULL AND e1.employee_id IS NULL
ORDER BY e2.employee_id