CREATE OR REPLACE FUNCTION select_name_sal (p_empno IN NUMBER)
RETURN VARCHAR2
IS
  v_ename VARCHAR2(50);
  v_sal NUMBER;
BEGIN
  SELECT ename, sal INTO v_ename, v_sal FROM emp WHERE empno = p_empno;
  RETURN v_ename || ' ' || v_sal;
END;
/
