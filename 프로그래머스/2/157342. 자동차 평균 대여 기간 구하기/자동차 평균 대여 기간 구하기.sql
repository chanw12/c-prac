-- 코드를 입력하세요
SELECT  CAR_ID,ROUND(avg(DATEDIFF(end_date,start_date))+1,1) as AVERAGE_DURATION from CAR_RENTAL_COMPANY_RENTAL_HISTORY
group by car_id
HAVING AVERAGE_DURATION >= 7
order by AVERAGE_DURATION desc,CAR_ID desc

# select * from CAR_RENTAL_COMPANY_RENTAL_HISTORY
# where car_id = 22