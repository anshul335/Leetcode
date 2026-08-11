# Write your MySQL query statement below
SELECT redCheck.name FROM 
(SELECT s.name ,
COUNT(CASE 
        WHEN c.name = 'RED' THEN 1 END) as red_count
FROM SalesPerson s
LEFT JOIN Orders o
ON o.sales_id = s.sales_id
LEFT JOIN Company c
ON o.com_id = c.com_id
GROUP BY s.sales_id, s.name) AS redCheck 
WHERE redCheck.red_count = 0;