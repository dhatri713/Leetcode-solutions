SELECT e.name 
FROM Employee e
LEFT JOIN Employee m
ON e.id = m.managerId
GROUP BY e.id
HAVING COUNT(DISTINCT m.id) >= 5;