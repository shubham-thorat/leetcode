# Write your MySQL query statement below


# SELECT employee_id,m.bonus
#     CASE WHEN employee_id % 2 == 1 AND name != 'M%'
#         THEN salary
#         ELSE 0
#     END AS bonus
# AS m FROM Employees;



SELECT e.employee_id,
    CASE
        WHEN e.employee_id % 2 = 1 AND e.name NOT LIKE "M%" THEN salary
        ELSE 0
    END AS bonus
FROM Employees AS e;