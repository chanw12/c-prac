-- 코드를 입력하세요
SELECT a.REST_ID,a.REST_NAME,a.FOOD_TYPE,a.FAVORITES,a.ADDRESS,b.SCORE from rest_info as a
join (
    select rest_id,round(avg(review_score),2) as SCORE from rest_review
    group by rest_id
) as b on a.rest_id = b.rest_id
where a.address like '서울%'
order by b.SCORE desc, a.FAVORITES desc;