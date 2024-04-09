-- 코드를 입력하세요
SELECT FOOD_TYPE,REST_ID,REST_NAME,FAVORITES from rest_info 
where (FOOD_TYPE,FAVORITES )in (select FOOD_TYPE,MAX(FAVORITES) as FAVORITES from rest_info group by FOOD_TYPE)
order by FOOD_TYPE desc
# select FOOD_TYPE,MAX(FAVORITES) from rest_info group by FOOD_TYPE
