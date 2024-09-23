# Write your MySQL query statement below
WITH CountTable AS (
    SELECT COUNT(num) as cnt, num
    FROM MyNumbers
    GROUP BY num
)

SELECT MAX(m.num) AS num
FROM MyNumbers m
JOIN CountTable c
ON m.num = c.num
WHERE c.cnt = 1;
