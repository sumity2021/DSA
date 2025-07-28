# Write your MySQL query statement below


SELECT (
    SELECT salary FROM (
        SELECT * , DENSE_RANK() OVER(ORDER BY salary DESC) AS rnk FROM employee
    ) AS  RANKED 
    WHERE rnk=2 
    LIMIT 1
) AS secondhighestsalary