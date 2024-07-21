SELECT t1.col1, t2.col2, t3.col3
FROM t1
JOIN t2 ON t1.col1 = t2.col1
JOIN t3 ON t2.col2 = t3.col2
WHERE t1.col4 = 'example' AND t2.col5 = 'another_example'
ORDER BY t3.col6 DESC;
