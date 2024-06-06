-- 코드를 입력하세요
with count_table as (
    SELECT car_id,count(*) as COUNT from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where start_date >= DATE("2022-08-01")
    group by car_id
    having COUNT >=5
)
# select * from count_table
# order by car_id
# select * from CAR_RENTAL_COMPANY_RENTAL_HISTORY
select MONTH(start_date) as MONTH,a.car_id as CAR_ID,count(*) as RECORDS from CAR_RENTAL_COMPANY_RENTAL_HISTORY as a
join count_table as b on a.car_id = b.car_id
WHERE 
    a.start_date >= DATE('2022-08-01')
group by YEAR(a.start_date), MONTH(a.start_date), a.car_id
order by 1 asc,2 desc