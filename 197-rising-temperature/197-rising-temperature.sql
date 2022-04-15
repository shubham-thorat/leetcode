# Write your MySQL query statement below


SELECT DISTINCT a.id FROM Weather a JOIN Weather b where a.temperature > b.temperature and DATEDIFF(a.recorddate,b.recorddate) = 1;