# Write your MySQL query statement below
SELECT ROUND(COUNT(DISTINCT p.player_id)/(SELECT COUNT(DISTINCT player_id) FROM activity),2) AS fraction
FROM (SELECT player_id , MIN(event_date) AS first_login FROM activity GROUP BY player_id) as p
JOIN activity a
ON p.player_id = a.player_id
AND a.event_date = DATE_ADD(p.first_login, INTERVAL 1 DAY)