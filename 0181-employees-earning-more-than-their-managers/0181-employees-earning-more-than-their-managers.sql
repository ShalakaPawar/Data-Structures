# Write your MySQL query statement below
select emp.name as Employee
from Employee as emp  join Employee as man
on emp.managerId = man.id
where emp.salary > man.salary