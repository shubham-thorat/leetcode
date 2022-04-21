CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    SET N=N-1;
  RETURN (
      SELECT DISTINCT salary FROM Employee order by salary desc limit 1 offset N
  );
END