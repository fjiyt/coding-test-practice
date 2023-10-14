-- 코드를 입력하세요
WITH PICK AS (
    SELECT DISTINCT CART_ID, NAME
    FROM CART_PRODUCTS
    WHERE NAME = 'MILK' OR NAME = 'YOGURT'
) 

SELECT CART_ID
FROM PICK
GROUP BY CART_ID
HAVING COUNT(CART_ID) >= 2
ORDER BY CART_ID