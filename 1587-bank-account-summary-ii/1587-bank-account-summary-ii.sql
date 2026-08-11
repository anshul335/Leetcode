# Write your MySQL query statement below
SELECT DISTINCT u.name as NAME, balance_count.total_balance as BALANCE
FROM Users u
LEFT JOIN (SELECT t.account , 
SUM(t.amount) OVER(PARTITION  BY t.account ) as total_balance
FROM Transactions t 
) as balance_count 
ON balance_count.account = u.account
WHERE balance_count.total_balance > 10000

