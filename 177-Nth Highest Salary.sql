CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    set N=N-1;
  RETURN (
      # Write your MySQL query statement below.
      Select distinct Salary
      From Employee
      Order by Salary Desc Limit N,1
  );
END