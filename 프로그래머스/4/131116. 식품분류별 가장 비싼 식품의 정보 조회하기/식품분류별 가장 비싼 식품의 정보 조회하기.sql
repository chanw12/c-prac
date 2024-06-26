-- 코드를 입력하세요
SELECT a.CATEGORY,price as MAX_PRICE,PRODUCT_NAME from FOOD_PRODUCT a,
( SELECT CATEGORY, MAX(PRICE) AS MAX_PRICE
    FROM FOOD_PRODUCT
    WHERE CATEGORY IN ('과자', '국', '김치', '식용유')
    GROUP BY CATEGORY ) as b
where a.category = b.category and a.price = b.MAX_PRICE
order by 2 desc

# SELECT CATEGORY, MAX(PRICE) AS MAX_PRICE
#     FROM FOOD_PRODUCT
#     WHERE CATEGORY IN ('과자', '국', '김치', '식용유')
#     GROUP BY CATEGORY 