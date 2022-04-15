# Write your MySQL query statement below

SELECT customer_id,COUNT(customer_id) AS count_no_trans 
    FROM Visits AS v LEFT JOIN Transactions AS t 
    ON v.visit_id = t.visit_id 
    WHERE t.visit_id IS NULL GROUP BY v.customer_id;  
    
#     SELECT
# 	customer_id,
# 	COUNT(Visits.visit_id) AS count_no_trans
# FROM
# 	visits
# LEFT JOIN Transactions
# 	ON Visits.visit_id = Transactions.visit_id
# WHERE 
# 	Transactions.visit_id IS NULL
# GROUP BY customer_id