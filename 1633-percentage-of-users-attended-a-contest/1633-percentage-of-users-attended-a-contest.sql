SELECT r.contest_id, 
       ROUND((COUNT(r.user_id) / (SELECT COUNT(user_id) FROM Users)) * 100, 2) AS percentage
FROM Register r
LEFT JOIN Users u ON u.user_id = r.user_id
GROUP BY r.contest_id
ORDER BY percentage DESC, r.contest_id ASC;
