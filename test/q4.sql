SELECT t1.col1, t2.col2, t3.col3
FROM t1
JOIN t2 ON t1.col1 = t2.col1
JOIN t3 ON t2.col2 = t3.col2
WHERE t1.col4 = 'example';
