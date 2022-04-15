# Write your MySQL query statement below


SELECT t.id,
    CASE
        WHEN t.p_id IS NULL THEN "Root"
        WHEN t.id NOT IN (SELECT t2.p_id FROM Tree as t2 WHERE t2.p_id IS NOT NULL) THEN "Leaf"
        ELSE "Inner"
    END AS "type"
FROM Tree as t;
    