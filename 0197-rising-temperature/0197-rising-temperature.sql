SELECT id
FROM Weather curr
WHERE curr.temperature > (
    SELECT prev.temperature
    FROM Weather prev
    WHERE DATEDIFF(curr.recordDate, prev.recordDate) = 1
);