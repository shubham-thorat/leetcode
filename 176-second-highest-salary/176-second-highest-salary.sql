# select IFNULL(
#     Null, 
#     (select distinct Salary from Employee 
#      order by Salary desc limit 1,1)
#  )
# as SecondHighestSalary

select (
select distinct(salary) from employee order by salary desc limit 1 offset 1 ) as SecondHighestSalary;