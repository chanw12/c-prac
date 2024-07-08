-- 코드를 입력하세요
SELECT year(os.sales_date) as YEAR,month(os.sales_date) as MONTH ,gender as GENDER, count(DISTINCT os.user_id) as USERS from online_sale as os
join user_info as ui on ui.user_id = os.user_id
group by year(os.sales_date),month(os.sales_date),gender
having gender = 1 or gender = 0
order by 1,2,3