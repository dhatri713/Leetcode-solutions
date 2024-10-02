# Write your MySQL query statement below
WITH MostRecentPrices AS (
    SELECT product_id, new_price,
    ROW_NUMBER() OVER(PARTITION BY product_id ORDER BY change_date DESC) AS rn
    FROM Products
    WHERE change_date <= '2019-08-16'
)

SELECT Products.product_id, COALESCE(new_price, 10) AS price
FROM (SELECT DISTINCT product_id FROM Products) AS Products
LEFT JOIN (SELECT product_id, new_price FROM MostRecentPrices WHERE rn = 1) AS RecentPrices
ON Products.product_id = RecentPrices.product_id;
