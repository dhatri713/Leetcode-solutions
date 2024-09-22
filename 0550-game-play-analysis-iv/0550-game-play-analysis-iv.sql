# Write your MySQL query statement below
WITH FirstDayLogin AS (
    SELECT MIN(event_date) AS first_date, player_id
    FROM Activity
    GROUP BY player_id
),

NextDayLogin AS (
    SELECT A.player_id
    FROM Activity A
    JOIN FirstDayLogin F
    ON A.player_id = F.player_id
    AND DATEDIFF(A.event_date, F.first_date) = 1
)

SELECT ROUND((SELECT COUNT(DISTINCT player_id) FROM NextDayLogin) / (SELECT COUNT(DISTINCT player_id) FROM Activity), 2) AS fraction;