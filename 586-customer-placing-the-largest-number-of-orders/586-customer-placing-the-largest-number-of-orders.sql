# Write your MySQL query statement below


# SELECT customer_number FROM (
# SELECT COUNT(customer_number) AS t,customer_number FROM Orders as o1 GROUP BY customer_number ORDER BY t DESC) as t2 limit 1;

SELECT customer_number FROM Orders GROUP BY customer_number ORDER BY COUNT(order_number) DESC limit 1;