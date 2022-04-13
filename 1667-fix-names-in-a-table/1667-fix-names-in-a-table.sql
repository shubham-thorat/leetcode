# Write your MySQL query statement below


# SELECT user_id,concat(UPPER(SUBSTR(name),1,1),LOWER(SUBSTR(name,1,len(name)))) FROM Users;

SELECT user_id,
CONCAT (
    UPPER(SUBSTR(name,1,1)),
    LOWER(SUBSTR(name,2))
) as name
FROM Users AS u ORDER BY user_id;