-- 코드를 입력하세요
SELECT a.PRODUCT_ID,a.PRODUCT_NAME,sum(a.price*b.amount) as TOTAL_SALES
from FOOD_PRODUCT as a,FOOD_ORDER as b
where a.PRODUCT_ID = b.PRODUCT_ID and b.PRODUCE_DATE like '2022-05%'
group by a.PRODUCT_ID
order by 3 desc,1 asc