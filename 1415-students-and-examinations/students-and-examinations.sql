# Write your MySQL query statement below
with cte1 AS(
    SELECT*
    FROM students 
    CROSS JOIN subjects
),
cte2 AS(
    SELECT student_id,subject_name, COUNT(subject_name) AS cnt
    FROM examinations
    GROUP BY student_id ,subject_name
)
SELECT cte1.student_id, cte1.student_name, cte1.subject_name,
CASE
    WHEN cte2.cnt IS NULL THEN 0
    ELSE cte2.cnt
END AS attended_exams
FROM cte1
LEFT JOIN cte2
ON cte1.student_id=cte2.student_id AND cte1.subject_name=cte2.subject_name
ORDER BY cte1.student_id , cte1.subject_name