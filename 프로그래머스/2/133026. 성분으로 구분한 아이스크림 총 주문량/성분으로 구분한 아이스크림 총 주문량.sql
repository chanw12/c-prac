-- 코드를 입력하세요
SELECT INGREDIENT_TYPE , sum(TOTAL_ORDER) as TOTAL_ORDER from first_half as a
join icecream_info as b on a.flavor = b.flavor
group by INGREDIENT_TYPE