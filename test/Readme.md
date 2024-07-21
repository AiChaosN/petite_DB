


# 各个SQL的内容

## 1. SQL1 单个条件
'''
SELECT * FROM t1 WHERE id = 1;
'''

## 2. SQL2 多个条件
'''
SELECT * FROM t1 WHERE id = 1 and name = 'zhangsan' and age > 18;
'''

## 3. SQL3 两个表 JOIN
'''
SELECT * FROM t1, t2 WHERE t1.id = t2.id;
'''

## 4. SQL4 三个表 JOIN
'''
SELECT t1.col1, t2.col2, t3.col3
FROM t1
JOIN t2 ON t1.col1 = t2.col1
JOIN t3 ON t2.col2 = t3.col2
WHERE t1.col4 = 'example';
'''

## 5. SQL5 多个 SELECT 嵌套
'''
SELECT col1, col2
FROM (
    SELECT col1, col2
    FROM t1
    WHERE col3 IN (
        SELECT col3
        FROM t2
        WHERE col4 = 'example'
    )
) AS subquery1
WHERE col1 IN (
    SELECT col1
    FROM t3
    WHERE col5 > 10
);
'''

## 6. SQL6 子查询
'''
SELECT * FROM t1 WHERE id IN (SELECT id FROM t2 WHERE name = 'zhangsan');
'''

## 7. SQL7 聚合函数
'''
SELECT COUNT(*), SUM(col1), AVG(col2), MAX(col3), MIN(col4) FROM t1;
'''

## 8. SQL8 分组
'''
SELECT col1, COUNT(*), SUM(col2), AVG(col3), MAX(col4), MIN(col5) FROM t1 GROUP BY col1;
'''

## 9. SQL9 排序
'''
SELECT * FROM t1 ORDER BY col1 ASC, col2 DESC;
'''

## 10. SQL10 复杂表
'''
SELECT * FROM (
    SELECT t1.col1, t2.col2
    FROM t1
    JOIN t2 ON t1.id = t2.id
    WHERE t1.col3 = 'example'
) AS subquery1
JOIN t3 ON subquery1.col1 = t3.col1;
'''
