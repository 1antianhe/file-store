SET SERVEROUTPUT ON;

DECLARE
  CURSOR emp_cursor IS SELECT ename, job, sal, deptno
  FROM scott.emp 
  WHERE job = (SELECT job FROM scott.emp WHERE deptno = 10 AND rownum = 1);
  emp_name scott.emp.ename%TYPE;
  emp_job scott.emp.job%TYPE;
  emp_sal scott.emp.sal%TYPE;
  emp_deptno scott.emp.deptno%TYPE;
BEGIN
  OPEN emp_cursor;
  LOOP
    FETCH emp_cursor INTO emp_name, emp_job, emp_sal, emp_deptno;
    EXIT WHEN emp_cursor%NOTFOUND;
    DBMS_OUTPUT.PUT_LINE('ename:'||emp_name || ' job:' || emp_job ||
      ' sal:' || emp_sal || ' deptno:' || emp_deptno);
  END LOOP;
  CLOSE emp_cursor;
END;
/
