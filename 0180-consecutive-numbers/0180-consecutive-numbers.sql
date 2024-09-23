-- SELECT DISTINCT l1.num AS ConsecutiveNums
-- FROM Logs l1, Logs l2, Logs l3
-- WHERE l1.id = l2.id - 1 AND l2.id = l3.id - 1 AND l1.num = l2.num AND l2.num = l3.num;

SELECT DISTINCT num AS ConsecutiveNums
FROM (
    SELECT num,
    LEAD(num) OVER (ORDER BY id) AS next_num,
    LAG(num) OVER (ORDER BY id) AS prev_num
    FROM Logs
) AS SubQuery 
WHERE prev_num = num AND next_num = num;