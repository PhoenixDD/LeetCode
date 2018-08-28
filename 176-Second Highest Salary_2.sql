# Write your MySQL query statement below
Select (Select Distinct Salary
From Employee
Order By Salary Desc Limit 1,1) As SecondHighestSalary