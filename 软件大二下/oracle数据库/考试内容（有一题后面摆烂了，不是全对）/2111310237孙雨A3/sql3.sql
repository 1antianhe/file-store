CREATE OR REPLACE TRIGGER trigger_insert_emp
AFTER INSERT ON emp
DECLARE
    v_row_count NUMBER;
BEGIN
    SELECT COUNT(*) INTO v_row_count FROM emp;

    DBMS_OUTPUT.PUT_LINE('New row count in emp table: ' || v_row_count);
END;
/
