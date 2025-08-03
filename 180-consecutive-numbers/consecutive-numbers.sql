# Write your MySQL query statement below
SELECT DISTINCT num as consecutiveNums 
FROM
(
    SELECT id,num,
    LEAD(num) OVER(ORDER BY id) AS nxt,
    LAG(num) OVER(ORDER BY id) AS prev
    FROM Logs
) AS sub
WHERE sub.nxt=num AND sub.prev=num