# Write your MySQL query statement below
Select max(Salary) as SecondHighestSalary
From Employee
where Salary < (select max(Salary) From Employee)