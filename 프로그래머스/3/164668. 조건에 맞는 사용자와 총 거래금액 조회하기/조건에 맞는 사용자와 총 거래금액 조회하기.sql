-- 코드를 입력하세요
SELECT USER_ID, NICKNAME, TOTAL AS TOTAL_SALES
FROM USED_GOODS_USER AS A
RIGHT JOIN
(
    SELECT WRITER_ID, SUM(PRICE) AS TOTAL
    FROM USED_GOODS_BOARD
    WHERE STATUS = 'DONE'
    GROUP BY WRITER_ID
) AS B
ON A.USER_ID = B.WRITER_ID
WHERE TOTAL >= 700000
ORDER BY TOTAL_SALES