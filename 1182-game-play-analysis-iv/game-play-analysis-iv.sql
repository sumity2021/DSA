SELECT 
ROUND(COUNT(DISTINCT b.player_id) / COUNT(DISTINCT a.player_id), 2) AS fraction
FROM activity a
LEFT JOIN (
    SELECT player_id, MIN(event_date) AS first_login
    FROM activity
    GROUP BY player_id
) b
ON a.player_id = b.player_id AND a.event_date = DATE_ADD(b.first_login, INTERVAL 1 DAY);